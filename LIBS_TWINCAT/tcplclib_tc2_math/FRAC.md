# FRAC

## Library
tcplclib_tc2_math

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
2. [Functions](ms-xhelp:///?Id=beckhoff-77a6-412d-8e44-93bd1afec836)
3. FRAC

# FRAC

![52840473](/tcplclib_tc2_math/1033/Images/png/68467979__Web.png)

The FRAC function determines the decimal component of a floating point number.

**Examples**

FRAC(2.8) = 0.8

FRAC(-2.8) = -0.8

## FUNCTION FRAC : LREAL

```
VAR_INPUT  
    lr_in : LREAL;  
END_VAR
```

**lr\_in** : Function parameters of type LREAL

![5802216](/tcplclib_tc2_math/1033/Images/png/9007199323205771__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Math |

[TwinCAT 3 | PLC Library:Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
