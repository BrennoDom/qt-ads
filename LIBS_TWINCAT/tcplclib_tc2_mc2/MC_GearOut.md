# MC_GearOut

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Axis coupling](ms-xhelp:///?Id=beckhoff-7801-4505-8925-dac3e0bfa5d7)
4. MC\_GearOut

# MC\_GearOut

![50714740](/tcplclib_tc2_mc2/1033/Images/png/9007199325093003__Web.png)

The function block MC\_GearOut deactivates a master-slave coupling.

![53779479](assets/img/safety-logos/SmallWarningYellow.gif)WARNING

No standstill of the axis due to decoupling

When a slave axis is uncoupled during the movement, it is not stopped automatically but reaches a constant velocity at which it continues to travel infinitely.

You can stop the axis with the function block [MC\_Halt](ms-xhelp:///?Id=beckhoff-5810-4bd8-af0f-d6ee63da26d7) or [MC\_Stop](ms-xhelp:///?Id=beckhoff-8fd4-4e57-a689-0508c190c4a6).

|  |  |
| --- | --- |
| 14253264 | Setpoint generator type  If the setpoint generator type of the axis is set to "7 phases (optimized)", the slave axis assumes an acceleration-free state after decoupling and continues to move with the resulting constant velocity. There is no positioning based on the master travel path calculated with the coupling factor. Instead, the behavior matches the behavior after a MC\_MoveVelocity command. In TwinCAT 2.10, the setpoint generator type can be selected by the user. From TwinCAT 2.11, the setpoint generator type is set to "7 phases (optimized)". The behavior described here is the result of a project update from TwinCAT 2.10 to TwinCAT 2.11. Depending on the circumstances, an update of existing applications to version 2.11 may necessitate an adaptation of the PLC program. |

## Inputs

```
VAR_INPUT  
    Execute : BOOL;  
    Options : ST_GearOutOptions;  
END_VAR
```

**Execute:** The command is executed with a positive edge.

**Options:** Currently not implemented

## Outputs

```
VAR_OUTPUT  
    Done    : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

**Done:** TRUE if the axis has been successfully decoupled.

**Busy:** TRUE as soon as the command is started and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done" or "Error" is set.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

## Inputs/outputs

```
VAR_IN_OUT  
    Slave : AXIS_REF;  
END_VAR
```

**Slave:** Axis data structure of the Slave.

The axis data structure of type [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) addresses an axis uniquely within the system. Among other parameters it contains the current axis status, including position, velocity or error status.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
