# MC_ReadStatus_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_ReadStatus\_BkPlcMc (from V3.0)

# MC\_ReadStatus\_BkPlcMc (from V3.0)

![14007894](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854666635__Web.gif)

The function block determines the current state of an axis.

```
VAR_INPUT  
    Enable:              BOOL;  
END_VAR
```

```
VAR_OUTPUT  
    Busy:               BOOL;  
    Done:               BOOL;  
    Error:              BOOL;  
    ErrorID:            UDINT;  
    Errorstop:          BOOL;  
    Disabled:           BOOL;  
    Stopping:           BOOL;  
    StandStill:         BOOL;  
    DiscreteMotion:     BOOL;  
    ContinousMotion:    BOOL;  
    SynchronizedMotion: BOOL;  
    Homing:             BOOL;  
    ConstantVelocity:   BOOL;  
    Accelerating:       BOOL;  
    Decelerating:       BOOL;  
END_VAR
```

```
VAR_INOUT  
    Axis:               Axis_Ref_BkPlcMc;  
END_VAR
```

**Enable**: A TRUE state at this input causes the function block to update.

**Busy**: Indicates that a command is being processed.

**Done**: Successful determination of the actual position is indicated here.

**Error**: This output reports any problems relating to the function of the function block.

**ErrorID**: Provides a coded cause of error, if the function block was unable to execute the required function.

**Errorstop**: This signal indicates that the axis associated with an error has been placed in a state in which it is not able to operate. This state can only be cleared by activating either a [MC\_Reset\_BkPlcMc](ms-xhelp:///?Id=beckhoff-e4ba-44fd-a251-2f2b0aa0abc2) or a [MC\_ResetAndStop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9025-42cf-b5c3-4abde4187a21) function block.

**Disabled**: This signal indicates whether the axis is enabled or disabled by its [MC\_Power\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f1de-4926-8132-1e2d75ae63fc) function block.

**Stopping**: This signal indicates that an active movement of the axis is being stopped by a [MC\_Stop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9b19-4599-8840-88fa788b9ed6) or by a [MC\_ResetAndStop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9025-42cf-b5c3-4abde4187a21) function block. This signal is cleared as soon as the axis is stationary.

**StandStill**: This signal indicates that the axis is neither in a fault state nor is it active.

**DiscreteMotion**: This signal indicates that the axis is executing an autonomous movement (not resulting from a coupling) with a defined target.

**ContinousMotion**: This signal indicates that the axis is executing an autonomous movement (not resulting from a coupling) with a defined velocity but not with a specified target.

**SynchronizedMotion**: This signal indicates that the axis is being controlled by a gear coupling.

**Homing**: This signal indicates that the axis is executing a reference travel.

**ConstantVelocity**: This signal indicates that the axis is being moved with constant velocity.

**Accelerating**: This signal indicates that the velocity of an axis is reaching a specified value.

|  |  |
| --- | --- |
| 58962188 | This does not always mean that the velocity is increasing: when an axis that is already in movement is started, it can happen that the axis accelerates in the direction opposite the current movement in order to achieve a specified velocity in the other direction. From the point of view of the original movement this is a deceleration, although from the point of the current (new) movement it is still an acceleration. |

**Decelerating**: This signal indicates that the axis is reducing its velocity in order to continue a movement with a velocity lower than the current velocity, or in order to end it.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block:

If **Enable** is TRUE, the function block examines the transferred axis interface and decodes the internal state information. A FALSE state at **Enable** clears all the pending output signals.

|  |  |
| --- | --- |
| 60897649 | This function block requires no time and no preconditions for executing its tasks. The outputs Error and Busy will never assume the value TRUE and only exist for compatibility reasons. |

|  |  |
| --- | --- |
| 11207934 | Observe outputs  The outputs **Error** and **ErrorID** indicate the state of the function block, **not** that of the axis. |

To read the current error code of the axis, an [MC\_ReadAxisError\_BkPlcMc()](ms-xhelp:///?Id=beckhoff-2349-410b-b8b6-306ce323bf22) function block should be used.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
