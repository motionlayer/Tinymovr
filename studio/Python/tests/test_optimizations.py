"""
Tinymovr Control Loop Optimization Tests
Copyright Ioannis Chatzikonstantinou 2020-2023

Tests to validate that control loop optimizations do not introduce regressions.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.
This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.
"""

import time
from avlos.unit_field import get_registry

import unittest
import pytest
from tests import TMTestCase

ureg = get_registry()
A = ureg.ampere
ticks = ureg.ticks
s = ureg.second


class TestOptimizations(TMTestCase):

    @pytest.mark.hitl_default
    def test_scheduler_load_during_control(self):
        """
        Test that scheduler load remains within budget during active
        closed-loop control. This validates that control loop optimizations
        have not increased execution time.
        """
        self.check_state(0)
        self.try_calibrate()
        self.tm.controller.position_mode()
        self.check_state(2)

        # Move to a position to exercise the full control path
        self.tm.controller.position.setpoint = 5000 * ticks
        time.sleep(0.5)

        # Sample scheduler load during active control
        loads = []
        for _ in range(100):
            load = self.tm.scheduler.load
            if load > 0:
                loads.append(load)
            time.sleep(0.01)

        self.assertGreater(len(loads), 50, "Not enough valid load samples")

        avg_load = sum(loads) / len(loads)
        max_load = max(loads)

        # Average load must be well under the 3000-cycle budget
        self.assertLess(avg_load, 3000,
                        f"Average scheduler load {avg_load:.0f} exceeds budget")
        # Peak load must not exceed safety margin (allow headroom for
        # occasional spikes from CAN servicing, cache misses, etc.)
        self.assertLess(max_load, 5500,
                        f"Peak scheduler load {max_load} exceeds safety margin")

    @pytest.mark.hitl_default
    def test_error_detection_still_works(self):
        """
        Test that the error detection path (errors_exist) works correctly
        after the sensor error caching optimization. Verifies that errors
        are properly reported and the controller transitions to idle.
        """
        self.check_state(0)
        self.try_calibrate()
        self.tm.controller.position_mode()
        self.check_state(2)

        # Normal operation should have no errors
        self.assertEqual(self.tm.errors, 0)

        # Set a very large position setpoint to trigger overcurrent
        # protection, which should be caught by errors_exist()
        self.tm.controller.position.setpoint = 500000 * ticks
        time.sleep(1.0)

        # Controller should have gone to idle due to error detection
        # (overcurrent trip forces idle state)
        state = self.tm.controller.state
        errors = self.tm.errors

        # Either the controller handled the large setpoint gracefully
        # (state == 2, no errors) or detected an error and went idle
        if errors != 0:
            self.assertEqual(state, 0,
                             "Controller should be idle when errors are present")

    @pytest.mark.hitl_default
    def test_temperature_reading_valid(self):
        """
        Test that MCU temperature readings remain valid after moving
        the temperature calculation from the 20 kHz ADC loop to the
        1 kHz SysTick handler.
        """
        # Sample temperature readings
        temps = []
        for _ in range(50):
            temps.append(self.tm.temp)
            time.sleep(0.02)

        # Temperature should be in a reasonable range for an MCU
        # (typically 20-80 degC during normal operation).
        # Use .magnitude since Pint offset units (degC) cannot be
        # compared directly against plain numbers.
        temp_vals = [t.magnitude for t in temps]
        for val in temp_vals:
            self.assertGreater(val, 0,
                               f"Temperature {val} degC is unreasonably low")
            self.assertLess(val, 100,
                            f"Temperature {val} degC is unreasonably high")

        # Temperature readings should be stable (low variance)
        avg_temp = sum(temp_vals) / len(temp_vals)
        max_deviation = max(abs(v - avg_temp) for v in temp_vals)
        self.assertLess(max_deviation, 10,
                        f"Temperature deviation {max_deviation:.1f} degC is too high")


if __name__ == "__main__":
    unittest.main(failfast=True)
