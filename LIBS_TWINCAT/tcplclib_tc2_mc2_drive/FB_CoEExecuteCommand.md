# FB_CoEExecuteCommand

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_CoEExecuteCommand

FB\_CoEExecuteCommand NetId  T\_AmsNetIDIndex  WORDpSrcBuf  PVOIDSrcBufLen  UDINTpDstBuf  PVOIDDstBufLen  UDINTExecute  BOOLTimeout  TIME↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUDINT  ErrorId\_E\_CoeCommandStatus  Status

With the function block FB\_CoEExecuteCommand a command can be executed.

## VAR\_INPUT

```
VAR_INPUT  
    NetId       : T_AmsNetId := '';  
    Index       : WORD;  
    pSrcBuf     : PVOID;  
    SrcBufLen   : UDINT;  
    pDstBuf     : PVOID;  
    DstBufLen   : UDINT;  
    Execute     : BOOL;  
    Timeout     : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NetId**: String, which contains the AMS-Network ID of the PC (Type: T\_AmsNetId).

**Index**: CoE object index to which FB\_CoEExecuteCommand refers.

**pSrcBuf**: Address of the structure of the data to be sent

**SrcBufLen**: Size in bytes of the structure of the data to be sent

**pDstBuf**: Address of the structure of the data to be received

**DstBufLen**: Size in bytes of the structure of the data to be received

**Execute**: The function block is enabled via a positive edge at this input.

**Timeout**: Maximum time allowed for the execution of the function block.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   Axis : AXIS_REF;  
END_VAR
```

**Axis**: The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other things it contains the current status of the axis such as the position, the velocity and the error state.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Busy        : BOOL;  
    Error       : BOOL;  
    ErrorId     : UDINT;  
    Status      : _E_CoECommandStatus;  
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until a feedback is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**ErrorID**: In the event of a set error output returns the ADS error code.

**Status**: Status of the command execution
