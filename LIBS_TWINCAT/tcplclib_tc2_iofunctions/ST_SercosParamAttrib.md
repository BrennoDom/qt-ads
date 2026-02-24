# ST_SercosParamAttrib

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_SercosParamAttrib

# ST\_SercosParamAttrib

ST\_SercosParamAttrib contains the nAttrib attribute of the Sercos parameter, broken down into individual variables.

```
TYPE ST_SercosParamAttrib :  
STRUCT  
    nFactor       : UINT;  
    eLength       : E_SercosAttribLen;  
    bCommand      : BOOL;  
    eType         : E_SercosAttribType;  
    bReserved1    : BOOL;  
    nComma        : USINT;  
    bWriteProtCP2 : BOOL;  
    bWriteProtCP3 : BOOL;  
    bWriteProtCP4 : BOOL;  
    bReserved2    : BOOL;  
END_STRUCT  
END_TYP
```

**nFactor**: bits 0..15.

**eLength**: bits 16..18. (Type: [E\_SercosAttribLen](ms-xhelp:///?Id=beckhoff-cb5d-4830-a6ed-1cbdf6e92551)).

**bCommand**: bit 19.

**eType**: bits 20..22. (Type: [E\_SercosAttribType](ms-xhelp:///?Id=beckhoff-a406-4abd-b33b-4d70ee8ff7e6)).

**bReserved1**: bit 23.

**nComma**: bits 24..27.

**bWriteProtCP2**: bit 28.

**bWriteProtCP3**: bit 29.

**bWriteProtCP4**: bit 30.

**bReserved2**: bit 31.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC (x86) | Sercans SCS-P ISA; Sercans SCS-P PCI; Beckhoff FC750x PCI | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
