# MC_Jog

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Manual motion](ms-xhelp:///?Id=beckhoff-0ae9-40c8-ad89-f27e73d5d6d9)
4. MC\_Jog

# MC\_Jog

![62503562](/tcplclib_tc2_mc2/1033/Images/png/9007199325083403__Web.png)

The function block MC\_Jog enables an axis to be moved via manual keys. The key signal can be linked directly with the "JogForward" and "JogBackwards" inputs. The required operating mode is specified via the "mode" input. An inching mode for moving the axis by a specified distance whenever the key is pressed is also available. The velocity and dynamics of the motion can be specified depending on the operation mode.

## Inputs

```
VAR_INPUT  
    JogForward   : BOOL;  
    JogBackwards : BOOL;  
    Mode         : E_JogMode;  
    Position     : LREAL;  
    Velocity     : LREAL;  
    Acceleration : LREAL;  
    Deceleration : LREAL;  
    Jerk         : LREAL;  
END_VAR
```

**JogForward:** The command is executed with a positive edge, and the axis is moved in positive direction of travel. Depending on the operating mode (see "Mode" input), the axis moves as long as the signal remains TRUE, or it stops automatically after a specified distance. During the motion no further signal edges are accepted (this includes the "JogBackwards" input). If a simultaneous signal edge occurs at the inputs "JogForward" and "JogBackwards", "JogForward" has priority.

**JogBackwards:** The command is executed with a positive edge, and the axis is moved in negative direction of travel. "JogForward" and "JogBackwards" should be triggered alternatively, although they are also mutually locked internally.

**Mode:** Determines the operating mode in which the manual function is executed. (Type: [E\_JogMode](ms-xhelp:///?Id=beckhoff-cb5b-4cd8-98ee-d1e45533b14c))

* MC\_JOGMODE\_STANDARD\_SLOWThe axis moves as long as the signal at one of the jog inputs is TRUE. The "low velocity for manual functions" specified in the TwinCAT System Manager and standard dynamics are used. In this operation mode the position, velocity and dynamics data specified in the function block have no effect.
* MC\_JOGMODE\_STANDARD\_FASTThe axis moves as long as the signal at one of the jog inputs is TRUE. The "high velocity for manual functions" specified in the TwinCAT System Manager and standard dynamics are used. In this operation mode the position, velocity and dynamics data specified in the function block have no effect.
* MC\_JOGMODE\_CONTINOUSThe axis moves as long as the signal at one of the jog inputs is TRUE. The velocity and dynamics data specified by the user are used. The position has no effect.
* MC\_JOGMODE\_INCHINGThe axis is moved with a positive edge at one of the jog inputs by a certain distance, which is defined via the "Position" input. The axis stops automatically, irrespective of the state of the jog inputs. A new movement step is only executed once a further positive edge is encountered. With each start the velocity and dynamics data specified by the user are used.
* MC\_JOGMODE\_INCHING\_MODULO  
  The axis is moved with a positive edge at one of the jog inputs by a certain distance, which is defined via the "Position" input. The axis position will snap to an integer multiple of the position parameter. The axis stops automatically, irrespective of the state of the jog inputs. A new movement step is only executed once a further positive edge is encountered. With each start the velocity and dynamics data specified by the user are used.

**Position:** Relative distance for movements in MC\_JOGMODE\_INCHING operation mode.

**Velocity:** Maximum travel velocity (>0).

**Acceleration:** Acceleration (≥0). If the value is 0, the standard acceleration from the axis configuration in the System Manager is used.

**Deceleration:** Deceleration (≥0). If the value is 0, the standard deceleration from the axis configuration in the System Manager is used.

**Jerk:** Jerk (≥0). At a value of 0, the standard jerk from the axis configuration in the System Manager is applied.

|  |  |
| --- | --- |
| 25661150 | The parameters "Position", "Velocity", "Acceleration", "Deceleration" and "Jerk" are not used in the operating modes MC\_JOGMODE\_STANDARD\_SLOW and MC\_JOGMODE\_STANDARD\_FAST and can remain unassigned. |

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

**CommandAborted:** TRUE if the operation was aborted from the outside, e.g. by calling [MC\_Stop](ms-xhelp:///?Id=beckhoff-8fd4-4e57-a689-0508c190c4a6).

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

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
