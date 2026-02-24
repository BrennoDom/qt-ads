# FB_ASI_ReadParameter

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [ASI master terminal](ms-xhelp:///?Id=beckhoff-eee2-417f-9360-0c5cf67a2427)
4. FB\_ASI\_ReadParameter

# FB\_ASI\_ReadParameter

![36810105](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314162059__Web.png)

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stParameterBuffer : ST_ParameterBuffer;   
END_VAR
```

**stParameterBuffer**: Data buffer for the background communication (type: [ST\_ParameterBuffer](ms-xhelp:///?Id=beckhoff-24d8-4a67-bc8c-6e338fc526cd)).

## VAR\_INPUT

```
VAR_INPUT  
    iParameternumber : WORD;  
    bCycleMode       : BOOL;(*0: Acyclic , 1:Cyclic (permanent Read/Write) *)  
    bStart           : BOOL;  
END_VAR
```

**iParameterNumber**: parameter number.

**bCycleMode**: 0: Acyclic, 1:Cyclic (permanent Read/Write). If this bit is set, the bBusy output is only cancelled when the bStart input is pulled to FALSE. No current value is present at the output yet if the bStart input is pulled to FALSE too early.

**bStart**: The respective task is carried out via a rising edge at this boolean input.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy               : BOOL;  
    bErr                : BOOL;  
    iErrornumber        : DWORD;(* Error code of ASI-Master *)  
    iParameterReadvalue : BYTE;  
END_VAR
```

**bBusy**: This output remains TRUE until the block has executed a command. While Busy = TRUE, no new command will be accepted at the inputs. Please note that it is not the execution of the service but its acceptance whose time is monitored.

**bErr**: This output shows the error status.

**iErrornumber**: contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs.

| Command-specific error code (decimal) | Description |
| --- | --- |
| 1 | Communication timeout |
| 2 | ASI slave address does not exist |
| 3 - 10 | Reserved |
| 11 | ASI slave is not activated (slave is not in LAS) |
| 12 | An error occurred during communication. |
| 13 | Data exchange bit (CN.4) not set |

**iParameterReadvalue**: I/O ID or ID code of the addressed slave.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | ASI master terminal | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
