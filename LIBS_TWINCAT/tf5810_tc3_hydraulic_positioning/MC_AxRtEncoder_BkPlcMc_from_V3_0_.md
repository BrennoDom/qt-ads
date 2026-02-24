# MC_AxRtEncoder_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Encoder](ms-xhelp:///?Id=beckhoff-f3c4-4c4f-b160-19fe406dfb7c)
5. MC\_AxRtEncoder\_BkPlcMc (from V3.0)

# MC\_AxRtEncoder\_BkPlcMc (from V3.0)

![39377290](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854754187__Web.gif)

This function block determines the actual position of the axis from the input information of a hardware module. To this end a function block is called depending on the value set as **nEnc\_Type** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2), which takes into account the special features of the hardware module.

[MC\_AxRtHybridAxisActuals\_BkPlcMc](ms-xhelp:///?Id=beckhoff-2939-4fc5-b645-2205eba49080) is an adapted function block for determining the essential actual values of a servo-electric/hydraulic hybrid axis.

```
VAR_OUTPUT  
    Error:          BOOL;  
    ErrorID:        UDINT;  
    AboveLimit:     BOOL;  
    BelowLimit:     BOOL;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**AboveLimit**: Exceeding of the upper software limit switch is indicated by the actual position.

**BelowLimit**: If the value falls below the lower software limit switch, this is indicated by the actual position.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block investigates the axis interface that has been passed to it every time it is called. A number of problems can be detected and reported during this process:

* If **nEnc\_Type** in pStAxParams is set to an unacceptable value, the function block responds with **Error** and **ErrorID**:=dwTcHydErrCdEncType. The axis is set to an error state.
* If one of the specific sub-function-blocks detects a problem, it will (if possible) place the axis into a fault state. This error is then echoed at the outputs of the **MC\_AxRtEncoder\_BkPlcMc**.

If it is possible to carry out these checks without encountering any problems, the actual value of the axis is determined by calling a type-specific function block corresponding to the [nEnc\_Type](ms-xhelp:///?Id=beckhoff-1819-4c81-9982-5253100bd275) in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).

Information about the necessary linking of I/O components with the input and output structures of the axis may be found in the Knowledge Base under [FAQ #4](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd).

If only the usual blocks (encoder, generator, finish, drive) for the axis are to be called, a block of type [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) should be used for simplicity.

The function blocks [MC\_AxUtiReadRegEncTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ffcf-4474-9c04-758f97fa6a6f) and [MC\_AxUtiWriteRegEncTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4abb-470a-baef-ba638f5fbde2) are available for asynchronous data exchange with I/O devices of the KL series.

## iTcMc\_EncoderAx2000\_B110A

The function block handles the evaluation of the actual values of an AX2000 servo actuator at the EtherCAT fieldbus. This assumes that the connected motor is equipped with an absolute encoder. If a motor is operated with a resolver, **iTcMc\_EncoderAx2000\_B110R** should be set.

|  |  |
| --- | --- |
| 18851291 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this proposition. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the drive function block. See also [iTcMc\_DriveAX2000\_B110R](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Position actual value | ST\_TcPlcDeviceInput.ActualPos[0..1] | Determines the actual position. |
| Status word | ST\_TcPlcDeviceInput.uiStatus | Device status, encoder emulation. |
| Control word | ST\_TcPlcDeviceOutput.uiDriveCtrl | Device control. |
| Velocity demand value | ST\_TcPlcDeviceOutput.NominalVelo | Output of the velocity control value. |
| WcState (see note) | ST\_TcPlcDeviceInput.wEncWcState | Connection monitoring for actual value acquisition. |
| WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring for the drive. |
| InfoData.State | ST\_TcPlcDeviceInput.uiDriveBoxState | Monitoring of online status |
| InfoData.AdsAddr (see note) | ST\_TcPlcDeviceInput.sEncAdsAddr | Parameter communication. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sDrvAdsAddr | Control of real-time status, parameter communication. |
| Chn0 (see note) | ST\_TcPlcDeviceInput.nEncAdsChannel | Parameter communication. |
| Chn0 | ST\_TcPlcDeviceInput.nDrvAdsChannel | Control of real-time status, parameter communication. |
| Output (on a DO terminal) | ST\_TcPlcDeviceOutput.PowerOn | Optional control of the mains contactor. A digital output terminal is required for this purpose. |
| Input (on a DI terminal) | ST\_TcPlcDeviceInput.PowerOk | Optional evaluation of the mains contactor. A digital input terminal is required for this purpose. |

|  |  |
| --- | --- |
| 35443891 | In order to simplify the establishment of the I/O link, the linking of ST\_TcPlcDeviceInput.sEncAdsAddr, ST\_TcPlcDeviceInput.nEncAdsChannel and ST\_TcPlcDeviceInput.wEncWcState can be avoided, if the actual value acquisition takes place via the same device, as usual. In this case, the function blocks for parameter communication and encoder evaluation use the corresponding variables of the drive link. |

## iTcMc\_EncoderAx2000\_B110R

The function block handles the evaluation of the actual values of an AX2000 servo actuator at the EtherCAT fieldbus. This assumes that the connected motor is equipped with a resolver. If a motor is operated with an absolute encoder, **iTcMc\_EncoderAx2000\_B110A** must be set.

|  |  |
| --- | --- |
| 50559563 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this proposition. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the drive function block. See also [iTcMc\_DriveAX2000\_B110R](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Position actual value | ST\_TcPlcDeviceInput.ActualPos[0..1] | Determines the actual position. |
| Status word | ST\_TcPlcDeviceInput.uiStatus | Device status, encoder emulation. |
| Control word | ST\_TcPlcDeviceOutput.uiDriveCtrl | Device control. |
| Velocity demand value | ST\_TcPlcDeviceOutput.NominalVelo | Output of the velocity control value. |
| WcState (see note) | ST\_TcPlcDeviceInput.wEncWcState | Connection monitoring for actual value acquisition. |
| WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring for the drive. |
| uiDriveBoxState | ST\_TcPlcDeviceInput.InfoData.State | Monitoring of online status |
| InfoData.AdsAddr (see note) | ST\_TcPlcDeviceInput.sEncAdsAddr | Parameter communication. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sDrvAdsAddr | Parameter communication. |
| Chn0 (see note) | ST\_TcPlcDeviceInput.nEncAdsChannel | Parameter communication. |
| Chn0 | ST\_TcPlcDeviceInput.nDrvAdsChannel | Parameter communication. |
| Output (on a DO terminal) | ST\_TcPlcDeviceOutput.PowerOn | Optional control of the mains contactor. A digital output terminal is required for this purpose. |
| Input (on a DI terminal) | ST\_TcPlcDeviceInput.PowerOk | Optional evaluation of the mains contactor. A digital input terminal is required for this purpose. |

|  |  |
| --- | --- |
| 52382884 | In order to simplify the establishment of the I/O link, the linking of ST\_TcPlcDeviceInput.sEncAdsAddr, ST\_TcPlcDeviceInput.nEncAdsChannel and ST\_TcPlcDeviceInput.wEncWcState can be avoided, if the actual value acquisition takes place via the same device, as usual. In this case, the function blocks for parameter communication and encoder evaluation use the corresponding variables of the drive link. |

## iTcMc\_EncoderAx2000\_B200R, iTcMc\_EncoderAx2000\_B900R

The function block deals with evaluation of the actual values of an AX2000 servo actuator with Lightbus (B200) or RealtimeEthernet (B900).

|  |  |
| --- | --- |
| 1683911 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this proposition. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the drive function block. See also [iTcMc\_DriveAX2000\_B200R](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| ActualPos[0..1] | ST\_TcPlcDeviceInput.ActualPos[0..1] | Determines the actual position. |
| DriveError | ST\_TcPlcDeviceInput.DriveError | Device status. |
| DriveState[0..3] | ST\_TcPlcDeviceInput.DriveState[0..3] | Device status. |
| BoxState | ST\_TcPlcDeviceInput.uiDriveBoxState | Connection monitoring. |
| DriveCtrl0 | ST\_TcPlcDeviceOutput.DriveCtrl[0] | Device control. |
| DriveCtrl1 | ST\_TcPlcDeviceOutput.DriveCtrl[1] | Device control. |
| DriveCtrl2 | ST\_TcPlcDeviceOutput.DriveCtrl[2] | Device control. |
| DriveCtrl3 | ST\_TcPlcDeviceOutput.DriveCtrl[3] | Device control. |
| NominalVelo | ST\_TcPlcDeviceOutput.NominalVelo | Output of the velocity control value. |
| Output (on a DO terminal) | ST\_TcPlcDeviceOutput.PowerOn | Optional control of the mains contactor. A digital output terminal is required for this purpose. |
| Input (on a DI terminal) | ST\_TcPlcDeviceInput.PowerOk | Optional evaluation of the mains contactor. A digital input terminal is required for this purpose. |

## iTcMc\_EncoderAx2000\_B750A

The function block handles (from V3.0.26) the evaluation of the actual values of an AX2000 servo actuator at the Sercos fieldbus. The function block handles the evaluation of the actual values of an AX2000 servo actuator at the EtherCAT fieldbus.

|  |  |
| --- | --- |
| 15155206 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this proposition. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the drive function block. See also [iTcMc\_DriveAX2000\_B750A](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Drive status word | ST\_TcPlcDeviceInput.uiStatus | Device status. |
| Actual position value encoder 1 | ST\_TcPlcDeviceInput.udiCount | Determines the actual position. |
| Master control word | ST\_TcPlcDeviceOutput.uiDriveCtrl | Device control. |
| Velocity command value | ST\_TcPlcDeviceOutput.NominalVelo | Output of the velocity control value. |
| SystemStatus (from Sercos master) | ST\_TcPlcDeviceInput.uiDriveBoxState | Monitoring of the Sercos phase. **Note**: This variable is provided by the Sercos master (e.g. FC7501). |
| Output (on a DO terminal) | ST\_TcPlcDeviceOutput.PowerOn | Optional control of the mains contactor. A digital output terminal is required for this purpose. |
| Input (on a DI terminal) | ST\_TcPlcDeviceInput.PowerOk | Optional evaluation of the mains contactor. A digital input terminal is required for this purpose. |

Note a number of special characteristics. Further information can be found in the [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e).

## iTcMc\_EncoderAx5000\_B110A, iTcMc\_EncoderAx5000\_B110SR

The function block handles the evaluation of the actual values of an AX5000 servo actuator at the EtherCAT fieldbus. This assumes that the connected motor is equipped with an absolute encoder. If a motor is operated with a resolver, **iTcMc\_EncoderAx5000\_B110SR** should be set.

|  |  |
| --- | --- |
| 2179128 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this proposition. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the drive function block. See also [iTcMc\_DriveAX5000\_B110A](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Position feedback 1 value | ST\_TcPlcDeviceInput.udiCount | Determines the actual position. |
| Drive status word | ST\_TcPlcDeviceInput.uiStatus | Device status. |
| Master control word | ST\_TcPlcDeviceOutput.uiDriveCtrl | Device control. |
| Velocity command value | ST\_TcPlcDeviceOutput.NominalVelo | Output of the velocity control value. |
| WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring for the drive. |
| WcState (see note) | ST\_TcPlcDeviceInput.wEncWcState | Connection monitoring for actual value acquisition. |
| InfoData.State | ST\_TcPlcDeviceInput. uiDriveBoxState | Monitoring of online status |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sDrvAdsAddr | Control of real-time status, parameter communication. |
| InfoData.AdsAddr (see note) | ST\_TcPlcDeviceInput.sEncAdsAddr | Parameter communication. |
| Chn0 (see note 2) | ST\_TcPlcDeviceInput.nDrvAdsChannel | For single devices or the first drive of a dual device: Control of real-time status, parameter communication. |
| Chn0 (see notes 1,2) | ST\_TcPlcDeviceInput.nEncAdsChannel | For single devices or the first drive of a dual device: Parameter communication. |
| Chn1 (see note 2) | ST\_TcPlcDeviceInput.nDrvAdsChannel | Only for the second drive of a dual device: Control of real-time status, parameter communication. |
| Chn1 (see notes 1,2) | ST\_TcPlcDeviceInput.nEncAdsChannel | Only for the second drive of a dual device: Parameter communication. |
| Output (on a DO terminal) | ST\_TcPlcDeviceOutput.PowerOn | Optional control of the mains contactor. A digital output terminal is required for this purpose. |
| Input (on a DI terminal) | ST\_TcPlcDeviceInput.PowerOk | Optional evaluation of the mains contactor. A digital input terminal is required for this purpose. |

The following list of compatible devices is naturally incomplete. It is not a recommendation but is merely intended for information. Beckhoff cannot guarantee trouble-free operation of the listed devices. If a manufacturer or one of their devices is not listed, trouble-free operation may well be possible, but is not guaranteed.

| Manufacturer | Type | Description |
| --- | --- | --- |
| Baumüller | b-maxx | Servo controller with single-turn absolute encoder |
|  |  |  |

|  |  |
| --- | --- |
| 19612160 | In order to simplify the establishment of the I/O link, the linking of ST\_TcPlcDeviceInput.sEncAdsAddr, ST\_TcPlcDeviceInput.nEncAdsChannel and ST\_TcPlcDeviceInput.wEncWcState can be avoided, if the actual value acquisition takes place via the same device, as usual. In this case, the function blocks for parameter communication and encoder evaluation use the corresponding variables of the drive link. |

|  |  |
| --- | --- |
| 42291718 | The variables Chn0 and Chn2 are used for distinguishing the channels of a dual unit. Connect Chn0 for the first drive of the device and Chn1 for the second. For single devices proceed as for the first channel of a dual device. |

Note a number of special characteristics. Further information can be found in the Knowledge Base.

## iTcMc\_EncoderCoE\_DS402A

The function block handles the evaluation of the actual values of a servo actuator with CoE DS402 profile at the EtherCAT fieldbus. This assumes that the connected motor is equipped with a multi-turn absolute encoder.

|  |  |
| --- | --- |
| 45081147 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this proposition. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the drive function block. See also [iTcMc\_DriveCoE\_DS402](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| see note | ST\_TcPlcDeviceInput.udiCount | Determines the actual position. |
|  | ST\_TcPlcDeviceInput.uiStatus |  |
|  | ST\_TcPlcDeviceOutput.uiDriveCtrl |  |
|  | ST\_TcPlcDeviceOutput.NominalVelo |  |
| WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring. |
| InfoData.State | ST\_TcPlcDeviceInput.uiDriveBoxState | Monitoring of online status |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sEncAdsAddr | Automatic identification. |

|  |  |
| --- | --- |
| 3077144 | The names of the process data exchanged with the device are specified via the XML file of the manufacturer. |

A list with compatible devices can be found below

## iTcMc\_EncoderCoE\_DS402SR

The function block handles the evaluation of the actual values of a servo actuator with CoE DS402 profile at the EtherCAT fieldbus. This assumes that the connected motor is equipped with a resolver or a single-turn absolute encoder.

|  |  |
| --- | --- |
| 27694303 | During manual insertion or automatic detection of a drive actuator the TwinCAT System Manager will suggest to insert an NC axis in the project and connect it with this actuator. If this actuator is to be controlled with the hydraulic system library, it is essential to decline this proposition. |

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions overlap with those of the drive function block. See also [iTcMc\_DriveCoE\_DS402](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| see note | ST\_TcPlcDeviceInput.udiCount | Determines the actual position. |
|  | ST\_TcPlcDeviceInput.uiStatus |  |
|  | ST\_TcPlcDeviceOutput.uiDriveCtrl |  |
|  | ST\_TcPlcDeviceOutput.NominalVelo |  |
| WcState | ST\_TcPlcDeviceInput.wDriveWcState | Connection monitoring. |
| InfoData.State | ST\_TcPlcDeviceInput.uiDriveBoxState | Monitoring of online status |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sEncAdsAddr | Automatic identification. |

|  |  |
| --- | --- |
| 47922135 | The names of the process data exchanged with the device are specified via the XML file of the manufacturer. |

The encoder must support the following Index.SubIndex combinations.

| Index | Subindex | Meaning |
| --- | --- | --- |
| 1000 | 0 | Identification |
| 1008 | 0 | Device name (optional) |
| 1018 | 1 | Manufacturer ID |
| 1018 | 2 | Device type |
| 6080 | 0 | Maximum speed in RPM (optional; if this object is not supported, the reference speed must be entered manually). |
| 608F | 1 | Number of encoder increments per motor revolution. |
| 6090 | 1 | Number of increments per motor revolution used for control value output. |

The following list of compatible devices is naturally incomplete. It is not a recommendation but is merely intended for information. Beckhoff cannot guarantee trouble-free operation of the listed devices. If a manufacturer or one of their devices is not listed, trouble-free operation may well be possible, but is not guaranteed.

| Manufacturer | Type | Description |
| --- | --- | --- |
| LTi DRiVES GmbH |  | Servo controller with single-turn absolute encoder |
|  |  |  |

## iTcMc\_EncoderCoE\_DS406

The function block handles the evaluation of encoders with direct EtherCAT connection. The encoder must support the CiA DS406 profile.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| see note | ST\_TcPlcDeviceInput.udiCount | Determines the actual position. |
| see notes | ST\_TcPlcDeviceInput.wEncDevState | Monitoring the device status. |
| WcState | ST\_TcPlcDeviceInput.wEncWcState | Connection monitoring. |
| InfoData.State | ST\_TcPlcDeviceInput.uiEncBoxState | Monitoring of online status. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sEncAdsAddr | Automatic identification. |

|  |  |
| --- | --- |
| 28646034 | The names of the process data exchanged with the device are specified via the XML file of the manufacturer. |

|  |  |
| --- | --- |
| 56487722 | Monitoring of the device status is not guaranteed for all devices from all manufacturers. For some devices an 8-bit status is provided. This kind of information should be mapped on the lower 8 bits of the wEncDevState element. |

The encoder must support the following Index.SubIndex combinations.

| Index | Subindex | Meaning |
| --- | --- | --- |
| 1000 | 0 | Identification |
| 1008 | 0 | Device name (optional) |
| 1018 | 1 | Manufacturer ID |
| 1018 | 2 | Device type |
| 6001 | 0 | Rotational encoders: increments per revolution (obligatory) |
| 6002 | 0 | Rotational encoders: Total counting range (option A, alternatively: index 6502)  Linear encoders: Total counting range (obligatory) |
| 6005 | 1 | Linear encoders: Resolution (option A, alternatively: index 6501) |
| 6501 | 0 | Linear encoders: Resolution (option B, alternatively: index 6005) |
| 6502 | 0 | Rotational encoders: Number of counted revolutions (option B, alternatively: index 6002) |
| 650A | 2 | Linear encoders: lower limit of the intended working area (option) |
| 650B | 3 | Linear encoders: upper limit of the intended working area (option) |

The following list of compatible devices is naturally incomplete. It is not a recommendation but is merely intended for information. Beckhoff cannot guarantee trouble-free operation of the listed devices. If a manufacturer or one of their devices is not listed, trouble-free operation may well be possible, but is not guaranteed.

Certain parameters can be determined automatically, depending on the support of the listed objects. This applies to the counting range, the overflow detection and (for linear encoders) the resolution. If the respective objects are not provided or not in a supported combination, this is not possible. In such a case, operation may be possible. However, the parameters must then be set manually during commissioning.

| Manufacturer | Type | Description |
| --- | --- | --- |
| Fritz Kübler GmbH | 58x8 | Multi-turn absolute encoder. |
| IVO GmbH & Co. KG | GXMMW\_H | Multi-turn absolute encoder. |
| MTS | Temposonics R | Linear absolute encoder. |
| TR Electronic GmbH: | LMP | Linear absolute encoder. |
| TWK-Electronic GmbH | CRKxx12R12C1xx | Multi-turn absolute encoder. |

## iTcMc\_EncoderDigCam

The function block handles the evaluation of four digital inputs as position cams.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Input | ST\_TcPlcDeviceInput.bDigCamPP | Determines the actual position: Positive target cam. |
| Input | ST\_TcPlcDeviceInput.bDigCamP | Determines the actual position: Positive brake cam. |
| Input | ST\_TcPlcDeviceInput.bDigCamM | Determines the actual position: Negative brake cam. |
| Input | ST\_TcPlcDeviceInput.bDigCamMM | Determines the actual position: Negative target cam. |

## iTcMc\_EncoderDigIncrement

The function block handles the evaluation of two digital inputs for the emulation of an incremental encoder evaluation.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Input | ST\_TcPlcDeviceInput.bDigInA | Determines the actual position. |
| Input | ST\_TcPlcDeviceInput.bDigInB | Determines the actual position. |

## iTcMc\_EncoderEL3102

The function block handles the evaluation of data from an EL3102 analog input terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Value | ST\_TcPlcDeviceInput.uiCount | Read the actual position. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sEncAdsAddr | Optional: Address information for parameter communication via CoE. |
| InfoData.State | ST\_TcPlcDeviceInput.uiEncBoxState | Connection monitoring, condition monitoring. |
| WcState | ST\_TcPlcDeviceInput.wEncWcState | Connection monitoring. |

## iTcMc\_EncoderEL3142

The function block handles the evaluation of data from an EL3142 analog input terminal. The mapping is similar to the interface-compatible EL3102.

## iTcMc\_EncoderEL3162

The function block handles the evaluation of data from an EL3162 analog input terminal. The mapping is similar to the interface-compatible EL3102.

## iTcMc\_EncoderEL3255

The function block handles the evaluation of data from an EL3255 analog input terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| AI Standard Channel x.Value | ST\_TcPlcDeviceInput.uiCount | Read the actual position. |
| AI Standard Channel x.Status | ST\_TcPlcDeviceInput.wEncDevState | Evaluation of the fault signal of the encoder. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sEncAdsAddr | Address information for parameter communication via CoE. |
| InfoData.State | ST\_TcPlcDeviceInput.uiEncBoxState | Connection monitoring, condition monitoring. |
| WcState | ST\_TcPlcDeviceInput.wEncWcState | Connection monitoring. |

|  |  |
| --- | --- |
| 38627455 | The terminal supports up to five encoders. The variables InfoData.AdsAddr, InfoData.State and WcState should be distributed to all axes involved through multiple mapping. |

## iTcMc\_EncoderEL5001

The function block handles the evaluation of data from an EL5001 SSI encoder terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Value | ST\_TcPlcDeviceInput.udiCount | Read the actual position. |
| Status | ST\_TcPlcDeviceOutput.usiRegStatus | Evaluation of the fault signal of the encoder. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sEncAdsAddr | Address information for parameter communication via CoE. |
| InfoData.State | ST\_TcPlcDeviceInput.uiEncBoxState | Connection monitoring, condition monitoring. |
| WcState | ST\_TcPlcDeviceInput.wEncWcState | Connection monitoring. |

## iTcMc\_EncoderEL5021

The function block handles the evaluation of data from an EL5021 sin/cos encoder terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| ENC Status.Counter value | ST\_TcPlcDeviceInput.udiCount | Read the actual position. |
| ENC Status.Status | ST\_TcPlcDeviceInput.usiRegStatus | Evaluation of the fault signal of the encoder. |
| ENC Status.Latch value | ST\_TcPlcDeviceInput.udiLatch | For homing using the synchronous pulse of the encoder. |
| ENC Control.Control | ST\_TcPlcDeviceOutput.usiCtrl | Control of the latch function. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sEncAdsAddr | Address information for parameter communication via CoE. |
| InfoData.State | ST\_TcPlcDeviceInput.uiEncBoxState | Connection monitoring, condition monitoring. |
| WcState | ST\_TcPlcDeviceInput.wEncWcState | Connection monitoring. |

## iTcMc\_EncoderEL5032 (ab V3.0.40)

The function block handles the evaluation of data from an EL5032 ENDAT encoder terminal.

The EL5032 terminal provides a 32-bit or 64-bit counter, depending on its setting. This means that the highest value that can be displayed is either 232 – 1 or 264 – 1. Multiplied with the encoder resolution, this results in the evaluable path. At 10 nm resolution results in a value of 42949 mm. This is sufficient for most applications, which is why it is usually OK to use the terminal in 32-bit mode. To do this, only the mapping to udiCount is required. Otherwise, the 64-bit mode of the terminal must be activated and the complete mapping to udiCount and S\_DiReserve[1] must be configured.

Note

Note the supply voltage

To prevent damage to the connected device, check the supply voltage set in the EL5032 before connecting the device

When a fieldbus is started and an axis error is reset, certain parameters of the connected device are read. The device type is included in the logging. Only absolute linear scales and absolute multi-turn encoders are accepted. With linear scales, the resolution is automatically updated in the encoder weighting and interpolation.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Position (DWORD or lower part of ULINT) | ST\_TcPlcDeviceInput.udiCount | Read the actual position. |
| Position (upper part of ULINT) | ST\_TcPlcDeviceInput.S\_DiReserve[1] | Optional: Reading of the actual position under TC2. |
| Position (upper part of ULINT) | ST\_TcPlcDeviceInput.udiLatch | Optional: Reading of the actual position under TC3. |
| Status | ST\_TcPlcDeviceInput.uiEncDevState | Evaluation of the fault signal of the encoder. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sEncAdsAddr | Address information for parameter communication via CoE. |
| InfoData.State | ST\_TcPlcDeviceInput.uiEncBoxState | Connection monitoring, condition monitoring. |
| WcState | ST\_TcPlcDeviceInput.wEncWcState | Connection monitoring. |

## iTcMc\_EncoderEL5101

The function block handles the evaluation of data from an EL5101 incremental encoder terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Value | ST\_TcPlcDeviceInput.uiCount | Operation: Read the actual position. |
| Latch | ST\_TcPlcDeviceInput.uiLatch | For homing using the synchronous pulse of the encoder. |
| Ctrl | ST\_TcPlcDeviceOutput.usiCtrl | Control of the latch function etc. |
| Status | ST\_TcPlcDeviceInput.usiStatus | Status of the encoder, of the latch function. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sEncAdsAddr | Address information for parameter communication via CoE. |
| InfoData.State | ST\_TcPlcDeviceInput.uiEncBoxState | Connection monitoring, condition monitoring. |
| WcState | ST\_TcPlcDeviceInput.wEncWcState | Connection monitoring. |

## iTcMc\_EncoderEL5111

The function block handles the evaluation of data from an EL5111 incremental encoder terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Value | ST\_TcPlcDeviceInput.uiCount | Operation: Read the actual position. |
| Latch | ST\_TcPlcDeviceInput.uiLatch | For homing using the synchronous pulse of the encoder. |
| Ctrl | ST\_TcPlcDeviceOutput.usiCtrl | Control of the latch function etc. |
| Status | ST\_TcPlcDeviceInput.usiStatus | Status of the encoder, of the latch function. |
| InfoData.AdsAddr | ST\_TcPlcDeviceInput.sEncAdsAddr | Address information for parameter communication via CoE. |
| InfoData.State | ST\_TcPlcDeviceInput.uiEncBoxState | Connection monitoring, condition monitoring. |
| WcState | ST\_TcPlcDeviceInput.wEncWcState | Connection monitoring. |

## iTcMc\_EncoderEL7041

The function block handles the evaluation of data from an EL7041 stepper motor output terminal.

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions, particularly for parameter communication, overlap with those of the drive function block. See also [iTcMc\_DriveEL7041](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

## iTcMc\_EncoderEL7201

The function block handles the evaluation of data from an EL7201 servo output terminal.

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions, particularly for parameter communication, overlap with those of the drive function block. See also iTcMc\_DriveEL7201.

## iTcMc\_EncoderIx5009

The function block handles the evaluation of data from an IP5009 SSI encoder box.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| PZDL\_RegDaten | ST\_TcPlcDeviceInput.uiPZDL\_RegDaten | Operation: Read the actual position.  For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for read data. |
| PZDH | ST\_TcPlcDeviceInput.uiPZDH | Read the actual position. |
| RegStatus | ST\_TcPlcDeviceInput.usiRegStatus | Miscellaneous status information. |

## iTcMc\_EncoderKL2521

The function block handles the evaluation of data from a KL2521 pulse output terminal. The output pulses are counted and used for an encoder emulation.

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions, particularly for parameter communication, overlap with those of the drive function block. See also [iTcMc\_DriveKL2521](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data in | ST\_TcPlcDeviceInput.uiTerminalData | Operation: Read the actual position.  For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for read data. |
| Control | ST\_TcPlcDeviceOutput.bTerminalCtrl | Register communication |
| Status | ST\_TcPlcDeviceInput.bTerminalState | Register communication |
| Data out | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal.  Register communication: Interface for written data. |

## iTcMc\_EncoderKL2531

The function block handles the evaluation of data from a KL2531 pulse output terminal. The output pulses are counted and used for an encoder emulation.

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions, particularly for parameter communication, overlap with those of the drive function block. See also [iTcMc\_DriveKL2531](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Velocity | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal.  For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for written data. |
| Position | ST\_TcPlcDeviceInput.uiTerminalData | Operation: Read the actual position.  For register communication: Interface for read data. |
| Ctrl | ST\_TcPlcDeviceOutput.bTerminalCtrl | Control the output stage, register communication. |
| Status | ST\_TcPlcDeviceInput.bTerminalState | Status of the output stage, register communication. |
| ExtStatus | ST\_TcPlcDeviceInput.uiTerminalState2 | Diagnosis of output stage and motor |

## iTcMc\_EncoderKL2541

The function block handles the evaluation of data from a KL2541 pulse output terminal. The output pulses are counted and used for an encoder emulation.

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions, particularly for parameter communication, overlap with those of the drive function block. See also [iTcMc\_DriveKL2541](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Velocity | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal.  For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for written data. |
| Position | ST\_TcPlcDeviceInput.uiTerminalData | Operation: Read the actual position.  For register communication: Interface for read data. |
| Ctrl | ST\_TcPlcDeviceOutput.bTerminalCtrl | Control the output stage, register communication. |
| Status | ST\_TcPlcDeviceInput.bTerminalState | Status of the output stage, register communication. |
| ExtCtrl | ST\_TcPlcDeviceOutput.uiTerminalCtrl2 | Latch control during homing with the synchronous pulse of the encoder |
| ExtStatus | ST\_TcPlcDeviceInput.uiTerminalState2 | Diagnosis of output stage and motor, latch status during homing with the synchronous pulse of the encoder |

## iTcMc\_EncoderKL2542

The function block handles the evaluation of data from a KL2542 motor output stage terminal.

This I/O device belongs to a group of devices, which are used for the control value output as well as actual value determination. The required mapping definitions, particularly for parameter communication, overlap with those of the drive function block. See also [iTcMc\_DriveKL2542](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data out | ST\_TcPlcDeviceOutput.nDacOut | Operation: Output of the velocity signal.  For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for written data. |
| Data in | ST\_TcPlcDeviceInput.uiTerminalData | Operation: Read the actual position.  For register communication: Interface for read data. |
| Control | ST\_TcPlcDeviceOutput.bTerminalCtrl | Control the output stage, register communication. |
| Status | ST\_TcPlcDeviceInput.bTerminalState | Status of the output stage, register communication. |

## iTcMc\_EncoderKL3002

The function block handles the evaluation of data from a KL3002 analog input terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data in | ST\_TcPlcDeviceInput.uiCount | Read the actual position. |
| Ctrl | ST\_TcPlcDeviceOutput.usiCtrl | [Register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) |
| Status | ST\_TcPlcDeviceInput.usiStatus | Register communication. |

## iTcMc\_EncoderKL3042

The function block handles the evaluation of data from a KL3042 analog input terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data in | ST\_TcPlcDeviceInput.uiCount | Read the actual position. |
| Ctrl | ST\_TcPlcDeviceOutput.usiCtrl | [Register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) |
| Status | ST\_TcPlcDeviceInput.usiStatus | Register communication. |

## iTcMc\_EncoderKL3062

The function block handles the evaluation of data from a KL3062 analog input terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data in | ST\_TcPlcDeviceInput.uiCount | Read the actual position. |
| Ctrl | ST\_TcPlcDeviceOutput.usiCtrl | [Register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) |
| Status | ST\_TcPlcDeviceInput.usiStatus | Register communication. |

## iTcMc\_EncoderKL3162

The function block handles the evaluation of data from a KL3162 analog input terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data in | ST\_TcPlcDeviceInput.uiCount | Read the actual position. |
| Ctrl | ST\_TcPlcDeviceOutput.usiCtrl | [Register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) |
| Status | ST\_TcPlcDeviceInput.usiStatus | Register communication. |

## iTcMc\_EncoderKL5001

The function block handles the evaluation of data from a KL5001 SSI encoder terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| PZDL\_RegDaten | ST\_TcPlcDeviceInput.uiPZDL\_RegDaten | Operation: Read the actual position.  For [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd): Interface for read data. |
| PZDH | ST\_TcPlcDeviceInput.uiPZDH | Read the actual position. |
| RegStatus | ST\_TcPlcDeviceInput.usiRegStatus | Miscellaneous status information. |
| RegDaten | ST\_TcPlcDeviceOutput.bTerminalData | Register communication. |

## iTcMc\_EncoderKL5101

The function block handles the evaluation of data from a KL5101 incremental encoder terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Counter | ST\_TcPlcDeviceInput.uiCount | Operation: Read the actual position.  For register communication: Interface for read data. |
| Latch | ST\_TcPlcDeviceInput.uiLatch | For homing using the synchronous pulse of the encoder. |
| Ctrl | ST\_TcPlcDeviceOutput.usiCtrl | Control of the latch function etc., [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) |
| Status | ST\_TcPlcDeviceInput.usiStatus | Miscellaneous status information. |
| RegDaten | ST\_TcPlcDeviceOutput.bTerminalData | Register communication. |

## iTcMc\_EncoderKL5111

The function block handles the evaluation of data from a KL5111 incremental encoder terminal.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Counter | ST\_TcPlcDeviceInput.uiCount | Operation: Read the actual position.  For register communication: Interface for read data. |
| Latch | ST\_TcPlcDeviceInput.uiLatch | For homing using the synchronous pulse of the encoder. |
| Ctrl | ST\_TcPlcDeviceOutput.usiCtrl | Control of the latch function etc., [register communication](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) |
| Status | ST\_TcPlcDeviceInput.usiStatus | Miscellaneous status information. |
| RegDaten | ST\_TcPlcDeviceOutput.bTerminalData | Register communication. |

## iTcMc\_EncoderLowCostStepper

If the value [iTcMc\_DriveLowCostStepper](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) is entered as nDrive\_Type, the half steps that are output are counted in ST\_TcPlcDeviceOutput.uiCount. The result is used to calculate the actual position. Mapping is not required for the encoder.

|  |  |
| --- | --- |
| 12102778 | This encoder type can only be used in combination with an iTcMc\_DriveLowCostStepperdrive. |

## iTcMc\_EncoderM2510

The function block handles the evaluation of data from an M2510 analog input box.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Data in | ST\_TcPlcDeviceInput.uiCount | Read the actual position. |

## iTcMc\_EncoderM3120

The function block handles the evaluation of data from an M3120 incremental encoder box.

| I/O variable | Interface.Variable | Use |
| --- | --- | --- |
| Value\_N | ST\_TcPlcDeviceInput.uiCount | Read the actual position. |
| State\_N | ST\_TcPlcDeviceInput.usiStatus | Miscellaneous status information. |
| Ctrl\_N | ST\_TcPlcDeviceOutput.usiCtrl | Control of the latch function etc. |

## iTcMc\_EncoderSim

A simulation encoder calculates the actual position through integration of the set velocity. No mapping is required.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
