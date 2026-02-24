# MC_TouchProbe

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Touch probe](ms-xhelp:///?Id=beckhoff-25dd-4c8d-a7d8-31a337a1e535)
4. MC\_TouchProbe

# MC\_TouchProbe

![51053199](/tcplclib_tc2_mc2/1033/Images/png/70227211__en-US__Web.png)

The function block MC\_TouchProbe records an axis position at the time of a digital signal (measuring probe function). The position is usually not recorded directly in the PLC environment, but via an external hardware latch and is therefore highly accurate and independent of the cycle time. The function block controls this mechanism and determines the externally recorded position.

|  |  |
| --- | --- |
| 56825610 | The function block was extended, compared to TwinCAT 2. It has the same functionality as the existing function block MC\_TouchProbe\_V2. |

## Requirements

The prerequisite for the position detection is suitable encoder hardware that is able to latch the recorded position. Support is offered for:

* SERCOS drives  
  In contrast to MC\_TouchProbe, the drive must be configured with an extended interface, in which the parameters S 0 0405 and S-0 0406 are included in the process image.
* EtherCAT SoE drives (E.g. AX5000)  
  In contrast to MC\_TouchProbe, the drive must be configured with an extended interface, in which the parameters S 0 0405 and S-0 0406 are included in the process image.
* EtherCAT CoE drives  
  The drive must be configured with the parameter 0x60B9 (touch probe status) in the process image.
* EL5101, KL5101  
  Latching of the C track and the digital input is possible. This hardware can only record one signal or edge at a time. Continuous mode is not supported.

The digital trigger signal is wired into this hardware and, independently of the PLC cycle, triggers the recording of the current axis position.

These end devices have to be configured to some extent so that a position detection is possible. Beckhoff EtherCAT drives can be configured with the System Manager. Note that the probe unit has to be configured with the "Extended NC Probe Unit" interface.

## Note

After a measuring probe cycle has been initiated by a positive edge on the "Execute" input, this is only terminated if the outputs "Done", "Error" or" CommandAborted" become TRUE. If the operation is to be aborted in the meantime, the function block [MC\_AbortTrigger](ms-xhelp:///?Id=beckhoff-a572-4f0b-a6c1-11a301b675b9) must be called with the same [TriggerInput](ms-xhelp:///?Id=beckhoff-4fad-4a66-9893-e6ef0842d838) data structure. Otherwise no new cycle can be initiated.

## Signal curve

![41668450](/tcplclib_tc2_mc2/1033/Images/gif/3117719435__Web.gif)

## Inputs

```
VAR_INPUT  
    Execute       : BOOL;  
    WindowOnly    : BOOL;  
    FirstPosition : LREAL;  
    LastPosition  : LREAL;  
END_VAR
```

**Execute:** The command is executed with a positive edge, and the external position latch is activated.

**WindowOnly:** If WindowOnly = TRUE, only one position within the window between "FirstPosition" and "LastPosition" is captured. Positions outside the window are rejected and the external position latch is automatically newly activated. Only if the recorded position lies inside the window, "Done" becomes TRUE. The recording window can be interpreted in terms of absolute or modulo values. For this purpose, the "ModuloPositions" flag must be set accordingly in the [TriggerInput](ms-xhelp:///?Id=beckhoff-4fad-4a66-9893-e6ef0842d838) data structure. In the case of absolute value positions there is exactly one window. With modulo positions, the window is repeated within the modulo cycle defined in the axis parameters (e.g. 0 to 360 degrees).

**FirstPosition:** Initial position of the recording window, if "WindowOnly" is TRUE. This position can be interpreted as an absolute or modulo value. For this purpose, the "ModuloPositions" flag must be set accordingly in the [TriggerInput](ms-xhelp:///?Id=beckhoff-4fad-4a66-9893-e6ef0842d838) data structure.

**LastPosition:** Final position of the recording window, if "WindowOnly" is TRUE. This position can be interpreted as an absolute or modulo value. For this purpose, the "ModuloPositions" flag must be set accordingly in the [TriggerInput](ms-xhelp:///?Id=beckhoff-4fad-4a66-9893-e6ef0842d838) data structure.

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

**CommandAborted:** Becomes TRUE if the process is interrupted by an external event, e.g. by the call up of [MC\_AbortTrigger](ms-xhelp:///?Id=beckhoff-a572-4f0b-a6c1-11a301b675b9).

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

**Axis:** Axis data structure (type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

**TriggerInput:** Data structure for describing the trigger source (type: [TRIGGER\_REF](ms-xhelp:///?Id=beckhoff-4fad-4a66-9893-e6ef0842d838)). This data structure must be parameterized before the function block is called for the first time.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
