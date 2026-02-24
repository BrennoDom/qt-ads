# XFC_EL2262

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_EL2262

XFC\_EL2262 OversamplingFactor  UINTOutputOneCycleDelayed  BOOLForceWhenLate  BOOLChannel  INT↔Output  Reference To OUTPUT\_REF↔TrackOptions  Reference To TRACK\_REF↔EL2262  Reference To EL2262\_IoInterfaceBOOL  ErrorUDINT  ErrorIDBOOL  ErrorOutputMissedBOOL  PrecisionReduced

XFC\_EL2262 handles the output of a digital cam with the EL2262 XFC oversampling terminal.

The maximum frequency depends on the cycle time. The minimum distance between two rising signal edges is two PLC cycles. The minimum distance between rising and falling edge can be smaller than a PLC cycle. The switching accuracy is determined by the set oversampling factor of the terminal.

The two channels of the terminal are independent of each other and are served by two instances of the XFC\_EL2262 function block.

## 66727538 Inputs

```
VAR_INPUT  
    OversamplingFactor    : UINT;  
    OutputOneCycleDelayed : BOOL; (* TRUE if EL2262 is updated with the NC SAF task at the beginning of the next cycle *)  
    ForceWhenLate         : BOOL;  
    Channel               : INT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| OversamplingFactor | UINT | Oversampling factor for the EL2262 terminal |
| OutputOneCycleDelayed | BOOL | OutputOneCycleDelayed is TRUE, if the output of the process image is delayed by a cycle due to the set timing. OutputOneCycleDelayed depends on the timing of the output task to which the EL2262 is linked. |
| ForceWhenLate | BOOL | If the time information changes slightly from cycle to cycle, it might not be possible for a switching edge to be output. In such a situation ForceWhenLate forces the best possible switching. In this case the PrecisionReduced output goes TRUE and can be used for diagnosis. (Can be used in the case of increased jitter in an axis position where the output of a switching edge cannot be determined to an exact output cycle). |
| Channel | INT | Channel number 0 or 1 of the EL2262 Terminal |

## 63676932 Outputs

```
VAR_OUTPUT  
    Error             : BOOL;  
    ErrorID           : UDINT;  
    ErrorOutputMissed : BOOL;   
    PrecisionReduced  : BOOL;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If an error output is set, this parameter supplies an error number |
| ErrorOutputMissed | BOOL | Indicates that a switching edge cannot be determined to an exact cycle and therefore cannot be output. The ForceWhenLate input can be set in order to output the switching edge as well as possible. |
| PrecisionReduced | BOOL | indicates that a switching edge cannot be determined to an exact cycle. However, the switching edge was output as well as possible. |

## 36221483/57557895 Inputs/outputs

```
VAR_IN_OUT  
    Output       : OUTPUT_REF;  
    TrackOptions : TRACK_REF;  
    EL2262       : EL2262_IoInterface;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Output | [OUTPUT\_REF](ms-xhelp:///?Id=beckhoff-cf93-4a99-b49d-5ccd1f864f49) | The data structure Output contains the calculated state of the digital output and the associated time stamp for the output at a digital XFC output terminal |
| TrackOptions | [TRACK\_REF](ms-xhelp:///?Id=beckhoff-773d-4477-bc02-eb9fd1379af3) | The data structure TrackOptions contains the parameterization for the cam track. |
| EL2262 | [EL2262\_IoInterface](ms-xhelp:///?Id=beckhoff-9082-4d5a-8320-81b195b0091a) | Process image of the terminal |
