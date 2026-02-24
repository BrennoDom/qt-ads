# E_MPBus_Override_6wayMPIV

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. E\_MPBus\_Override\_6wayMPIV

# E\_MPBus\_Override\_6wayMPIV

Override control mode.

```
TYPE E_MPBus_Override_6wayMPIV :  
(  
  MPBus_6wayMPIV_None     := 0,  
  MPBus_6wayMPIV_Seq1Open := 1,  
  MPBus_6wayMPIV_Seq2Open := 2,  
  MPBus_6wayMPIV_Close    := 3,  
  MPBus_6wayMPIV_Seq1Vmax := 4,  
  MPBus_6wayMPIV_Seq2Vmax := 5  
);  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.14 | Tc2\_MPBus from 3.4.8.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
