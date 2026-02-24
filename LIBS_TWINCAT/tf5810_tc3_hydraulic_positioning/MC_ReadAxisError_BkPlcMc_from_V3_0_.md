# MC_ReadAxisError_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_ReadAxisError\_BkPlcMc (from V3.0)

# MC\_ReadAxisError\_BkPlcMc (from V3.0)

![37460321](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854656907__Web.gif)

This function block determines the current error code of an axis.

```
VAR_INPUT  
    Enable:     BOOL;  
END_VAR
```

```
VAR_OUTPUT  
    Busy:       BOOL;  
    Done:       BOOL;  
    Error:      BOOL;  
    ErrorID:    UDINT;  
    AxisErrorID:UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Enable**: TRUE at this input triggers an update of the error code.

**Busy**: Indicates that a command is being processed.

**Done**: Successful determination of the actual position is indicated here.

**Error**: Indicates TRUE, if the function block was unable to execute the required function.

**ErrorID**: Provides a coded cause of error, if the function block was unable to execute the required function.

**AxisErrorID**: Provides the current [error code](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) of the axis.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block:

If **Enable** is TRUE, the function block checks the transferred axis interface. The current error code is reported as **AxisErrorID**. If **Enable** is FALSE, the function block cancels all pending output signals.

|  |  |
| --- | --- |
| 1598569 | This function block requires no time and no preconditions for executing its tasks. The outputs Error and Busy will never assume the value TRUE and only exist for compatibility reasons. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
