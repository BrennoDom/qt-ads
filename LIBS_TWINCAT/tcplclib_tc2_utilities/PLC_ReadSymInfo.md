# PLC_ReadSymInfo

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# PLC\_ReadSymInfo

![20682694](/tcplclib_tc2_utilities/1033/Images/png/9007199290398475__Web.png)

The "PLC\_ReadSymInfo" function block permits information regarding the symbols (variables) of a PLC run-time system.

## VAR\_INPUT

```
VAR_INPUT  
    NETID  : T_AmsNetId;  
    PORT   : T_AmsPort;  
    START  : BOOL;  
    TMOUT  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: It is possible here to provide the AmsNetId of the TwinCAT computer whose symbol information is to be found (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**PORT**: The port number of a PLC run-time system (type: T\_AmsPort).

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY     : BOOL;  
    ERR      : BOOL;  
    ERRID    : UDINT;  
    SYMCOUNT : UDINT;  
    SYMSIZE  : UDINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

**SYMCOUNT**: The number of symbols in the PLC run-time system.

**SYMSIZE**: Length of the data, in bytes, in which the symbol information is stored.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
