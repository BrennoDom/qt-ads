# Overview

## Library
tcplclib_tc2_coupler

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
2. Overview

# Overview

|  |  |
| --- | --- |
| 20831783 | The Tc2\_Coupler library can be used for the following products: BKxxx couplers, KLxxx terminals, KSxxxx terminals and KMxxx modules. |

The Tc2\_Coupler library contains function blocks that provide convenient access to registers in the terminals via the terminal's control/status byte (register communication) and for communication with the Beckhoff couplers via the 2-byte PLC interface. The function blocks can, for instance, be used for parameterization of the terminals by way of the fieldbus.

Only the intelligent terminals have a register structure. The intelligent terminals include, for example, all the analog input and output terminals. The terminal's status/control byte is only visible in the process image if the terminal has been mapped as a complex terminal. Each terminal channel has its own register structure with a maximum of 64 registers. Under a compact mapping the control/status bytes are not visible in the process image.

For register access via the 2-byte PLC interface it is also necessary for the status and control word variables of the PLC interface to be mapped into the process image. In some fieldbusses (Lightbus, Profibus) this can be configured for the particular coupler in the TwinCAT System Manager, but in others (e.g. Interbus S) special configuration software is required for the job (e.g. KS2000). The status and control variables are linked to the function block's corresponding input and output variables.

If any changes made to the registers are to be stored permanently, the power supply to the coupler must be interrupted.

Note

No cyclic access!

When called, the function blocks of the library carry out write/read access to the registers in the terminals or in the couplers. If they are called cyclically, the EEPROM memory may be destroyed. The function blocks were basically developed to facilitate configuration of the terminals/couplers or fault diagnosis from within the PLC program.

## **Contents of the Library**

| Name | Description |
| --- | --- |
| [ReadWriteTerminalReg](ms-xhelp:///?Id=beckhoff-c902-4c36-81a7-9b9920b4776e) | Access registers in the terminal via the terminal's control/status byte (register communication) |
| [CouplerReset](ms-xhelp:///?Id=beckhoff-430d-4112-b358-775a9e45edc5) | Reset the coupler via the 2-byte PLC interface |
| [FB\_ReadCouplerDiag](ms-xhelp:///?Id=beckhoff-8b8b-4e50-a661-84594ff412cf) | Read coupler diagnosis (flash code) |
| [FB\_ReadCouplerRegs](ms-xhelp:///?Id=beckhoff-38a7-4945-b5d4-bf4551263403) | Read coupler registers |
| [FB\_WriteCouplerRegs](ms-xhelp:///?Id=beckhoff-c5ce-40fd-bad7-9cca2746e145) | Write coupler registers |
| [F\_GetVersionTcPlcCoupler](ms-xhelp:///?Id=beckhoff-7c0f-4c5b-affd-c8a6267e25d8) | Returns library version info |

[TwinCAT 3 | PLC Library: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
