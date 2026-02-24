# BE128_TO_HOST

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# BE128\_TO\_HOST

![48477080](/tcplclib_tc2_utilities/1033/Images/gif/36239883__en-US__Web.gif)

The function performs a network-to-host conversion of a 128-bit number (“legacy” type: [T\_UHUGE\_INTEGER](ms-xhelp:///?Id=beckhoff-c088-401b-a9fb-ff96c7c44c27)). See also under: [Byte Order](ms-xhelp:///?Id=beckhoff-1928-452a-9ff0-7363825f50c0).

## FUNCTION BE128\_TO\_HOST: T\_UHUGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    in : T_UHUGE_INTEGER;  
END_VAR
```

**in**: Number to be converted (Type [T\_UHUGE\_INTEGER](ms-xhelp:///?Id=beckhoff-c088-401b-a9fb-ff96c7c44c27)).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
