# MP_BUS_MPX_ERROR

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Structures](ms-xhelp:///?Id=beckhoff-9706-4771-ad0e-639d770876a0)
5. MP\_BUS\_MPX\_ERROR

# MP\_BUS\_MPX\_ERROR

Error messages of the "MPX" sensors (function block [MP\_MPX](ms-xhelp:///?Id=beckhoff-f435-4d98-aec9-423f9031f00d)).

```
TYPE MP_BUS_MPX_ERROR :  
STRUCT  
  MP_BUS_MPX_TempSensorErr     : BOOL;  
  MP_BUS_MPX_HumiditySensorErr : BOOL;  
  MP_BUS_MPX_CO2SensorErr      : BOOL;  
  MP_BUS_MPX_VocSensorErr      : BOOL;  
END_STRUCT  
END_TYPE
```

**MP\_BUS\_MPX\_TempSensorErr:** The temperature sensor is faulty

**MP\_BUS\_MPX\_HumiditySensorErr:** The humidity sensor is faulty

**MP\_BUS\_MPX\_CO2SensorErr:** The CO2 sensor is faulty

**MP\_BUS\_MPX\_VocSensorErr:** The VOC sensor is faulty

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
