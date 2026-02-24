# XFC_EL1258_TouchProbe

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_EL1258\_TouchProbe

XFC\_EL1258\_TouchProbe Execute  BOOLWindowOnly  BOOLFirstPosition  LREALLastPosition  LREALOptions  ST\_XfcTouchProbeOptions↔Axis  Reference To AXIS\_REF↔TriggerInput  Reference To XFC\_MT\_TRIGGER\_REF↔EL1258  Reference To EL1258\_MT\_IoInterfaceBOOL  DoneBOOL  BusyBOOL  ErrorUDINT  ErrorIDST\_RecordedPosition  RecordedPositionsUDINT  NoOfRecordedPositionsST\_EL1258\_Diagnostics  Diagnostic

The function block XFC\_EL1258\_TouchProbe records the axis positions at the time of the edges of a digital input signal (touch probe function).

The digital input signal is recorded with an EL1258 XFC input terminal with timestamps for falling and rising signal edges. The function block determines the axis positions at which an edge change occurred and issues it as RecordedPosition.

In contrast to the conventional TouchProbe function MC\_TouchProbe the digital input is not directly linked to the drive hardware. The position of each EtherCAT or Sercos axis in the system can be recorded via the timestamps of the input. This axis is exactly synchronized via dead time compensation.

The function block can be used in free-running or single-shot mode. In free-running mode, each edge of the input signal is recorded (including several edges per PLC cycle). In single-shot mode the next edges are only recorded once until the function block is triggered again.

The optional window function can be used to ignore signal edges outside the defined position filter.

## 12633819 Inputs

```
VAR_INPUT  
    Execute       : BOOL;  
    WindowOnly    : BOOL;  
    FirstPosition : LREAL;  
    LastPosition  : LREAL;  
    Options       : ST_XfcTouchProbeOptions;  
    EL1258        : EL1258_MT_IoInterface;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | If Execute is active, the axis position is recorded at the defined signal edge of the input signal. A falling edge at Execute terminates the process immediately. Depending on the configuration in TriggerInput.FreeRun the next signal edge is recorded and evaluated once. If FreeRun is TRUE, a new position value is recorded continuously with each defined edge of the input signal, while Execute remains TRUE. |
| WindowOnly | BOOL | If this option is active, only one position inside the window between FirstPosition and LastPosition is recorded. Positions outside the window are discarded. Only if the recorded position lies inside the window does Done become TRUE. The recording window can be interpreted in terms of absolute or modulo values. In this connection the flag [XFC\_TRIGGER\_REF](ms-xhelp:///?Id=beckhoff-0bcc-41df-bc0d-c621c344bae4) in the structure [XFC\_TRIGGER\_REF](ms-xhelp:///?Id=beckhoff-0bcc-41df-bc0d-c621c344bae4) is to be set accordingly. In the case of absolute value positions there is exactly one window. In the case of modulo value positions the window repeats itself within the modulo cycle defined in the axis parameters (e.g. 0 to 360 degrees). |
| FirstPosition | LREAL | Initial position of the recording window, if WindowOnly is TRUE. This position can be interpreted as an absolute or modulo value. In this connection the flag [XFC\_TRIGGER\_REF](ms-xhelp:///?Id=beckhoff-0bcc-41df-bc0d-c621c344bae4) is to be set appropriately in the structure TriggerInput (see below). |
| LastPosition | LREAL | Final position of the recording window, if WindowOnly is TRUE. This position can be interpreted as an absolute or modulo value. In this connection the flag [XFC\_TRIGGER\_REF](ms-xhelp:///?Id=beckhoff-0bcc-41df-bc0d-c621c344bae4) is to be set appropriately in the structure TriggerInput (see below). |
| Options | [ST\_XFCTouchProbeOptions](ms-xhelp:///?Id=beckhoff-23a0-404c-85c2-d916489705c1) | Optional parameters |
| EL1258 | [EL1258\_MT\_IoInterface](ms-xhelp:///?Id=beckhoff-8369-471d-8ab6-4d7a66aa0918) | Process image of the terminal |

## 46595510 Outputs

```
VAR_OUTPUT  
    Done                  : BOOL;  
    Busy                  : BOOL;  
    Error                 : BOOL;  
    ErrorID               : UDINT;  
    RecordedPositions     : ARRAY[1..10];  
    NoOfRecordedPositions : UDINT;  
    Diagnostic            : ST_EL1258_Diagnostics  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Done | BOOL | The value RecordedPosition is valid. If TriggerInput.FreeRun is TRUE, Done only remains TRUE only for one PLC cycle and is then reset automatically, since TouchProbe is automatically reactivated. |
| Busy | BOOL | Becomes TRUE as soon as the function block is active, and becomes FALSE when it has returned to its initial state. If TriggerInput.FreeRun is TRUE, Busy remains TRUE continuously, even if Done or Error become TRUE, since TouchProbe is automatically reactivated. |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the Overview of NC Errors. |
| RecordedPositions | ARRAY[1..10] | One or more detected axis positions at the time of the trigger event.  If TriggerInput.FreeRun is TRUE, the function block operates in free-running mode, so that each valid change in the input signal leads to a new RecordedPosition. The positions can be evaluated if Done is TRUE. |
| NoOfRecordedPositions | UDINT | Number of positions recorded. |
| Diagnostic | [ST\_EL1258\_Diagnostics](ms-xhelp:///?Id=beckhoff-7641-4c6a-b098-b528f818f349) | Data structure containing diagnostic data that can be used for error analysis. |

## 16706408/16139946 Inputs/outputs

```
VAR_IN_OUT  
    Axis         : AXIS_REF;   
    TriggerInput : XFC_TRIGGER_REF;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Axis | [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) | The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other parameters it contains the current axis status, including position, velocity or error state. |
| TriggerInput | [XFC\_MT\_TRIGGER\_REF](ms-xhelp:///?Id=beckhoff-1923-4e24-b98b-1ffc7081a9b4) | TriggerInput is a data structure for describing the trigger source and for feeding the state and timestamp of a digital input signal. This data structure is filled by the user. |
