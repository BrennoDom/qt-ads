# FB_ReadCouplerDiag

## Library
tcplclib_tc2_coupler

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-5b9c-4736-89a9-f4c5c835d9e3)
3. FB\_ReadCouplerDiag

# FB\_ReadCouplerDiag

![48638545](/tcplclib_tc2_coupler/1033/Images/gif/9007199297376907__Web.gif)

The FB\_ReadCouplerDiag function block allows reading of the first and second flashing sequences of the error LED on the coupler when a terminal bus or coupler error occurs. The data is transferred to the PLC via the 2-byte PLC interface. This, however, only functions if communication over the fieldbus is maintained. It must be possible for the data to be transferred without error from the coupler to the PLC via the fieldbus. In order to detect that a coupler error has occurred, the status byte for the coupler in the PLC can be interrogated cyclically, and the function block activated when an error occurs.

## VAR\_INPUT

```
VAR_INPUT  
    stState    : PLCINTFSTRUCT;  
    bExecute   : BOOL;  
    tTimeout   : TIME;  
END_VAR
```

**stState** : Status word of the 2-byte PLC interface. ([PLCINTFSTRUCT](ms-xhelp:///?Id=beckhoff-1d50-460c-a4a8-dbe25d21d979))

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded during execution of the function.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    stCtrl   : PLCINTFSTRUCT;  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrId   : UDINT;  
    stDiag   : ST_CouplerDiag;  
END_VAR
```

**stCtrl** : Control word of the 2-byte PLC interface. ([PLCINTFSTRUCT](ms-xhelp:///?Id=beckhoff-1d50-460c-a4a8-dbe25d21d979))

**bBusy**: This output is set when the block is activated, and remains set until execution of the function has been completed.

**bError**: If an error should occur during the execution of the function, then this output is set, after the bBusy output has been reset.

**nErrId** : Supplies the error number when the bError output is set.

| Error number | Error description |
| --- | --- |
| 0 | No error |
| 0x100 | Error at initialisation of the communication via the 2 byte PLC interface |
| 0x200 | Error during communication |
| 0x300 | Timeout-Error. The permitted execution time was exceeded |
| 0x400 | Wrong parameter value at register number |
| 0x500 | Wrong parameter value at table number |

**stDiag** : Structure containing the coupler's diagnostic information (error type, and the first and second coupler flashing sequences). ([ST\_CouplerDiag](ms-xhelp:///?Id=beckhoff-89fe-443f-86d8-0df1c21b9bc5))

## Requirements

| Development environment | Target system type | PLC libraries to include (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Coupler (IO) |

[TwinCAT 3 | PLC Library: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
