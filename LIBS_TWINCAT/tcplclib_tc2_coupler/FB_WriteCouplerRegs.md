# FB_WriteCouplerRegs

## Library
tcplclib_tc2_coupler

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-5b9c-4736-89a9-f4c5c835d9e3)
3. FB\_WriteCouplerRegs

# FB\_WriteCouplerRegs

![47408069](/tcplclib_tc2_coupler/1033/Images/gif/9007199297383307__Web.gif)

This function block provides write access to the table register in the coupler and the registers of the intelligent terminals. The coupler itself is referred to as terminal 0 (null). All the other terminals in the terminal block, with the exception of passive terminals (such as power feed terminals), are counted in ascending sequence (beginning with 1) . It is possible either to write all registers, or only a partial region (between *nStartReg* and *nEndReg*). Several seconds are required in order to write all the registers (0.255) of a table of the coupler. The register values to be written are located in the structure *stCouplerTable.*The structure is an array of high and low bytes. Each array element corresponds to a register value (e.g.: *stCouplerTable*[ 5 ] == Register 5 ).

## VAR\_INPUT

```
VAR_INPUT  
    stState        : PLCINTFSTRUCT;  
    nTerminal      : BYTE := TERM_COUPLER;  
    nTable         : BYTE;  
    nStartReg      : BYTE;  
    nEndReg        : BYTE;  
    bExecute       : BOOL;  
    stCouplerTable : ST_CouplerTable;  
    tTimeout       : TIME;  
END_VAR
```

**stState** : Status word of the 2-byte PLC interface. ([PLCINTFSTRUCT](ms-xhelp:///?Id=beckhoff-1d50-460c-a4a8-dbe25d21d979))

**nTerminal** : Terminal number, to whose table register access is to be made. The coupler has terminal number null. Passive terminals are not to be counted.

**nTable** : Table number whose register values are to be written. Intelligent terminals only have one table for each terminal channel. A 4-channel terminal has the following table numbers: 0-3. An intelligent terminal, however, only possesses a maximum of 64 register values for each terminal channel!

**nStartReg** : The number of the first register that is to be written.

**nEndReg** : The number of the last register that is to be written.

**stCouplerTable** : Register value array to be written ([ST\_CouplerTable](ms-xhelp:///?Id=beckhoff-8d03-417a-b269-9e311197997e)).

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded during execution of the function.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    stCtrl   : PLCINTFSTRUCT;  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrId   : UDINT;  
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

## Requirements

| Development environment | Target system type | PLC libraries to include (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Coupler (IO) |

[TwinCAT 3 | PLC Library: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
