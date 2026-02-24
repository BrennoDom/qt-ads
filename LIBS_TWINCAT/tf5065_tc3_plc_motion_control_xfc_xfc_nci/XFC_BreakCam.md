# XFC_BreakCam

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_BreakCam

XFC\_BreakCam BreakRelease  BOOLLastOnPosition  LREALModulo  BOOLModuloFactor  LREALOffCompensation  LREALOptions  ST\_CamSwitchOptions↔Output  Reference To OUTPUT\_REF↔Axis  Reference To AXIS\_REFBOOL  ErrorUDINT  ErrorID

XFC\_BreakCam realizes a brake cam, which deactivates a digital output depending on the position as soon as BreakRelease is withdrawn.

In addition to the switching state of the digital output the output data structure contains precise time information for the next switching operations. This information is used for the actual output at an XFC output terminal with a downstream function block ([XFC\_EL2252\_V2](ms-xhelp:///?Id=beckhoff-a2cd-460d-bc37-9f69b2fb8618) or [XFC\_EL2262](ms-xhelp:///?Id=beckhoff-d181-4470-9b26-c09bfd4c663d)).

## 18068130 Inputs

```
VAR_INPUT  
    BreakRelease    : LREAL;  
    LastOnPosition  : LREAL;  
    Modulo          : BOOL;  
    ModuloFactor    : LREAL := 360;  
    OffCompensation : LREAL;  
    Options         : ST_CamSwitchOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| BreakRelease | LREAL | Brake enable. The cam remains active as long as BreakRelease is TRUE. When BreakRelease becomes FALSE, the cam is switched off at position LastOnPosition. |
| LastOnPosition | LREAL | Last position up to which the cam is switched on. |
| Modulo | BOOL | If Modulo TRUE, all positions are interpreted as modulo. The cam function is repeated cyclically. The parameter ModuloFactor is used for calculating the modulo cycle. |
| ModuloFactor | LREAL | ModuloFactor indicates the length of a modulo cycle in the positioning unit of the axis and is only used if Modulo=TRUE. |
| OffCompensation | LREAL | Compensation time for the falling edge of the cam in [s]. For negative values of OffCompensation the switching time is brought forward, otherwise it is delayed. The value OffCompensation parameterized here has priority over [TRACK\_REF](ms-xhelp:///?Id=beckhoff-773d-4477-bc02-eb9fd1379af3). |
| Options | [ST\_CamSwitchOptions](ms-xhelp:///?Id=beckhoff-ac0d-4c92-8b85-368893802d34) | Optional parameters |

## 28395444 Outputs

```
VAR_OUTPUT  
    Error             : BOOL;  
    ErrorID           : UDINT;   
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If an error output is set, this parameter supplies an Overview of NC Errors. |

## 54232412/18329666 Inputs/outputs

```
VAR_IN_OUT  
    Output : OUTPUT_REF;   
    Axis   : AXIS_REF;   
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Output | [OUTPUT\_REF](ms-xhelp:///?Id=beckhoff-cf93-4a99-b49d-5ccd1f864f49) | The data structure Output contains the calculated state of the digital output and the associated time stamp for the output at a digital XFC output terminal. |
| Axis | [AXIS\_REF](https://infosys.beckhoff.de/content/1033/tcplclibmc2/458448779.html?id=8850852884863363235) | The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other parameters it contains the current axis status, including position, velocity or error state. |

## Method of function of the time compensation

![30749271](/tf5065_tc3_plc_motion_control_xfc_xfc_nci/1033/Images/gif/462185355__en-US__Web.gif)
