# LREAL_TO_FIX16

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# LREAL\_TO\_FIX16

![42839264](/tcplclib_tc2_utilities/1033/Images/gif/36047883__en-US__Web.gif)

Converts a floating-point number of type: LREAL to a signed 16 bit fixed-point number with the required number of decimal places.

## FUNCTION LREAL\_TO\_FIX16: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)

## VAR\_INPUT

```
VAR_INPUT  
    in : LREAL;  
    n  : WORD(0..15) := 15;  
END_VAR
```

**in**: The LREAL number to be converted.

**n**: Number of required decimal places.

**Example:**

In the following example several constants are converted to fixed-point numbers. The number of decimal places can be specified for the conversion. Please note that (similar to the conversion of floating-point numbers) rounding errors may occur (q2 and q15 in our example).

```
PROGRAM TEST  
VAR  
    q2, q4, q8, q12, q15 : T_FIX16;  
    r2, r4, r8, r12, r15 : LREAL;  
END_VAR
```

```
q2  := LREAL_TO_FIX16( 0.6, 2 );  
q4  := LREAL_TO_FIX16( -0.25, 4 );  
q8  := LREAL_TO_FIX16( -0.75, 8 );  
q12 := LREAL_TO_FIX16( 2.30078125, 12 );  
q15 := LREAL_TO_FIX16( 0.6, 15 );  
  
r2  := FIX16_TO_LREAL( q2 );(* 0.5 *)  
r4  := FIX16_TO_LREAL( q4 );(* -0.25 *)  
r8  := FIX16_TO_LREAL( q8 );(* -0.75 *)  
r12 := FIX16_TO_LREAL( q12 );(* 2.30078125 *)  
r15 := FIX16_TO_LREAL( q15 );(* 0.600006103515625 *)
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
