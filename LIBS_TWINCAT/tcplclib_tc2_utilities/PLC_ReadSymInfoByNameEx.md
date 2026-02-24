# PLC_ReadSymInfoByNameEx

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# PLC\_ReadSymInfoByNameEx

![5034184](/tcplclib_tc2_utilities/1033/Images/png/9007199290411275__Web.png)

The function block "PLC\_ReadSymInfoByNameEx" has similar functionality as the function block [PLC\_ReadSymInfoByName](ms-xhelp:///?Id=beckhoff-35a3-4a11-8af3-5a51574e7dd7). Both function blocks can read symbol information through the symbol name. The difference between the two blocks is that the block described here does not report an error if the available buffer size is exceeded and may output incomplete information. In this case the comment and/or the data type ID may have been truncated. Two additional output variables indicate this, i.e. *OVTYPE* and *OVCOMMENT*, so that the application can respond accordingly.

## VAR\_INPUT

```
VAR_INPUT  
    NETID   : T_AmsNetId;  
    PORT    : T_AmsPort;  
    SYMNAME : T_MaxString;  
    START   : BOOL;  
    TMOUT   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: The AmsNetId of the TwinCAT computer on which the function is to be executed can be entered here (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**PORT**: The port number of the PLC run-time system to which the symbolic variable belongs (type: T\_AmsPort).

**SYMNAME**: The symbol name of the PLC variable whose information is to be read (type: T\_MaxString, max. 255 characters, including the whole path, e.g. 'MAIN.INIT\_TASK.VARINT' ).

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY      : BOOL;  
    ERR       : BOOL;  
    ERRID     : UDINT;  
    SymInfo   : SYMINFOSTRUCT;  
    OVTYPE    : BOOL;  
    OVCOMMENT : BOOL;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

**SymInfo**: A structure with additional information on the symbolic variable (type: [SYMINFOSTRUCT](ms-xhelp:///?Id=beckhoff-9c32-4b07-a31f-b9540b936baf)).

**OVTYPE**: Indicates whether the string with the data type identification has caused an overflow (TRUE). The string with the data type identification may have been truncated.

**OVCOMMENT**: Indicates whether the string with the symbol comment has caused an overflow (TRUE). The string with the comment may have been truncated.

**Example:**

See function block documentation: [PLC\_ReadSymInfoByName](ms-xhelp:///?Id=beckhoff-35a3-4a11-8af3-5a51574e7dd7)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
