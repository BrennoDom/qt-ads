# MC_AxRtDrive_BkPlcMc (in V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Drive](ms-xhelp:///?Id=beckhoff-b9b6-4d7a-bb1b-23acdc4913ef)
5. MC\_AxRtDrive\_BkPlcMc (in V3.0)

# MC\_AxRtDrive\_BkPlcMc (in V3.0)

![4640007](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854751755__Web.gif)

The function block performs preparation of the control value for the axis for it to be output on a hardware module. To this end a function block is called depending on the value set as nDrive\_Type in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2), which takes into account the special features of the hardware module.

```
VAR_OUTPUT  
    Error:      BOOL;  
    ErrorID:    UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block:

The function block investigates the axis interface that has been passed to it every time it is called. A number of problems can be detected and reported during this process:

* If nDrive\_Type in pStAxParams is set to an unacceptable value, the function block reacts with **Error** and **ErrorID**:=dwTcHydErrCdDriveType. If the pointer pStAxRtData for the axis has been initialized, it is placed into a fault state.
* If one of the specific sub-function-blocks detects a problem, it will (if possible) place the axis into a fault state. This error is then echoed at the outputs of the MC\_AxRtDrive\_BkPlcMc.

If it is possible to carry out these checks without encountering any problems, the control value for the axis is processed appropriately for the [nDrive\_Type](ms-xhelp:///?Id=beckhoff-540a-458a-ab44-3657804f519c) in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).

Information about the necessary linking of I/O components with the input and output structures of the axis may be found in the [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e) under FAQ #7.

If only the usual blocks (encoder, generator, finish, drive) for the axis are to be called, a block of type [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) should be used for simplicity.

The function blocks [MC\_AxUtiReadRegDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6cad-4416-a595-99af3f7e4d4d) and [MC\_AxUtiWriteRegDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-278e-4ad1-9a74-c27725e3bc65) are available for asynchronous data exchange with I/O devices of the KL series.

## iTcMc\_DriveAx2000\_B110A

The function block handles the evaluation of the actual values of an AX2000 servo actuator at the EtherCAT fieldbus. This assumes that the connected motor is equipped with an absolute encoder. If a motor is operated with a resolver, **iTcMc\_DriveAx2000\_B110R** should be set.

|  |  |
| --- | --- |
| 41760071 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this suggestion. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the encoder function block and described there. See also [iTcMc\_EncoderAX2000\_B110A](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

## iTcMc\_DriveAx2000\_B110R

The function block handles the processing of the axis control value for output on an AX2000 servo drive at the EtherCAT fieldbus.

|  |  |
| --- | --- |
| 40296320 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this suggestion. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the encoder function block and described there. See also [iTcMc\_EncoderAx2000\_B110R](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

## iTcMc\_DriveAx2000\_B200R, iTcMc\_DriveAx2000\_B900R

The function block handles the processing of the axis control value for output on an AX2000 servo drive at the Beckhoff Lightbus (B200) or RtEthernet fieldbus (B900).

|  |  |
| --- | --- |
| 27122565 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this suggestion. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the encoder function block and described there. See also [iTcMc\_EncoderAx2000\_B200R](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

## iTcMc\_DriveAx2000\_B750A

The function block handles (from V3.0.26) processing of the control value of the axis for output at an AX2000 servo actuator at the Sercos fieldbus. The function block handles the evaluation of the actual values of an AX2000 servo actuator at the EtherCAT fieldbus.

|  |  |
| --- | --- |
| 42776493 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this suggestion. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the encoder function block and described there. See also [iTcMc\_EncoderAX2000\_B750A](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

Note a number of special features. Further information can be found in the Knowledge Base.

## iTcMc\_DriveAx5000\_B110A, iTcMc\_DriveAx5000\_B110SR

The function block handles the processing of the axis control value for output on an AX5000 servo actuator at the EtherCAT fieldbus. The function block handles the evaluation of the actual values of an AX2000 servo actuator at the EtherCAT fieldbus. If motor is operated with a resolver, **iTcMc\_EncoderAx5000\_B110SR** should be set.

|  |  |
| --- | --- |
| 49444123 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this suggestion. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the encoder function block and described there. See also [iTcMc\_EncoderAX5000\_B110A](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

A list of successfully tested compatible devices can be found under [iTcMc\_EncoderAX5000\_B110A](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

Note a number of special characteristics. Further information can be found in the Knowledge Base.

## iTcMc\_DriveCoE\_DS402

The function block handles the evaluation of the actual values of a servo actuator with CoE DS402 profile at the EtherCAT fieldbus.

|  |  |
| --- | --- |
| 42343927 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this suggestion. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the encoder function block and described there. See also [iTcMc\_EncoderCoE\_DS402A](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) and [iTcMc\_EncoderCoE\_DS402SR](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

A list of successfully tested compatible devices can be found under [iTcMc\_EncoderCoE\_DS402SR](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

|  |  |
| --- | --- |
| 45551026 | Currently only drives with resolver or single-turn encoders are supported. |

## iTcMc\_Drive\_CoE\_DS408

The function block handles the processing of the axis control value for output to a proportional valve at the EtherCAT fieldbus. The valve must support the CiA DS408 profile.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| see note | ST\_TcPlcDeviceInput.nDacOut | Output of the velocity signal. |
| see note | ST\_TcPlcDeviceOutput.uiDriveCtrl | Device control. |
| see note | ST\_TcPlcDeviceInput.uiStatus | Device status |
| WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring. |
| InfoData.State | ST\_TcPlcDeviceInput.uiDriveBoxState | Monitoring of online status |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sDrvAdsAddr | Automatic identification. |

|  |  |
| --- | --- |
| 7306053 | The names of the process data exchanged with the device are specified via the XML file of the manufacturer. |

The valve must support the following Index.SubIndex combinations.

| Index | Subindex | Meaning |
| --- | --- | --- |
| 1000 | 0 | Identification |
| 1008 | 0 | Device name (optional) |
| 1018 | 1 | Manufacturer ID |
| 1018 | 2 | Device type |

The following list of compatible devices is naturally incomplete. It is not a recommendation but is merely intended for information. Beckhoff cannot guarantee trouble-free operation of the listed devices. If a manufacturer or one of their devices is not listed, trouble-free operation may well be possible, but is not guaranteed.

| Manufacturer | Type | Description |
| --- | --- | --- |
| Moog | D638Exxx | Proportional valve |
| Parker | DxxFP /DxxFE /TDP /TPQ | Proportional valve |

x: Represents a placeholder for different characters.

## iTcMc\_DriveIx2512\_1Coil

The function block deals with processing of the axis control value for output on an IP2512 PWM fieldbus module.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data out | ST\_TcPlcDeviceOutput.uiDacOutA | Output of the PWM factor. |

## iTcMc\_DriveIx2512\_2Coil

The function block deals with processing of the axis control value for output on an IP2512 PWM fieldbus module.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data out | ST\_TcPlcDeviceOutput.uiDacOutA | Output of the PWM factor for coil 1. |
| Data out | ST\_TcPlcDeviceOutput.uiDacOutB | Output of the PWM factor for coil 2. |

## iTcMc\_DriveEL2535

The function block prepares the control value of the axis for output on a current-controlled PWM output terminal. This terminal provides two independent output stages and can be used for the following valve types:

|  |  |
| --- | --- |
| 65754481 | Proportional valve with spring center position and two coils without permanent magnets: nDrive\_Type = iTcMc\_DriveEL2535\_2Coil. |

Both channels are required for one valve. The terminal cannot be used for another valve at the same time.

With this type of valve, a proportion of the full current in the directionally active coil with currentless countercoil is required to move the slider to the desired position. For -100% .. 0% .. +100% control, the terminal block generates the output values 0 .. 0 .. 32767 in uiDacOutA and 32767 .. 0 .. 0 in uiDacOutB.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Channel1.PWM Output | ST\_TcPlcDeviceOutput.uiDacOutA | Output of the PWM factor for coil 1. |
| Channel2.PWM Output | ST\_TcPlcDeviceOutput.uiDacOutB | Output of the PWM factor for coil 2. |
|  | ST\_TcPlcDeviceOutput.nDacOut | DO NOT USE! |
| Channel1.Status | ST\_TcPlcDeviceInput.uiStatus | Status of the first device channel |
| Channel2.Status | ST\_TcPlcDeviceInput.uiTerminalState2 | Status of the second device channel |
| Channel1.Control | ST\_TcPlcDeviceOutput.uiDriveCtrl | Control of the first device channel |
| Channel2.Control | ST\_TcPlcDeviceOutput.uiTerminalCtrl2 | Control of the second device channel |
| InfoData.State | ST\_TcPlcDeviceInput.uiDriveBoxState | Connection monitoring, condition monitoring. |
| WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sDrvAdsAddr | Automatic identification, parameterization. |

|  |  |
| --- | --- |
| 54919424 | Proportional valve with spring end position and coil without permanent magnets: nDrive\_Type = iTcMc\_DriveEL2535\_1Coil. |

Only one channel is required here. The terminal can also be used for another valve. The I/O variables of the second channel must be used for this purpose.

With this type of valve, 50% of the full power supply is required to move the slider to the center position. The terminal module generates the output values 0 .. 16384 .. 32767 for -100% .. 0% .. +100% control.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
|  | ST\_TcPlcDeviceOutput.uiDacOutA | DO NOT USE! |
|  | ST\_TcPlcDeviceOutput.uiDacOutB | DO NOT USE! |
| Channel1.PWM Output | ST\_TcPlcDeviceOutput.nDacOut | Output of the PWM factor. |
| Channel1.Status | ST\_TcPlcDeviceInput.uiStatus | Device status |
|  |  |  |
| Channel1.Control | ST\_TcPlcDeviceOutput.uiDriveCtrl | Device control. |
| InfoData.State | ST\_TcPlcDeviceInput.uiDriveBoxState | Connection monitoring, condition monitoring. |
| WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sDrvAdsAddr | Automatic identification, parameterization. |

|  |  |
| --- | --- |
| 24512769 | Proportional valve with spring center position and a coil with permanent magnets: nDrive\_Type = iTcMc\_DriveEL2535\_1Coil. |

Only one channel is required here. The terminal can also be used for another valve. The I/O variables of the second channel must be used for this purpose.

This type of valve requires a bipolar current supply, which corresponds to the operating principle of a ±10 V terminal. The output value generated by the terminal block is to be adjusted as follows AFTER the drive function block has been called by the application:

ST\_TcPlcDeviceOutput.nDacOut := 2 \* (ST\_TcPlcDeviceOutput.nDacOut - 16384);

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
|  | ST\_TcPlcDeviceOutput.uiDacOutA | DO NOT USE! |
|  | ST\_TcPlcDeviceOutput.uiDacOutB | DO NOT USE! |
| Channel1.PWM Output | ST\_TcPlcDeviceOutput.nDacOut | Output of the PWM factor. |
| Channel1.Status | ST\_TcPlcDeviceInput.uiStatus | Device status |
| Channel1.Control | ST\_TcPlcDeviceOutput.uiDriveCtrl | Device control. |
| InfoData.State | ST\_TcPlcDeviceInput.uiDriveBoxState | Connection monitoring, condition monitoring. |
| WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sDrvAdsAddr | Automatic identification, parameterization. |

## iTcMc\_DriveEL4132

The function block deals with processing of the axis control value for output on a ±10 V output terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Output | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal. |
| InfoData.State | ST\_TcPlcDeviceInput.uiDriveBoxState | Connection monitoring, condition monitoring. |
| WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring. |

## iTcMc\_DriveEL7031

The function block deals with processing of the axis control value for output on an EL7031 stepper motor output stage terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| STM Velocity.Velocity | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal. |
| STM Control.Control | ST\_TcPlcDeviceOutput.uiDriveCtrl | Operation: Control of the output stage. |
| STM Status.Status | ST\_TcPlcDeviceInput.uiStatus | Operation: Status of the output stage. |
| WcState.WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring. |
| InfoData.State | ST\_TcPlcDeviceInput.uiDriveBoxState | Connection monitoring, condition monitoring. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sDrvAdsAddr | Communication. |

## iTcMc\_DriveEL7041

The function block deals with processing of the axis control value for output on an EL7041 stepper motor output stage terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| STM Velocity.Velocity | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal. |
| STM Control.Control | ST\_TcPlcDeviceOutput.uiDriveCtrl | Operation: Control of the output stage. |
| STM Status.Status | ST\_TcPlcDeviceInput.uiStatus | Operation: Status of the output stage. |
| ENC Status.Counter Value | ST\_TcPlcDeviceInput.uiCount | Operation: Read the actual position. |
| ENC Status.Latch Value | ST\_TcPlcDeviceInput.uiLatch | Operation: Reading the latch position. |
| ENC Status.Status | ST\_TcPlcDeviceInput.uiTerminalState2 | Operation: Status of the encoder interface. |
| ENC Control.Control | ST\_TcPlcDeviceOutput.uiTerminalCtrl2 | Operation: Control of the encoder interface. |
| WcState.WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring. |
| InfoData.State | ST\_TcPlcDeviceInput.uiDriveBoxState | Connection monitoring, condition monitoring. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sDrvAdsAddr | Communication. |

## iTcMc\_DriveEL7201

The function block prepares the control value of the axis for output to an EL7201 servo terminal.

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions, particularly for parameter communication, overlap with those of the encoder function block. See also iTcMc\_EncoderEL7201.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Target velocity | ST\_TcPlcDeviceOutput.NominalVelo | Operation: Output of the velocity signal. |
|  |  |  |
| Controlword | ST\_TcPlcDeviceOutput.uiDriveCtrl | Operation: Control of the output stage. |
| Position actual value | ST\_TcPlcDeviceInput.udiCount | Operation: Read the actual position. |
| WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring. |
| Statusword | ST\_TcPlcDeviceInput.uiStatus | Operation: Status of the output stage. |
| InfoData.State | ST\_TcPlcDeviceInput.uiDriveBoxState | Connection monitoring, condition monitoring. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sDrvAdsAddr | Communication |

## iTcMc\_DriveKL2521

The function block deals with processing of the axis control value for output on a KL2521 pulse output terminal.

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions, particularly for parameter communication, overlap with those of the encoder function block. See also [iTcMc\_EncoderKL2521](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data in | ST\_TcPlcDeviceInput.uiTerminalData | Operation: Read the actual position.  For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for read data. |
| Control | ST\_TcPlcDeviceOutput.bTerminalCtrl | Register communication |
| Status | ST\_TcPlcDeviceInput.bTerminalState | Register communication |
| Data out | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal.  Register communication: Interface for written data. |

## iTcMc\_DriveKL2531

The function block deals with processing of the axis control value for output on a KL2531 stepper motor output stage terminal.

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions, particularly for parameter communication, overlap with those of the encoder function block. See also [iTcMc\_EncoderKL2531](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Velocity | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal.  For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for written data. |
| Position | ST\_TcPlcDeviceInput.uiTerminalData | Operation: Read the actual position.  For register communication: Interface for read data. |
| Ctrl | ST\_TcPlcDeviceOutput.bTerminalCtrl | Control the output stage, register communication. |
| Status | ST\_TcPlcDeviceInput.bTerminalState | Status of the output stage, register communication. |
| ExtStatus | ST\_TcPlcDeviceInput.uiTerminalState2 | Diagnosis of output stage and motor |

## iTcMc\_DriveKL2532

The function block deals with processing of the axis control value for output on a KL2532 DC motor output stage terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data in | ST\_TcPlcDeviceInput.uiTerminalData | For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for read data. |
| Control | ST\_TcPlcDeviceOutput.bTerminalCtrl | Register communication. |
| Status | ST\_TcPlcDeviceInput.bTerminalState | Register communication |
| Data out | ST\_TcPlcDeviceOutput.nDacOut | Register communication |

## iTcMc\_DriveKL2535\_1Coil, iTcMc\_DriveKL2535\_2Coil

The function block deals with processing of the axis control value for output on a KL2535 PWM output stage terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data in | ST\_TcPlcDeviceInput.uiTerminalData | [Register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) |
| Control | ST\_TcPlcDeviceOutput.bTerminalCtrl | Register communication. |
| Status | ST\_TcPlcDeviceInput.bTerminalState | Register communication |
| Data out | ST\_TcPlcDeviceOutput.nDacOut | Register communication |

## iTcMc\_DriveKL2541

The function block deals with processing of the axis control value for output on a KL2541 stepper motor output stage terminal.

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions, particularly for parameter communication, overlap with those of the encoder function block. See also [iTcMc\_EncoderKL2541](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Velocity | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal.  For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for written data. |
| Position | ST\_TcPlcDeviceInput.uiTerminalData | Operation: Read the actual position.  For register communication: Interface for read data. |
| Ctrl | ST\_TcPlcDeviceOutput.bTerminalCtrl | Control the output stage, register communication. |
| Status | ST\_TcPlcDeviceInput.bTerminalState | Status of the output stage, register communication. |
| ExtCtrl | ST\_TcPlcDeviceOutput.uiTerminalCtrl2 | Latch control during homing with the synchronous pulse of the encoder |
| ExtStatus | ST\_TcPlcDeviceInput.uiTerminalState2 | Diagnosis of output stage and motor, latch status during homing with the synchronous pulse of the encoder |

## iTcMc\_DriveKL2542

The function block deals with processing of the axis control value for output on a KL2542 DC motor output stage terminal.

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions, particularly for parameter communication, overlap with those of the encoder function block. See also [iTcMc\_EncoderKL2542](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data out | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal.  For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for written data. |
| Data in | ST\_TcPlcDeviceInput.uiTerminalData | Operation: Read the actual position.  For register communication: Interface for read data. |
| Control | ST\_TcPlcDeviceOutput.bTerminalCtrl | Control the output stage, register communication. |
| Status | ST\_TcPlcDeviceInput.bTerminalState | Status of the output stage, register communication. |

## iTcMc\_DriveKL4032

The function block deals with processing of the axis control value for output on a ±10 V output terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data out | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal.  For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for written data. |
| Control | ST\_TcPlcDeviceOutput.bTerminalCtrl | Register communication |
| Status | ST\_TcPlcDeviceInput.bTerminalState | Register communication |
| Data in | ST\_TcPlcDeviceOutput.uiTerminalData | Register communication: Interface for read data. |

## iTcMc\_DriveLowCostStepper

The function block deals with processing of the axis control value for output on digital output terminals. For emulation of an actual position, a pulse counter is updated, which can be evaluated with an [iTcMc\_EncoderLowCostStepper](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) encoder.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Output | ST\_TcPlcDeviceOutput.nDigOutAp | Non-inverted control of the A phase. |
| Output | ST\_TcPlcDeviceOutput.nDigOutAn | Inverted control of the A phase. |
| Output | ST\_TcPlcDeviceOutput.nDigOutBp | Non-inverted control of the B phase. |
| Output | ST\_TcPlcDeviceOutput.nDigOutBn | Inverted control of the B phase. |

## iTcMc\_DriveLowCostInverter

The function block deals with processing of the axis control value for output on digital output terminals for operation of a pole reversing contactor configuration or a frequency inverter with fixed frequencies. If this drive type is used, a number of special characteristics must be taken into account. For linking, a distinction has to be made between two options:

## Brake, enable, direction and velocity level

After the [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) or [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) function block of the axis has been called, four decoded signals are available. In order to generate the required signals, the following consolidations of the direction-specific signals are required after the function block call.   
**Sample**:  
stAxDeviceOut.bDigOutAp:=stAxDeviceOut.bDigOutAp OR stAxDeviceOut.bDigOutBp;

stAxDeviceOut.bDigOutAn:=stAxDeviceOut.bDigOutAn OR stAxDeviceOut.bDigOutBn;

|  |  |
| --- | --- |
| 19288335 | From V3.0.11 the output of an absolute value can be activated on the valve tab. In this case, the signal consolidation shown above is applied internally. |

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Output | ST\_TcPlcDeviceOutput.nDigOutAp | Selection of the fixed frequency for rapid traverse. |
| Output | ST\_TcPlcDeviceOutput.nDigOutAn | Selection of the fixed frequency for slow traverse. |
| Output | ST\_TcPlcDeviceOutput.bMovePos | Specifies the direction of travel: Positive. |
| Output | ST\_TcPlcDeviceOutput.bMoveNeg | Specifies the direction of travel: Negative. |
| Output | ST\_TcPlcDeviceOutput.bPowerOn | Enabling the power stage. |
| Output | ST\_TcPlcDeviceOutput.bBrakeOff | Activation of the brake. |
| Input | ST\_TcPlcDeviceInput.bPowerOk | Status of the converter: Ready for operation. |

**Brake, enable and direction-coded velocity level**

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Output | ST\_TcPlcDeviceOutput.nDigOutAp | Selection of the fixed frequency for rapid traverse in positive direction of travel. |
| Output | ST\_TcPlcDeviceOutput.nDigOutAn | Selection of the fixed frequency for slow traverse in positive direction of travel. |
| Output | ST\_TcPlcDeviceOutput.nDigOutBn | Selection of the fixed frequency for slow traverse in negative direction of travel. |
| Output | ST\_TcPlcDeviceOutput.nDigOutBp | Selection of the fixed frequency for rapid traverse in negative direction of travel. |
| Output | ST\_TcPlcDeviceOutput.bPowerOn | Enabling the power stage. |
| Output | ST\_TcPlcDeviceOutput.bBrakeOff | Activation of the brake. |
| Input | ST\_TcPlcDeviceInput.bPowerOk | Status of the converter: Ready for operation. |

## iTcMc\_DriveM2400\_Dn

The function block performs preparation of the control value for the axis so that it can be output on one of the four channels of a ±10 V M2400 output box.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data out | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
