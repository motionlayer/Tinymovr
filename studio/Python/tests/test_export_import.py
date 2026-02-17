"""
Tinymovr Export/Import Tests
Copyright Ioannis Chatzikonstantinou 2020-2023

Tests for export/import functionality:
- YAML spec consistency (all settable config attrs have export: True)
- HITL round-trip (export -> reset -> import -> verify)
- HITL export completeness (all export-tagged attrs appear in output)

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

import os
import time
import json
import unittest

import yaml
import pytest
from importlib.resources import files as importlib_files

from avlos.unit_field import get_registry
from avlos.json_codec import AvlosEncoder
from avlos.definitions import RemoteAttribute, RemoteEnum, RemoteBitmask

from tinymovr.config import export_config, import_config
from tests import TMTestCase

ureg = get_registry()
A = ureg.ampere
Hz = ureg.hertz
tick = ureg.ticks
s = ureg.second

# ---------------------------------------------------------------------------
# Helpers for YAML spec walking
# ---------------------------------------------------------------------------

SPECS_DIR = str(importlib_files("tinymovr").joinpath("specs"))

# Attributes that have setters but should NOT have export: True.
# Includes runtime controls and dangerous-to-import parameters.
EXCLUDED_SETTER_PATHS = {
    "controller.state",
    "controller.mode",
    "comms.can.rate",  # importing a mismatched CAN rate kills communication
    "comms.can.id",    # importing CAN ID mid-batch disrupts addressing
}

# Meta keys that indicate a runtime setpoint rather than a config parameter.
RUNTIME_META_KEYS = {"jog_step"}


def _walk_spec_attrs(attrs, path_prefix=""):
    """
    Recursively yield (dotted_path, attr_dict) for every leaf attribute
    in a YAML spec attribute tree.
    """
    for attr in attrs:
        name = attr["name"]
        dotted = f"{path_prefix}.{name}" if path_prefix else name
        if "remote_attributes" in attr:
            yield from _walk_spec_attrs(attr["remote_attributes"], dotted)
        else:
            yield dotted, attr


def _is_excluded_setter(dotted_path, attr):
    """
    Return True if this attribute has a setter but should NOT
    be expected to have export: True (e.g. runtime controls,
    dangerous-to-import parameters).
    """
    if dotted_path in EXCLUDED_SETTER_PATHS:
        return True
    meta = attr.get("meta", {})
    if any(k in meta for k in RUNTIME_META_KEYS):
        return True
    return False


# ---------------------------------------------------------------------------
# 4a. YAML Spec Consistency Test (no hardware required)
# ---------------------------------------------------------------------------

class TestSpecExportConsistency(unittest.TestCase):
    """
    Verify that every settable config attribute in the latest YAML spec
    has meta: {export: True}.  This is a pure-Python test with no hardware
    dependency.
    """

    def _load_spec(self, filename):
        path = os.path.join(SPECS_DIR, filename)
        with open(path, "r") as f:
            return yaml.safe_load(f)

    def _check_spec(self, filename):
        spec = self._load_spec(filename)
        missing = []
        for dotted, attr in _walk_spec_attrs(spec.get("remote_attributes", [])):
            if "setter_name" not in attr:
                continue
            if _is_excluded_setter(dotted, attr):
                continue
            # Also skip void callers masquerading as setters (arguments list)
            if "arguments" in attr:
                continue
            meta = attr.get("meta", {})
            if not meta.get("export"):
                missing.append(dotted)
        return missing

    def test_latest_spec_export_tags(self):
        """
        All settable config attributes in tinymovr_2_5_x.yaml must have
        meta: {export: True}.
        """
        missing = self._check_spec("tinymovr_2_5_x.yaml")
        self.assertEqual(
            missing,
            [],
            "The following settable config attributes are missing "
            "meta: {export: True} in tinymovr_2_5_x.yaml:\n  "
            + "\n  ".join(missing),
        )


# ---------------------------------------------------------------------------
# 4b. HITL Export/Import Round-Trip Test
# ---------------------------------------------------------------------------

@pytest.mark.hitl_default
class TestExportImportRoundTrip(TMTestCase):
    """
    Hardware-in-the-loop test: modify values, export, reset to defaults,
    import, then verify the values were restored.
    """

    def test_a_export_import_round_trip(self):
        """
        Set non-default values on key attributes, export, reset, import,
        and verify each value is correctly restored.
        """
        self.check_state(0)
        self.erase_config()
        time.sleep(0.2)

        self.try_calibrate()
        self.assertEqual(self.tm.motor.calibrated, True)

        # --- Define test values (non-default) ---
        test_values = {
            "controller.position.p_gain": 35.0,
            "controller.velocity.p_gain": 5e-5,
            "controller.velocity.i_gain": 1.5e-2,
            "controller.velocity.limit": 80000,
            "controller.velocity.deadband": 300,
            "controller.velocity.increment": 150.0,
            "controller.current.bandwidth": 1500.0,
            "controller.current.max_Ibrake": 2.0,
            "traj_planner.max_vel": 90000,
            "traj_planner.max_accel": 400000,
            "traj_planner.max_decel": 400000,
        }

        # Conditionally add attrs that may exist in newer specs
        if hasattr(self.tm.controller.current, "Iq_limit"):
            test_values["controller.current.Iq_limit"] = 6.0
        if hasattr(self.tm.controller.current, "max_Ibus_regen"):
            test_values["controller.current.max_Ibus_regen"] = 1.5

        # --- Set values ---
        self.tm.controller.position.p_gain = test_values["controller.position.p_gain"]
        self.tm.controller.velocity.p_gain = test_values["controller.velocity.p_gain"]
        self.tm.controller.velocity.i_gain = test_values["controller.velocity.i_gain"]
        self.tm.controller.velocity.limit = test_values["controller.velocity.limit"] * tick / s
        self.tm.controller.velocity.deadband = test_values["controller.velocity.deadband"] * tick
        self.tm.controller.velocity.increment = test_values["controller.velocity.increment"]
        self.tm.controller.current.bandwidth = test_values["controller.current.bandwidth"]
        self.tm.controller.current.max_Ibrake = test_values["controller.current.max_Ibrake"] * A
        self.tm.traj_planner.max_vel = test_values["traj_planner.max_vel"] * tick / s
        self.tm.traj_planner.max_accel = test_values["traj_planner.max_accel"] * tick / s
        self.tm.traj_planner.max_decel = test_values["traj_planner.max_decel"] * tick / (s * s)

        if "controller.current.Iq_limit" in test_values:
            self.tm.controller.current.Iq_limit = test_values["controller.current.Iq_limit"]
        if "controller.current.max_Ibus_regen" in test_values:
            self.tm.controller.current.max_Ibus_regen = test_values["controller.current.max_Ibus_regen"]

        time.sleep(0.1)

        # --- Export ---
        exported = export_config(self.tm)
        self.assertIsNotNone(exported, "export_config() returned None")
        self.assertIsInstance(exported, dict, "export_config() should return a dict")

        # Verify JSON round-trip (mimics what the GUI does)
        json_str = json.dumps(exported, cls=AvlosEncoder)
        reimported = json.loads(json_str)
        self.assertIsInstance(reimported, dict)

        # --- Verify exported contains key sections ---
        self.assertIn("controller", exported)
        self.assertIn("traj_planner", exported)

        # --- Verify current controller attributes are exported if device supports them ---
        if "controller.current.Iq_limit" in test_values:
            self.assertIn("current", exported["controller"],
                          "controller.current section missing from export")
            self.assertIn("Iq_limit", exported["controller"]["current"],
                          "Iq_limit missing from exported JSON")
            # Compare as Quantity (exported value is a pint.Quantity before JSON encoding)
            self.assertAlmostEqual(
                exported["controller"]["current"]["Iq_limit"],
                test_values["controller.current.Iq_limit"] * A,
                msg="Iq_limit value mismatch in exported JSON"
            )
        if "controller.current.max_Ibus_regen" in test_values:
            self.assertIn("current", exported["controller"],
                          "controller.current section missing from export")
            self.assertIn("max_Ibus_regen", exported["controller"]["current"],
                          "max_Ibus_regen missing from exported JSON")
            # Compare as Quantity (exported value is a pint.Quantity before JSON encoding)
            self.assertAlmostEqual(
                exported["controller"]["current"]["max_Ibus_regen"],
                test_values["controller.current.max_Ibus_regen"] * A,
                msg="max_Ibus_regen value mismatch in exported JSON"
            )

        # --- Reset to defaults ---
        self.tm.controller.idle()
        time.sleep(0.1)
        self.erase_config()
        time.sleep(0.2)
        self.reset_and_wait()

        # --- Import ---
        import_config(self.tm, reimported)
        time.sleep(0.2)

        # --- Verify values restored ---
        self.assertAlmostEqual(
            self.tm.controller.position.p_gain,
            test_values["controller.position.p_gain"],
            places=1,
            msg="p_gain not restored after import",
        )
        self.assertAlmostEqual(
            self.tm.controller.velocity.p_gain,
            test_values["controller.velocity.p_gain"],
            places=8,
            msg="velocity p_gain not restored after import",
        )
        self.assertAlmostEqual(
            self.tm.controller.velocity.i_gain,
            test_values["controller.velocity.i_gain"],
            places=5,
            msg="velocity i_gain not restored after import",
        )
        self.assertAlmostEqual(
            self.tm.controller.velocity.limit,
            test_values["controller.velocity.limit"] * tick / s,
            msg="velocity limit not restored after import",
        )
        self.assertAlmostEqual(
            self.tm.controller.velocity.deadband,
            test_values["controller.velocity.deadband"] * tick,
            msg="velocity deadband not restored after import",
        )
        self.assertAlmostEqual(
            self.tm.controller.current.bandwidth,
            test_values["controller.current.bandwidth"] * Hz,
            delta=50 * Hz,
            msg="current bandwidth not restored after import",
        )
        self.assertAlmostEqual(
            self.tm.controller.current.max_Ibrake,
            test_values["controller.current.max_Ibrake"] * A,
            msg="max_Ibrake not restored after import",
        )
        self.assertAlmostEqual(
            self.tm.traj_planner.max_vel,
            test_values["traj_planner.max_vel"] * tick / s,
            msg="traj_planner max_vel not restored after import",
        )
        self.assertAlmostEqual(
            self.tm.traj_planner.max_accel,
            test_values["traj_planner.max_accel"] * tick / s,
            msg="traj_planner max_accel not restored after import",
        )

        if "controller.current.Iq_limit" in test_values:
            self.assertAlmostEqual(
                self.tm.controller.current.Iq_limit,
                test_values["controller.current.Iq_limit"] * A,
                msg="Iq_limit not restored after import",
            )
        if "controller.current.max_Ibus_regen" in test_values:
            self.assertAlmostEqual(
                self.tm.controller.current.max_Ibus_regen,
                test_values["controller.current.max_Ibus_regen"] * A,
                msg="max_Ibus_regen not restored after import",
            )

        # --- Clean up ---
        self.erase_config()
        time.sleep(0.2)


# ---------------------------------------------------------------------------
# 4c. HITL Export Completeness Test
# ---------------------------------------------------------------------------

@pytest.mark.hitl_default
class TestExportCompleteness(TMTestCase):
    """
    Verify every attribute with meta: {export: True} on the *connected
    device* actually appears in the output of export_values().

    Uses the live device attribute tree (not a YAML file) so the test
    is accurate regardless of which firmware/spec version is running.
    """

    def _collect_device_export_paths(self, node, prefix=""):
        """
        Walk the live Avlos node tree and collect dotted paths of all
        attributes that have meta["export"] == True.
        """
        paths = []
        if hasattr(node, "remote_attributes"):
            for name, child in node.remote_attributes.items():
                dotted = f"{prefix}.{name}" if prefix else name
                paths.extend(self._collect_device_export_paths(child, dotted))
        else:
            if isinstance(node, (RemoteAttribute, RemoteEnum, RemoteBitmask)):
                if node.meta.get("export"):
                    paths.append(prefix)
        return paths

    def _lookup_nested(self, data, dotted_path):
        """
        Look up a dotted path like 'controller.position.p_gain' in a
        nested dict.  Returns (True, value) or (False, None).
        """
        keys = dotted_path.split(".")
        current = data
        for key in keys:
            if not isinstance(current, dict) or key not in current:
                return False, None
            current = current[key]
        return True, current

    def test_a_all_export_tagged_attrs_present(self):
        """
        Every attribute with export: True on the connected device must
        appear in export_values() output.
        """
        self.check_state(0)
        self.try_calibrate()

        exported = export_config(self.tm)
        self.assertIsNotNone(exported, "export_config() returned None")

        expected_paths = self._collect_device_export_paths(self.tm)
        self.assertGreater(len(expected_paths), 0,
                           "No export-tagged attributes found on device")

        missing = []
        for path in expected_paths:
            found, _ = self._lookup_nested(exported, path)
            if not found:
                missing.append(path)

        self.assertEqual(
            missing,
            [],
            "The following export-tagged attributes are missing from "
            "export_values() output:\n  " + "\n  ".join(missing),
        )

        self.erase_config()
        time.sleep(0.2)


if __name__ == "__main__":
    unittest.main()
