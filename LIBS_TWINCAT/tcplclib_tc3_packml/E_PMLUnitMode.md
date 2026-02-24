# E_PMLUnitMode

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-a3d4-4ab9-9d45-3f6129419cf0)
3. [DataTypes](ms-xhelp:///?Id=beckhoff-bea2-459d-9d22-156f058cbf6e)
4. E\_PMLUnitMode

# E\_PMLUnitMode

**E\_PMLUnitMode**

```
TYPE E_PMLUnitMode : (  
    ePMLUnitMode_UNDEFINED      := 0,  
    ePMLUnitMode_AUTOMATIC      := 1,  
    ePMLUnitMode_MAINTENANCE    := 2,  
    ePMLUnitMode_MANUAL         := 3,  
    ePMLUnitMode_SEMIAUTOMATIC  := 4,  
    ePMLUnitMode_DRYRUN         := 5,  
    ePMLUnitMode_USERMODE1      := 6,  
    ePMLUnitMode_USERMODE2      := 7,  
    ePMLUnitMode_IDLE           := 8,  
    ePMLUnitMode_ESTOP          := 9  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
