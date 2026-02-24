# FLOOR

## Library
tcplclib_tc2_math

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
2. [Functions](ms-xhelp:///?Id=beckhoff-77a6-412d-8e44-93bd1afec836)
3. FLOOR

# FLOOR

![31003317](/tcplclib_tc2_math/1033/Images/png/68461579__Web.png)

The FLOOR function determines a integral value from a floating point number that is a fraction smaller than or equal that number. The resulting number is of type LREAL and is therefore not limited to the value range of integer variables.

**Examples**

FLOOR(2.8) = 2

FLOOR(-2.8) = -3

**Similar functions**: TRUNC, [LTRUNC](ms-xhelp:///?Id=beckhoff-0c40-4823-b7f2-2c89a7014327)

|  |  |
| --- | --- |
| 10594405 | Unlike FLOOR, the [LTRUNC](ms-xhelp:///?Id=beckhoff-0c40-4823-b7f2-2c89a7014327) function always determines the integral part of a number. For positive values, this number is smaller than or equal the input parameter, for negative values it is greater than or equal the input parameter. |

## FUNCTION FLOOR : LREAL

```
VAR_INPUT  
    lr_in : LREAL;  
END_VAR
```

**lr\_in** : Function parameters of type LREAL

![28240785](/tcplclib_tc2_math/1033/Images/png/9007199323205771__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Math |

[TwinCAT 3 | PLC Library:Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
