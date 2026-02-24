# MC_DigitalCamSwitch_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_DigitalCamSwitch\_BkPlcMc (from V3.0)

# MC\_DigitalCamSwitch\_BkPlcMc (from V3.0)

![56607127](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854698251__Web.gif)

The function block generates software cams depending on the position, direction of travel and velocity of an axis.

```
VAR_INPUT  
    Enable:         BOOL;  
    EnableMask:     DWORD;  
END_VAR
```

```
VAR_OUTPUT  
    InOperation:    BOOL;  
    Busy:           BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
    Switches:       CAMSWITCH_REF_BkPlcMc;  
    Outputs:        OUTPUT_REF_BkPlcMc;  
    TrackOptions:   TRACK_REF_BkPlcMc;  
END_VAR
```

**Enable**: This input controls all activities of the function block.

**EnableMask**: A mask with bits that specify the activation of the outputs in **Outputs**.

**InOperation**: This indicates whether the function block is active.

**Busy**: This output TRUE while the command is being processed.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

**Switches**: Here, an array of type [CAMSWITCH\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f33f-4253-9407-ea045cafcc25) should be transferred.

**Outputs**: Here, the address of a variable of type [OUTPUT\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f9aa-4587-a859-7e05ee8c20f1) should be transferred.

**TrackOptions**: Here, an array of type [TRACK\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ee5c-4cd0-a66f-7a08ab2a33b2) should be transferred.

## Behavior of the function block

Cam signals (switches) are switched based on the actual position of an axis. The available options are position-controlled (with start and end position) and time-controlled (with trigger position and duration). The direction of travel of the axis can be taken into account.

The cam signals are assigned to tracks with parameter sable properties. The time response can be specified through a switch-on and switch-off delay. Predictive signalling can be achieved through negative values. A hysteresis enables suppression of undesirable signalling, if the axis is near a switching points and the actual position is not entirely constant.

## Example

[CAMSWITCH\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f33f-4253-9407-ea045cafcc25) used:

| Parameter | Switch[1] | Switch[2] | Switch[3] | Switch[4] | ... | Switch[n] |
| --- | --- | --- | --- | --- | --- | --- |
| TrackNumber | 1 | 1 | 1 | 2 |  |  |
| FirstOnPosition | 2000.0 | 2500.0 | -1000.0 | 3000.0 |  |  |
| LastOnPosition | 3000.0 | 3000.0 | 1000.0 |  |  |  |
| AxisDirection | 1 | 2 | 0 | 0 |  |  |
| CamSwitchMode | 0 | 0 | 0 | 1 |  |  |
| Duration |  |  |  | 1.35 |  |  |
| ..... |  |  |  |  |  |  |

[TRACK\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ee5c-4cd0-a66f-7a08ab2a33b2) used:

| Parameter | Track[1] | Track[2] | ... | Track[n] |
| --- | --- | --- | --- | --- |
| OnCompensation | -0.125 | 0.0 |  |  |
| OffCompensation | 0.250 | 0.0 |  |  |
| Hysteresis | 0.0 | 0.0 |  |  |

Signal curves during axis motion from 0.0 to 5000.0 and back:

![39702100](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1599959691__Web.gif)

The following diagram shows the signal curves over the position. For positive direction of travel the signals are shown normally (upwards), for negative direction of travel they are shown negative, i.e. 'downwards'. The vertical cursor lines indicate the positions 1000 and 3000 mm.

![21774588](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1599962123__Web.gif)

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
