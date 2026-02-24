# ST_UPSStatus

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_UPSStatus

# ST\_UPSStatus

```
TYPE ST_UPSStatus  
STRUCT  
    Vendor             : STRING; (* UPS vendor name  *)  
    Model              : STRING; (* UPS model name *)  
    FirmwareRev        : STRING; (* UPS firmware revision *)  
    SerialNumber       : STRING; (* UPS serial number *)  
    BatteryLifePercent : DWORD; (* The percent of battery capacity remaining in the UPS (0..100%) *)  
    BatteryLifeTime    : DWORD; (* Remaining UPS run time, in minutes *)  
    eBatteryStatus     : E_BatteryStatus; (* UPS battery state *)  
    eCommStatus        : E_UpsCommStatus; (* Status of the communication path to the UPS *)  
    ePowerStatus       : E_UpsPowerStatus; (* Status of utility-supplied power into the UPS *)  
    nPowerFailCnt      : DWORD; (* Power Fail counter. Increments every time the UPS service detects power fail *)  
    dwChargeFlags      : DWORD; (* Battery charge status flags. This member can be one or more of the following values.  
    Bits0..7 := General battery status flags (if all bits are set to 0 => unknown status)  
        Bit0 := High (bit set => high battery charge)  
        Bit1 := Low (bit set => low battery charge)  
        Bit2 := Critical (bit set  => battery is near empty)  
        Bit3 := Charging (bit set  => battery is charging)  
        Bits4..6 := reserved (all bits are 0)  
        Bit7 := No Battery (bit set => battery not found or not connected, bit not set => battery is existing or unknown state)   
   Bits8..15 := Special status information (if all bits are set to 0 => state ok or unknown state)  
        Bit8 := UPS Fan Error (bit set => fan hardware reports an error, bit not set => fan is ok)  
        Bit9 := Over Temperature (bit set => over temperature detected, bit not set => temperature is ok)  
        Bit10 := Service Interval Notify (bit set => service interval time expired, bit not set =>service interval time not expired )  
        Bit11 := Under Temperature (bit set => under temperature detected , bit not set => temperature is ok )  
        Bit12 := Fuse Not Ok (bit set => fuse broken or missed, bit not set => fuse ok)  
        Bit13 := Alarm1 (reserved for later use, bit is 0)  
        Bit14 := Alarm2 (reserved for later use, bit is 0)  
        Bit15 := Alarm3 (reserved for later use, bit is 0)  
    Bits16..31 := (reserved for later use, all bits are 0)  
 *)  
END_STRUCT  
END_TYPE
```

Not all UPS models can supply every item of status information.

**X**: The status information is available with this model.

\*) Available only if the model “Smart Signaling to any APC UPS & TwinCAT” has been configured.

| Status information | Beckhoff BAPI v1 | Beckhoff P24Vxxxx UPS | Beckhoff 24V UPS on the CP903x card | CX2100-09x4 | APC Back-UPS Pro 280 | APC Smart-UPS 420 | Description |
| --- | --- | --- | --- | --- | --- | --- | --- |
| **Vendor** | X | X | X | X | X | X | Vendor name. |
| **Model** | X | X | X | X | X | X | Model string. Empty string if no UPS has been configured. |
| **FirmwareRev** | X | X | X | X | X | X | UPS firmware version information. Empty string if the UPS does not support this parameter. |
| **SerialNumber** | X | X | None | X | X | X | Serial number of the UPS. Empty string if the UPS does not support this parameter. |
| **BatteryLifePercent** | X | X | None | X | X | X | Remaining battery life in percent. The value is always zero if the UPS cannot supply this parameter. |
| **BatteryLifeTime** | X | X | None | X | X | X | Remaining battery life in minutes. The value is always zero if the UPS cannot supply this parameter. |
| **eBatteryStatus** | **BatteryOk** | **BatteryUnknownStatus** if no battery exists; from UPS software version >= 2.0.0.6 and UPS firmware >= 25.1.I    **BatteryOk** | **BatteryUnknownStatus** if no battery exists.    **BatteryOk** | **BatteryUnknownStatus** when no battery is present (applicable only for the model with "Smart Battery" and not with capacitors)    **BatteryOk** | X | X | Battery status (type: E\_BatteryStatus). |
| **eCommStatus** | X | X | X | X | X | X | Status of the communication with the UPS (type: E\_UpsCommStatus). |
| **ePowerStatus** | X | X | X | X | X | X | Status of external power supply (type: E\_UpsPowerStatus). |
| **nPowerFailCnt** | X | X | X | X | \*X | \*X | Power-fail counter. The counter is incremented if a voltage failure is detected by the UPS service. |
| **dwChargeFlags** | **No Battery** (bit 7 set) from UPS firmware >=33.12-0 if no battery isconnected.  **Service Interval Notify** (bit 10 set). The configured battery change interval service has expired | **No Battery** (bit 7 set) from UPS software version >= 2.0.0.6 and firmware >= 25.1.I. The existence of the battery is checked every minute.    **UPS Fan Error** (bit 8 set) from UPS software version >= 2.0.0.7 and firmware >= 40.1.I. The UPS fan status is checked each minute.  **Requires a newer (second) hardware revision!**    **Service Interval Notify** (bit 10 set). The configured battery change interval service has expired. Implemented in the UPS software version >= 3.0.0.8; | **High** (bit 0 set) if battery is fully charged.    **Charging** (bit 3 set)    **No Battery** (bit 7 set) if no battery was found. | **No Battery** (bit 7 set). No communication to the battery (applicable only for the model with "Smart Battery" and not with capacitors).    **Over Temperature** (bit 9 set) was detected and the charging of the battery was interrupted.  **Requires a newer (second) hardware revision.** Implemented in the UPS software version >= 3.0.0.18.    **Service Interval Notify** (bit 10 set). The configured battery service interval has expired.    **Under Temperature** (bit 11 set) was detected and the charging of the battery was interrupted.  **Requires a newer (second) hardware revision.** Implemented in the UPS software version >= 3.0.0.18.    **Fuse Not Ok** (bit 12 set). The "Smart Battery" fuse is defective or not available. **Requires a newer (second) hardware revision.** Implemented in the UPS software version >= 3.0.0.18. | None | None | Battery charge status flags and special status information. |

## Requirements

| Development environment | Target platform | UPS hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | * Beckhoff BAPI v1; * Beckhoff P24Vxxxx; * Beckhoff CP903x card (PCI/ISA); * Beckhoff CX2100-09x4 models (e.g. CX2100-0904 or CX2100-0914 + "Smart Battery" CX2900-0192); * The APC devices that come supplied with Beckhoff Industrial PC support the Smart protocol and can be configured with the Windows UPS service. | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
