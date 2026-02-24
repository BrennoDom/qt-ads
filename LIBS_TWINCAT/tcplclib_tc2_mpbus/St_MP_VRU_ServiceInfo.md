# St_MP_VRU_ServiceInfo

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Structures](ms-xhelp:///?Id=beckhoff-9706-4771-ad0e-639d770876a0)
5. St\_MP\_VRU\_ServiceInfo

# St\_MP\_VRU\_ServiceInfo

Fault and service information.

```
TYPE St_MP_VRU_ServiceInfo :  
STRUCT  
  bError_dP_Sensor                 : BOOL;  
  bReverseAirflowDetected          : BOOL;  
  bAirflowNotReached               : BOOL;  
  bFlowInClosedPosition            : BOOL;  
  bInternalActivity                : BOOL;  
  bGearDisengaged                  : BOOL;  
  bBusWatchdogTriggered            : BOOL;  
  bActuatorDoseNotFitToApplication : BOOL;  
  bPressSensorWrongConnected       : BOOL;  
  bPressureSensorNotReached        : BOOL;  
  bError_dP_SensorOutOfRange       : BOOL;  
END_STRUCT  
END_TYPE
```

**bError\_dP\_Sensor:** Error dp sensor.

**bReverseAirflowDetected:** Reverse airflow detected.

**bAirflowNotReached:** Airflow not reached.

**bFlowInClosedPosition:** Flow in closed position.

**bInternalActivity:** Internal activity.

**bGearDisengaged:** Gear unit disengaged.

**bBusWatchdogTriggered:** Bus watchdog triggered.

**bActuatorDoseNotFitToApplication:** Actuator does not fit the application.

**bPressSensorWrongConnected:** Pressure sensor connected incorrectly.

**bPressureSensorNotReached:** Pressure sensor not reached.

**bError\_dP\_SensorOutOfRange:** dP sensor out of range.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.22 | Tc2\_MPBus from 3.4.13.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
