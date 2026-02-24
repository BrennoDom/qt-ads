# LMOD

## Library
tcplclib_tc2_math

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
2. [Functions](ms-xhelp:///?Id=beckhoff-77a6-412d-8e44-93bd1afec836)
3. LMOD

# LMOD

![52219950](/tcplclib_tc2_math/1033/Images/png/68471179__Web.png)

The LMOD function carries out a modulo division and returns the signed residual.

**Examples**

LMOD(400.56, 360) = 40.56

LMOD(-400.56, 360) = -40.56

**Similar functions**: MOD, [MODABS](ms-xhelp:///?Id=beckhoff-6324-45a2-a5e8-176d42e0e19c)

|  |  |
| --- | --- |
| 217508 | Unlike MOD, the LMOD function operates with floating point variables and also determines non-integer residuals. |

In the context of NC axes, modulo values are usually used unsigned. These can be calculated with the [MODABS](ms-xhelp:///?Id=beckhoff-6324-45a2-a5e8-176d42e0e19c) function.

## FUNCTION LMOD : LREAL

```
VAR_INPUT  
    lr_Value    : LREAL;  
    lr_Arg      : LREAL;  
END_VAR
```

**lr\_Value** : Input value

**lr\_Arg** : Modulo range

![1957580](/tcplclib_tc2_math/1033/Images/png/9007199323215371__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Math |

[TwinCAT 3 | PLC Library:Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
