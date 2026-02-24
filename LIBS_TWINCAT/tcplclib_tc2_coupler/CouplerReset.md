# CouplerReset

## Library
tcplclib_tc2_coupler

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-5b9c-4736-89a9-f4c5c835d9e3)
3. CouplerReset

# CouplerReset

![43682709](/tcplclib_tc2_coupler/1033/Images/gif/9007199297370507__Web.gif)

The CouplerReset function block can be used to execute a reset of the coupler via the 2-byte PLC interface. In a coupler reset the current terminal configuration, for example, is read in again by the coupler via the K-bus (the terminal bus), and communication on the K-bus is reinitialized. Existing K-bus error messages for the coupler are reset. The **STATE** and **CONTROL** variables are used to perform a handshake with the coupler while the function block is being executed. These variables must therefore be linked with the status/control I/O variables of the 2-byte PLC interface in the TwinCAT System Manager.

## VAR\_INPUT

```
VAR_INPUT  
     STATE   : PLCINTFSTRUCT;  
     START   : BOOL;  
     TMOUT   : TIME;  
END_VAR
```

**STATE**: Status word of the 2-byte PLC interface. ([PLCINTFSTRUCT](ms-xhelp:///?Id=beckhoff-1d50-460c-a4a8-dbe25d21d979))

**START**: The function block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded during execution of the function.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    CONTROL  : PLCINTFSTRUCT;  
    BUSY     : BOOL;  
    ERR      : BOOL;  
    ERRID    : UDINT;  
END_VAR 
```

**CONTROL**: Control word of the 2-byte PLC interface ([PLCINTFSTRUCT](ms-xhelp:///?Id=beckhoff-1d50-460c-a4a8-dbe25d21d979)).

**BUSY**: This output is set when the block is activated, and remains set until execution of the function has been completed.

**ERR**: If an error should occur during the execution of the function, then this output is set, after the BUSY output has been reset.

**ERRID**: Supplies the error number when the ERR output is set.

| Error number | Error description |
| --- | --- |
| 0 | no error |
| 0x100 | Error at initialisation of the communication via the 2 byte PLC interface |
| 0x200 | error during communication |
| 0x300 | Timeout-Error. The permitted execution time was exceeded |
| 0x400 | Wrong parameter value at register number |
| 0x500 | Wrong parameter value at table number |

## Example of a call in FBD:

```
VAR   
    IntfState AT%I*      : PLCINTFSTRUCT;  
    IntfControl AT%Q*    : PLCINTFSTRUCT;  
    CouplerReset1        : CouplerReset;  
    Start_CouplerReset   : BOOL;  
    CouplerReset_Busy    : BOOL;  
    CouplerReset_Err     : BOOL;  
    CouplerReset_ErrId   : UDINT;  
END_VAR
```

![57600065](/tcplclib_tc2_coupler/1033/Images/gif/9007199297373707__Web.gif)

The variables *IntfState* and *IntfControl* are linked with corresponding I/O variables in the TwinCAT System Manager.

## Requirements

| Development environment | Target system type | PLC libraries to include (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Coupler (IO) |

[TwinCAT 3 | PLC Library: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
