# MODTURNS

## Library
tcplclib_tc2_math

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
2. [Functions](ms-xhelp:///?Id=beckhoff-77a6-412d-8e44-93bd1afec836)
3. MODTURNS

# MODTURNS

![16581154](/tcplclib_tc2_math/1033/Images/png/68487179__Web.png)

The MODTURNS function carries out a modulo division and determines the signed integral component (modulo periods, modulo rotations).

**Examples**

MODTURNS (800.56, 360) = 2

MODTURNS (-400.56, 360) = -2

|  |  |
| --- | --- |
| 15012662 | The MODTURNS function can be used to calculate the number of modulo rotations of an NC axis from its absolute set position. |

ModuloSetTurns := MODTURNS ( NcToPlc.fPosSoll, 360 );

## FUNCTION MODTURNS : LREAL

```
VAR_INPUT  
    lr_Value    : LREAL;  
    lr_Arg      : LREAL;  
END_VAR
```

**lr\_Value** : Input value

**lr\_Arg** : Modulo range

![896237](/tcplclib_tc2_math/1033/Images/gif/68483979__en-US__Web.gif)

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Math |

[TwinCAT 3 | PLC Library:Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
