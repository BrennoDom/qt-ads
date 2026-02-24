# Using the 1-second UPS with several PLC projects on a target system

## Library
tcplclib_tc2_sups

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
2. Using the 1-second UPS with several PLC projects on a target system

# Using the 1-second UPS with several PLC projects on a target system

To use the 1-second UPS with several PLC projects on a target system (PC/CX), please note the following process description.

The process is the same for all supported 1-second UPS devices. Only the SUPS function block for controlling the 1-second UPS is different, depending on the target platform. The PLC runtime systems communicate via process data.

Process description:

* Both PLC runtime systems use their own instance of the SUPS function block to check whether the voltage has failed and then write the persistent data without quick shutdown.
* When the first PLC runtime system has completed the process of writing the persistent data, it notifies the second PLC runtime system.
* The second PLC runtime system also writes the persistent data and at the same time waits for the notification from the first PLC runtime system.
* When both PLC runtime systems have completed the writing process, the second PLC runtime system directly initiates the quick shutdown.

Note

In configurations with two or more PLC projects, only one PLC runtime system may trigger the quick shutdown.

## Example for CX51x0 Embedded PCs

The example illustrates the application of the 1-second UPS with two PLC projects for 51x0 Embedded PCs.

**Download:**  [Sample\_SUPS\_TwoPlcsTC3.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_sups/Resources/zip/3714188299.zip)

[TwinCAT 3 | PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
