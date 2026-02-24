# HOST_TO_BE128

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# HOST\_TO\_BE128

![61185139](/tcplclib_tc2_utilities/1033/Images/gif/36227083__en-US__Web.gif)

The function performs a host-to-network conversion of a 128-bit number (“legacy” type: [T\_UHUGE\_INTEGER](ms-xhelp:///?Id=beckhoff-c088-401b-a9fb-ff96c7c44c27)). See also under: [Byte Order](ms-xhelp:///?Id=beckhoff-1928-452a-9ff0-7363825f50c0).

## FUNCTION HOST\_TO\_BE128: T\_UHUGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    in : T_UHUGE_INTEGER;  
END_VAR
```

**in**: Number to be converted (Type:[T\_UHUGE\_INTEGER](ms-xhelp:///?Id=beckhoff-c088-401b-a9fb-ff96c7c44c27)).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
