# Constants

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [GVLs](ms-xhelp:///?Id=beckhoff-1185-4c64-83e3-d3005d948f41)
4. Constants

# Constants

```
VAR_GLOBAL  
  eEventTraceLevel            : TcEventSeverity := TcEventSeverity.Critical;  
END_VAR  
VAR_GLOBAL_CONSTANT  
  cMemoryMode                 : DWORD := 16#0000_0001;  
  
  cCompleteNewInstallation    : DWORD := 16#0000_0001;  
  cDeleteAllGroupAssignments  : DWORD := 16#0000_0002;  
  cDeleteAllSceneAssignments  : DWORD := 16#0000_0004;  
  cOpticalFeedback            : DWORD := 16#0000_0008;  
  
  cOptionActualDimLevel       : DWORD := 16#0000_0001;  
  cOptionPowerOnLevel         : DWORD := 16#0000_0002;  
  cOptionSystemFailureLevel   : DWORD := 16#0000_0004;  
  cOptionMinLevel             : DWORD := 16#0000_0008;  
  cOptionMaxLevel             : DWORD := 16#0000_0010;  
  cOptionFadeRate             : DWORD := 16#0000_0020;  
  cOptionFadeTime             : DWORD := 16#0000_0040;  
  cOptionFadeRateFadeTime     : DWORD := 16#0000_0080;  
  cOptionExtendedFadeTime     : DWORD := 16#0000_0100;  
  cOptionRandomAddress        : DWORD := 16#0000_0200;  
  cOptionGroups               : DWORD := 16#0000_0400;  
  cOptionSceneLevels          : DWORD := 16#0000_0800;  
  cOptionStatusInformation    : DWORD := 16#0000_1000;  
  cOptionVersionNumber        : DWORD := 16#0000_2000;  
  cOptionDeviceType           : DWORD := 16#0000_4000;  
  cOptionPhysicalMinLevel     : DWORD := 16#0000_8000;  
  cOptionAll                  : DWORD := 16#00FF_FFFF;  
END_VAR
```

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
