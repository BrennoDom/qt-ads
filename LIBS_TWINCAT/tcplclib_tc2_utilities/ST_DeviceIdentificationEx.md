# ST_DeviceIdentificationEx

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_DeviceIdentificationEx

```
TYPE ST_DeviceIdentificationEx :  
STRUCT  
    strTargetType       : STRING(30);  
    strHardwareModel    : STRING(16);  
    strHardwareSerialNo : STRING(16);  
    strHardwareVersion  : STRING(8);  
    strHardwareDate     : STRING(12);  
    strHardwareCPU      : STRING(20);  
    strImageDevice      : STRING(48);  
    strImageVersion     : STRING(32);  
    strImageLevel       : STRING(32);  
    strImageOsName      : STRING(48);  
    strImageOsVersion   : STRING(8);  
    strTwinCATVersion   : STRING(4);  
    strTwinCATRevision  : STRING(4);  
    strTwinCATBuild     : STRING(8);  
    strTwinCATLevel     : STRING(20);  
    strAmsNetId         : T_AmsNetId;  
END_STRUCT  
END_TYPE
```

**strTargetType**: Target system type, e.g. 'CX1000 CE', ....

**strHardwareModel**: Hardware model, e.g. '1001'.

**strHardwareSerialNo**: Hardware serial number, e.g. '123'.

**strHardwareVersion**: Hardware version, e.g. '1.7'.

**strHardwareDate**: Hardware production date, e.g. '18.8.06'.

**strHardwareCPU**: Hardware CPU architecture, e.g. 'INTELx86', 'ARM', 'UNKNOWN' or '' (empty string).

**strImageDevice**: Software platform, e.g. 'CX1000', ....

**strImageVersion**: Software platform version, e.g. '2.15'.

**strImageLevel**: Software platform level, e.g. 'HMI'.

**strImageOsName**: Name of operating system, e.g. 'Windows CE'.

**strImageOsVersion**: Operating system version, e.g. '5.0'.

**strTwinCATVersion**: TwinCAT version, e.g. for TwinCAT 2.10.1307: '2'.

**strTwinCATRevision**: TwinCAT revision, e.g. for TwinCAT 2.10.1307: '10'.

**strTwinCATBuild**: TwinCAT build, e.g. for TwinCAT 2.10.1307: '1307'.

**strTwinCATLevel**: Registered TwinCAT level, e.g. 'PLC', 'NC-PTP', 'NC-I', ....

**strAmsNetId**: TwinCAT AMS-NetID, e.g. '5.0.252.31.1.1'.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
