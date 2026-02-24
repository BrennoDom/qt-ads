# MC_AxUtiAutoIdent_BkPlcMc (from V3.0.28)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Utilities](ms-xhelp:///?Id=beckhoff-05d5-4e7a-847c-eea5a0277852)
5. [Identification](ms-xhelp:///?Id=beckhoff-43e6-48ab-bc46-4a9c05c23e54)
6. MC\_AxUtiAutoIdent\_BkPlcMc (from V3.0.28)

# MC\_AxUtiAutoIdent\_BkPlcMc (from V3.0.28)

![7035667](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854853899__Web.gif)

The function block automatic determines a number of axis parameters.

```
                    VAR_INPUT  
    Execute:        BOOL;  
    Wait:            BOOL;  
END_VAR
```

```
                                                        VAR_OUTPUT  
    Busy:            BOOL;  
    Done:            BOOL;  
    Error:        BOOL;  
    ErrorID:        UDINT;  
    Step:            INT;  
    InRecovery:    BOOL;  
END_VAR
```

```
            VAR_INOUT  
    Axis:            Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: A rising edge at this input triggers the identification.

**Wait**: (From TC2 V3.0.44 / TC3 V3.3.1.22) If this input is set to TRUE, the internal sequence processor does not go outside the recovery time. This prevents the output value from ramping up when the valves are not yet switched.

**Busy**: Indicates that a command is being processed.

**Done**: This indicates successful identification.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Step**: The current step of the internal sequence processor.

**InRecovery**: (From TC2 V3.0.44 / TC3 V3.3.1.22) This indicates that a recovery time (defined by **ValveCharacteristicRecovery**) has elapsed.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block checks whether the pointer [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).pStAxAutoParams was initialized. If this is the case, it performs a number of initializations when a rising edge is detected at the **Execute** input and then commences the parameter identification. The individual steps of the identification are determined by the values in [ST\_TcMcAutoIdent](ms-xhelp:///?Id=beckhoff-d8cd-4957-b2b8-b8cd53f4d9b3).

**EnableEndOfTravel**: If this boolean parameter is set, the mechanical travel limits are determined automatically. First, the system ensures that the axis can move freely or is at the positive function block. The axis is now moved with a negative control voltage until it has reached the function block. The axis is then operated with a positive control voltage until the positive function block has been detected. The control voltage is limited to **EndOfTravel\_NegativLimit** and **EndOfTravel\_PositivLimit**. If the positive travel limit falls below the negative limit, the values are swapped, and Axis.stAxParams.bDrive\_Reversed is inverted.

**EnableOverlap, EnableZeroAdjust**: If one of these boolean parameter is set, the cover or the offset voltage of the valve is determined.

|  |  |
| --- | --- |
| 63321005 | Thus operation is influenced by EndOfTravel\_Negative and EndOfTravel\_Positive. |

First, the axis is moved into a position window that is located in the middle between **EndOfTravel\_Positive** and **EndOfTravel\_Negative**. The width of the window is 80% of the area defined by these parameters. The output polarity of the drive is inverted, if required. Now, the output voltage is determined, at which the axis starts moving in positive direction. Then, the corresponding negative voltage is determined. By offsetting these parameter, both the cover and the offset voltage are determined. The type of entry in the axis parameter is controlled through **EnableOverlap** and **EnableZeroAdjust**.

**EnableArreaRatio**: If this boolean parameter is set, the direction-dependent velocity ratio is determined. First, the axis is moved into a position window, which is located in the middle between pStAxAutoParams. **EndOfTravel\_Positiv** and pStAxAutoParams. **EndOfTravel\_Negativ**. The width of the window is 80% of the area defined by these parameters. Then, the axis is moved in positive and negative direction for one second with a control voltage of 1 V. The velocities determined during this movement are divided, in order to determine the velocity ratio.

**EndOfTravel\_Negativ**: [mm] If determination of the travel limits is activated, this value is determined by the function block. If it is disabled, the application must specify the value here.

|  |  |
| --- | --- |
| 33018140 | This parameter influences the determination of the offset voltage and the area ratio. |

**EndOfTravel\_Positiv:** [mm] If determination of the travel limits is activated, this value is determined by the function block. If it is disabled, the application must specify the value here.

|  |  |
| --- | --- |
| 28727808 | This parameter influences the determination of the offset voltage and the area ratio. |

**EndOfIncrements\_Negativ**: [1] If determination of the travel limits is activated, this value is determined by the function block. It then matches **EndOfTravel\_Negativ**, but it is the raw encoder value in increments.

**EndOfIncrements\_Positiv**: [1] If determination of the travel limits is activated, this value is determined by the function block. It then matches **EndOfTravel\_Positiv**, but it is the raw encoder value in increments.

**EndOfTravel\_NegativLimit**: [V] This parameter limits negative output voltages.

**EndOfTravel\_PositivLimit**: [V] This parameter limits positive output voltages.

**EndOfTravel\_PositivDone**: This signal is set by the function block, if determination of the travel limits is disabled or the positive travel limit was determined.

**EndOfTravel\_NegativDone**: This signal is set by the function block, if determination of the travel limits is disabled or the negative travel limit was determined.

**EndOfVelocity\_NegativLimit**: [mm/s] This parameter limits negative velocities. If this velocity is reached or exceeded during the measurement, the current measurement is completed, but no further measurement in this direction is performed.

**EndOfVelocity\_PositivLimit**: [mm/s] This parameter limits positive velocities. If this velocity is reached or exceeded during the measurement, the current measurement is completed, but no further measurement in this direction is performed.

**DecelerationFactor**: [1] After the measuring stroke, the axis is moved to the end of the measuring path for the next measuring stroke. The regular axis parameter **fMaxAcc** and **fMaxDec,** which are weighted with this factor, are used.

**EnableValveCharacteristic**: If this boolean parameter is set, the characteristic velocity curve is determined automatically.

**ValveCharacteristicTable**: This ARRAY[1..2,1..100] contains the value pairs of the linearization table. ValveCharacteristicTable[nnn,1] is the normalized velocity value, ValveCharacteristicTable[nnn,2] is the normalized output value. Within the table, the value pairs with increasing index have increasing values for the velocity value and the output value. The first value pair therefore describes the fastest negative point, the last active value pair the fastest positive point. During automatic determination, the control voltage is limited to **EndOfTravel\_NegativLimit** and **EndOfTravel\_PositivLimit** and the velocity to **EndOfVelocity\_NegativLimit** and **EndOfVelocity\_PositivLimit**. The further points of the table are determined through extrapolation from the last two measuring points.

**ValveCharacteristicType**: The identification can be adapted here to special valve variants or special conditions of the axis. See also [E\_TcMcValveType](ms-xhelp:///?Id=beckhoff-1d3a-41d4-85d1-c521d18dbbab).

**ValveCharacteristicTblCount**: This parameter specifies the number of value pairs to be determined in **ValveCharacteristicTable**. The value must be odd and between 3 and 99 (including).

**ValveCharacteristicLowEnd**: [mm] The lower end position of the range permitted for determining the characteristic curve.

**ValveCharacteristicHighEnd**: [mm] The upper end position of the range permitted for determining the characteristic curve.

ValveCharacteristicRamp: [s] This parameter specifies the ramp for establishing the measuring voltage for the characteristic curve determination. During the specified time the voltage is increased to 10 V. Since the actual voltages are generally lower, less time is usually required to establish the voltage. Please pay attention to the notes at the end of this document.

ValveCharacteristicSettling: [s] Once the control value has been ramped up to the test level for the measurement, the starting of the measurement can be delayed through this parameter. Please pay attention to the notes at the end of this document.

**ValveCharacteristicRecovery**: [s] This parameter defines a dwell time, which is adhered to before the measurement travel. This enables the supply to compensate a pressure drop that may have been caused by the previous measurement travel.

|  |  |
| --- | --- |
| 57223682 | During this time the axis is not controlled. |

From TC2 V3.0.44 / TC3 V3.3.1.22: The expiry of the dwell time is indicated at the **InRecovery** output.

**ValveCharacteristicMinCycle**: [mm] The measurement travel is only valid if the measuring voltage was established before the axis has moved towards the center of the measuring distance defined by **ValveCharacteristicHighEnd** and **ValveCharacteristicLowEnd** by less than the half of this value. Otherwise the effective measuring distance (without ramps) is less than this distance, and this measurement and all further measurements in this direction are replaced by a value calculated using the reference velocity of the axis.

**Valve\_LinLimitP, Valve\_LinLimitM:** [mm/s] The lowest velocity for using the linearization table. For lower velocities, the characteristic curve is replaced by a straight line that connects the zero point with the point for the velocity specified here.

**Sample**: Diagram of a characteristic curve determination in TwinCAT ScopeView:

![45251091](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600115339__Web.gif)

**Sample**: Display of a linearization in the PlcMcManager:

![4606636](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600064267__Web.gif)

The characteristic curve determined in this way can be used with an MC\_AxRtFinishLinear\_BkPlcMc function block for linearization at runtime.

|  |  |
| --- | --- |
| 41459726 | The characteristic curve is stored in the parameter file of the axis and automatically read on system startup. |

Irrespective of that, the linearization table can be imported from a [text or binary file](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) with an [MC\_LinTableImportFromAsciFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-cb84-41ca-bd1c-281a5c81f629) or [MC\_LinTableImportFromBinFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1afc-4f33-a3b7-d5196ffc6065) function block, or exported with an [MC\_LinTableExportToAsciFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-7b5f-4485-91c5-cf897aaf1d5c) or [MC\_LinTableExportToBinFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-dc08-447c-8568-c4d63e15bc88) function block.

|  |  |
| --- | --- |
| 37593218 | If a lower speed than at the previous measuring point is detected in the same direction during the measurement at a test output, a warning is issued regardless of the set logger limit. The measuring point is automatically corrected to avoid falling characteristic ranges. This correction has no influence on the validity of the characteristic curve. However, it should be checked whether the values in ValveCharacteristicRamp and ValveCharacteristicSettling are suitable for this axis. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
