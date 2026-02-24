# F_LTrim

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_LTrim

![29553812](/tcplclib_tc2_utilities/1033/Images/gif/35839883__en-US__Web.gif)

Removes leading spaces from the character string and returns the reduced character string.

## FUNCTION F\_LTrim: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in  : T_MaxString;  
END_VAR
```

**in**: The string to be converted (Type:T\_MaxString).

**Example**:

```
PROGRAM MAIN  
VAR  
    sLTrim : STRING;  
END_VAR
```

```
sLTrim := F_LTrim(' <trim ');(* result: '<trim ' *)  
sLTrim := F_LTrim(' <trim');(* result: '<trim' *)  
sLTrim := F_LTrim('<trim');(* result: '<trim' *)  
sLTrim := F_LTrim('');(* result: '' *)
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
