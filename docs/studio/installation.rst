.. _studio-installation:

*******************
Studio Installation
*******************

Tinymovr Studio is a cross-platform GUI application, CLI application, and Python library that offers easy access to all of Tinymovr's functionality. 

Studio requires Python 3.9 or newer.

The matching wheel is also available from the
`3.2.1 release <https://github.com/motionlayer/Tinymovr/releases/tag/3.2.1>`_.
For the CLI/library, download it and run::

    python -m pip install ./tinymovr-3.2.1-py3-none-any.whl

For the browser dashboard, see :doc:`web`.

Preparation
###########

If using Windows with a CANtact-compatible CAN Bus adapter, such as CANine, you will need to install an .inf file to enable proper device naming. You can `download the inf file here <https://canable.io/utilities/windows-driver.zip>`_. Extract the archive, right click and select Install.

Using pip
#########

This is the most straightforward method to install Tinymovr studio and have access to hardware. The following command will install Tinymovr with the dependencies required for the Qt-based Tinymovr Studio GUI:

.. code-block:: console

    pip3 install --upgrade 'tinymovr[GUI]==3.2.1'

If you don't plan to use the GUI, you can skip installing some dependencies using the following installation command instead:

.. code-block:: console

    pip3 install --upgrade tinymovr==3.2.1

.. code-block:: console

    tinymovr

You should now be looking at the Tinymovr GUI. Alternatively, to start the IPython-based Command Line Interface (CLI):

.. code-block:: console

    tinymovr_cli

Anaconda Installation
---------------------

Tinymovr can be installed inside a Virtualenv or Anaconda environment. 

With Anaconda, create a new environment:

.. code-block:: console

    conda create --name tinymovr python=3.10 -y
    conda activate tinymovr

Alternatively you can use any Python version >= 3.9.

Then simply install and run Tinymovr:

.. code-block:: console

    pip install --upgrade 'tinymovr[GUI]==3.2.1'
    tinymovr

Legacy source installation
##########################

The public repository contains frozen source from 3.0.0. Cloning it does not
install Studio 3.2.1. Use the matching release package above for current firmware.
The source-development instructions in :doc:`../develop/guide` apply to that
legacy public source.
