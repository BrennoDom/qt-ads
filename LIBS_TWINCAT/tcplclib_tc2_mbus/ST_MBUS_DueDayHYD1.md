# ST_MBUS_DueDayHYD1

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
4. [Structures](ms-xhelp:///?Id=beckhoff-4dd1-4d9d-808a-6e4cba67de22)
5. [Hydrometer](ms-xhelp:///?Id=beckhoff-d6be-42ee-99b8-f3c8ab6938ed)
6. ST\_MBUS\_DueDayHYD1

# ST\_MBUS\_DueDayHYD1

Structure of the cutoff date values in the block [FB\_MBUS\_HYD\_Sharky\_00()](ms-xhelp:///?Id=beckhoff-6f7c-4075-9022-42419a9f8748).

```
TYPE ST_MBUS_DueDayHYD1 :  
STRUCT  
  stEnergy           : ST_MBus_Info;  
  stVolume           : ST_MBus_Info;  
  stTariff1          : ST_MBus_Info;  
  stTariff2          : ST_MBus_Info;  
  stDate             : ST_MBus_Info;  
  stDateFutureDueDay : ST_MBus_Info;  
END_STRUCT  
END_TYPE
```

**stEnergy:** Energy meter reading (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVolume:** Volume meter reading (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stTariff1:** Meter reading tariff 1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stTariff2:** Meter reading tariff 2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stDate:** Cutoff date (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stDateFutureDueDay:** Future cutoff date (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
