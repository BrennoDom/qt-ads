# ReadWriteTerminalReg

## Library
tcplclib_tc2_coupler

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-5b9c-4736-89a9-f4c5c835d9e3)
3. ReadWriteTerminalReg

# ReadWriteTerminalReg

![53268321](/tcplclib_tc2_coupler/1033/Images/gif/9007199297360907__Web.gif)

The ReadWriteTerminalReg function block permits convenient access to the registers of the terminal via the terminal channel's status/control byte (register communication). In the standard operating mode, the data inputs and outputs of the intelligent terminal (e.g. an analog output terminal) are used to exchange the analog output data. A handshake via the status/control byte permits register access. The data input and output variables are used here to transfer the register values. A rising edge at the READ or WRITE input causes the register with number REGNO to be read or written to. Write protection of the register is disabled by the function block for a write access and enabled once more afterwards. When a register is written to, the new register value is first written to and then read, the read value is available at the CURRREGVALUE output. If changes made to the register values are to be stored permanently, the power supply to the coupler must be interrupted. The variables STATE, DATAIN, CTRL and DATAOUT must be linked in the TwinCAT System Manager to the corresponding I/O variables in the terminal channel.

## VAR\_INPUT

```
VAR_INPUT  
    STATE       : BYTE;  
    DATAIN      : WORD;  
    REGNO       : BYTE;  
    READ        : BOOL;  
    WRITE       : BOOL;  
    TMOUT       : TIME;  
    NEWREGVALUE : WORD;  
END_VAR
```

**STATE**: Terminal channel status byte.

**DATAIN**: Terminal channel data input word.

**REGNO**: Number of the register that is to be written to or read.

**READ**: A rising edge at this input activates the block, and the current register value is read. If successful, the register value is available in the output variable CURREGVALUE.

**WRITE**: A rising edge at this input activates the block, and the value in the input variable NEWREGVALUE is written into the register REGNO. After this, the current value of the register is read, and, if successful, is made available in the output variable CURREGVALUE.

**TMOUT**: States the length of the timeout that may not be exceeded during execution of the function.

**NEWREGVALUE**: Data word that is to be written into the register with number REGNO by a write access.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    CTRL        : BYTE;  
    DATAOUT     : WORD;  
    BUSY        : BOOL;  
    ERR         : BOOL;  
    ERRID       : UDINT;  
    CURREGVALUE : WORD;  
END_VAR
```

**CTRL**: Terminal channel control byte.

**DATAOUT**: Terminal channel data output word.

**BUSY**: This output is set when the block is activated, and remains set until execution of the function has been completed.

**ERR**: If an error should occur during the execution of the function, then this output is set, after the BUSY output has been reset.

**ERRID**: Supplies the error number when the ERR output is set.

| **Error number** | Error descriptions |
| --- | --- |
| 0 | No error |
| 0x100 | Timeout error. The time permitted for execution has been exceeded. |
| 0x200 | Parameter error (e.g. an invalid register number). |
| 0x300 | The read value differs from the written value (writing not allowed) |

**CURREGVALUE**: This variable provides the current register value after a successful read or write access.

**Examples of calls in FBD:**

**Example 1**

```
VAR  
    ReadWriteTerminalReg1      : ReadWriteTerminalReg;  
    State AT%I*                : BYTE;  
    Control AT%Q*              : BYTE;  
    DataIn AT%I*               : WORD;  
    DataOut AT%Q*              : WORD;  
    Start_ReadTerminalType     : BOOL;  
    Start_WriteFeatureRegister : BOOL;  
    RWTerminalReg_Busy         : BOOL;  
    RWTerminalReg_Err          : BOOL;  
    RWTerminalReg_ErrId        : UDINT;  
    TerminalType               : WORD;  
    FeatureRegValue            : WORD;  
END_VAR
```

![9652842](/tcplclib_tc2_coupler/1033/Images/gif/9007199297364107__Web.gif)

In Example 1 the terminal identifier is read from register 8 of an analog output terminal. The variables *State*, *Control*, *DataIn* and *DataOut* are linked to the terminal's corresponding I/O variables in the TwinCAT System Manager. The terminal identifier is KL**4022**..

**Example 2**

![19766715](/tcplclib_tc2_coupler/1033/Images/gif/9007199297367307__Web.gif)

In Example 2 the user-scaling is activated in the feature register (register 32) of a KL4022 analog output terminal. The new value in the feature register is then read by the function block, and can be checked through the output variable **CURREGVALUE**.

## Requirements

| Development environment | Target system type | PLC libraries to include (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Coupler (IO) |

[TwinCAT 3 | PLC Library: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
