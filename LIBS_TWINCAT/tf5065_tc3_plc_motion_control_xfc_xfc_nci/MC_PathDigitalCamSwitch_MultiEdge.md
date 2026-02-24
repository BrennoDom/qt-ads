# MC_PathDigitalCamSwitch_MultiEdge

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# MC\_PathDigitalCamSwitch\_MultiEdge

MC\_PathDigitalCamSwitch\_MultiEdge Enable  BOOLHParam  UDINTOptions  ST\_CamSwitchOptions↔NciToPlc  Reference To NCTOPLC\_NCICHANNEL\_REF↔Switches  Reference To PATH\_CAMSWITCH\_REF↔Output  Reference To OUTPUT\_REF\_MULTIEDGE↔TrackOptions  Reference To TRACK\_REFBOOL  InOperationBOOL  BusyBOOL  ErrorUDINT  ErrorID

MC\_PathDigitalCamSwitch\_MultiEdge is a digital cam controller with one or several cams on a digital output track. The function block is capable of performing several switching operations during a PLC cycle. The switching operations are defined by position cams. Further output tracks can be realized with independent instances of the function block.

In addition to the switching states of the digital output the output data structure contains precise time information for the next switching operations. With this information, the actual output can take place on an XFC multi-timestamp output terminal with a downstream function block (XFC\_EL1259\_MultiEdge, [XFC\_EL2212\_MultiEdge](ms-xhelp:///?Id=beckhoff-b0d2-4c50-8e57-5d95c9127f5a), [XFC\_EL2262\_MultiEdge](ms-xhelp:///?Id=beckhoff-2a44-4ce5-a830-d08e4e3b5d5c) or [XFC\_EL2258\_MultiEdge](ms-xhelp:///?Id=beckhoff-d115-4fe4-b916-7bce3c5f0f48)).

|  |  |
| --- | --- |
| 54948942 | Time cams and brake cams cannot be used with the function block MC\_PathDigitalCamSwitch\_MultiEdge. Terminals without multi-timestamp functionality are not suitable for use with this function block. |

## 24778434 Inputs

```
VAR_INPUT  
    Enable  : BOOL;  
    HParam  : DINT;  
    Options : ST_CamSwitchOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Enable | BOOL | The cam controller is activated via the Enable input. The initial state remains unchanged, as long as Enable=FALSE. |
| HParam | DINT | H-parameter value that corresponds to the switching state TRUE. |
| Options | [ST\_CamSwitchOptions](ms-xhelp:///?Id=beckhoff-ac0d-4c92-8b85-368893802d34) | Optional parameters |

## 21679321 Outputs

```
VAR_OUTPUT  
    InOperation : BOOL;   
    Busy        : BOOL;   
    Error       : BOOL;   
    ErrorID     : UDINT;   
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| InOperation | BOOL | InOperation is TRUE, as long as the cam controller is active and the cam track is calculated according to the cam parameterization. |
| Busy | BOOL | Busy is TRUE as long as the block function is not completed. |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number |

## 60896162/11194552 Inputs/outputs

```
VAR_IN_OUT  
    NciToPlc     : NciChannelToPlc  
    Switches     : PATH_CAMSWITCH_REF;  
    Output       : OUTPUT_REF_MULTIEDGE;   
    TrackOptions : TRACK_REF;   
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| NciToPlc | NciChannelToPlc | The structure of the cyclic channel interface from the NCI to the PLC. This structure is only accessed for reading. |
| Switches | [PATH\_CAMSWITCH\_REF](ms-xhelp:///?Id=beckhoff-7a6f-4e8d-ac3f-cc987a2662e5) | The data structure Switches contains a reference to the parameterization of all cams on the cam track. |
| Output | [OUTPUT\_REF\_MULTIEDGE](ms-xhelp:///?Id=beckhoff-8aef-41c6-a986-977cfaa8f276) | The data structure Output contains the calculated states of the digital output and the associated time stamps for the output at a digital XFC output terminal. |
| TrackOptions | [TRACK\_REF](ms-xhelp:///?Id=beckhoff-773d-4477-bc02-eb9fd1379af3) | The data structure TrackOptions contains the parameterization for the cam track. |
