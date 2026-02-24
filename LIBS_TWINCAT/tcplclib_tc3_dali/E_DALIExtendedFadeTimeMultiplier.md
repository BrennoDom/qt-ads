# E_DALIExtendedFadeTimeMultiplier

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [DUTs](ms-xhelp:///?Id=beckhoff-e84a-422d-b94e-99adcaade658)
4. [Enumerations](ms-xhelp:///?Id=beckhoff-c968-4aa7-be35-e6241e64c6c6)
5. E\_DALIExtendedFadeTimeMultiplier

# E\_DALIExtendedFadeTimeMultiplier

```
TYPE E_DALIExtendeFadeTimeMultiplier :  
(  
  Disabled         := 0,  
  Multiplier100ms  := 1,  
  Multiplier1s     := 2,  
  Multiplier10s    := 3,  
  Multiplier1min   := 4,  
  Unknown          := 255  
) BYTE := Unknown;  
END_TYPE
```

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
