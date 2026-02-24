# E_MPBus_Override

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. E\_MPBus\_Override

# E\_MPBus\_Override

Override mode.

```
TYPE E_MPBus_Override :  
(  
  MPBus_Override_None  := 0,  
  MPBus_Override_Auto  := 1,  
  MPBus_Override_Close := 2,  
  MPBus_Override_Open  := 3,  
  MPBus_Override_Vnom  := 4,  
  MPBus_Override_Vmax  := 5,  
  MPBus_Override_Stop  := 6,  
  MPBus_Override_Pnom  := 7,  
  MPBus_Override_Pmax  := 8  
);  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
