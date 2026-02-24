# Other Settings

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Other Settings

![27247099](/tf50x0_tc3_nc_ptp/1033/Images/png/3460261771__Web.png)![43897299](/tf50x0_tc3_nc_ptp/1033/Images/png/3460264971__Web.png)![59531373](/tf50x0_tc3_nc_ptp/1033/Images/png/3460258571__Web.png)

## Encoder Mode

The parameter Encoder Mode offers the opportunity to select which values shall be calculated from the encoder position:

* ‘POS’: The actual position is determined.
* ‘POSVELO’: The actual position and the actual velocity are determined.
* ‘POSVELOACC’: The actual position, the actual velocity and the actual acceleration are determined.

![66020315](/tf50x0_tc3_nc_ptp/1033/Images/png/3362603659__Web.png)![57311924](/tf50x0_tc3_nc_ptp/1033/Images/png/3362619659__Web.png)![46045275](/tf50x0_tc3_nc_ptp/1033/Images/png/3362622859__Web.png)

## Position Correction

The Position Correction can be activated at MOTION | NC-Task 1 SAF | Axes | Axis 1 | Parameter.

Alternatively, the Position Correction can be activated at MOTION | NC-Task 1 SAF | Axes | Axis 1 | Enc | Parameter.

Analogously, for different identfiers.

`FALSE`: The Position Correction is disabled.

`TRUE`: The Position Correction is enabled.

The variable `axis.PlcToNc.PositionCorrection` is of data type `LREAL` and belongs to the structure `PLCTONC_AXIS_REF`. If Position Correction is enabled, this variable adds an additional offset onto the target position. Note, that this correction does not affect software limits.

## Filter Time Position Correction (P-T1)

The filter time for the PT-1 filter that filters variations within the Actual Position Correction with the filter time set here. Consult section [PT1 Filter](ms-xhelp:///?Id=beckhoff-603d-4393-806e-9faf331d20fd) for more information on a PT1 filter.

## See also:

## `MC_PositionCorrectionLimiter`

* [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)

The function block `MC_PositionCorrectionLimiter` adds the correction value `PositionCorrectionValue` to the actual position value of the axis. Depending on the `CorrectionMode` the position correction value is either written directly or filtered.

|  |  |
| --- | --- |
| 11754296 | To use the `MC_PositionCorrectionLimiter` function block successfully the Position Correction has to be enabled by setting the parameter Position Correction `TRUE`. |
