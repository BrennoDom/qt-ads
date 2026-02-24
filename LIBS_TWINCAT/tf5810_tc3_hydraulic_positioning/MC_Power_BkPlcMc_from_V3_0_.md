# MC_Power_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_Power\_BkPlcMc (from V3.0)

# MC\_Power\_BkPlcMc (from V3.0)

![2819581](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854647179__Web.gif)

The function block is used to control an external actuator. Further information on this topic can be found under [FAQ #9](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd).

```
VAR_INPUT  
    Enable:             BOOL;  
    Enable_Positive:    BOOL;  
    Enable_Negative:    BOOL;  
    BufferMode:         MC_BufferMode_BkPlcMc:=Aborting_BkPlcMc;  (ab/from V3.0.8)  
END_VAR
```

```
VAR_OUTPUT  
    Busy:       BOOL;  
    Status:     BOOL;  
    Error:      BOOL;  
    ErrorID:    UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Enable**: A TRUE at this input activates an external actuator of an axis.

**Enable\_Positive**: A TRUE at this input activates the directional enable of an external actuator of an axis for movements in a positive direction.

**Enable\_Negative**: A TRUE at this input activates the directional enable of an external actuator of an axis for movements in a negative direction.

**BufferMode**: Reserved. This input is provided in preparation for a future build. It should currently either not be assigned or assigned the constant Aborting\_BkPlcMc. (from V3.0.8)

**Busy**: Indicates that a command is being processed.

**Status**: Readiness for operation is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded error message is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block:

This function block is used to control external actuators. These can be modules for valve control (the valve's onboard output stage or switch cabinet assembly), frequency converters or servoamplifiers. These devices usually require a digital signal to enable the output of energy through a power stage. Depending on the design of the device, it is also possible for the "positive" and "negative" movement directions to be individually activated.

The function block's input signals are passed on through the interface to the peripheral device. **Enable** also activates error monitoring.

The function block investigates the axis interface that has been passed to it every time it is called. A number of problems can be detected and reported during this process:

* If the value iTcMc\_DriveAx2000\_XXXXX is set under nDrive\_Type in pStAxParams, the following procedure is applied:

+ If one of the pointers pStDeviceOutput or pStDeviceInput in [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) is not initialized, the block responds with E**rror** and **ErrorID**:=dwTcHydErrCdPtrPlcDriveIn or dwTcHydErrCdPtrPlcDriveOut. **Status** is then FALSE.
+ If an error is detected in the communication with the AX device or an error message occurs in the pStDeviceInput interface of the AX device, the function block responds with **Error** and an **ErrorID**, which is defined in the [global constants](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) of the library. **Status** is then FALSE, and the axis is set to an error state with the axis error dwTcHydErrCdDriveNotReady.
+ Otherwise, the value of **Enable** is returned as the **Status**.

* If the value iTcMc\_DriveKL2531 or iTcMc\_DriveKL2541 is set under nDrive\_Type in pStAxParams, the following procedure is applied:

+ The pointers pStDeviceOutput and or pStDeviceInput [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) are checked. If these pointers have not been initialised, the function block responds with **Error** and **ErrorID**:=dwTcHydErrCdPtrPlcDriveIn or dwTcHydErrCdPtrPlcDriveOut. **Status** is then FALSE.
+ If an error is detected in the communication with the I/O terminal or an error message occurs in the pStDeviceInput interface of the terminal, the function block responds with **Error** and an **ErrorID**, which is defined in the in [global constants](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) of the library. **Status** is then FALSE, and the axis is set to an error state with the axis error dwTcHydErrCdDriveNotReady.
+ **Enable** is used to activate the terminal output stage through a bit in pStDeviceOutput.bTerminalCtrl. The ready signal in bTerminalCtrl.bTerminalState is returned as **Status**.
+ If the drive interface is operating without error, the value of **Enable\_Positive** is entered with the mask dwTcHydDcDwFdPosEna in the nDeCtrlDWord of pStAxRtData.
+ If the drive interface is operating without error, the value of **Enable\_Negative** is entered with the mask dwTcHydDcDwFdNegEna in the nDeCtrlDWord of pStAxRtData.

* Otherwise the pointers pStDeviceInput and pStDeviceOutput in [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) are checked. If these pointers have not been initialised, the function block responds with **Error** and **ErrorID**:=dwTcHydErrCdPtrPlcDriveIn or dwTcHydErrCdPtrPlcDriveOut. **Status** is then FALSE.

+ Otherwise, the value of bPowerOk from pStDeviceInput is returned as the **Status**.

* If the drive interface is operating without error, the value of **Enable** is entered with the mask dwTcHydDcDwCtrlEnable in the nDeCtrlDWord of pStAxRtData.
* If the drive interface is operating without error, the value of **Enable\_Positive** is entered with the mask dwTcHydDcDwFdPosEna in the nDeCtrlDWord of pStAxRtData.
* If the drive interface is operating without error, the value of **Enable\_Negative** is entered with the mask dwTcHydDcDwFdNegEna in the nDeCtrlDWord of pStAxRtData.

|  |  |
| --- | --- |
| 25376232 | This function block requires no time for executing its tasks. The output Busy will never assume the value TRUE and only exists for compatibility reasons. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
