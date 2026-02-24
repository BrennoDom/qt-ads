# MC_AxRtCheckSyncDistance_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Runtime](ms-xhelp:///?Id=beckhoff-6898-463a-a8a2-80cf35a5250d)
5. MC\_AxRtCheckSyncDistance\_BkPlcMc (from V3.0)

# MC\_AxRtCheckSyncDistance\_BkPlcMc (from V3.0)

![66405588](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854797963__Web.gif)

The function block checks for an invalid path (distance) after leaving the cam during homing.

```
VAR_INPUT  
    MaxDistance:    LREAL;  
    MinDistance:    LREAL;  
    MaxIndexWidth:  LREAL;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    Active:         BOOL;  
    Exceeded:       BOOL;  
END_VAR
```

**MaxDistance**: [mm] This parameter is used to specify the maximum permitted distance that may be traveled between the referencing cam and reaching of the zero pulse.

**MinDistance**: [mm] This parameter is used to specify the minimum distance that must be traveled between the referencing cam and reaching of the zero pulse.

**MaxIndexWidth**: [mm] This parameter is used to specify the minimum distance that must be traveled to leave the referencing cam. (from V3.0.20)

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

**Exceeded**: Indicates that the axis has travelled more than **MaxDistance** after leaving the cam, without detection of the zero pulse of the encoder.

**Active:** Indicates that the axis has left the cam has and expects the zero pulse of the encoder.

## Behavior of the function block

The function block detects the part of the homing, in which the axis searches for the zero pulse of encoder, thereby monitoring the distance travelled. Two problems can be detected during this process:

* The axis travels **MaxIndexWidth**, without that the falling edges of the referencing cam being detected.
* The axis travels **MaxDistance**, without a zero pulse being detected.
* The zero pulse is detected, before the axis has traveled **MinDistance**.

Any problems that are detected are indicated with **Exceeded**. If this is to lead to an axis error, the application must specify a corresponding change of state. An [MC\_AxRtGoErrorState\_BkPlcMc](ms-xhelp:///?Id=beckhoff-cb21-4ce5-b78e-f2e3b4609fb3) function block and a coded [Error Code](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) should be used here.

|  |  |
| --- | --- |
| 60779388 | Monitoring for MinDistance and MaxDistance can be suppressed by setting the respective parameter to 0.0. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
