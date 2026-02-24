# FIX16Sub

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FIX16Sub

![19672999](/tcplclib_tc2_utilities/1033/Images/gif/36073483__en-US__Web.gif)

This function subtracts two signed 16-bit fixed-point numbers. The numbers do not have to have the same resolution (number of decimal places). The resolution of the number with the higher number of decimal places is reduced before the subtraction, i.e. the decimal places of the number with the higher resolution are truncated. The result of the subtraction is a signed 16-bit fixed-point number.

## FUNCTION FIX16Sub: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)

## VAR\_INPUT

```
VAR_INPUT  
    minuend    : T_FIX16;  
    subtrahend : T_FIX16;  
END_VAR
```

**minuend**: Number from which a value is subtracted (type: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)).

**subtrahend**: Number that is subtracted (type: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)).

**Example:**

```
PROGRAM FIXSUB  
VAR  
    a, b   : T_FIX16;  
    result : LREAL;  
END_VAR
```

```
a := LREAL_TO_FIX16( 0.5, 8 );  
b := LREAL_TO_FIX16( 0.75, 8 );  
  
result := FIX16_TO_LREAL( FIX16Sub( a, b ) ); (* The result is: -0.25 *)
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
