# FIX16Align

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FIX16Align

![64098000](/tcplclib_tc2_utilities/1033/Images/gif/36063883__en-US__Web.gif)

This function can be used to change the resolution (number of decimal places) of a signed 16-bit fixed-point number. The function supplies the new fixed-point number as return parameter.

## FUNCTION FIX16Align: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)

## VAR\_INPUT

```
VAR_INPUT  
    in : T_FIX16;  
    n  : BYTE(0..15);  
END_VAR
```

**in**: Fixed-point number whose resolution is to be modified (type: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)).

**n**: The new number of decimal places.

**Example:**

```
PROGRAM FIXALIGN  
VAR  
    q8, q4 : T_FIX16;  
    result : LREAL;  
END_VAR
```

```
q8 := LREAL_TO_FIX16( 0.6, 8 );  
result := FIX16_TO_LREAL( q8 );(* The result is: 0.6015625 *)  
  
q4 := FIX16Align( q8, 4 );  
result := FIX16_TO_LREAL( q4 );(* The result is: 0.5625 *)
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
