# NT_StartProcess

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# NT\_StartProcess

![37538044](/tcplclib_tc2_utilities/1033/Images/png/9007199290382475__Web.png)

The "NT\_StartProcess" function block can be used to start a Windows application from the PLC. The function block can also be used to run applications on a remote PC.

## VAR\_INPUT

```
VAR_INPUT  
    NETID     : T_AmsNetId;  
    PATHSTR   : T_MaxString;  
    DIRNAME   : T_MaxString;  
    COMNDLINE : T_MaxString;  
    START     : BOOL;  
    TMOUT     : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: It is possible here to provide the AmsNetId of the TwinCAT computer on which the application is to be started (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**PATHSTR**: Whole path of the application to be executed as a string (type: T\_MaxString, e.g. "C:\WINNT\NOTEPAD.EXE" ).

**DIRNAME**: Working directory of the application to be executed as a string (type: T\_MaxString, e.g. "C:\WINNT" ).

**COMNDLINE**: Command line parameter (type: T\_MaxString, e.g.: "win.ini" ).

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY   : BOOL;  
    ERR    : BOOL;  
    ERRID  : UDINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) or the [Win32 error code](ms-xhelp:///?Id=beckhoff-7266-45c8-aaf2-26da98b316bf) when the ERR output is set (Platform SDK: Win32 API).

**Example:**

```
NT_StartProcess1      : NT_StartProcess;  
NT_StartProcess_Busy  : BOOL;  
NT_StartProcess_Err   : BOOL;  
NT_StartProcess_ErrId : UDINT;  
StartProcess          : BOOL;  
Tmout                 : TIME;
```

![2298077](/tcplclib_tc2_utilities/1033/Images/gif/35644683__en-US__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64) | Tc2\_Utilities (System) |
