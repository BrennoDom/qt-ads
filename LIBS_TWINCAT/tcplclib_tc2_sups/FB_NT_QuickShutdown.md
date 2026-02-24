# FB_NT_QuickShutdown

## Library
tcplclib_tc2_sups

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a6eb-4086-b3fb-cafd20716093)
3. FB\_NT\_QuickShutdown

# FB\_NT\_QuickShutdown

Note

Loss of data

The function block FB\_NT\_QuickShutdown is used internally by the various FB\_S\_UPS blocks. It must not be used independently, because this could result in data loss!

![2142393](/tcplclib_tc2_sups/1033/Images/gif/30513419__en-US__Web.gif)

The function block FB\_NT\_QuickShutdown can be used to trigger an immediate reboot, without stopping TwinCAT or the Windows operating system.

## VAR\_INPUT

```
VAR_INPUT  
    NETID : T_AmsNetId;  
    START : BOOL;  
    TMOUT : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: AmsNetID of the controller (type: T\_AmsNetID)

**START**: Rising edge leads to immediate reboot of the control system.

**TMOUT**: Timeout time

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY  : BOOL;  
    ERR   : BOOL;  
    ERRID : UDINT;  
END_VAR
```

**BUSY**: Quick shutdown is executed.

**ERR**: Becomes TRUE, as soon as an error occurs.

**ERRID**: Supplies the error number when the ERR output is set.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86),  1-Second UPS | Tc2\_SUPS (Version: 3.3.3.0) |

[TwinCAT 3 | PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
