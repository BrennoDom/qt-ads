# MC_AxRtGoErrorState_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Runtime](ms-xhelp:///?Id=beckhoff-6898-463a-a8a2-80cf35a5250d)
5. MC\_AxRtGoErrorState\_BkPlcMc (from V3.0)

# MC\_AxRtGoErrorState\_BkPlcMc (from V3.0)

![61411666](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854807691__Web.gif)

(not recommended) This function block places the axis into a fault state.

```
VAR_INPUT  
    Trigger:        BOOL;  
    ErrorID:        UDINT;  
    NoLogging:      BOOL;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

**Trigger**: A rising edge at this input places the axis in a fault state.

**ErrorCode**: An encoded indication of the cause of the error is provided here.

**NoLogging**: TRUE at this input suppresses the output of a message.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block

The axis is placed into a fault state by a rising edge at the **Trigger** input.

Requirements:

* The value at the **ErrorCode** input is not equal to 0.
* The axis is not already in a fault state.

|  |  |
| --- | --- |
| 15834086 | If NoLogging is FALSE (default state), message containing information on the affected axis and the ErrorCode is generated during the transition of the axis to the error state. This default message should be replaced with a message that is meaningful for the application. In this case the default message should be suppressed by setting NoLogging to TRUE. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
