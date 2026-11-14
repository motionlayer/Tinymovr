Release 3.2.1
=============

This documentation describes firmware 3.2.1 and the matching Studio packages.
Download binaries, the Python wheel, and the browser dashboard from the
`3.2.1 release <https://github.com/motionlayer/Tinymovr/releases/tag/3.2.1>`_.
The public repository's firmware and Studio source remains frozen at 3.0.0;
GitHub's automatically generated source archives and public compare links do
not describe the current private implementation.

Compatibility
-------------

Use Studio Python 3.2.1 or the Studio Web asset distributed with release 3.2.1.
The firmware protocol hash is ``957896750`` and differs from 3.0.0. A client
without this protocol definition cannot connect. The :ref:`api-reference` is
generated from the matching protocol definition (the 3.1.x schema is also used
by firmware 3.2.1).

Changes in 3.2.1
----------------

* Adds the M5.4 target (``M54``) with 20 mOhm shunts and hardware revision ID 24.
  M5.1/M5.2 still use ``M51``; these firmware targets are not interchangeable.
* Fixes Web Studio setpoint editing during polling and initializes each homing run.
* Clears homing velocity feedforward on completion and timeout.
* Aligns the Web Studio release version with firmware and Python Studio.
* Retains the 3.2.0 protocol hash; Studio Python 3.2.0 remains compatible.

Changes since the frozen public source
--------------------------------------

* External SPI sensor selection supports MPS MA600.
* :ref:`differential-positioning` adds geared dual-encoder calibration and
  absolute origin recovery within one output-shaft turn.
* X5.1 adds an onboard geared second encoder and defaults to differential mode.
* A separate position encoder skips rotor-based eccentricity compensation by
  default; the commutation magnetic encoder still receives compensation.
* :doc:`studio/web` adds a trajectory planner, connection guidance for Linux,
  and anonymous usage analytics. The calibration banner is dismissed when a
  closed-loop control state is selected; this is not confirmation of calibration.

Upgrading
---------

See :doc:`upgrade/upgrade`. Use the board-specific ``-upgrade.bin`` for CAN DFU.
The ``-release.bin`` image includes the bootloader and is intended for full
programming via a debug probe. M5.1 and M5.2 use ``M51`` assets; M5.4 uses ``M54``; X5.1 uses ``X51``.
Firmware changes invalidate saved configuration except the separately preserved
CAN node ID. Restore appropriate settings and recalibrate before operation.
