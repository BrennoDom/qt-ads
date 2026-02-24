# LTRUNC

## Library
tcplclib_tc2_math

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
2. [Functions](ms-xhelp:///?Id=beckhoff-77a6-412d-8e44-93bd1afec836)
3. LTRUNC

# LTRUNC

![17618221](/tcplclib_tc2_math/1033/Images/png/68477579__Web.png)

The LTRUNC function determines the integral component of a floating point number.

**Examples**

LTRUNC(2.8) = 2

LTRUNC(-2.8) = -2

**Similar functions**: TRUNC, [FLOOR](ms-xhelp:///?Id=beckhoff-3c7e-41cf-8de8-55ed4c8e2d35)

|  |  |
| --- | --- |
| 24346266 | Unlike TRUNC, the result from LTRUNC is of type LREAL and is therefore not limited to the value range of integer variables. |

## FUNCTION LTRUNC : LREAL

```
VAR_INPUT  
    lr_in : LREAL;  
END_VAR
```

**lr\_in** : Function parameters of type LREAL

![17789802](/tcplclib_tc2_math/1033/Images/png/9007199323215371__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Math |

[TwinCAT 3 | PLC Library:Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
