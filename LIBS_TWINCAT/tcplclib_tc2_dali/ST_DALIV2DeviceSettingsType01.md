# ST_DALIV2DeviceSettingsType01

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [DUTs](ms-xhelp:///?Id=beckhoff-0d46-4b85-ba71-1afd6231d322)
4. [Structures](ms-xhelp:///?Id=beckhoff-5d3e-4ef1-b36c-0c741eb45d90)
5. ST\_DALIV2DeviceSettingsType01

# ST\_DALIV2DeviceSettingsType01

```
TYPE ST_DALIV2DeviceSettingsType01 :  
STRUCT  
  nErrors                 : DWORD;  
  bPresent                : BOOL;  
  nBatteryCharge          : UINT; (*0..254, 255->Error*)  
  tDurationTestResult     : TIME; (*0..510 min*)  
  tLampEmergencyTime      : TIME; (*0..255 h*)  
  tLampTotalOperationTime : TIME; (*0..1024 h*)  
  nEmergencyLevel         : BYTE; (*0..254*)  
  nEmergencyMinLevel      : BYTE; (*0..254*)  
  nEmergencyMaxLevel      : BYTE; (*0..254*)  
  tRatedDuration          : TIME; (*0..510 min*)  
  nNextFunctionTest       : UINT; (*0..255*)  
  nNextDurationTest       : UINT; (*0..255*)  
  nFunctionTestInterval   : UINT; (*0..255*)  
  nDurationTestInterval   : UINT; (*0..255*)  
  nTestExecutionTimeout   : UINT; (*0..255*)  
  nProlongTime            : UINT; (*0..255*)  
  nEmergencyMode          : BYTE;  
  nFeatures               : BYTE;  
  nFailureStatus          : BYTE;  
  nEmergencyStatus        : BYTE;  
END_STRUCT  
END_TYPE
```

**Note:**

The following variables are adapted to their target display range when they are read out. They therefore differ from the read representation of the DALI device:

tDurationTestResult : TIME; (\*0..510 min\*)  
tLampEmergencyTime : TIME; (\*0..255 h\*)  
tLampTotalOperationTime : TIME; (\*0..1024 h\*)  
tRatedDuration : TIME; (\*0..510 min\*)

For the other variables the conversion either makes no sense (e.g. *nEmergencyLevel*), or a display is not possible (e.g. *nNextDurationTest*), since the range of the variable type TIME is insufficient.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
