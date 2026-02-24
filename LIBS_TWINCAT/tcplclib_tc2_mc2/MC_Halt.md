# MC_Halt

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Point to point motion](ms-xhelp:///?Id=beckhoff-4120-4cf1-ab1b-35a13a0a1cec)
4. MC\_Halt

# MC\_Halt

![19920592](/tcplclib_tc2_mc2/1033/Images/png/9007199325054603__Web.png)

MC\_Halt stops an axis with a defined braking ramp.

In contrast to [MC\_Stop](ms-xhelp:///?Id=beckhoff-8fd4-4e57-a689-0508c190c4a6), the axis is not locked against further movement commands. The axis can therefore be restarted through a further command during the braking ramp or after it has come to a halt.

Motion commands can be applied to coupled slave axes, if this option was explicitly activated in the axis parameters. A motion command such as MC\_Halt then automatically leads to decoupling of the axis, after which the command is executed. In this case the only available BufferMode is "Aborting".

## Inputs

```
VAR_INPUT  
    Execute      : BOOL;   
    Deceleration : LREAL;   
    Jerk         : LREAL;  
    BufferMode   : MC_BufferMode;   
    Options      : ST_MoveOptions;   
END_VAR
```

**Execute:** The command is executed with a positive edge.

**Deceleration:** Deceleration   
If the value is ≤ 0, the deceleration parameterized with the last Move command is used. For safety reasons MC\_Halt and [MC\_Stop](ms-xhelp:///?Id=beckhoff-8fd4-4e57-a689-0508c190c4a6) cannot be executed with weaker dynamics than the currently active travel command. The parameterization is adjusted automatically, if necessary.

**Jerk:** Jerk   
If the value is ≤ 0, the jerk parameterized with the last Move command is used.  
For safety reasons MC\_Halt and [MC\_Stop](ms-xhelp:///?Id=beckhoff-8fd4-4e57-a689-0508c190c4a6) cannot be executed with weaker dynamics than the currently active travel command. The parameterization is adjusted automatically, if necessary.

**BufferMode:** Is evaluated if the axis already executes another command (see [MC\_BufferMode](ms-xhelp:///?Id=beckhoff-53fe-47a4-8963-2af9ad8ff58b)). MC\_Halt becomes active after the current command or aborts it. Transition conditions from the current to the next command are also determined by the BufferMode. If the command is applied to a coupled slave axis, the only available BufferMode is "Aborting".  
Special characteristics of MC\_Halt: The BufferMode "Buffered" has no effect, if the command is executed when the system is at a standstill. The blending modes "MC\_BlendingNext" and "MC\_BlendingLow" do not change the last target position, although they can result in a change in dynamics (deceleration) of the stop ramp. The modes "MC\_BlendingPrevious" and "MC\_BlendingHigh" extend the travel to the original target position. The stop ramp is only initiated when this position is reached (defined braking point).

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

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done", "CommandAborted" or "Error" is set.

**Active:** Indicates that the command is executed. If the command was buffered, it becomes active once a running command is completed.

**CommandAborted:** Becomes TRUE, if the command could not be fully executed. The running command may have been followed by a Move command.

**Error:** TRUE, if an error occurs.

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
