# TRACK_REF

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# TRACK\_REF

The data type TRACK\_REF contains the parameters of a digital cam track for a digital cam controller [MC\_DigitalCamSwitch](ms-xhelp:///?Id=beckhoff-e466-4ae9-8b40-db813e9b946d).

```
TYPE TRACK_REF :  
STRUCT  
    ModuloPositions : BOOL := TRUE; (* all cam positions are interpreted as modulo positions when TRUE *)  
    ModuloFactor    : LREAL := 360; (* e. g. 360 degrees *)  
    OnCompensation  : LREAL;        (* compensation time [s] *)  
    OffCompensation : LREAL;        (* compensation time [s] *)  
    Hysteresis      : LREAL;        (* distance from last switch position (+ or -) *)  
    BreakRelease    : BOOL;         (* allow break to be released when TRUE, break cams will be activated when FALSE *)  
    Force           : BOOL;         (* override all digital cams and set track ON *)  
    Disable         : BOOL;         (* override all digital cams and set track OFF - overrides Force as well *)  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| ModuloPositions | BOOL | If Modulo TRUE, all positions are interpreted as modulo. The cam function is repeated cyclically. The parameter ModuloFactor is used for calculating the modulo cycle. |
| ModuloFactor | LREAL | ModuloFactor indicates the length of a modulo cycle in the positioning unit of the axis and is only used if Modulo TRUE. |
| OnCompensation | LREAL | Compensation time for the rising edge of the cam in [s]. For negative values of OnCompensation the switching time is brought forward, otherwise it is delayed. |
| OffCompensation | LREAL | Compensation time for the falling edge of the cam in [s]. For negative values of OffCompensation the switching time is brought forward, otherwise it is delayed. |
| Hysteresis | LREAL | not implemented. Hysteresis of the switching operations for reversing the rotation direction. The hysteresis is specified in the position unit of the axis. |
| BreakRelease | BOOL | Brake enable for brake cams on this cam track |
| Force | BOOL | The digital output is activated independent of the cams on this track. Disable has priority over Force. |
| Disable | BOOL | The digital output is deactivated independent of the cams on this track. Disable has priority over Force. |

## Method of function of the time compensation

![38193748](/tf5065_tc3_plc_motion_control_xfc_xfc_nci/1033/Images/gif/462185355__en-US__Web.gif)
