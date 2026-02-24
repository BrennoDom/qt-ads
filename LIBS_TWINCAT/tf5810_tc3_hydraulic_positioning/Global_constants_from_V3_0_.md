# Global constants (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. Global constants (from V3.0)

# Global constants (from V3.0)

## Bit-masks for position cams

These masks are to be used by the application to provide digital movement cams for bActPosCams in ST\_TcHydAxRtData.

| Constant | Description |
| --- | --- |
| bTcHydActPosCamPos | Summary of bTcHydActPosCamHigh and bTcHydActPosCamUp. |
| bTcHydActPosCamHigh | The axis has reached the upper target position. |
| bTcHydActPosCamUp | The axis is located close to the upper target position. |
| bTcHydActPosCamDown | The axis is located close to the lower target position. |
| bTcHydActPosCamLow | The axis has reached the lower target position. |
| bTcHydActPosCamNeg | Summary of bTcHydActPosCamLow and bTcHydActPosCamDown. |

## Bit-masks for axis status information

These masks are to be used by the application to interrogate status signals in nStateDWord in ST\_TcHydAxRtData.

| Constant | Description |
| --- | --- |
| dwTcHydNsDwFunctional | Axis is ready for operation. |
| dwTcHydNsDwReferenced | Axis has been referenced. |
| dwTcHydNsDwSteady | Axis is not active. |
| dwTcHydNsDwInTargRng | The axis is located within a distance from the target position specified by fMonPositionRange in ST\_TcHydAxParam. |
| dwTcHydNsDwInTarget | The axis has been located without interruption since a time specified by fMonTargetFilter within a distance from the target position specified by fMonTargetRange in ST\_TcHydAxParam. |
| dwTcHydNsDwDontTouchProtected | Reserved. Not supported. |
| dwTcHydNsDwStopped | The last movement of the axis was stopped without reaching the specified target position. |
| dwTcHydNsDwBusy | The axis is active. |
| dwTcHydNsDwMoveUp | The axis is moving in the direction of increasing positions. |
| dwTcHydNsDwMoveDown | The axis is moving in the direction of decreasing positions. |
| dwTcHydNsDwReferencing | Axis is homing. |
| dwTcHydNsDwConstVelo | The axis is moving with constant velocity. |
| dwTcHydNsDwExtSetpointActive | The axis is controlled by an [MC\_AxRtSetExtGenValues\_BkPlcMc](ms-xhelp:///?Id=beckhoff-47ec-4355-83da-221f9f967897) function block. |
| dwTcHydNsDwStartedOver | The axis was started, i.e. the last accepted command took effect while the axis was still in motion. |
| dwTcHydNsDwControlActive | Reserved. Not supported. |
| dwTcHydNsDwErrState | The axis is in an error state. |

## Bit-masks for axis enable information

These masks are to be used by the application to provide enable signals in nDeCtrlDWord in ST\_TcHydAxRtData.

| Constant | Description |
| --- | --- |
| dwTcHydDcDwCtrlEnable | Controller enable. This enable is a precondition for the output of control value and controller outputs. |
| dwTcHydDcDwFdPosEna | Advance movement enable in positive direction. This enable is a precondition for the output of control value and controller outputs in the direction of increasing values of position. |
| dwTcHydDcDwCtrlPosEna | Combination of dwTcHydDcDwCtrlEnable and dwTcHydDcDwFdPosEna. |
| dwTcHydDcDwFdNegEna | Advance movement enable in negative direction. This enable is a precondition for the output of control value and controller outputs in the direction of decreasing values of position. |
| dwTcHydDcDwCtrlNegEna | Combination of dwTcHydDcDwCtrlEnable and dwTcHydDcDwFdNegEna. |
| dwTcHydDcDwRefIndex | Referencing cam. |
| dwTcHydDcDwAcceptBlockedDrive | Reserved. Not supported. |
| dwTcHydDcDwBlockedDriveDetected | Reserved. Not fully supported.  This signal suppresses any active velocity controller. |

## Error Codes

These constants are to be used for the outputs of ErrorID from function blocks and for nErrorCode in ST\_TcHydAxRtData.

| Constant | Hexadecimal | Decimal | Description |
| --- | --- | --- | --- |
| dwTcHydAdsErrNoError | 0 | 0 | No error. |
| dwTcHydAdsErrUnknownPort | 16#0006 | 6 | ADS port unknown. Possible causes:   * AMS NetID / ADS port address the wrong runtime system or the wrong computer * another project is running in the addressed PLC * the application does not call a [MC\_AxAdsCommServer\_BkPlcMc](ms-xhelp:///?Id=beckhoff-5702-45de-80d2-87ae2f7a2a8a)() function block |
| dwTcHydAdsErrUnknownTarget | 16#0007 | 7 | Target machine unknown. Possible causes:   * AMS NetID / ADS port address the wrong runtime system or the wrong computer * the target system has not been started * TwinCAT has not been started * the connection is electrically / mechanically interrupted * for communication via Ethernet: the TCP/IP connection is not working |
| dwTcHydAdsErrInvalidIdxGroup | 16#0702 | 1794 | Invalid IndexGroup. Possible causes:   * AMS NetID / ADS port address the wrong runtime system or the wrong computer * another project is running in the addressed PLC * application software error (incorrect combination of ADS port / IdxGroup / IdxOffset) |
| dwTcHydAdsErrInvalidIdxOffset | 16#0703 | 1795 | Invalid IndexOffset. Possible causes:   * AMS NetID / ADS port address the wrong runtime system or the wrong computer * another project is running in the addressed PLC * application software error (incorrect combination of ADS port / IdxGroup / IdxOffset) * attempted access to an array element with invalid index (out of bounds) |
| dwTcHydAdsErrRdWrNotPermitted | 16#0704 | 1796 | Access (write, read) not permitted. Possible causes:   * a write access to a variable without write permission was requested |
| dwTcHydAdsErrInvalidSize | 16#0705 | 1797 | Size (number of bytes) not permitted. Possible causes:   * application software error (incorrect combination of ADS port / IdxGroup / IdxOffset) |
| dwTcHydAdsErrIllegalValue | 16#0706 | 1798 | Value not permitted. Possible causes:   * the transferred value is outside absolute parameter limits * the transferred value is outside parameter limits, which have been specified by other already applicable parameters |
| dwTcHydAdsErrNotReady | 16#0707 | 1799 | Not ready for operation. Possible causes:   * an MC\_Power\_BkPlcMc function block was prompted by its Enable input to activate an axis that is not ready for operation |
| dwTcHydAdsErrBusy | 16#0708 | 1800 | Already active. Possible causes:   * the axis could not accept an instruction because it is already dealing with another task |
| dwTcHydAdsErrNoFile | 16#070C | 1804 | Reserved: File is missing / not accessible. |
| dwTcHydAdsErrSyntax | 16#070D | 1805 | Syntax in command or file invalid. Possible causes:   * invalid characters or character combinations were detected while reading a characteristic curve file stored in ASCII format * incomplete information was detected while reading a characteristic curve file stored in ASCII format |
| dwTcHydAdsErrTimeout | 16#0745 | 1861 | Timeout. Possible causes:   * during a communication the response did not arrive within a designed time  + the chosen time is too short + the connection is interrupted  * the process has prevented processing of the command or delayed it beyond the designated time * the specified commands parameters have increased the time requirement beyond the designated value |
| dwTcHydAdsErrNoAmsAddr | 16#0749 | 1865 | AMS/ADS address missing:   * The ADS address of the device was not mapped to the corresponding variable of the input structure. |
| dwTcHydErrCdNotCompatible | 16#4040 | 16448 | The axis is incompatible with the required function. Possible causes:   * application software error |
| dwTcHydErrCdIllegalOutputNumber | 16#4104 | 16644 | The output number is outside the permitted range. Possible causes:   * an MC\_ReadDigitalOutput\_BkPlcMc or MC\_WriteDigitalOutput\_BkPlcMc function block was called with an invalid parameter. |
| dwTcHydErrCdNotSupport | 16#4107 | 16647 | Function or command not supported. Possible causes:   * application software error |
| dwTcHydErrCdCycleTime | 16#4205 | 16901 | Cycle time (fCycletime in ST\_TcHydAxParam) not permitted. Possible causes:   * Parameterization error |
| dwTcHydErrCdMissingEnc | 16#4210 | 16912 | There is no connection to an encoder interface (pStDeviceInput and/or pStDeviceOutput in [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c)). Possible causes:   * Application software error (the MC\_AxUtiStandardInit\_BkPlcMc function block was not called or not provided with the address of an ST\_TcPlcDeviceInput and an ST\_TcPlcDeviceOutput structure) |
| dwTcHydErrCdMissingDrive | 16#4212 | 16914 | There is no connection to a drive interface (pStDeviceInput and/or pStDeviceOutput in [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c)). Possible causes:   * Application software error (the MC\_AxUtiStandardInit\_BkPlcMc function block was not called or not provided with the address of an ST\_TcPlcDeviceInput and an ST\_TcPlcDeviceOutput structure) |
| dwTcHydErrCdCannotSynchronize | 16#421A | 16922 | Start distance inadequate when an MC\_GearInPos\_BkPlcMc() function block is called. Possible causes:   * the axis is too close to the sync point when the function block is activated * the dynamic axis parameters are inadequate |
| dwTcHydErrCdIllegalGearFactor | 16#421B | 16923 | The parameters of a gear coupling are not permitted. Possible causes:   * the parameter of the function block is not permitted |
| dwTcHydErrCdSoftEnd | 16#4222 | 16930 | The target position is located on the far side of an active software limit switch, and is therefore not permitted. |
| dwTcHydErrCdLowDist | 16#4228 | 16936 | The travel distance is unacceptably small. |
| dwTcHydErrCdIllegalStartType | 16#4239 | 16953 | Invalid start type. |
| dwTcHydErrCdCommandBufferOverflow | 16#423F | 16959 | Command buffer is full. |
| dwTcHydErrCdEncLostCamm | 16#4253 | 16979 | Reserved. Not supported. |
| dwTcHydErrCdCtrlEnaLost | 16#4260 | 16992 | Controller enable was withdrawn during the motion. Possible causes:   * the axis enable was withdrawn at an unexpected time due to a machine logic signal * application software error |
| dwTcHydErrCdEncNoCammFound | 16#429C | 17052 | Reserved. Not supported. |
| dwTcHydErrCdEncNoCammEnd | 16#429D | 17053 | Reserved. Not supported. |
| dwTcHydErrCdEncNoSyncPulse | 16#429E | 17054 | Reserved. Not supported. |
| dwTcHydErrCdAcc | 16#4309 | 17161 | The acceleration is not acceptable. |
| dwTcHydErrCdDec | 16#430A | 17162 | The deceleration is not acceptable. |
| dwTcHydErrCdJerk | 16#430B | 17163 | The jerk limitation is invalid. |
| dwTcHydErrCdPtrPlcMc | 16#4345 | 17221 | No connection to one of the required axis interfaces (pStDeviceInput or pStDeviceOutput in [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c)). |
| dwTcHydErrCdPtrMcPlc | 16#4346 | 17222 | No connection to one of the required axis interfaces (pStDeviceInput or pStDeviceOutput in [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c)). |
| dwTcHydErrCdCtrlEna | 16#4356 | 17238 | Movement without controller enable is not permitted. |
| dwTcHydErrCdNegFdEna | 16#4357 | 17239 | Movement in the direction of reducing positions without the negative direction advance enable is not permitted. |
| dwTcHydErrCdPosFdEna | 16#4358 | 17240 | Movement in the direction of increasing positions without positive direction advance enable is not permitted. |
| dwTcHydErrCdSetVelo | 16#4359 | 17241 | The required velocity is not acceptable. |
| dwTcHydErrCdPehTimeout | 16#435C | 17244 | The axis does not reach the target window within the specified time. |
| dwTcHydErrCdNotMoving | 16#435D | 17245 | The axis is not moving, or not in the correct direction. |
| dwTcHydErrCdConsequential | 16#43A0 | 17312 | Consequential error: The axis was put in an error state due to a problem with another axis. |
| dwTcHydErrCdEncType | 16#4401 | 17409 | The parameter type is invalid. |
| dwTcHydErrCdEncScaling | 16#4406 | 17414 | The increment scaling is not permitted. |
| dwTcHydErrCdEncSyncDist | 16#4414 | 17428 | The distance between Latch\_Enable and the sync pulse is too small. |
| dwTcHydErrCdEncSetActPos | 16#4422 | 17442 | A problem occurred during actual value setting. |
| dwTcHydErrCdPtrPlcEncIn | 16#4442 | 17474 | The axis does not have a pointer to an encoder input interface |
| dwTcHydErrCdPtrPlcEncOut | 16#4443 | 17475 | The axis does not have a pointer to an encoder output interface. |
| dwTcHydErrCdEncUnderrun | 16#4450 | 17488 | Reported by some encoder types: The actual position has passed the lower count limit of the encoder. |
| dwTcHydErrCdEncOverrun | 16#4451 | 17489 | Reported by some encoder types: The actual position has passed the upper count limit of the encoder. |
| dwTcHydErrCdEncHdwFailed | 16#4464 | 17508 | Drive actuator or encoder report a hardware fault. |
| dwTcHydErrCdSsi | 16#4470 | 17520 | An error was detected when operating an SSI encoder. |
| dwTcHydErrCdPosLag | 16#4550 | 17744 | The lag error exceeds an active limit. |
| dwTcHydErrCdDriveType | 16#4601 | 17921 | The value set in nDrive\_Type is not permitted. |
| dwTcHydErrCdRefVelo | 16#4605 | 17925 | Reference velocity (fRefVelo in ST\_TcHydAxParam) is invalid. |
| dwTcHydErrCdStepperStalled | 16#4636 | 17974 | A stall situation was detected. |
| dwTcHydErrCdPtrPlcDriveIn | 16#4642 | 17986 | The axis does not have a pointer to a drive input interface. |
| dwTcHydErrCdPtrPlcDriveOut | 16#4643 | 17987 | The axis does not have a pointer to a drive output interface. |
| dwTcHydErrCdDriveNotReady | 16#4650 | 18000 | Power section not ready for operation. |
| dwTcHydErrCdTblEntryCount | 16#4A02 | 18946 | The number of table entries (rows) is not permitted. |
| dwTcHydErrCdTblInvalidMasterStep | 16#4A04 | 18948 | The table contains entries with invalid master step size. |
| dwTcHydErrCdTblNoInit | 16#4A10 | 18960 | The table is not initialized. |
| dwTcHydErrCdTblIllegalIndex | 16#4A13 | 18963 | Table index not permitted. |
| dwTcHydErrCdTblLineCount | 16#4A15 | 18965 | The number of table entries is too large. |
| dwTcHydErrCdNotStartable | 16#4B01 | 19201 | Axis in a state that does not allow it to start. |
| dwTcHydErrCdFuncTimeout | 16#4B07 | 19207 | The function was not reported as complete within the specified time. |
| dwTcHydErrCdNotReady | 16#4B09 | 19209 | The axis is not in an operable state. |
| dwTcHydErrCdHomingType | 16#4F00 | 20224 | Referencing method (nEnc\_HomingType in ST\_TcHydAxParam) is not permitted. |
| dwTcHydErrCdEncCutOff | 16#4F01 | 20225 | The limit frequency for the actual value acquisition has been exceeded. |
| dwTcHydErrCdIllegalDistance | 16#4F02 | 20226 | Distance is invalid: zero or negative. |
| dwTcHydErrEncDisconected | 16#4FF0 | 20464 | Encoder hardware is uncoupled. Possible causes:   * the fieldbus connection is interrupted * the power supply for the device is not available * the device is faulty * another device, which is located in the fieldbus connection between the controller and the device, has no power supply or is faulty |
| dwTcHydErrDriveDisconected | 16#4FF1 | 20465 | Drive hardware is uncoupled. Possible causes:   * the fieldbus connection is interrupted * the power supply for the device is not available * the device is faulty * another device, which is located in the fieldbus connection between the controller and the device, has no power supply or is faulty |
| dwTcHydErrDistanceInsufficient | 16#4FF2 | 20466 | The travel path is inadequate. |
| dwTcHydErrIllegalAreas | 16#4FF3 | 20467 | Inadmissible effective areas:   * inadmissible values have been entered for the cylinder areas on the valve tab * the combination of the registered areas is not permitted in this way |
| dwTcHydErrIncompleteImplementation | 16#4FF4 | 20468 | The axis implementation is incomplete:   * although the axis is marked with bDriveIsHybrid in its parameters, no MC\_AxRtHybridAxisActuals\_BkPlcMc function block is called * the same instance of type ST\_TcPlcDeviceInput is also transferred to the MC\_AxUtiStandardInit\_BkPlcMc function block of another axis * the same instance of type ST\_TcPlcDeviceOutput is also transferred to the MC\_AxUtiStandardInit\_BkPlcMc function block of another axis * another instance of ST\_TcPlcMcLogBuffer is passed to another axis * the same valid pointer to an instance of ST\_TcPlcCmdBuffer\_BkPlcMc was passed to another axis * the same valid pointer to an instance of ST\_TcMcAutoIdent was passed to another axis |

## Device-specific error codes of function block MC\_Power\_BkPlcMc

These values appear at the **ErrorID** output of an MC\_Power\_BkPlcMc function block, if an error is reported by the external device.

| Constant | Hexadecimal | Decimal | Description |
| --- | --- | --- | --- |
| dwTcHydErrCdAX2000MainPwrTmOut | 16#0001 | 1 | Only for AX2000: no feedback by the mains contactor (timeout during waiting for ST\_TcPlcMcAx2000In.bPowerOk). |
| dwTcHydErrCdAX2000MainPwrFault | 16#0002 | 2 | Only for AX2000: negative edge on feedback from mains contactor (ST\_TcPlcMcAx2000In.bPowerOk). |
| dwTcHydErrCdAX2000PwrStageTmOut | 16#0003 | 3 | Only for AX2000: no feedback from AX output stage (timeout during waiting for ST\_TcPlcMcAx2000In.DriveState[3].6, no Ready). |
| dwTcHydErrCdAX2000PwrStageFault | 16#0004 | 4 | Only for AX2000: Negative edge of AX output stage (ST\_TcPlcMcAx2000In.DriveState[3].6, no Ready). |
| dwTcHydErrCdAX2000ReportsError | 16#0005 | 5 | Only for AX2000: error message from AX device (ST\_TcPlcMcAx2000In.DriveState[3].7 or ST\_TcPlcMcAx2000In.DriveError<>0). |
| dwTcHydErrCdAX2000ErrorI2T | 16#0006 | 6 | Only for AX2000: I2T error message from AX output stage (ST\_TcPlcMcAx2000In.DriveState[0].0). |
| dwTcHydErrCdAX2000ErrorChopper | 16#0007 | 7 | Only for AX2000: brake resistor of the AX output stage faulty (ST\_TcPlcMcAx2000In.DriveState[0].1). |
| dwTcHydErrCdAX2000ErrorWatchDog | 16#0008 | 8 | Only for AX2000: watchdog (timeout during communication) of the AX output stage was triggered (ST\_TcPlcMcAx2000In.DriveState[0].3). |
| dwTcHydErrCdAX2000ErrorPwrLine | 16#0009 | 9 | Only for AX2000: supply error reported by AX output stage (ST\_TcPlcMcAx2000In.DriveState[0].4). |
| dwTcHydErrCdAX2000ConnectionLost | 16#000A | 10 | Only for AX2000: The connection to the AX device is broken or substantially disrupted (ST\_TcPlcMcAx2000In.BoxState<>0). |
| dwTcHydErrCdAX2000ConnectionTmOut | 16#000B | 11 | Only for AX2000: The communication with the AX device could not be established (timeout). |
| dwTcHydErrCdKL2531OverTemp | 16#0001 | 1 | Only for KL2531/KL2541: The KL2531/KL2541 terminal reports overtemperature alarm. |
| dwTcHydErrCdKL2531UnderVoltage | 16#0002 | 2 | Only for KL2531/KL2541: The KL2531/KL2541 terminal reports inadequate supply voltage on the power rail. |
|  | 16#0003 | 3 | Only for KL2531/KL2541: Reserved. |
| dwTcHydErrCdKL2531OpenLoadA | 16#0004 | 4 | Only for KL2531/KL2541: The KL2531/KL2541 terminal reports broken wire on the A-side. |
| dwTcHydErrCdKL2531OpenLoadB | 16#0005 | 5 | Only for KL2531/KL2541: The KL2531/KL2541 terminal reports broken wire on the B-side. |
| dwTcHydErrCdKL2531OverCurrentA | 16#0006 | 6 | Only for KL2531/KL2541: The KL2531/KL2541 terminal reports overcurrent at output stage A. |
| dwTcHydErrCdKL2531OverCurrentB | 16#0007 | 7 | Only for KL2531/KL2541: The KL2531/KL2541 terminal reports overcurrent at output stage B. |
| dwTcHydErrCdKL2531NotReady | 16#0008 | 8 | Only for KL2531/KL2541: The terminal reports a output stage problem (enabled, not ready). |
| dwTcHydErrCdKL2531ConnectionLost | 16#000A | 10 | Only for KL2531/KL2541: The connection to the terminal is broken or substantially disrupted (ST\_TcPlcMcDriveIn.uiBoxState<>0). |
| dwTcHydErrCdKL2531ConnectionTmOut | 16#000B | 11 | Only for KL2531/KL2541: The communication with the terminal could not be established (timeout). |

## ADS Codes

These constants are accepted by the MC\_AxAdsReadDecoder and MC\_AxAdsWriteDecoder function blocks.

| IndexGroup | IndexOffset | Type | R/W | Description |
| --- | --- | --- | --- | --- |
| 16#4000 + axis index | 2 | STRING() | R | Axis name in text form. |
|  | 4 | UDINT | R | Cycle time in microseconds. |
|  | 16#10003 | UDINT | R | Encoder type: nEnc\_Type from ST\_TcHydAxParam. |
|  | 16#10006 | LREAL | R | Incremental evaluation: fEnc\_IncWeighting from ST\_TcHydAxParam. |
|  | 16#30003 | UDINT | R | Drive type: nDrive\_Type from ST\_TcHydAxParam. |
| 16#4100 + axis index | 1 | UDINT | R | Error code: nErrorCode from ST\_TcHydAxRtData. |
|  | 16#10002 | LREAL | R | Actual position: fActPos from ST\_TcHydAxRtData. |
|  | 16#10005 | LREAL | R | Actual velocity: fActVelo from ST\_TcHydAxRtData. |
| 16#4200 + axis index | 1 | - | W | Execute axis reset. |
|  | 16#10 | - | W | Start homing. |
|  | 16#21 | Structure | W | Start axis movement. |
|  | 16#FFFF0001 | - | W | Save parameters. |
|  | 16#FFFF0002 | - | W | Load parameters. |
| 16#4300 + axis index | 16#81 | UDINT | R | Status double word: nStateDWord from ST\_TcHydAxRtData. |
|  | 16#B1 | UDINT | R | Error code: nErrorCode from ST\_TcHydAxRtData. |
| 16#F000 + axis index | 1 | Structure | R | The ST\_TcHydAxRtData variable for the axis. |
|  | 2 | Structure | R/W | The ST\_TcHydAxParam variable for the axis. |
| 16#800F0000 + axis index | [E\_TcMCParameter](ms-xhelp:///?Id=beckhoff-ea11-4506-b969-56d5e1515b02) |  | R/W | Parameters and actual values of the axis. |
| 16#FFFFFFFF | 0 | String() | R | Identification of the server. |
|  | 1 | UINT | R | Major version of the library. |
|  | 2 | UINT | R | Minor version of the library. |
|  | 3 | UINT | R | Release of the library. |
|  | 4 | UINT | R | Number of axes supported |

## Array Dimensions

The following constants used for dimensioning of fields and can be used by the application.

| Constant | Description |
| --- | --- |
| ciBkPlcMc\_CamSwitchRef\_MinIdx | Lower boundary index on an array[] of [CAMSWITCH\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f33f-4253-9407-ea045cafcc25), supplied to blocks of type [MC\_DigitalCamSwitch\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f926-4994-ab22-ff25375bcbfc) |
| ciBkPlcMc\_CamSwitchRef\_MaxIdx | Upper boundary index on an array[] of [CAMSWITCH\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f33f-4253-9407-ea045cafcc25), supplied to blocks of type [MC\_DigitalCamSwitch\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f926-4994-ab22-ff25375bcbfc) |
| ciBkPlcMc\_TrackRef\_MinIdx | Lower boundary index on an array[] of [TRACK\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ee5c-4cd0-a66f-7a08ab2a33b2), supplied to blocks of type [MC\_DigitalCamSwitch\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f926-4994-ab22-ff25375bcbfc) |
| ciBkPlcMc\_TrackRef\_MaxIdx | Upper boundary index on an array[] of [TRACK\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ee5c-4cd0-a66f-7a08ab2a33b2), supplied to blocks of type [MC\_DigitalCamSwitch\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f926-4994-ab22-ff25375bcbfc) |

## Logger Levels

The following constants are used for the specification of the level, from which messages are included in the logger function of the library.

| Constant | Description |
| --- | --- |
| dwTcHydLogLevel\_None | No logging |
| dwTcHydLogLevel\_Errors | Only error messages |
| dwTcHydLogLevel\_Warnings | Error messages and warnings |
| dwTcHydLogLevel\_Actions | Error messages, warnings and activities |

## Logger Sources

The following constants are used to specify the source of messages in the logger function of the library.

| Constant | Description |
| --- | --- |
| dwTcHydLogSource\_Library | A function block of the hydraulics library |
| dwTcHydLogSource\_LibExt\_2R2V | A function block of the 2R2V library |
| dwTcHydLogSource\_Application | A function block of the application |
| dwTcHydLogSource\_ApplicationFramework | A function block of an application platform |

## Logger Argument Types

The following constants are used to specify the type of an optional parameter for a message in the logger function of the library.

| Constant | Description |
| --- | --- |
| dwTcHydLogArgType\_DInt | The message contains a parameter of type DINT. The message text must include a placeholder in the form %d. |
| dwTcHydLogArgType\_LReal | The message contains a parameter of type LREAL. The message text must include a placeholder in the form %f. |
| dwTcHydLogArgType\_String | The message contains a parameter of type STRING. The message text must include a placeholder in the form %s. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
