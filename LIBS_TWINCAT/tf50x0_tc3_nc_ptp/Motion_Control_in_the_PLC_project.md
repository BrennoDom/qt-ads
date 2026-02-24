# Motion Control in the PLC project

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Motion Control in the PLC project

On this page you will find out how to implement motion control from the PLC project in accordance with PLCopen.

## Opening the "Add Library" dialog

In order to be able to use motion control in accordance with **PLCopen**, you must add a reference to your PLC project.

![60503138](/tf50x0_tc3_nc_ptp/1033/Images/png/2551654027__Web.png)

:   1. Create a new PLC project.
:   2. Right-click the **References** folder [1] in the PLC project to which you wish to add a reference.
:   A context menu opens.
:   3. Click the entry **Add library…** [2] in the context menu.

:   The **Add Library…** dialog opens.

## Selecting a library

Tc2\_MC2 is the default library

* for motion control in accordance with PLCopen,
* PTP motion (Point to Point Motion) and
* axis management.

![7657338](/tf50x0_tc3_nc_ptp/1033/Images/png/2551583627__Web.png)

:   The **Add Library** dialog is open.

:   1. Select the library that you wish to add to the PLC project.
:   2. To do this, switch the **Add Library** dialog to the **Category View** [1] if it is in a different view.
:   3. Expand the **Motion** subtree [2].
:   4. Expand the **PTP** subtree [3].
:   5. Select the **Tc2\_MC2** library [4].
:   6. Confirm your selection with the **OK** button [5].

:   A reference to the **Tc2\_MC2** library [4] is created in the PLC project to which you wish to add this reference.

## MC axis variable

![1807185](/tf50x0_tc3_nc_ptp/1033/Images/png/9007202152039947__Web.png)

The PLC axis variable `MAIN.axis` has the data type `AXIS_REF`.

The data type `AXIS_REF:`

* contains information about an axis,
* is an interface between the PLC and the NC and
* is given to the MC function blocks as a reference to an axis.

|  |  |
| --- | --- |
| 16264673 | Refreshing the status data structure in `AXIS_REF`  The status data structure `Status` of the type `ST_AxisStatus` contains additional or prepared status and diagnostic information about an axis. The structure is not cyclically refreshed, but has to be updated by the PLC program  Calling the `ReadStatus()` action from `AXIS_REF` updates the status data structure and should be done once at the beginning of each PLC cycle.  The status information does not change within a PLC cycle. After calling `ReadStatus(),` the current status information can be accessed in `AXIS_REF` within the entire PLC program.  The nature of the status data structure is purely informative. Therefore, its use is not mandatory. |

```
PROGRAM MAIN  
VAR  
    axis: AXIS_REF;  
END_VAR
```

```
axis.ReadStatus();
```

## Simulation axis

![12164329](/tf50x0_tc3_nc_ptp/1033/Images/png/2833834251__Web.png)

|  |  |
| --- | --- |
| [1] | The local MC axis variable `MAIN.axis` is connected to the NC axis for movement with MC function blocks. |
| [2] | The simulation axis **Standard (Mapping via Encoder and Drive)** is set as the NC axis under **Axis Type**. |
| [3] | The entry **Link To I/O...** remains empty for a simulation axis. |

## MC\_Power

![42370099](/tf50x0_tc3_nc_ptp/1033/Images/png/8354798859__Web.png)

The function block **MC\_Power** switches the software enabling of an axis.

## MC\_Power: Inputs (excerpt)

|  |  |
| --- | --- |
| `Enable: BOOL;` | Sets the general software and controller enabling for an axis. Enabled if `Enable = TRUE`. Corresponds to the **Controller** checkbox in the **Set Enabling** dialog. Enabled if the checkbox is checked. |
| `Enable_Positive: BOOL;` | Sets the feed enabling for an axis for the positive travel direction. Enabled if `Enable_Positive = TRUE`. Corresponds to the **Feed Fw** checkbox in the **Set Enabling** dialog. Enabled if the checkbox is checked. |
| `Enable_Negative: BOOL;` | Sets the feed enabling for an axis for the negative travel direction. Enabled if `Enable_Negative = TRUE`. Corresponds to the **Feed Bw** checkbox in the **Set Enabling** dialog. Enabled if the checkbox is checked. |
| `Override: LREAL;` | Influences the velocity of all travel commands as a percentage. It is `0 ≤ Override ≤ 100.0`. |

## MC\_MoveAbsolute

![45786577](/tf50x0_tc3_nc_ptp/1033/Images/png/8354796939__Web.png)

* The function block **MC\_MoveAbsolute** starts the positioning to an absolute target position and monitors the axis movement over the entire travel path.

## MC\_MoveAbsolute: Inputs (excerpt)

|  |  |
| --- | --- |
| `Execute: BOOL;` | A rising edge at this input executes the command. |
| `Position: LREAL;` | Absolute target position to be used for positioning. |
| `Velocity: LREAL;` | Maximum travel velocity. A positive value. |

## Sample program for moving to a target position

The **MAIN** program shows a short example with which a target position is to be moved to.

## `PROGRAM MAIN`: Declaration

```
PROGRAM MAIN  
VAR  
    axis: AXIS_REF;  
    fbAxisPower: MC_Power;  
    fbAxisMoveAbsolute: MC_MoveAbsolute;  
    bEnable: BOOL := FALSE;  
    fOverride: LREAL := 100;  
    bMove: BOOL := FALSE;  
    fTargetPosition: LREAL := 90;  
    fTargetVelocity: LREAL := 5;  
END_VAR
```

## `PROGRAM MAIN`: Implementation

```
axis.ReadStatus();  
  
fbAxisPower(  
    Axis:= axis,  
    Enable:= bEnable,  
    Enable_Positive:= bEnable,  
    Enable_Negative:= bEnable,  
    Override:= fOverride,  
    BufferMode:= ,  
    Options:= ,  
    Status=> ,  
    Busy=> ,  
    Active=> ,  
    Error=> ,  
    ErrorID=> );  
  
fbAxisMoveAbsolute(  
    Axis:= axis,  
    Execute:= bMove,  
    Position:= fTargetPosition,  
    Velocity:= fTargetVelocity,  
    Acceleration:= ,  
    Deceleration:= ,  
    Jerk:= ,  
    BufferMode:= ,  
    Options:= ,  
    Done=> ,  
    Busy=> ,  
    Active=> ,  
    CommandAborted=> ,  
    Error=> ,  
    ErrorID=> );
```

## MAIN: Local variables

|  |  |
| --- | --- |
| `axis: AXIS_REF;` | Instance of an MC axis. This instance can be linked with an NC axis. |
| `fbAxisPower: MC_Power;` | Instance variable of the MC\_Power function block. |
| `fbAxisMoveAbsolute: MC_MoveAbsolute;` | Instance variable of the MC\_MoveAbsolute function block. |
| `bEnable: BOOL := FALSE;` | Switches the inputs `Enable`, `Enable_Positive` and `Enable_Negative` of the MC\_Power function block. |
| `fOverride: LREAL := 100;` | Override value for the `Override` input of the MC\_Power function block. |
| `bMove: BOOL := FALSE;` | Positive edge switches the `Execute` input of the MC\_MoveAbsolute function block. |
| `fTargetPosition: LREAL := 90;` | Target position value for the `Position` input of the MC\_MoveAbsolute function block. |
| `fTargetVelocity: LREAL := 5;` | Target velocity value for the `Velocity` input of the MC\_MoveAbsolute function block. |

## Further information

* [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
* [PLC](ms-xhelp:///?Id=beckhoff-1dff-44fb-9ec7-21738d9dc15a)
