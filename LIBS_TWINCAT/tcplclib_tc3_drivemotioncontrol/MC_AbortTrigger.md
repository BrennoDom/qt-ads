# MC_AbortTrigger

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-290a-4455-9df4-a3a3057c631c)
3. [Touch probe](ms-xhelp:///?Id=beckhoff-9933-44bf-8d87-e64eb2b07ba8)
4. MC\_AbortTrigger

# MC\_AbortTrigger

![23069209](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/8873650699__Web.png)

The function block MC\_AbortTrigger cancels a probe cycle started by MC\_TouchProbe. MC\_TouchProbe starts a probe cycle by activating a position latch in the drive hardware. The function block MC\_AbortTrigger can be used to terminate the procedure before the trigger signal has activated the position latch. If the measuring probe cycle has completed successfully, it is not necessary to call up this function block.

## Inputs

```
VAR_INPUT  
    Execute : BOOL;  
END_VAR
```

**Execute:** The command is executed with the positive edge and the external position latch is deactivated.

## Outputs

```
VAR_OUTPUT  
    Done    : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

**Done:** TRUE as soon as the measuring probe cycle has been successfully terminated.

**Busy:** TRUE as soon as the function block is active. FALSE if it is in the default state.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

## Inputs/outputs

```
VAR_IN_OUT  
    Axis         : AXIS_REF;  
    TriggerInput : TRIGGER_REF;   
END_VAR
```

**Axis:** Axis data structure (type: [ACHSE\_REF](ms-xhelp:///?Id=beckhoff-1610-445d-9b44-15a5aa4e120c))

**TriggerInput:** Data structure for describing the trigger source (type: [TRIGGER\_REF](ms-xhelp:///?Id=beckhoff-a3ce-428b-9f65-4e3014e8a95b)). This data structure must be parameterized before the function block is called for the first time.

## Requirements

| Development environment | PLC libraries to include |
| --- | --- |
| TwinCAT 3.1.4024.11 | Tc3\_DriveMotionControl |

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
