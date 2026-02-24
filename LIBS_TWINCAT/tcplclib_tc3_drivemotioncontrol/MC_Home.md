# MC_Home

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-7ffe-4e9a-b17d-c6d5be097acd)
3. [Homing](ms-xhelp:///?Id=beckhoff-411f-4140-b5a6-80b6ffcafdd2)
4. MC\_Home

# MC\_Home

![38001806](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/8873654539__Web.png)

An axis reference run is carried out with the function block MC\_Home.

Referencing mode is set in the options with the parameter "ReferenceMode".

|  |  |
| --- | --- |
| 6471942 | The parameters involved may have to be set in the drive parameters. For the servo terminal the parameters can be found in the objects DMC Setting (0x8030) or DMC Features (0x8031). |

## Inputs

```
VAR_INPUT  
    Execute         : BOOL;   
    Position        : LREAL         := DEFAULT_HOME_POSITION;  
    HomingMode      : MC_HomingMode;  
    Options         : ST_HomingOptions;  
END_VAR
```

**Execute:** The command is executed with a rising edge.

**Position:** Absolute reference position to which the axis is set after homing. Alternatively, the constant DEFAULT\_HOME\_POSITION can be used here. In this case, the "Reference position for homing" specified in the TwinCAT System Manager is used.

|  |  |
| --- | --- |
| 58247484 | Since the reference position is generally set during the motion, the axis will not stop exactly at this position. The standstill position differs by the braking distance of the axis, although the calibration is nevertheless exact. |

**HomingMode:** Determines how the calibration is performed. (Type: [MC\_HomingMode](ms-xhelp:///?Id=beckhoff-5f21-459d-821b-03f6699ec70a))

* MC\_DefaultHoming  
  Executes the standard homing.
* MC\_Direct  
  Sets the axis position directly to Position without executing a movement.
* MC\_Block  
  Performs referencing to a mechanical end stop.
* MC\_ForceCalibration   
  Forces the state "Axis is calibrated". No movement takes place, and the position remains unchanged.
* MC\_ResetCalibration   
  Resets the calibration status of the axis. No movement takes place, and the position remains unchanged.

**Options:** Data structure containing additional parameters.

* SearchDirection:  
  Direction in which the referencing cam is to be searched
* SearchVelocity:  
  Velocity at which the referencing cam is to be searched
* SyncDirection:  
  Direction in which the falling edge of the referencing cam is searched after the referencing cam has been detected
* SyncVelocity:  
  Velocity at which the falling edge of the referencing cam is searched for after the referencing cam has been detected
* ReferenceMode:  
  Referencing mode (currently only ENCODERREFERENCEMODE\_CAMATDIGITALINPUT)
* Acceleration:  
  Acceleration for the reference run
* Deceleration:  
  Deceleration for the reference run

The signal of a referencing cam must be routed to a digital terminal input (HomingMode = MC\_DefaultHoming).

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

**Done:** TRUE when the axis has been calibrated and the movement is complete.

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the movement command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done", "CommandAborted" or "Error" is set.

**Active:** Currently not implemented - "Active" indicates that the command is running. If the command has been buffered, it may only become active after a running command has been terminated.

**CommandAborted:** TRUE if the command could not be executed completely.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-1610-445d-9b44-15a5aa4e120c))

**Note**

The referencing process has several phases. The following diagram illustrates the sequence after starting function block MC\_Home with the individual phases for the case HomingMode = MC\_DefaultHoming.

![54465313](/tcplclib_tc3_drivemotioncontrol/1033/Images/gif/70339211__en-US__Web.gif)

## Requirements

| Development environment | PLC libraries to include |
| --- | --- |
| TwinCAT 3.1.4024.11 | Tc3\_DriveMotionControl |

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
