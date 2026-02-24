# XFC_PathPositionCam

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_PathPositionCam

XFC\_PathPositionCam HParam  UDINTFirstPathId  UDINTLastPathId  UDINTFirstOnPathPosition  LREALLastOnPathPosition  LREALOnCompensation  LREALOffCompensation  LREALOptions  ST\_CamSwitchOptions↔NciToPlc  Reference To NCTOPLC\_NCICHANNEL\_REF↔Output  Reference To OUTPUT\_REF

XFC\_PathPositionCam realizes a path cam that switches a digital output on and off depending on the path.

In contrast to the digital cam controller [MC\_PathDigitalCamSwitch\_MultiEdge](ms-xhelp:///?Id=beckhoff-43b7-4f8f-84a3-212ffca0bd37), the function block switches precisely one cam on a digital output track. This facilitates parameterization of the function block, although it cannot be used if several cams are required on an output track.

In addition to the switching state of the digital output the output data structure contains precise time information for the next switching operations.

This information is used for the actual output at an XFC output terminal with a downstream function block ([XFC\_EL2252\_V2](ms-xhelp:///?Id=beckhoff-a2cd-460d-bc37-9f69b2fb8618) or [XFC\_EL2262](ms-xhelp:///?Id=beckhoff-d181-4470-9b26-c09bfd4c663d)).

## 61660876 Inputs

```
VAR_INPUT  
    HParam              : UDINT;  
    FirstPathId         : UDINT;  
    LastPathId          : UDINT;  
    FirstOnPathPosition : LREAL;  
    LastOnPathPosition  : LREAL;  
    OnCompensation      : LREAL;   
    OffCompensation     : LREAL;  
    Options             : ST_CamSwitchOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| HParam | UDINT | H-parameter value that corresponds to the switching state. |
| FirstPathId | UDINT | Unique ID that continually increases over the path and belongs to the relative path until the cam switches on. |
| LastPathId | UDINT | Unique ID that continually increases over the path and belongs to the relative path until the cam switches off. |
| FirstOnPathPosition | LREAL | Relative path until the cam switches on. |
| LastOnPathPosition | LREAL | Relative path until the cam switches off. |
| OnCompensation | LREAL | Compensation time for the rising edge of the cam in [s]. For negative values of OnCompensation the switching time is brought forward, otherwise it is delayed. The value OnCompensation parameterized here has priority over TRACK\_REF |
| OffCompensation | LREAL | Compensation time for the falling edge of the cam in [s]. For negative values of OffCompensation the switching time is brought forward, otherwise it is delayed. The value OffCompensation parameterized here has priority over TRACK\_REF |
| Options | [ST\_CamSwitchOptions](ms-xhelp:///?Id=beckhoff-ac0d-4c92-8b85-368893802d34) | Optional parameters |

## 18076976/28475059 Inputs/outputs

```
VAR_IN_OUT  
    NciToPlc : NciChannelToPlc;  
    Output   : OUTPUT_REF;   
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| NciToPlc | NciChannelToPlc | The structure of the cyclic channel interface from the NCI to the PLC. This structure is only accessed for reading |
| Output | [OUTPUT\_REF](ms-xhelp:///?Id=beckhoff-cf93-4a99-b49d-5ccd1f864f49) | The data structure Output contains the calculated state of the digital output and the associated time stamp for the output at a digital XFC output terminal |
