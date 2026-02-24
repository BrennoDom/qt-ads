# MC_Home_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_Home\_BkPlcMc (from V3.0)

# MC\_Home\_BkPlcMc (from V3.0)

![36308794](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854717707__Web.gif)

This function block starts and monitors the homing of an axis.

```
VAR_INPUT  
    Execute:        BOOL;  
    Position:       LREAL;  
    HomingMode:     MC_HomingMode_BkPlcMc;  
    CalibrationCam: BOOL;  
    BufferMode:     MC_BufferMode_BkPlcMc:=Aborting_BkPlcMc;    (ab/from V3.0.8)  
END_VAR
```

```
VAR_OUTPUT  
    Busy:           BOOL;  
    Done:           BOOL;  
    CommandAborted: BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: The homing is initiated by a rising edge at this input.

**Position**: [mm] The reference position.

**HomingMode**: Specifies the [method](ms-xhelp:///?Id=beckhoff-9007-49dc-a035-f71f1e0e29da) to be used.

**CalibrationCam**: This can be used for direct transfer of the referencing index (cam).

**BufferMode**: reserved. This input is provided in preparation for a future build. It should currently either not be assigned or assigned the constant Aborting\_BkPlcMc. (from V3.0.8)

**Busy**: Indicates that a command is being processed.

**Done**: Successful processing of the homing is indicated here.

**CommandAborted**: Abortion of homing is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

On a rising edge at **Execute**, the function block examines the transferred axis interface. A number of problems can be detected and reported during this process:

* Homing can only be started from a stationary condition without errors. If that is not the case, the function block will react by asserting **Error** with **ErrorID**:=dwTcHydErrCdNotStartable or with the error code that is passed to it.
* If the axis is already in a fault state, or if it is in the process of carrying out a stop operation, it responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.
* If one of the velocities stated in the axis parameters is too small (less than 1% of the reference velocity) the function block responds with **Error** and **ErrorID**:=dwTcHydErrCdSetVelo.

Homing begins if these checks are carried out without problems. The exact sequence is specified by [HomingMode](ms-xhelp:///?Id=beckhoff-9007-49dc-a035-f71f1e0e29da). If the movement algorithm reports an error code while homing is being executed, the function block responds with **Error** and **ErrorID**:=the movement algorithm's error code. If completion of homing is prevented by the activity of another function block, the function block responds with **CommandAborted**. Successful completion of homing is reported with **Done**.

A falling edge at **Execute** clears all the pending output signals. If, while homing is still active, **Execute** is set to FALSE, execution of homing that had started continues unaffected. The signals provided at the end of the movement (**Error**, **ErrorID, CommandAborted**, **Done**) are made available for one cycle.

Note fEnc\_DefaultHomePosition in pStAxParams is provided for circumstances in which the application does not itself specify a reference position and a value saved with the machine data is to be loaded for use instead. If different values are required, depending on the situation, use should be made of fCustomerData[] in pStAxParams.

If iTcMc\_EncoderSim is set as encoder type, the mode MC\_Direct\_BkPlcMc takes effect, irrespective of **HomingMode** and [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).stAxParams.nEnc\_HomingType.

## MC\_DefaultHomingMode\_BkPlcMc

The referencing method is not specified by the application, but through [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).stAxParams.nEnc\_HomingType. The following rules apply:

| nEnc\_HomingType | MC\_HomingMode\_BkPlcMc |
| --- | --- |
| iTcMc\_HomingOnBlock | MC\_Block\_BkPlcMc |
| iTcMc\_HomingOnIndex | MC\_AbsSwitch\_BkPlcMc |
| iTcMc\_HomingOnSync | MC\_RefPulse\_BkPlcMc |
| iTcMc\_HomingOnExec | MC\_Direct\_BkPlcMc |

## MC\_AbsSwitch\_BkPlcMc

The axis is moved with [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).stAxParams.fEnc\_RefIndexVelo in the direction specified by bEnc\_RefIndexPositive. The axis stops if **CalibrationCam** becomes TRUE or if the reference cam (bit 5, dwTcHydDcDwRefIndex) is detected in [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).stAxRtData.nDeCtrlDWord. The axis is then moved with fEnc\_RefSyncVelo in the direction specified by bEnc\_RefSyncPositive, until the reference cam is exited. The actual value for the axis is set to the value of the reference position.

## MC\_LimitSwitch\_BkPlcMc

Not currently supported.

## MC\_RefPulse\_BkPlcMc

The axis is moved with [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).stAxParams.fEnc\_RefIndexVelo in the direction specified by bEnc\_RefIndexPositive. The axis stops if **CalibrationCam** becomes TRUE or if the reference cam (bit 5, dwTcHydDcDwRefIndex) is detected in [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).stAxRtData.nDeCtrlDWord. The axis is then moved with fEnc\_RefSyncVelo in the direction specified by bEnc\_RefSyncPositive, until the reference cam is exited. The encoder's hardware latch is then activated, and the axis is moved on until the latch becomes valid. After the axis has stopped, the actual value for the axis is set to a value that is calculated from the reference position and from the distance covered since the encoder's sync pulse was detected.

## MC\_Direct\_BkPlcMc

The actual value of the axis is immediately set to the value of the reference position.

## MC\_Absolute\_BkPlcMc

Not currently supported.

## MC\_Block\_BkPlcMc

The axis is moved with [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).stAxParams.fEnc\_RefIndexVelo in the direction specified by bEnc\_RefIndexPositive. If no movement is detected over a period of 2 seconds, the fixed stop (block) is considered to have been reached. The actual value for the axis is set to the value of the reference position.

From version 3.0.41 of 12 October 2017 it is possible to change the time period for the function block detection. See [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fBlockDetectDelay.

## MC\_FlyingSwitch\_BkPlcMc

Not currently supported.

## MC\_FlyingRefPulse\_BkPlcMc

Not currently supported.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
