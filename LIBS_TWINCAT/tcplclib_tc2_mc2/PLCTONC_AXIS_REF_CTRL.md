# PLCTONC_AXIS_REF_CTRL

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Axis interface](ms-xhelp:///?Id=beckhoff-6c92-40ec-8c23-14d31eb6d79e)
4. PLCTONC\_AXIS\_REF\_CTRL

# PLCTONC\_AXIS\_REF\_CTRL

The structure PLCTONC\_AXIS\_REF\_CTRL is part of the structure [NCTOPLC\_AXIS\_REF](ms-xhelp:///?Id=beckhoff-da5b-4c7d-a89f-2ceb1b348721).

```
TYPE PLCTONC_AXIS_REF_CTRL :   
    DWORD;  
END_TYPE
```

| Bit | Variable name | Description |
| --- | --- | --- |
| 0 | Enable | Enable controller |
| 1 | FeedEnablePlus | Feed enable plus |
| 2 | FeedEnableMinus | Feed enable minus |
| 3-4 | - | RESERVE |
| 5 | HomingSensor | Referencing cam or referencing sensor |
| 6-7 | - | RESERVE |
| 8 | AcceptBlockedDrive | Accept blocking of the drive setpoint adoption (e.g. hardware end positions) from TwinCAT V2.10 Build 1311 |
| 9 | BlockedDriveDetected | User signal "Axis is blocked" (e.g. mechanical fixed stop). Not yet released! |
| 10-29 | - | RESERVE |
| 30 | PlcDebugFlag | PLC debug function. For internal use only! |

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
