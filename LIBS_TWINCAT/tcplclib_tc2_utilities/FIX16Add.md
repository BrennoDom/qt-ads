# FIX16Add

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FIX16Add

![36948161](/tcplclib_tc2_utilities/1033/Images/gif/36060683__en-US__Web.gif)

This function adds two signed 16-bit fixed-point numbers. The numbers do not have to have the same resolution (number of decimal places). The resolution of the number with the higher number of decimal places is reduced before the addition, i.e. the decimal places of the number with the higher resolution are truncated. The result of the addition is a signed 16-bit fixed-point number.

## FUNCTION FIX16Add: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)

## VAR\_INPUT

```
VAR_INPUT  
    augend : T_FIX16;  
    addend : T_FIX16;  
END_VAR
```

**augend**: The first summand (type: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)).

**addend**: The second summand (type: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)).

**Example:**

```
PROGRAM FIXADD  
VAR  
    a, b   : T_FIX16;  
    result : LREAL;  
END_VAR
```

```
a := LREAL_TO_FIX16( 0.5, 8 );  
b := LREAL_TO_FIX16( -0.25, 8 );  
  
result := FIX16_TO_LREAL( FIX16Add( a, b ) );(* The result is: 0.25 *)
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
