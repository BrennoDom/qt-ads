# MC_Home

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Homing](ms-xhelp:///?Id=beckhoff-e209-4d1e-bf9f-b5f77c96c326)
4. MC\_Home

# MC\_Home

![23099752](/tcplclib_tc2_mc2/1033/Images/png/9007199325077003__Web.png)

An axis reference run is carried out with the function block MC\_Home.

The referencing mode is set in the TwinCAT System Manager with the encoder parameter "Reference Mode". Depending on the connected encoder system, different sequences are possible (see also Reference mode for incremental encoders in the TwinCAT 3 ADS Interface NC documentation).

## Inputs

```
VAR_INPUT  
    Execute         : BOOL;   
    Position        : LREAL         := DEFAULT_HOME_POSITION;  
    HomingMode      : MC_HomingMode;  
    BufferMode      : MC_BufferMode;   
    Options         : ST_HomingOptions;  
    bCalibrationCam : BOOL;   
END_VAR
```

**Execute:** The command is executed with a positive edge.

**Position:** Absolute reference position to which the axis is set after homing. Alternatively, the constant DEFAULT\_HOME\_POSITION can be used here. In this case, the "Reference position for homing" specified in the TwinCAT System Manager is used.

|  |  |
| --- | --- |
| 6571180 | Since the reference position is generally set during the motion, the axis will not stop exactly at this position. The standstill position differs by the braking distance of the axis, although the calibration is nevertheless exact. |

**HomingMode:** Determines how the calibration is performed. (Type: [MC\_HomingMode](ms-xhelp:///?Id=beckhoff-d55a-4049-97de-43ddf7b08f4e))

* MC\_DefaultHoming  
  Executes the standard homing.
* MC\_Direct  
  Sets the axis position directly to Position without executing a movement.
* MC\_ForceCalibration   
  Forces the state "Axis is calibrated". No movement takes place, and the position remains unchanged.
* MC\_ResetCalibration   
  Resets the calibration status of the axis. No movement takes place, and the position remains unchanged.

**BufferMode:** Currently not implemented.

**Options:** Data structure containing additional, rarely used parameters. The input can normally remain open.

* **ClearPositionLag:** Only works in "MC\_Direct" mode. Can optionally be used to set the set and actual positions to the same value. In this case the lag error is cleared.

**bCalibrationCam:** Reflects the signal of a reference cam that can be applied to the controller via a digital input.

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

**Done:** TRUE when the axis has been calibrated and the movement is complete.

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the movement command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done", "CommandAborted" or "Error" is set.

**Active:** Currently not implemented - "Active" indicates that the command is running. If the command has been buffered, it may only become active after a running command has been terminated.

**CommandAborted:** TRUE if the command could not be executed completely.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Inputs/outputs

```
VAR_IN_OUT  
    Axis     : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

**Note**

The referencing process has several phases. The calibration state is signaled in the cyclic interface of the axis (Axis.NcToPlc.HomingState). The following diagram shows the process flow after starting function block MC\_Home with the individual phases.

If an axis is to be referenced without reference cam, i.e. only based on the sync pulse of the encoder, the reference cam can be simulated via the PLC program. The "bCalibrationCam" signal is initially activated and then canceled, if [Axis.NcToPlc.HomingState](ms-xhelp:///?Id=beckhoff-00d5-42b3-9ded-9a9f62e7df27) is equal or greater 4.

![59140623](/tcplclib_tc2_mc2/1033/Images/gif/70339211__en-US__Web.gif)

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
