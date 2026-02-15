***************
Comm Interfaces
***************


CAN Bus
-------

CAN Bus is the primary interface for communicating with Tinymovr. The physical and data link interface adheres to the CAN 2.0 standard. Tinymovr exposes to CAN all communication endpoints defined in firmware.

Data rate
#########

By default, the CAN baud rate is set to 1Mbit/s. This is customizable both through CAN as well as through UART. See :ref:`api-can-rate`. Possible values are 125kbit/s, 250kbit/s, 500kbit/s and 1Mbit/s.

Addressing
##########

Tinymovr uses extended CAN frames for communication. The 29-bit identifier of the extended CAN frame is used for device, endpoint and message sequence identification. The 12 least significant bits of the identifier are reserved for endpoint identification, the next 9 for message sequence identification, and the 8 most significant bits, for device identification. The total number of addressable endpoints in a single device are 4096, the number of addressable devices is 256, and a message sequence can include up to 512 messages. 

Protocol
########

For a detailed description, please see :ref:`integrating` and :ref:`api-reference`.


UART
----

As an alternative to CAN Bus, Tinymovr offers UART-based (serial) communication. The protocol is human-readable ASCII and exposes the same endpoints as CAN, so you can use any serial terminal without Tinymovr Studio.

.. warning::
   The UART port on Tinymovr is NOT 5V tolerant. Applying 5V voltage will immediately damage the onboard PAC5527 controller. Please use only 3.3V for UART communication.

.. warning::
   The UART port on Tinymovr offers a 3.3v output for driving very light loads (30mA absolute max). Tinymovr cannot be powered by this pin. In addition, most UART adapters offer 5V power, which is incompatible with Tinymovr. **In short: If in doubt, leave this pin disconnected**.

Protocol Description
####################

The UART port is TTL at 115200 baud. A regular FTDI-style USB to UART adapter should be sufficient.

UART uses the same Avlos endpoint set as CAN. Each command is one line: it starts with a dot (``.``), followed by the **endpoint ID** (0–99, decimal), then optionally one or more space-separated **values** for writes or calls. The line is terminated by a newline (``\n``). Tinymovr only responds to commands; it never sends on its own.

**Command format**

- **Read**: ``.<endpoint_id>`` → response is one line with the value (number, ``true``/``false``, or string).
- **Write** (single value): ``.<endpoint_id> <value>`` → response is ``ok``.
- **Call** (no args, e.g. save config): ``.<endpoint_id>`` → response is ``ok``.
- **Call** (with args, e.g. set position + velocity): ``.<endpoint_id> <arg1> <arg2> ...`` → response is ``ok`` or one value if the call returns data.

Values are human-readable: integers, decimals (e.g. ``1000.5``), and ``true``/``false`` or ``1``/``0`` for booleans. No scaling is required; the firmware parses and formats values according to the endpoint type.

**Response format**

- One line per command: the value (ASCII), or ``ok`` for writes and void calls, or ``error: invalid endpoint`` / ``error: bad value`` on failure.

**Endpoint IDs**

Endpoint IDs match the same API as CAN. For the full list and types, see :ref:`api-reference`. Endpoints are numbered in the order they appear in the spec (e.g. 0 = protocol hash, 4 = Vbus, 11 = save_config, 25 = controller position setpoint).

Examples
########

Read protocol hash:

.. code-block:: shell

    .0
    3999954334

Read bus voltage (float):

.. code-block:: shell

    .4
    24.500000

Read firmware version (string):

.. code-block:: shell

    .2
    2.3.4-17-g0768c21-dirty

Set position setpoint then read it back (endpoint 25, float):

.. code-block:: shell

    .25 1000.5
    ok

    .25
    1000.500000

Save configuration (endpoint 11, void call):

.. code-block:: shell

    .11
    ok

Call an endpoint that takes multiple arguments (e.g. two floats):

.. code-block:: shell

    .47 1000.0 50.0
    ok

Invalid endpoint:

.. code-block:: shell

    .200
    error: invalid endpoint
