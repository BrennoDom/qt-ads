# WORD_TO_FIX16

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# WORD\_TO\_FIX16

![50009058](/tcplclib_tc2_utilities/1033/Images/gif/36054283__en-US__Web.gif)

The function converts a WORD variable to a 16-bit fixed-point number (the WORD variable contains the coded digits and decimal places for the fixed-point number).

## FUNCTION WORD\_TO\_FIX16: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)

## VAR\_INPUT

```
VAR_INPUT  
    in : WORD;(* 16 bit fixed point number *)  
    n  : WORD(0..15);(* number of fractional bits *)  
END_VAR
```

**Example:**

```
PROGRAM WORD_TO_FIX  
VAR  
    double : LREAL;  
END_VAR
```

```
double := FIX16_TO_LREAL(WORD_TO_FIX16(2#0000110010000000, 8));
```

The value of the *double* variable is: 12.5

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
