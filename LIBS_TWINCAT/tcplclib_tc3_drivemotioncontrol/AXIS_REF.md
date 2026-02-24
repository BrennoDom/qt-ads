# AXIS_REF

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Data types](ms-xhelp:///?Id=beckhoff-6026-4a24-928a-c60b12336bae)
3. [Axis interface](ms-xhelp:///?Id=beckhoff-0b38-4e86-b3db-2ec0a7740dd9)
4. AXIS\_REF

# AXIS\_REF

The AXIS\_REF data type contains axis information. AXIS\_REF is an interface between the PLC and the DRIVE. It is added to MC function blocks as axis reference.

```
TYPE AXIS_REF :  
VAR_INPUT  
    PlcToDrive AT %Q* : PLCTODRIVE_AXIS_REF;  
    Parameter         : ST_AxisParameter;  
END_VAR  
VAR_OUTPUT  
    DriveToPlc AT %I* : DRIVETOPLC_AXIS_REF;  
    WcState    AT %I* : DRIVETOPLC_WCSTATE;  
    InfoData   AT %I* : DRIVETOPLC_IFODATA;  
    Status            : ST_AxisStatus;  
END_VAR  
END_TYPE
```

## AXIS\_REF elements

**PlcToDrive**: Data structure that is cyclically exchanged between PLC and DRIVE. The MC function blocks communicate with the DRIVE via this data structure and send control information and commands from the PLC to the DRIVE. The data structure is automatically placed in the output process image of the PLC and must be connected to the input process image of a DRIVE in the TwinCAT System Manager.

**Parameter**: Data structure for parameterization of the axis (type: [ST\_AxisParameters](ms-xhelp:///?Id=beckhoff-b114-4bc6-9273-f2987e4615b9)).

**DriveToPlc**: Data structure that is cyclically exchanged between PLC and DRIVE. The MC function blocks communicate with the DRIVE via this data structure and receive status information from the DRIVE. The data structure is automatically placed in the input process image of the PLC and must be connected to the output process image of a DRIVE in the TwinCAT System Manager. The DRIVETOPLC structure contains all main state data for an axis such as position, velocity and instruction state. Since data exchange takes place cyclically, the PLC can access the current axis state at any time without additional communication effort.

**WcState**: Data structure that is cyclically exchanged between PLC and DRIVE and contains the WcState of the DRIVE. The data structure is automatically placed in the input process image of the PLC and must be connected to the output process image of a DRIVE in the TwinCAT System Manager (type: [DRIVETOPLC\_WCSTATE](ms-xhelp:///?Id=beckhoff-7d9c-4792-b96e-604074b2ed0c)).

**InfoData:** Data structure that is cyclically exchanged between PLC and DRIVE and contains ADS information for accessing DRIVE parameters. The data structure is automatically placed in the input process image of the PLC and must be connected to the output process image of a DRIVE in the TwinCAT System Manager (type: [DRIVETOPLC\_INFODATA](ms-xhelp:///?Id=beckhoff-203b-4c22-8446-edf2118242d6)).

**Status**: Data structure containing additional or processed status information for an axis (type: [ST\_AxisStatus](ms-xhelp:///?Id=beckhoff-e58a-447e-9467-3b1914ef9646)). This data structure is not refreshed cyclically, but has to be updated through the PLC program. For this purpose MC\_ReadStatus or alternatively the action "ReadStatus" of AXIS\_REF can be called:

Example:

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

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
