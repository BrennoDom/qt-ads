# MC_TouchProbe

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-290a-4455-9df4-a3a3057c631c)
3. [Touch probe](ms-xhelp:///?Id=beckhoff-9933-44bf-8d87-e64eb2b07ba8)
4. MC\_TouchProbe

# MC\_TouchProbe

![6296289](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/9007208128414731__Web.png)

The function block MC\_TouchProbe records an axis position at the time of a digital signal (measuring probe function). The position is captured via an external hardware latch and is therefore highly accurate and independent of the cycle time. The function block controls this mechanism and determines the externally recorded position.

|  |  |
| --- | --- |
| 56666602 | The parameters involved may have to be set in the drive parameters. For the servo terminal the parameters can be found in the objects DMC Setting (0x8030) or DMC Features (0x8031). |

|  |  |
| --- | --- |
| 40237373 | After a measuring probe cycle has been initiated by a rising edge on the "Execute" input, this is only terminated if the outputs "Done", "Error" or" CommandAborted" become TRUE. If the operation is to be aborted in the meantime, the function block [MC\_AbortTrigger](ms-xhelp:///?Id=beckhoff-854a-44a0-beb7-e0653bc50967) must be called with the same [TriggerInput](ms-xhelp:///?Id=beckhoff-a3ce-428b-9f65-4e3014e8a95b) data structure. Otherwise no new cycle can be initiated. |

## Signal curve

![26592044](/tcplclib_tc3_drivemotioncontrol/1033/Images/gif/3117719435__Web.gif)

## Inputs

```
VAR_INPUT  
    Execute       : BOOL;  
    WindowOnly    : BOOL;  
    FirstPosition : LREAL;  
    LastPosition  : LREAL;  
END_VAR
```

**Execute:** The command is executed with a rising edge, and the external position latch is activated.

**WindowOnly:** If WindowOnly = TRUE, only one position within the window between "FirstPosition" and "LastPosition" is captured. Positions outside the window are rejected and the external position latch is automatically newly activated. Only if the recorded position lies inside the window, "Done" becomes TRUE. The recording window can be interpreted in terms of absolute or modulo values. For this purpose, the "ModuloPositions" flag must be set accordingly in the [TriggerInput](ms-xhelp:///?Id=beckhoff-a3ce-428b-9f65-4e3014e8a95b) data structure. In the case of absolute value positions there is exactly one window. With modulo positions, the window is repeated within the modulo cycle defined in the axis parameters (e.g. 0 to 360°).

**FirstPosition:** Initial position of the recording window, if "WindowOnly" is TRUE. This position can be interpreted as an absolute or modulo value. For this purpose, the "ModuloPositions" flag must be set accordingly in the [TriggerInput](ms-xhelp:///?Id=beckhoff-a3ce-428b-9f65-4e3014e8a95b) data structure.

**LastPosition:** End position of the recording window, if "WindowOnly" is TRUE. This position can be interpreted as an absolute or modulo value. For this purpose, the "ModuloPositions" flag must be set accordingly in the [TriggerInput](ms-xhelp:///?Id=beckhoff-a3ce-428b-9f65-4e3014e8a95b) data structure.

A. FirstPosition < LastPosition

B. FirstPosition > LastPosition

FirstPosition

LastPosition

LastPosition

FirstPosition

FirstPosition

LastPosition

LastPosition

FirstPosition

examples of windows, where trigger events are accepted (for modulo axes)


-

+


-

+


-

+


-

+

0

0

0

0

 
accepted 

 
accepted 

 
accepted 

 
accepted 

 
accepted

## Outputs

```
VAR_OUTPUT  
    Done             : BOOL;  
    Busy             : BOOL;  
    CommandAborted   : BOOL;  
    Error            : BOOL;  
    ErrorId          : UDINT;  
    RecordedPosition : LREAL;  
    RecordedData     : MC_TouchProbeRecordedData;   
END_VAR 
```

**Done:** TRUE if an axis position was successfully detected. The position is sent to the output "RecordedPosition".

**Busy:** TRUE as soon as the function block is active. FALSE if it is in the default state.

**CommandAborted:** Becomes TRUE if the process is interrupted by an external event, e.g. by the call up of [MC\_AbortTrigger](ms-xhelp:///?Id=beckhoff-854a-44a0-beb7-e0653bc50967).

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

**RecordedPosition:** Axis position recorded at the point in time of the trigger signal

**RecordedData:** Data structure with complementary information relating to the logged axis position at the time of the trigger signal

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
