
.. _hardware-overview:

*****************
Hardware Overview
*****************

R5.x
****

Tinymovr R5.x is the high-current Tinymovr series. It features increased connectivity in a reduced footprint.

Board Dimensions (R5.0, R5.1)
#############################

.. image:: dimensions_r5.png
  :width: 800
  :alt: Tinymovr R5 dimensions

Connectivity (R5.0, R5.1)
#########################

.. image:: connectors_r5.png
  :width: 800
  :alt: Tinymovr R5 connectors and pinouts

.. warning::
   The UART pins in Tinymovr R5.1 have the silkscreen reversed. If you are planning to use UART with R5.1, consult :ref:`r51-erratum-1`. This only affects R5.1 boards.

Board Dimensions (R5.2)
#######################

.. image:: dimensions_r52.png
  :width: 800
  :alt: Tinymovr R5.2 dimensions

Connectivity (R5.2)
###################

.. image:: connectors_r52.png
  :width: 800
  :alt: Tinymovr R5.2 connectors and pinouts


M5.x
****

Tinymovr M5.x is is our specialized driver for gimbal motors and light robotic joints. It features a very compact footprint and 5A max drive.

M5.4 uses 20 mOhm current-sense shunts and requires the dedicated ``M54``
firmware target. M5.1/M5.2 use 50 mOhm shunts and the ``M51`` target.
The M54 target retains the M5 current limits, calibration defaults, and
bootloader pinout, with current-sense amplifier gain x2.

Do not interchange M51 and M54 firmware: their current measurement scales differ.

Board Dimensions (M5.1, M5.2)
#############################

.. image:: dimensions_m5.png
  :width: 800
  :alt: Tinymovr M5 dimensions

Connectivity (M5.1)
#########################

.. image:: connectors_m5.png
  :width: 800
  :alt: Tinymovr M5.1 connectors and pinouts

Connectivity (M5.2)
#########################

.. image:: connectors_m5_2.png
  :width: 800
  :alt: Tinymovr M5.2 connectors and pinouts


R3.x
****************

R3.x is the previous Tinymovr revision, with CAN and UART connectivity.

Board Dimensions (R3.x)
#######################

.. image:: dimensions.png
  :width: 800
  :alt: Tinymovr R3.x dimensions

Connectivity (R3.x)
###################

.. image:: connectors.png
  :width: 800
  :alt: Tinymovr R3.x connectors and pinouts


X5.1
****

X5.1 uses M5.1 electricals and includes a geared second encoder onboard,
connected through the interface identified as ``EXTERNAL_SPI`` in the API.
It defaults to :ref:`differential-positioning`. Other supported board revisions
default to ``STANDARD`` transform initialization.

Use the dedicated ``X51`` firmware files from the 3.2.1 release, even though
the board shares M5.1 electricals.
