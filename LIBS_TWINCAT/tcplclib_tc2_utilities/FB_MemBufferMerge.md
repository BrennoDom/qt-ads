# FB_MemBufferMerge

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_MemBufferMerge

![39785801](/tcplclib_tc2_utilities/1033/Images/png/9007199290286475__Web.png)

This function block consolidates individual smaller data segments to form a larger data segment. The target buffer must be transferred as input parameter to the block. No further data bytes are added, if the segment to be added exceeds the remaining free buffer size.

## VAR\_INPUT

```
VAR_INPUT  
    eCmd      : E_EnumCmdType := eEnumCmd_First;  
    pBuffer   : POINTER TO BYTE;  
    cbBuffer  : UDINT;  
    pSegment  : POINTER TO BYTE := 0;  
    cbSegment : UDINT := 0;  
END_VAR
```

**eCmd**: Control parameter for the enumeration block (type: [E\_EnumCmdType](ms-xhelp:///?Id=beckhoff-cb91-427b-a901-37149aa7aa27)). eEnumCmd\_First adds the first segment, eEnumCmd\_Next adds the next segment. No other parameters are used.

**pBuffer**: Address (pointer) for the target buffer variable. The address can be determined with the ADR operator.

**cbBuffer**: Maximum available size (in bytes) of the target buffer variables. The size can be determined with the SIZEOF operator.

**pSegment**: Address (pointer) for the next data segment to be added (optional, may be zero). The address can also be determined with the ADR operator.

**cbSegment**: Size of the next data segment to be added (optional, may be zero). The size can also be determined with the SIZEOF operator.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bOk    : BOOL;  
    cbSize : UDINT;  
END_VAR
```

**bOk**: TRUE = success, FALSE = buffer overflow or faulty input parameters.

**cbSize**: Current buffer fill status (number of data bytes in the buffer).

**Example:**

In the following example, the large data segment is converted to a hexadecimal string after the smaller data segments have been consolidated (for test purposes).

```
PROGRAM MAIN  
VAR  
    bMerge    : BOOL := TRUE;  
    fbMerge   : FB_MemBufferMerge;  
    buffer    : ARRAY[0..25] OF BYTE;  
    seg1      : ARRAY[0..5] OF BYTE := [0,1,2,3,4,5];  
    seg2      : ARRAY[0..3] OF BYTE := [6,7,8,9];  
    seg3      : ARRAY[0..9] OF BYTE := [10,11,12,13,14,15,16,17,18,19];  
    sHex      : T_MaxString;  
END_VAR
```

```
IF bMerge THEN  
    bMerge := FALSE;  
  
    fbMerge( eCmd := eEnumCmd_First, pBuffer := ADR(buffer), cbBuffer := SIZEOF(buffer), pSegment := ADR(seg1), cbSegment:= SIZEOF(seg1) );  
    fbMerge( eCmd := eEnumCmd_Next, pBuffer := ADR(buffer), cbBuffer := SIZEOF(buffer), pSegment := ADR(seg2), cbSegment:= SIZEOF(seg2 ) );  
    fbMerge( pBuffer := ADR(buffer), cbBuffer := SIZEOF(buffer), pSegment := ADR(seg3), cbSegment:= SIZEOF(seg3) );  
    fbMerge( pBuffer := ADR(buffer), cbBuffer := SIZEOF(buffer), pSegment := 0, cbSegment:= 0 );(* merge zero length segment *)  
    fbMerge( pBuffer := ADR(buffer), cbBuffer := SIZEOF(buffer), pSegment := ADR(seg3), cbSegment:= SIZEOF(seg3) );  
    IF NOT fbMerge.bOk THEN  
        ;(* TODO: Error handler *)  
    END_IF  
  
    sHex := DATA_TO_HEXSTR( pData := ADR(buffer), cbData := fbMerge.cbSize, FALSE );  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
