# ST_MBus_F22

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
4. [Structures](ms-xhelp:///?Id=beckhoff-4dd1-4d9d-808a-6e4cba67de22)
5. [Metrima](ms-xhelp:///?Id=beckhoff-254a-4d84-87bf-974de3377c0a)
6. ST\_MBus\_F22

# ST\_MBus\_F22

Structure of the monthly values in the block [FB\_MBUS\_SVM\_F22\_Ext()](ms-xhelp:///?Id=beckhoff-a18a-43b3-9142-e75458d25943).

```
TYPE ST_MBus_F22 :  
STRUCT  
  stEnergy        : ST_MBus_Info;  
  stVolume        : ST_MBus_Info;  
  stVolume2       : ST_MBus_Info;  
  stPulsecounter1 : ST_MBus_Info;  
  stPulsecounter2 : ST_MBus_Info;  
  stDate          : ST_MBus_Info;  
END_STRUCT  
END_TYPE
```

**stEnergy:** Energy meter reading (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVolume:** Volume meter reading (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVolume2:** Volume meter reading (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPulsecounter1:** Meter reading pulse counter 1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPulsecounter2:** Meter reading pulse counter 2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stDate:** Date (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
