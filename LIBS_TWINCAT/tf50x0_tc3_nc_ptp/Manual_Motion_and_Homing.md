# Manual Motion and Homing

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Manual Motion and Homing

![17425743](/tf50x0_tc3_nc_ptp/1033/Images/png/3362539659__Web.png)![22613965](/tf50x0_tc3_nc_ptp/1033/Images/png/3362555659__Web.png)![2199097](/tf50x0_tc3_nc_ptp/1033/Images/png/3362530059__Web.png)

## bCalibrationCam

A boolean input of `MC_Home`. It evaluates the signal of a reference cam. This reference signal may be coupled into the control unit via a digital input.

## Homing Velocity (towards plc cam)

Velocity used by an `MC_Home` function block driving towards a reference cam within the standard homing sequence when the `HomingMode` `MC_DefaultHoming` is selected and the input `bCalibrationCam` is evaluated.

## Homing Velocity (off plc cam)

Velocity used by an `MC_Home` function block driving off a reference cam within the standard homing sequence when the `HomingMode` `MC_DefaultHoming` is selected and the input `bCalibrationCam` is evaluated.

![19791876](/tf50x0_tc3_nc_ptp/1033/Images/png/3362539659__Web.png)![43909159](/tf50x0_tc3_nc_ptp/1033/Images/png/3362555659__Web.png)![59638115](/tf50x0_tc3_nc_ptp/1033/Images/png/3362536459__Web.png)

## Buttons in the Online Dialog

The buttons -- F1, - F2, + F3 and ++ F4 are in the “MOTION | NC-Task 1 SAF | Axes | Axis 1 | Online” dialog.

![66980994](/tf50x0_tc3_nc_ptp/1033/Images/png/2833866251__Web.png)

## Manual Velocity (Fast)

**Online**

Velocity used for MOTION | NC-Task 1 SAF | Axes | Axis 1 | Online | -- F1.

Velocity used for MOTION | NC-Task 1 SAF | Axes | Axis 1 | Online | ++ F4.

Analogously, for different identifiers.

**MC\_Jog**

Velocity used by an `MC_Jog` function block applied on the axis when its input `JogForward` or its input `JogBackwards` is `TRUE` and `MC_JOGMODE_STANDARD_FAST` is selected as its `Mode`.

## Manual Velocity (Slow)

**Online**

Velocity used for MOTION | NC-Task 1 SAF | Axes | Axis 1 | Online | - F2.

Velocity used for MOTION | NC-Task 1 SAF | Axes | Axis 1 | Online | + F3.

Analogously, for different identifiers.

**MC\_Jog**

Velocity used by an `MC_Jog` function block applied on the axis when its input `JogForward` or its input `JogBackwards` is `TRUE` and `MC_JOGMODE_STANDARD_SLOW` is selected as its `Mode`.

![65958035](/tf50x0_tc3_nc_ptp/1033/Images/png/3362539659__Web.png)![56751409](/tf50x0_tc3_nc_ptp/1033/Images/png/3362555659__Web.png)![41000636](/tf50x0_tc3_nc_ptp/1033/Images/png/3362533259__Web.png)

## Jog Increment (Forward)

Unused.

Explicitly, this parameter is not used in any current TC3 motion library. Still, this parameter itself can be read or be written or be employed by the user indirectly, e.g. within a user-made function block or within an HMI.

## Jog Increment (Backward)

Unused.

Explicitly, this parameter is not used in any current TC3 motion library. Still, this parameter itself can be read or be written or be employed by the user indirectly, e.g. within a user-made function block or within an HMI.

## MC\_JOGMODE\_INCHING

The `MC_Jog` function block enables an axis to be moved via manual keys. The key signal can be linked directly to the `JogForward` or the `JogBackwards` input. The desired operating mode is prescribed by the input `Mode`. Applying mode `MC_JOGMODE_INCHING` a rising edge at one of the jog inputs moves the axis by a certain distance that is assigned at the input `Position`.

## Additional Information: `MC_Jog`

Following

* [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc) or  
  https://infosys.beckhoff.com/content/1033/tcplclib\_tc2\_mc2/index.html

you can find further information on `MC_Jog`.
