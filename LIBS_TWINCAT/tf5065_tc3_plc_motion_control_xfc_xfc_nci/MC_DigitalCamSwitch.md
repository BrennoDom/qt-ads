# MC_DigitalCamSwitch

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# MC\_DigitalCamSwitch

MC\_DigitalCamSwitch Enable  BOOLOptions  ST\_CamSwitchOptions↔Axis  Reference To AXIS\_REF↔Switches  Reference To CAMSWITCH\_REF↔Output  Reference To OUTPUT\_REF↔TrackOptions  Reference To TRACK\_REFBOOL  InOperationBOOL  BusyBOOL  ErrorUDINT  ErrorID

MC\_DigitalCamSwitch is a digital cam controller with one or several cams on a digital output track.

Position, time and brake cams can be realized through suitable parameterization. Further output tracks can be realized with independent instances of the function block.

In addition to the switching state of the digital output the output data structure contains precise time information for the next switching operations. This information is used for the actual output at an XFC output terminal with a downstream function block ([XFC\_EL2252\_V2](ms-xhelp:///?Id=beckhoff-a2cd-460d-bc37-9f69b2fb8618) or [XFC\_EL2262](ms-xhelp:///?Id=beckhoff-d181-4470-9b26-c09bfd4c663d)).

## 22433040 Inputs

```
VAR_INPUT  
    Enable  : BOOL;  
    Options : ST_CamSwitchOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Enable | BOOL | The cam controller is activated via the Enable input. The initial state remains unchanged, as long as Enable=FALSE. |
| Options | [ST\_CamSwitchOptions](ms-xhelp:///?Id=beckhoff-ac0d-4c92-8b85-368893802d34) | Optional parameter |

## 570775 Outputs

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
| ErrorID | UDINT | If the error output is set, this parameter supplies the Overview of NC Errors. |

## 5136981/46232835 Inputs/outputs

```
VAR_IN_OUT  
    Axis         : AXIS_REF;   
    Switches     : CAMSWITCH_REF;  
    Output       : OUTPUT_REF;   
    TrackOptions : TRACK_REF;   
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Axis | [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) | The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other parameters it contains the current axis status, including position, velocity or error state. |
| Switches | [CAMSWITCH\_REF](ms-xhelp:///?Id=beckhoff-d6d3-4335-b4f0-5c376cb2aebe) | The data structure Switches contains a reference to the parameterization of all cams on the cam track. |
| Output | [OUTPUT\_REF](ms-xhelp:///?Id=beckhoff-cf93-4a99-b49d-5ccd1f864f49) | The data structure Output contains the calculated state of the digital output and the associated time stamp for the output at a digital XFC output terminal. |
| TrackOptions | [TRACK\_REF](ms-xhelp:///?Id=beckhoff-773d-4477-bc02-eb9fd1379af3) | The data structure TrackOptions contains the parameterization for the cam track. |

## Example for two digital cam tracks

![13442339](/tf5065_tc3_plc_motion_control_xfc_xfc_nci/1033/Images/gif/462172555__en-US__Web.gif)

The following switching diagrams result from the cam data. The switching sequence is represented without any time compensation and hysteresis and varies for both directions of travel due to the cam data.

**Switching sequence for positive direction of travel**

![53872188](/tf5065_tc3_plc_motion_control_xfc_xfc_nci/1033/Images/gif/462175755__en-US__Web.gif)

**Switching sequence for negative direction of travel**

![15087649](/tf5065_tc3_plc_motion_control_xfc_xfc_nci/1033/Images/gif/462178955__en-US__Web.gif)
