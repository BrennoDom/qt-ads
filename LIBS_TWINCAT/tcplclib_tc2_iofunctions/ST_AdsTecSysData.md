# ST_AdsTecSysData

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_AdsTecSysData

# ST\_AdsTecSysData

```
TYPE ST_AdsTecSysData  
STRUCT  
    bShiftKey    : BOOL;(* TRUE == Shift key pressed*)  
    bRMouseKey   : BOOL;(* TRUE == Right mouse key pressed *)  
    bHotKey      : BOOL;(* TRUE == Hotkey pressed *)  
    bTaskChaKey  : BOOL;(* TRUE == Task change key pressed *)  
    bABCKey      : BOOL;(* TRUE == ABC soft keyboard key pressed*)  
    bRsrv1       : BOOL;  
    bRsrv2       : BOOL;  
    bRsrv3       : BOOL;  
    bMainFanErr  : BOOL;(* TRUE == Main fan error*)  
    bCpuFanErr   : BOOL;(* TRUE == CPU fan error*)  
    bTempErr     : BOOL;(* TRUE == Internal temperature error ( temp > 50°C)*)  
    bBatteryErr  : BOOL;(* TRUE == Battery error *)  
    bRsrv4       : BOOL;  
    bRsrv5       : BOOL;  
    bRsrv6       : BOOL;  
    bRsrv7       : BOOL;  
    nMainNtcTemp : SINT;(* Main NTC temperature (-127°C .. + 127°C) *)  
    nExtNtcTemp  : SINT;(* External NTC temperature (-127°C .. + 127°C) *)  
    nRsrv8       : ARRAY[1..12] OF BYTE;  
END_STRUCT  
END_TYPE
```

**bShiftKey:** “Shift” key pressed (key on the far right in the front).

**bRMouseKey:** “Right mouse” button pressed.

**bHotKey:** “Hotkey” pressed.

**bTaskChaKey:** “Task change” key pressed.

**bABCKey:** “ABC soft keyboard” key pressed.

**bMainFanErr:** Main fan error.

**bCpuFanErr:** CPU fan error.

**bTempErr:** Temperature error (internal temperature > 50 °C).

**bBatteryErr:** Battery error (currently reserved).

**nMainNtcTemp:** Temperature value 1 (soldered NTC -127 °C to +127 °C).

**nExtNtcTemp:** Temperature level 2 (connectable NTC, does not exist in every device).

**bRsrv1 - bRsrv7:** Reserved.

**nRsrv8:** Reserved.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | None. This functionality is not supported by TwinCAT 3 at present! | ads-tec PC | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
