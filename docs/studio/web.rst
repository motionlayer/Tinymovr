Studio Web
==========

Studio Web is a browser dashboard for configuring and controlling Tinymovr
through an slcan-compatible USB-CAN serial adapter. Download
``motionlayer-studio-web-3.2.1.html`` from the
`3.2.1 release <https://github.com/motionlayer/Tinymovr/releases/tag/3.2.1>`_
and open it in a desktop browser with Web Serial support, such as Chrome or
Edge. Firefox and Safari are not supported by this dashboard.

Web Studio shares its release version with firmware and Python Studio. The
version appears in the dashboard header; hover over it to see the source commit.

Connect
-------

Connect the adapter and powered Tinymovr, choose the bus bitrate, then use the
connection control to select the adapter's serial port. The dashboard discovers
compatible devices on the bus. Close other programs using that serial port.
On Linux, a failed connection may display guidance about serial-port permissions;
ensure your user has access to the selected device and reconnect after applying
the relevant permissions for your distribution.

Trajectory planner
------------------

The planner offers velocity-limited and time-limited position moves. Calibrate
the device, verify limits and available travel, and enter position control
before launching a move. The planner sends motion commands to the device;
its preview does not detect mechanical obstacles. See :doc:`../features/features`
for the firmware trajectory planner parameters.

Configuration and firmware
--------------------------

The dashboard supports configuration import/export and device actions such as
saving configuration and resetting. Review imported settings for your motor
and hardware. Firmware flashing is not implemented in this dashboard; use
:doc:`../upgrade/upgrade`.

Usage analytics
---------------

The dashboard includes Umami analytics for page visits and categorical events,
including connection results, firmware versions, calibration outcomes, and
trajectory profile selection. Configuration values and motor serial numbers
are not included in the application's event payloads. A browser tracker blocker
can block the analytics script without preventing motor control.
