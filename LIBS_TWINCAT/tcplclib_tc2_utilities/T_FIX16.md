# T_FIX16

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# T\_FIX16

Variables of this type represent a signed 16 bit fixed-point number. This data type is often used by systems that have no FPU unit (e.g.: micro controllers or devices from the area of telecontrol). If for example data in fixed point number format has to be transferred via serial interface, then these data have to be converted to a suitable format.

The number of decimal places is chosen as per the required numerical range and resolution. For 15 decimal places it is possible to display fixed-point numbers in the range: -1..1-2^15. This corresponds approximately to the floating-point number range: -1..0.999969482421875.

Unlike the floating-point numbers the resolution of the fixed-point numbers is constant over the complete numerical range. Unfortunately the fixed-point numbers have a smaller number range for display. Care is to be taken with mathematical operations that can generate a positive or negative overflow.

```
TYPE T_FIX16 :  
STRUCT  
    value  : INT := 0;  
    n      : WORD(0..15);  
    status : DWORD := 0;  
END_STRUCT  
END_TYPE
```

**value:** This member variable contains the actual value of the fixed-point number (16 bits before and after the decimal point).

**n**: Number of decimal places. Permitted range: 0..15. The highest value bit is reserved for the sign bit.

**status**: Status flags (reserved, not used at the moment).

**Example 1:**

An A/D-C supplies values as signed 16 bit fixed-point numbers with 15 decimal places. These measurement values are imported into the PLC and should be converted to LREAL data type.

```
PROGRAM FIX_TO_FLOAT  
VAR  
    adc_0        : WORD := 2#1010000000000000;(* = -0.75 (Q0.15) *)  
    adc_1        : WORD := 2#0111000000000000;(* = +0.875 (Q0.15) *)  
    fix_0, fix_1 : T_FIX16;  
    dbl_0, dbl_1 : LREAL;  
END_VAR
```

```
fix_0 := WORD_TO_FIX16( adc_0, 15 );  
fix_1 := WORD_TO_FIX16( adc_1, 15 );  
dbl_0 := FIX16_TO_LREAL( fix_0 );  
dbl_1 := FIX16_TO_LREAL( fix_1 );
```

**Example 2:**

The parameters of a micro controller are signed 16 bit fixed-point numbers with 8 decimal places. The LREAL parameters in the PLC should be converted to this format.

```
PROGRAM FLOAT_TO_FIX  
VAR  
    dbl_0          : LREAL := +3.5;  
    dbl_1          : LREAL := -3.5;  
    fix_0, fix_1   : T_FIX16;  
    ctrl_0, ctrl_1 : WORD;  
END_VAR
```

```
fix_0  := LREAL_TO_FIX16( dbl_0, 8 );  
fix_1  := LREAL_TO_FIX16( dbl_1, 8 );  
ctrl_0 := FIX16_TO_WORD( fix_0 );  
ctrl_1 := FIX16_TO_WORD( fix_1 );
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
