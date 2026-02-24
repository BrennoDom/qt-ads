# ST_DALIControlGearSettings

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [DUTs](ms-xhelp:///?Id=beckhoff-e84a-422d-b94e-99adcaade658)
4. [Structures](ms-xhelp:///?Id=beckhoff-889b-4c62-8488-daa2897ee3a6)
5. ST\_DALIControlGearSettings

# ST\_DALIControlGearSettings

```
TYPE ST_DALIVControlGearSettings :  
STRUCT  
  nErrors              : DWORD;  
  bPresent             : BOOL;  
  nActualLevel         : BYTE;  
  nPowerOnLevel        : BYTE;  
  nSystemFailureLevel  : BYTE;  
  nMinLevel            : BYTE;  
  nMaxLevel            : BYTE;  
  eFadeRate            : E_DALIFadeRate;  
  eFadeTime            : E_DALIFadeTime;  
  eFadeTimeBase        : E_DALIExtendedFadeTimeBase;  
  eFadeTimeMultiplier  : E_DALIExtendedFadeTimeMultiplier;  
  nRandomAddress       : DWORD;  
  nGroups              : WORD;  
  aSceneLevels         : ARRAY [0..15] OF BYTE;  
  nStatus              : BYTE;  
  nMajorVersion        : BYTE;  
  nMinorVersion        : BYTE;  
  aDeviceTypes         : ARRAY [1..20] OF E_DALIDeviceType;  
  nPhysicalMinLevel    : BYTE;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
