# MC_ReadActualVelocity_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_ReadActualVelocity\_BkPlcMc (from V3.0)

# MC\_ReadActualVelocity\_BkPlcMc (from V3.0)

![34431157](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854654475__Web.gif)

The function block determines the current velocity of an axis.

```
VAR_INPUT  
    Enable:     BOOL;  
END_VAR
```

```
VAR_OUTPUT  
    Valid:      BOOL;  
    Busy:       BOOL;  
    Error:      BOOL;  
    ErrorID:    UDINT;  
    Velocity:   LREAL;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Enable**: A positive edge at this input triggers an update of the velocity value.

**Valid**: This indicates successful determination of the velocity.

**Busy**: This output is TRUE while the command is being processed.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Velocity**: [mm/s] The actual velocity.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block is activated by a positive edge at **Enable**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If the axis is already in a fault state, and if the cause lies with an encoder problem, it responds with **Error** and **ErrorID**:=the encoder's error code.

The velocity is determined and reported with **Valid** if these checks can be carried out without problems.

A negative edge at **Enable** clears all the pending output signals.

|  |  |
| --- | --- |
| 41444960 | This function block requires no time for executing its tasks. The output Busy will never assume the value TRUE and only exists for compatibility reasons. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
