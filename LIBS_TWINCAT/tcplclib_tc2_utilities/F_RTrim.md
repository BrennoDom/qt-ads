# F_RTrim

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_RTrim

![64657722](/tcplclib_tc2_utilities/1033/Images/gif/35843083__en-US__Web.gif)

Truncates all trailing spaces from the specified value and returns the result.

## FUNCTION F\_RTrim: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in : T_MaxString;  
END_VAR
```

**in**: The string to be converted (Type: T\_MaxString).

**Example**:

```
PROGRAM MAIN  
VAR  
    sRTrim  : STRING;  
    sLRTrim : STRING;  
END_VAR
```

```
sRTrim := F_RTrim(' trim> ');(* result: ' trim>' *)  
sRTrim := F_RTrim('trim> ');(* result: 'trim>' *)  
sRTrim := F_RTrim('trim>');(* result: 'trim>' *)  
sRTrim := F_RTrim('');(* result: '' *)  
  
sLRTrim := F_RTrim( F_LTrim( ' <trim> '));(* result: '<trim>' *)
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
