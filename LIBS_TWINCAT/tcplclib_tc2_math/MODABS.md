# MODABS

## Library
tcplclib_tc2_math

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
2. [Functions](ms-xhelp:///?Id=beckhoff-77a6-412d-8e44-93bd1afec836)
3. MODABS

# MODABS

![25890496](/tcplclib_tc2_math/1033/Images/png/68480779__Web.png)

The MODABS function carries out a modulo division and determines the unsigned modulo value within the modulo range.

**Examples**

MODABS(400.56, 360) = 40.56

MODABS(-400.56, 360) = 319,44

**Similar functions**: MOD, [LMOD](ms-xhelp:///?Id=beckhoff-9b74-410d-b412-9059a6f98996)

|  |  |
| --- | --- |
| 31687876 | The MODABS function can be used to calculate the modulo set position of an NC axis from its absolute set position. |

ModuloSetPosition := MODABS( NcToPlc.fPosSoll, 360 );

## FUNCTION MODABS : LREAL

```
VAR_INPUT  
    lr_val : LREAL;  
    lr_mod : LREAL;  
END_VAR
```

**lr\_val** : Input value

**lr\_mod** : Modulo range

![16755431](/tcplclib_tc2_math/1033/Images/gif/68483979__en-US__Web.gif)

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Math |

[TwinCAT 3 | PLC Library:Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
