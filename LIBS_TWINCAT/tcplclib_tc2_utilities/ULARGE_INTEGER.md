# ULARGE_INTEGER

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ULARGE\_INTEGER

![65488131](/tcplclib_tc2_utilities/1033/Images/gif/35919883__en-US__Web.gif)

The function initializes a TwinCAT 2 unsigned 64-bit number (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)).

## FUNCTION ULARGE\_INTEGER: T\_ULARGE\_INTEGER

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
