# FB_MemBufferSplit

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_MemBufferSplit

![22527890](/tcplclib_tc2_utilities/1033/Images/png/9007199290289675__Web.png)

This function block splits a memory area (data buffer) into several smaller segments of certain maximum length as required. The function block returns a smaller partial segment, if the length of the last segment is smaller than required.

## VAR\_INPUT

```
VAR_INPUT  
    eCmd     : E_EnumCmdType := eEnumCmd_First;  
    pBuffer  : POINTER TO BYTE;  
    cbBuffer : UDINT;  
    cbSize   : UDINT;  
END_VAR
```

**eCmd**: Control parameter for the function block (type: [E\_EnumCmdType](ms-xhelp:///?Id=beckhoff-cb91-427b-a901-37149aa7aa27)). eEnumCmd\_First returns the first segment, eEnumCmd\_Next returns the next segment. No other parameters are used.

**pBuffer**: Address (pointer) of the data buffer to be divided. The address can be determined with the ADR operator.

**cbBuffer**: Length of the data buffer to be divided. The length can be determined with the SIZEOF operator.

**cbSize**: Maximum segment size into which the data buffer is to be divided.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bOk       : BOOL;  
    pSegment  : POINTER TO BYTE;  
    cbSegment : UDINT;  
    bEOS      : BOOL;  
END_VAR
```

**bOk**: TRUE = success, FALSE = error, invalid parameter value or no further segment available.

**pSegment**: Address (pointer) to the next data segment.

**cbSegment**: Length (bytes) of the next data segment.

**bEOS**: End of segment. TRUE = last segment. FALSE = further segments follow.

**Example:**

In the following example the *buffer* variable is divided into 5-byte segments. The returned segments are converted to a hexadecimal string for test purposes.

```
PROGRAM MAIN  
VAR  
    bSplit   : BOOL := TRUE;  
    buffer   : ARRAY[1..30] OF BYTE := [16#A,1,2,3,4,5,6,7,8,9,16#B,1,2,3,4,5,6,7,8,9,16#C,1,2,3,4,5,6,7,8,9];  
    fbSplit  : FB_MemBufferSplit;  
    sHex     : T_MaxString;  
END_VAR
```

```
IF bSplit THEN  
    bSplit := FALSE;  
    fbSplit.eCmd := eEnumCmd_First;  
  
    REPEAT  
        fbSplit( pBuffer := ADR(buffer), cbBuffer := SIZEOF(buffer), cbSize := 5 );  
        IF fbSplit.bOk THEN  
            sHex := DATA_TO_HEXSTR( pData := fbSplit.pSegment, cbData := fbSplit.cbSegment, FALSE );  
            fbSplit.eCmd := eEnumCmd_Next;  
        END_IF  
    UNTIL NOT fbSplit.bOk  
    END_REPEAT  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
