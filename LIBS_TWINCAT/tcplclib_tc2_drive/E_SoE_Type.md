# E_SoE_Type

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [SERCOS](ms-xhelp:///?Id=beckhoff-4caa-4381-82bf-3f8474c57300)
4. E\_SoE\_Type

# E\_SoE\_Type

The enumeration E\_SoE\_Type describes the representation of the parameter value in the attribute of the parameter.

```
TYPE E_SoE_Type : (  
    eSoE_Type_BIN       := 0,  
    eSoE_Type_UNSIGNED  := 1,  
    eSoE_Type_SIGNED    := 2,  
    eSoE_Type_HEX       := 3,  
    eSoE_Type_TEXT      := 4,  
    eSoE_Type_IDN       := 5,  
    eSoE_Type_FLOAT     := 6  
    );  
END_TYPE
```

The enumeration E\_SoE\_Type is used to determine how the data can be interpreted:

| Name | Description |
| --- | --- |
| **eSoE\_Type\_BIN** | Binary |
| **eSoE\_Type\_UNSIGNED** | Integer without sign |
| **eSoE\_Type\_SIGNED** | Integer with sign |
| **eSoE\_Type\_HEX** | Hexadecimal number |
| **eSoE\_Type\_TEXT** | Text |
| **eSoE\_Type\_IDN** | Parameter number |
| **eSoE\_Type\_FLOAT** | Floating point number |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
