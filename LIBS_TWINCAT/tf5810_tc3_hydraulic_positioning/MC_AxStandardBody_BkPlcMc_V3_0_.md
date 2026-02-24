# MC_AxStandardBody_BkPlcMc (V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Runtime](ms-xhelp:///?Id=beckhoff-6898-463a-a8a2-80cf35a5250d)
5. MC\_AxStandardBody\_BkPlcMc (V3.0)

# MC\_AxStandardBody\_BkPlcMc (V3.0)

![26298136](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854817419__Web.gif)

This function bllock calls a function block of each of the following types: [MC\_AxRtEncoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191), [MC\_AxRuntime\_BkPlcMc](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862), [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) and [MC\_AxRtDrive\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

```
VAR_OUTPUT  
    Error:      BOOL;  
    ErrorID:    UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block

The usual components of the axis are called, depending on the value in [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2). If one of the called function blocks reports an **Error** it is echoed, together with its **ErrorID**, at the outputs of this function block.

|  |  |
| --- | --- |
| 35356632 | In the event of multiple problems, they are prioritized according to the following sequence: encoder, generator, finish, drive. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
