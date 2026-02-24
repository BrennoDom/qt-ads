# LARGE_INTEGER

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# LARGE\_INTEGER

![42402339](/tcplclib_tc2_utilities/1033/Images/gif/36006283__en-US__Web.gif)

The function initializes a TwinCAT 2 signed 64-bit number (“legacy” type: [T\_LARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-3d0c-4b6a-95f9-eef4d2da39b1)).

## FUNCTION LARGE\_INTEGER: T\_LARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    dwHighPart : DWORD;  
    dwLowPart  : DWORD;  
END_VAR
```

**dwHighPart**: Upper 32 bits.

**dwLowPart**: Lower 32 bits.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
