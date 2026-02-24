# FIX16Mul

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FIX16Mul

![24555510](/tcplclib_tc2_utilities/1033/Images/gif/36070283__en-US__Web.gif)

This function multiplies two signed 16-bit fixed-point numbers. The numbers do not have to have the same resolution (number of decimal places). The resolution of the number with the higher number of decimal places is reduced before the multiplication, i.e. the decimal places of the number with the higher resolution are truncated. The result of the multiplication is a signed 16-bit fixed-point number.

## FUNCTION FIX16Mul: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)

## VAR\_INPUT

```
VAR_INPUT  
    multiA : T_FIX16;  
    multiB : T_FIX16;  
END_VAR
```

**multiA**: The first multiplier (type: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)).

**multiB**: The second multiplier (type: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)).

**Example:**

```
PROGRAM FIXMUL  
VAR  
    a, b   : T_FIX16;  
    result : LREAL;  
END_VAR
```

```
a := LREAL_TO_FIX16( 0.25, 8 );  
b := LREAL_TO_FIX16( 10.0, 8 );  
  
result := FIX16_TO_LREAL( FIX16Mul( a, b ) );(* The result is: 2.5 *)
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
