# AXIS_REF

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Axis interface](ms-xhelp:///?Id=beckhoff-6c92-40ec-8c23-14d31eb6d79e)
4. AXIS\_REF

# AXIS\_REF

The AXIS\_REF data type contains axis information. AXIS\_REF is an interface between the PLC and the NC. It is added to MC function blocks as axis reference.

```
TYPE AXIS_REF :  
VAR_INPUT  
    PlcToNc AT %Q* : PLCTONC_AXIS_REF;  
END_VAR  
VAR_OUTPUT  
    NcToPlc AT %I* : NCTOPLC_AXIS_REF;  
    ADS            : ST_AdsAddress;  
    Status         : ST_AxisStatus;  
    DriveAddress   : ST_DriveAddress;  
END_VAR  
END_TYPE
```

## AXIS\_REF elements

**PlcToNc**: Data structure which is cyclically exchanged between PLC and NC. Via this data structure the MC function blocks communicate with the NC and send control information from the PLC to the NC. This data structure is automatically placed in the output process image of the PLC and must be linked in TwinCAT System Manager with the input process image of an NC axis. (Type: [PLCTONC\_AXIS\_REF](ms-xhelp:///?Id=beckhoff-da5b-4c7d-a89f-2ceb1b348721))

**NcToPlc**: Data structure which is cyclically exchanged between PLC and NC. Via this data structure the MC function blocks communicate with the NC and receive status information from the NC. This data structure is automatically placed in the input process image of the PLC and must be linked in TwinCAT System Manager with the output process image of an NC axis. The NCTOPLC structure contains all main state data for an axis such as position, velocity and instruction state. Since data exchange takes place cyclically, the PLC can access the current axis state at any time without additional communication effort. (Type: [NCTOPLC\_AXIS\_REF](ms-xhelp:///?Id=beckhoff-00d5-42b3-9ded-9a9f62e7df27))

**ADS**: The ADS data structure contains the ADS communication parameters for an axis that are required for direct ADS communication. Normally this structure does not have to be populated. The user can use it to stored information for controlling an axis on another target system or via a special port number.

**Status**: Data structure containing additional or processed status information for an axis (type: [ST\_AxisStatus](ms-xhelp:///?Id=beckhoff-1153-4ed0-8c31-5628d5b609a0)). This data structure is not refreshed cyclically, but has to be updated through the PLC program. For this purpose [MC\_ReadStatus](ms-xhelp:///?Id=beckhoff-49de-42bc-8e83-8798b6d84282) or alternatively the action "ReadStatus" of AXIS\_REF can be called:

**DriveAddress:** Data structure containing the ADS access data of a drive device. These data are not filled until the function block [MC\_ReadDriveAddress](ms-xhelp:///?Id=beckhoff-b4a9-4575-a32b-c3347b2f4e29) has been called implicitly or explicitly.

Sample:

```
VAR  
 Axis1 : AXIS_REF (* axis data structure for Axis-1 *)  
END_VAR  
  
(* program code at the beginning of each PLC cycle *)  
Axis1.ReadStatus();  
  
(* alternative program code at the beginning of each PLC cycle *)  
Axis1();
```

The call of "ReadStatus" or "Axis1" should be made once at the beginning of each PLC cycle. The current status information can then be accessed in AXIS\_REF from the whole PLC program. Within a cycle the status does not change.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
