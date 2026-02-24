# MC_Stop

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Point to point motion](ms-xhelp:///?Id=beckhoff-4120-4cf1-ab1b-35a13a0a1cec)
4. MC\_Stop

# MC\_Stop

![45067606](/tcplclib_tc2_mc2/1033/Images/png/9007199325057803__Web.png)

MC\_Stop stops an axis with a defined braking ramp and locks it against other motion commands. The function block is therefore suitable for stops in special situations, in which further axis movements are to be prevented.

At the same time the axis is blocked for other motion commands. The axis can only be restarted once the Execute signal has been set to FALSE after the axis has stopped. A few cycles are required to release the axis after a negative edge of Execute. During this phase the "Busy" output remains TRUE, and the function block has to be called until "Busy" becomes FALSE.

The locking of the axis is canceled with an [MC\_Reset](ms-xhelp:///?Id=beckhoff-fdf9-4bca-9932-eec2e9e0399e).

Alternatively, the axis can be stopped with [MC\_Halt](ms-xhelp:///?Id=beckhoff-5810-4bd8-af0f-d6ee63da26d7) without locking. MC\_Halt is preferable for normal movement sequences.

Motion commands can be applied to coupled slave axes, if this option was explicitly activated in the axis parameters. A motion command such as MC\_Stop then automatically leads to decoupling of the axis, after which the command is executed.

## Inputs

```
VAR_INPUT  
    Execute      : BOOL;   
    Deceleration : LREAL;   
    Jerk         : LREAL;  
    Options      : ST_MoveOptions;   
END_VAR
```

**Execute:** The command is executed with a positive edge. The axis is locked during the stop. The axis can only be restarted once the Execute signal has been set to FALSE after the axis has stopped.

**Deceleration:** Deceleration   
If the value is ≤ 0, the deceleration parameterized with the last Move command is used. For safety reasons MC\_Stop and MC\_Halt cannot be executed with weaker dynamics than the currently active motion command. The parameterization is adjusted automatically, if necessary.

**Jerk:** Jerk   
If the value is ≤ 0, the jerk parameterized with the last Move command is used. For safety reasons MC\_Stop and MC\_Halt cannot be executed with weaker dynamics than the currently active motion command. The parameterization is adjusted automatically, if necessary.

**Options:** Data structure ([ST\_MoveOptions](ms-xhelp:///?Id=beckhoff-d19a-49e9-9f59-b682be3472f8)), which contains additional, rarely required parameters. The input can normally remain open.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Outputs

```
VAR_OUTPUT  
    Done           : BOOL;  
    Busy           : BOOL;  
    Active         : BOOL;  
    CommandAborted : BOOL;  
    Error          : BOOL;  
    ErrorID        : UDINT;  
END_VAR
```

**Done:** TRUE if the axis has been stopped and is stationary.

**Busy:** TRUE as soon as the command is started with Execute and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. "Busy" remains TRUE as long as the axis is locked. The axis is only unlocked and "Busy" becomes FALSE when Execute is set to FALSE.

**Active:** Indicates that the function block controls the axis. Remains TRUE as long as the axis is locked. The axis is only unlocked and "Active" becomes FALSE when Execute is set to FALSE.

**CommandAborted:** TRUE if the command could not be executed completely.

**Error:** TRUE, if an error occurs

**ErrorID:** If the error output is set, this parameter supplies the error number.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
