# BE64_TO_HOST

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# BE64\_TO\_HOST

![43680716](/tcplclib_tc2_utilities/1033/Images/gif/36236683__en-US__Web.gif)

The function performs a network-to-host conversion of a 64-bit number (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)). See also under: [Byte Order](ms-xhelp:///?Id=beckhoff-1928-452a-9ff0-7363825f50c0).

## FUNCTION BE64\_TO\_HOST: T\_ULARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    in : T_ULARGE_INTEGER;  
END_VAR
```

**in**: Number to be converted (Type:[T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
