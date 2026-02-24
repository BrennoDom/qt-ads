# MC_Halt_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_Halt\_BkPlcMc (from V3.0)

# MC\_Halt\_BkPlcMc (from V3.0)

![64243102](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854715275__Web.gif)

The function block cancels a current axis motion and monitors the stop operation.

|  |  |
| --- | --- |
| 41317012 | The stop operation initiated by this function block can be interrupted by other function blocks. An MC\_Stop\_BkPlcMc function block can be used to prevent the axis from restarting during a stop operation. |

```
VAR_INPUT  
    Execute:        BOOL;  
    Deceleration:   LREAL;  (ab/from V3.0.5)  
    Jerk:           LREAL;  (ab/from V3.0.5)  
    RampTime:       LREAL;  (ab/from V3.0.5)  
    BufferMode:     MC_BufferMode_BkPlcMc:=Aborting_BkPlcMc;    (ab/from V3.0.8)  
END_VAR
```

```
VAR_OUTPUT  
    Busy:           BOOL;  
    Done:           BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
    Active:         BOOL;  
    CommandAborted: BOOL;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: A positive edge at this input ends a movement being carried out by the axis.

**Deceleration**: [mm/s2] The deceleration to be applied.

**Jerk**: [mm/s3] The jerk to be applied.

**RampTime**: [s] The required stopping time.

**BufferMode**: Reserved. This input is provided in preparation for a future build. It should currently either not be assigned or assigned the constant Aborting\_BkPlcMc. (from V3.0.8)

**Busy**: Indicates that a command is being processed.

**Done**: This indicates successful processing of the operation.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Active:** Indicates that a command is being processed.

**CommandAborted**: Indicates that processing of this command was canceled by another command.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The behavior of the function block is identical to that of the [MC\_Stop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9b19-4599-8840-88fa788b9ed6)() function block. The only difference is that processing of the command can be canceled by other function blocks.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
