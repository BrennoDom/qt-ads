# MC_ReadDriveAddress

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Special extensions](ms-xhelp:///?Id=beckhoff-8c7a-4985-bc2a-8740f4381d5f)
4. MC\_ReadDriveAddress

# MC\_ReadDriveAddress

![55848701](/tcplclib_tc2_mc2/1033/Images/png/9007199325019403__Web.png)

MC\_ReadDriveAddress reads the ADS access data for a drive device connected to the axis. This information is required for accessing the device, e.g. for special parameterization.

## Inputs

```
VAR_INPUT  
    Execute : BOOL; (* B *)  
END_VAR
```

**Execute:** The command is executed with a positive edge.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Outputs

```
VAR_OUTPUT  
    Done         : BOOL; (* B *)  
    Busy         : BOOL; (* E *)  
    Error        : BOOL; (* B *)  
    ErrorID      : DWORD; (* B *)  
    DriveAddress : ST_DriveAddress; (* B *)  
END_VAR
```

**Done:** TRUE if the command was executed without errors.

**Busy:** TRUE as soon as the command is started with Execute and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

**DriveAddress:** ADS access data of a drive device connected to the axis. (Type: [ST\_DriveAddress](ms-xhelp:///?Id=beckhoff-1eab-4c53-810c-307394ae0fc8))

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
