# F_CheckSum16

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_CheckSum16

![39790309](/tcplclib_tc2_utilities/1033/Images/gif/35804683__en-US__Web.gif)

The function "F\_CheckSum16" can be used to determine a 16-bit checksum for any data.

## FUNCTION F\_CheckSum16: WORD

## VAR\_INPUT

```
VAR_INPUT  
    dwSrcAddr  : POINTER TO BYTE;  
    cbLen      : UDINT;  
    wChkSum    : WORD;  
END_VAR
```

**dwSrcAddr**: Address of the data buffer.

**cbLen**: Length of the data buffer.

**wChkSum**: Initial value = 0 or last checksum.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
