# ST_CX_DeviceIdentification

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Data Types](ms-xhelp:///?Id=beckhoff-4a07-48a9-b44d-b1ed4891f6d2)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f0c1-4d10-bc64-b4db97924456)
4. ST\_CX\_DeviceIdentification

# ST\_CX\_DeviceIdentification

```
    TYPE ST_CxDeviceIdentification :  
STRUCT  
 strTargetType       : STRING(20);  
 strHardwareModel    : STRING(10);  
 strHardwareSerialNo : STRING(12);  
 strHardwareVersion  : STRING(4);  
 strHardwareDate     : STRING(10);  
 strHardwareCPU      : STRING(10);  
 strImageDevice      : STRING(20);  
 strImageVersion     : STRING(10);  
 strImageLevel       : STRING(10);  
 strImageOsName      : STRING(20);  
 strImageOsVersion   : STRING(8);  
 strTwinCATVersion   : STRING(4);  
 strTwinCATRevision  : STRING(4);  
 strTwinCATBuild     : STRING(8);  
 strTwinCATLevel     : STRING(20);  
 strAmsNetId         : STRING(23);  
END_STRUCT  
END_TYPE
```

**strTargetType**: Type of the target system, e.g. 'CX1000-CE', ...

**strHardwareModel**: Hardware model, e.g. '1001'

**strHardwareSerialNo**: Hardware serial number, e.g. '123'

**strHardwareVersion**: Hardware version, e.g. '1.7'

**strHardwareDate**: Hardware production date, e.g. '18.8.06'

**strHardwareCPU**: Hardware CPU architecture, e.g. 'INTELx86', 'ARM', 'UNKNOWN' or '' (empty string)

**strImageDevice**: Software platform, e.g. 'CX1000', ...

**strImageVersion**: Version of the software platform, e.g. '2.15'

**strImageVersion**: Version of the software platform, e.g. 'HMI'

**strImageOsVersion**: Name of the operating system, e.g. 'Windows CE'

**strImageOsVersion**: Version of the operating system, e.g. '5.0'

**strTwinCATVersion**: TwinCAT version, e.g. for TwinCAT 2.10.1307: '2'

**strTwinCATRevision**: TwinCAT Reversion, e.g. for TwinCAT 2.10.1307: '10'

**strTwinCATBuild**: TwinCAT Build, e.g. for TwinCAT 2.10.1307: '1307'

**strTwinCATLevel**: Registered TwinCAT level, e.g. 'PLC', 'NC-PTP', 'NC-I', ....

**strAmsNetId**: TwinCAT AMS-NetID, e.g. '5.0.252.31.1.1'

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | CX (x86) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
