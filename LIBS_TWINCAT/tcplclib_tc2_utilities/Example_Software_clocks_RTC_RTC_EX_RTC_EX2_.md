# Example: Software clocks (RTC, RTC_EX, RTC_EX2)

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Example: Software clocks (RTC, RTC\_EX, RTC\_EX2)

Here you can unpack the complete sources: [RTCSample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/9007200058349835.zip)

In the following example the three software clocks are synchronized with the local Windows system time every 5 seconds (the local Windows system time is shown in the taskbar).

```
PROGRAM MAIN  
VAR  
    fbGetLocalTime  : NT_GetTime;  
    bBusy           : BOOL;  
    bError          : BOOL;  
    nErrID          : UDINT;  
    presetTime      : TIMESTRUCT;  
  
    syncTimer       : TON;  
    syncTrigger     : F_TRIG;  
    bSynchronize    : BOOL;      
      
    fbRTC           : RTC;  
    bValid_RTC      : BOOL;  
    time_RTC        : DT;  
  
    fbRTC_EX        : RTC_EX;  
    bValid_RTCEX    : BOOL;  
    time_RTCEX      : DT;  
    nMilliseconds   : DWORD;  
  
    fbRTC_EX2       : RTC_EX2;  
    bValid_RTCEX2   : BOOL;  
    time_RTCEX2     : TIMESTRUCT;  
    nMicroseconds   : DWORD;  
END_VAR
```

![57664987](/tcplclib_tc2_utilities/1033/Images/gif/36255883__en-US__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
