# MP_Serial_Number

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Structures](ms-xhelp:///?Id=beckhoff-9706-4771-ad0e-639d770876a0)
5. MP\_Serial\_Number

# MP\_Serial\_Number

Serial number of the device

```
TYPE MP_Serial_Number :  
STRUCT  
  YearAndWeek  : WORD;  
  DayAndNumber : WORD;  
  DeviceFamily : BYTE;  
  TestStation  : BYTE;  
  FamilySuffix : BYTE;  
END_STRUCT  
END_TYPE
```

**YearAndWeek:** Year and week

**DayAndNumber:** Day and number

**DeviceFamily:** Device family

**TestStation:** Test station

**FamilySuffix:** Device family suffix

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
