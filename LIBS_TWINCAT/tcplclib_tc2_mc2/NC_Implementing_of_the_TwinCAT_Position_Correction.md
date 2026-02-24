# NC Implementing of the TwinCAT Position Correction

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Appendix](ms-xhelp:///?Id=beckhoff-cdf2-455c-a8c9-c0f6b150df73)
3. [NC Backlash Compensation](ms-xhelp:///?Id=beckhoff-67c2-4819-9161-d59c0787cef9)
4. NC Implementing of the TwinCAT Position Correction

# NC Implementing of the TwinCAT Position Correction

TwinCAT position correction is used for the backlash compensation.

The following table shows a description of TwinCAT position correction for drives in cyclic position and velocity interfaces.

|  | Implementation and effect of Position Correction resp. Backlash Compensation |
| --- | --- |
| **Implementation** | 1. The backlash correction is subtracted from the required position which is transmitted to the drive. 2. The backlash correction is added to the actual position which is transmitted from the encoder. |
| **Effect in the Position Interface**  (position control in the Drive) | Description / Effect:  By manipulating the required position which is transmitted to the drive the backlash will be driven (subtraction of position correction, see case 1).  To realize that the monitored actual value is correct, this backlash correction is subtracted from the transmitted actual value (addition of the position correction, see case 2). |
| **Effect in the Velocity Interface**  (position control in TwinCAT) | Description / Effect:  In the velocity interface no required position is transmitted to the drive, so correcting the required position would have no effect.  By correcting the actual position which is transmitted from the encoder to the drive a position difference is created. The closed loop position controller in TwinCAT controls, by means of this position difference (“lag error”) that the backlash is driven (addition of the position correction, see case 2). |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
