# LrealIsNaN

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# LrealIsNaN

This function tests whether a value is NaN (Not a Number). If the return value is TRUE, the value is NaN.

```
FUNCTION LrealIsNaN : BOOL  
VAR_INPUT  
    x        : REFERENCE TO LREAL;  
END_VAR
```

The following points rank among the main features of NaN values:

* All arithmetic operations that use NaN as input data return NaN as the result.
* All relational operators =, !=, > < >= <= always return the value False if at least one of the operands is NaN.
* The standard C function `isnan()` or `_isnan()` or the PLC function [LrealIsNaN()](ms-xhelp:///?Id=beckhoff-f50b-45e9-8004-cf5c9aa021c3) (Tc2\_Utilities library) returns the value True if the argument has the value NaN.
* The expression `isnan(a)` is equivalent to the expression `!(a == a)` or `NOT(a = a)`.

The fact that NaN values reproduce themselves when used in further calculations is advantageous in that invalid values cannot be overlooked.

|  |  |
| --- | --- |
| 33640543CAUTION | |
| Software malfunctions  NaN values may only be used in PLC libraries, in particular as control values in functions for Motion Control and for drive control, if they are expressly approved! Otherwise NaN values can lead to potentially dangerous malfunctions of the software concerned! | |

|  |  |
| --- | --- |
| 34329433CAUTION | |
| Floating point exceptions  If NaNs are to be used and processed in the application, the FP exceptions must be switched off. Otherwise, comparisons with NaN can lead to an exception, which will cause a stop of the runtime and possible machine damage. | |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4020 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >=3.3.16.0 |
