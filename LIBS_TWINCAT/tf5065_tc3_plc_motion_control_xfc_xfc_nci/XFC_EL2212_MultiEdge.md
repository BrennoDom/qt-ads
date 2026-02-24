# XFC_EL2212_MultiEdge

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_EL2212\_MultiEdge

XFC\_EL2212\_MultiEdge ForceWhenLate  BOOLReset  BOOL↔Output  Reference To OUTPUT\_REF\_MULTIEDGE↔TrackOptions  Reference To TRACK\_REF↔EL2212  Reference To EL2212\_MT\_IoInterfaceBOOL  ErrorUDINT  ErrorIDBOOL  ErrorOutputMissedBOOL  PrecisionReducedST\_EL2258\_Diagnostics  Diagnostics

The function block XFC\_EL2212\_MultiEdge handles the output of a multi-edge cam controller [MC\_DigitalCamSwitch\_MultiEdge](ms-xhelp:///?Id=beckhoff-b4c5-46de-b495-c5ddad1db2d7) via the EL2212 XFC timestamp terminal.

## 34717793 Inputs

```
VAR_INPUT  
    ForceWhenLate : BOOL;   
    Reset         : BOOL;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| ForceWhenLate | BOOL | If ForceWhenLate is TRUE, the output is activated even if the time stamp is already exceeded. It is recommended to set ForceWhenLate to prevent the loss of a switching edge in case of fluctuations of the time signal. |
| Reset | BOOL | Reset initiates a reset of the terminal |

## 44024689 Outputs

```
VAR_OUTPUT  
    Error             : BOOL;  
    ErrorID           : UDINT;  
    ErrorOutputMissed : BOOL;  
    PrecisionReduced  : BOOL;  
    Diagnostics       : ST_EL2258_Diagnostics;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If an error output is set, this parameter supplies an error number |
| ErrorOutputMissed | BOOL | One of the switching points transferred in the Output structure could not be maintained and the output state remains unchanged. If ForceWhenLate is TRUE, the initial state is always output and ErrorOutputMissed does not become TRUE. |
| PrecisionReduced | BOOL | One of the switching points transferred in the Output structure could not be maintained, but the output state was output with a delay. PrecisionReduced should be regarded as a warning. It can only become TRUE if ForceWhenLate is TRUE. |
| Diagnostics | [ST\_EL2258\_Diagnostics](ms-xhelp:///?Id=beckhoff-352e-454b-96cc-fcf50b1b60c8) | Data structure containing diagnostic data that can be used for error analysis. |

## 60677888/9230088 Inputs/outputs

```
VAR_IN_OUT  
    Output       : OUTPUT_REF_MULTIEDGE;  
    TrackOptions : TRACK_REF;  
    EL2212       : EL2212_IoInterface;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Output | [OUTPUT\_REF\_MULTIEDGE](ms-xhelp:///?Id=beckhoff-8aef-41c6-a986-977cfaa8f276) | Output state for a channel of the Terminal. The data structure Output contains the next calculated states of the digital output and the associated timestamp for output on a digital XFC output terminal. |
| TrackOptions | [TRACK\_REF](ms-xhelp:///?Id=beckhoff-773d-4477-bc02-eb9fd1379af3) | The data structure TrackOptions contains the parameterization for the cam track. |
| EL2212 | [EL2212\_IoInterface](ms-xhelp:///?Id=beckhoff-46ec-4174-9b0d-bbabe03e2830) | Process image of the terminal |

## Process image

The terminal is inserted in the process image with up to 10 timestamps for operation with this function block in the multi-timestamp mode and the DC mode must be activated.
