# XFC_EL2262_MultiEdge

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_EL2262\_MultiEdge

XFC\_EL2262\_MultiEdge Reset  BOOLPreset  BOOLOversamplingFactor  UINTOutputOneCycleDelayed  BOOLForceWhenLate  BOOLChannel  INT↔Output  Reference To OUTPUT\_REF\_MULTIEDGE↔TrackOptions  Reference To TRACK\_REF↔EL2262  Reference To EL2262\_IoInterfaceBOOL  ErrorUDINT  ErrorIDBOOL  ErrorOutputMissedBOOL  PrecisionReducedST\_EL2262\_Diagnostics  Diagnostics

\_XFC\_EL2262\_Multiedge handles the output of digital cams with the EL2262 XFC oversampling terminal.

The maximum frequency depends on the cycle time. The minimum distance between two rising signal edges = (2\*PLC cycle time) / oversampling factor. The minimum distance between a rising and falling edge = PLC cycle time / oversampling factor. The switching accuracy is determined by the set oversampling factor of the terminal.

## 48259009 Inputs

```
VAR_INPUT  
    Reset                      : BOOL;  
    Preset                     : BOOL;  
    OversamplingFactor         : UINT;  
    OutputOneCycleDelayed      : BOOL; (* TRUE if EL2262 is updated with the NC SAF task at the beginning of the next cycle *)  
    ForceWhenLate              : BOOL; (* forces the output even when the timestamp is missed *)  
    Channel                    : INT;  (* select 0 or 1 for Output0 or Output1 *)  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Reset | BOOL | The terminal output is deactivated. |
| Preset | BOOL | The terminal output is activated. |
| OversamplingFactor | UINT | Oversampling factor for the EL2262 terminal |
| OutputOneCycleDelayed | BOOL | OutputOneCycleDelayed is TRUE, if the output of the process image is delayed by a cycle due to the set timing. OutputOneCycleDelayed depends on the timing of the output task to which the EL2262 is linked. |
| ForceWhenLate | BOOL | If the time information changes slightly from cycle to cycle, it might not be possible for a switching edge to be output. In such a situation ForceWhenLate forces the best possible switching. In this case the PrecisionReduced output goes TRUE and can be used for diagnosis. (Can be used in the case of increased jitter in an axis position where the output of a switching edge cannot be determined to an exact output cycle). |
| Channel | INT | Defines the output channel of the EL2262, where 0 = Output0 and 1 = Output1. |

## 31677898 Outputs

```
VAR_OUTPUT  
    Error             : BOOL;  
    ErrorID           : UDINT;  
    ErrorOutputMissed : BOOL;  
    PrecisionReduced  : BOOL;  
    Diagnostics       : ST_EL2262_Diagnostics;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If an error output is set, this parameter supplies an error number |
| ErrorOutputMissed | BOOL | One of the switching points transferred in the Output structure could not be maintained and the output state remains unchanged. If ForceWhenLate is TRUE, the initial state is always output and ErrorOutputMissed does not become TRUE. |
| PrecisionReduced | BOOL | One of the switching points transferred in the Output structure could not be maintained, but the output state was output with a delay. PrecisionReduced should be regarded as a warning. It can only become TRUE if ForceWhenLate is TRUE. |
| Diagnostics | [ST\_EL2262\_Diagnostics](ms-xhelp:///?Id=beckhoff-c427-4245-8440-40f0bba7303a) | Data structure containing diagnostic data that can be used for error analysis. |

## 16665627/15772917 Inputs/outputs

```
VAR_IN_OUT  
    Output       : OUTPUT_REF_MULTIEDGE;  
    TrackOptions : TRACK_REF;  
    EL2262       : EL2262_IoInterface;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Output | [OUTPUT\_REF\_MULTIEDGE](ms-xhelp:///?Id=beckhoff-8aef-41c6-a986-977cfaa8f276) | The data structure Output contains an array of calculated states of the digital output and the associated timestamp for output on a digital XFC output terminal |
| TrackOptions | [TRACK\_REF](ms-xhelp:///?Id=beckhoff-773d-4477-bc02-eb9fd1379af3) | The data structure TrackOptions contains the parameterization for the cam track. |
| EL2262 | [EL2262\_IoInterface](ms-xhelp:///?Id=beckhoff-9082-4d5a-8320-81b195b0091a) | Process image of the terminal |
