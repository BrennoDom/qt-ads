# MC_Jog

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-7ffe-4e9a-b17d-c6d5be097acd)
3. [Manual motion](ms-xhelp:///?Id=beckhoff-5c82-4434-8738-9c54497789ec)
4. MC\_Jog

# MC\_Jog

![20425774](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/8873656459__Web.png)

The function block MC\_Jog enables an axis to be moved via manual keys. The key signal can be linked directly with the "JogForward" and "JogBackwards" inputs.

## Inputs

```
VAR_INPUT  
    JogForward   : BOOL;  
    JogBackwards : BOOL;  
    Velocity     : LREAL;  
    Acceleration : LREAL;  
    Deceleration : LREAL;  
END_VAR
```

**JogForward:** The command is executed with a rising edge, and the axis is moved in positive direction of travel. During the motion no further signal edges are accepted (this includes the "JogBackwards" input).

**JogBackwards:** The command is executed with a rising edge, and the axis is moved in negative direction of travel. "JogForward" and "JogBackwards" should be triggered alternatively, although they are also mutually locked internally.

**Velocity:** Maximum travel velocity (>0).

**Acceleration:** Acceleration (>0).

**Deceleration:** Deceleration (>0).

## Outputs

```
VAR_OUTPUT  
    Done           : BOOL;  
    Busy           : BOOL;  
    CommandAborted : BOOL;  
    Error          : BOOL;  
    ErrorID        : UDINT;  
END_VAR
```

**Done:** TRUE if a movement was successfully completed.

**Busy:** TRUE as soon as the function block is active. FALSE if it is in the default state. Only then can a further edge be accepted at the jog inputs.

**Active:** Indicates that the axis is moved via the jog function.

**CommandAborted:** TRUE if the operation was aborted from the outside, e.g. by calling [MC\_Stop](ms-xhelp:///?Id=beckhoff-bba4-4c3f-9dbd-4b986c3444cc).

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-1610-445d-9b44-15a5aa4e120c))

## Requirements

| Development environment | PLC libraries to include |
| --- | --- |
| TwinCAT 3.1.4024.11 | Tc3\_DriveMotionControl |

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
