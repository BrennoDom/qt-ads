# XFC_TouchProbe

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_TouchProbe

XFC\_TouchProbe Execute  BOOLWindowOnly  BOOLFirstPosition  LREALLastPosition  LREALOptions  ST\_XfcTouchProbeOptions↔Axis  Reference To AXIS\_REF↔TriggerInput  Reference To XFC\_TRIGGER\_REFBOOL  DoneBOOL  BusyBOOL  ErrorUDINT  ErrorIDLREAL  RecordedPosition

The XFC\_TouchProbe function block records an axis position at the time of the edge of a digital input signal (measuring probe function).

The digital input signal is recorded with an XFC input terminal (e.g. EL1252) with time stamps for the falling and rising signal edge. The function block determines the axis position at which the edge change occurred and issues it as RecordedPosition.

In contrast to the conventional TouchProbe function [MC\_TouchProbe](ms-xhelp:///?Id=beckhoff-cdf3-4593-9d50-fd29cc644812) the digital input is not directly linked to the drive hardware. The position of each EtherCAT or Sercos axis in the system can be recorded via the time stamp of the input. This axis is exactly synchronized via [Dead time compensation](ms-xhelp:///?Id=beckhoff-b13e-4b6f-9b86-391a758e324f).

The function block can be used in free-running or single-shot mode. In free-running mode each edge of the input signal is recorded (maximum one edge per PLC cycle). In single-shot mode the next edge is only recorded once until the function block is triggered again.

The optional window function can be used to ignore signal edges outside the defined position filter.

## Signal curve

![8307988](/tf5065_tc3_plc_motion_control_xfc_xfc_nci/1033/Images/gif/462198155__en-US__Web.gif)

## 7663035 Inputs

```
VAR_INPUT  
    Execute       : BOOL;  
    WindowOnly    : BOOL;  
    FirstPosition : LREAL;  
    LastPosition  : LREAL;  
    Options       : ST_XfcTouchProbeOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | If Execute is active, the axis position is recorded at the defined signal edge of the input signal. A falling edge at Execute terminates the process immediately. Depending on the configuration in TriggerInput.FreeRun the next signal edge is recorded and evaluated once. If FreeRun is TRUE, a new position value is recorded continuously with each defined edge of the input signal, while Execute remains TRUE. |
| WindowOnly | BOOL | If this option is active, only one position inside the window between FirstPosition and LastPosition is recorded. Positions outside the window are discarded. Only if the recorded position lies inside the window does Done become TRUE. The recording window can be interpreted in terms of absolute or modulo values. In this connection the flag [ModuloPositions](ms-xhelp:///?Id=beckhoff-0bcc-41df-bc0d-c621c344bae4)in the structure [TriggerInput](ms-xhelp:///?Id=beckhoff-0bcc-41df-bc0d-c621c344bae4)is to be set accordingly. In the case of absolute value positions there is exactly one window. In the case of modulo value positions the window repeats itself within the modulo cycle defined in the axis parameters (e.g. 0 to 360 degrees). |
| FirstPosition | LREAL | Initial position of the recording window, if WindowOnly is TRUE. This position can be interpreted as an absolute or modulo value. In this connection the flag [ModuloPositions](ms-xhelp:///?Id=beckhoff-0bcc-41df-bc0d-c621c344bae4) is to be set appropriately in the structure TriggerInput (see below). |
| LastPosition | LREAL | Final position of the recording window, if WindowOnly is TRUE. This position can be interpreted as an absolute or modulo value. In this connection the flag [ModuloPositions](ms-xhelp:///?Id=beckhoff-0bcc-41df-bc0d-c621c344bae4) is to be set appropriately in the structure TriggerInput (see below). |
| Options | [ST\_XfcTouchProbeOptions](ms-xhelp:///?Id=beckhoff-23a0-404c-85c2-d916489705c1) | Optional parameters |

## 1858451 Outputs

```
VAR_OUTPUT  
    Done             : BOOL;  
    Busy             : BOOL;  
    Error            : BOOL;  
    ErrorID          : UDINT;  
    RecordedPosition : LREAL;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Done | BOOL | The value RecordedPosition is valid. If TriggerInput.FreeRun is TRUE, Done only remains TRUE only for one PLC cycle and is then reset automatically, since TouchProbe is automatically reactivated. |
| Busy | BOOL | Becomes TRUE as soon as the function block is active, and becomes FALSE when it has returned to its initial state. If TriggerInput.FreeRun is TRUE, Busy remains TRUE continuously, even if Done or Error become TRUE, since TouchProbe is automatically reactivated. |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number |
| RecordedPosition | LREAL | Axis position recorded at the point in time of the trigger signal. If TriggerInput.FreeRun is TRUE, the function block operates in free-running mode, so that each valid change in the input signal leads to a new RecordedPosition. The position can be analyzed, if Done becomes TRUE. |

## 16726062/16316838 Inputs/outputs

```
VAR_IN_OUT  
    Axis         : AXIS_REF;   
    TriggerInput : XFC_TRIGGER_REF;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Axis | [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) | The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other parameters it contains the current axis status, including position, velocity or error state. |
| TriggerInput | [XFC\_TRIGGER\_REF](ms-xhelp:///?Id=beckhoff-0bcc-41df-bc0d-c621c344bae4) | TriggerInput is a data structure for describing the trigger source and for feeding the state and time stamp of a digital input signal. This data structure is filled by the user. |
