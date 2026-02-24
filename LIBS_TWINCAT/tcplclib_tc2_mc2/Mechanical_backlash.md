# Mechanical backlash

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Appendix](ms-xhelp:///?Id=beckhoff-cdf2-455c-a8c9-c0f6b150df73)
3. [NC Backlash Compensation](ms-xhelp:///?Id=beckhoff-67c2-4819-9161-d59c0787cef9)
4. Mechanical backlash

# Mechanical backlash

Mechanical backlash is the difference in position between a drive or an encoder and the load. Mechanical backlash arises due mechanical tolerances in the drivetrain. This causes a difference between the required and the actual position of the load. This is especially important when the direction of motion is reversed.

There are three types of mechanical backlash:

## Positive backlash

Positive backlash occurs in systems where the measuring system is directly coupled to the drive. In this case the backlash exists between the drive and the load. When the direction of motion is reversed, the measuring system will detect a change in position before the load has moved. So the encoder, which here measures the position of the load indirectly, leads the actual position of the load. As a consequence, the load will not reach the required position, it will be shorten by the length of the backlash.

In the figure below, a movement from left to right is defined as a positive movement.

![912076](/tcplclib_tc2_mc2/1033/Images/png/9749165963__Web.png)

The encoder leads the load (e.g. machine table), so the measured encoder position, leads the actual position of the table. Therefore the table’s movement will be too short.

In this case enter a positive correction value for the backlash (= normal case).

## Negative backlash

Negative backlash occurs in systems where a mechanical tolerance exists between the drive and the measuring system. When the direction of motion is reversed the load immediately moves in the new direction and the measuring system won’t detect the changed position. In this case the load will travel further than required. The encoder, which measures the position of the load directly, lags behind the actual position of the machine part.

![8208684](/tcplclib_tc2_mc2/1033/Images/png/9749167883__Web.png)

The encoder lags behind the actual position of the load (e.g. machine table). Therefore the table will travel too far.

In this case enter a negative correction value for the backlash.

## Neutral backlash

In systems, neutral backlash is an exception. In this case the measuring system is directly coupled to the load and electrically connected with the drive. Here the encoder position and the load position are the same. Now when the drive’s direction of motion is reversed, the backlash will be automatically compensated. The position control loop is closed around the drivetrain because the encoder is coupled to the load directly. The required position can be reached with no further compensation.

![6769295](/tcplclib_tc2_mc2/1033/Images/png/9749169803__Web.png)

|  |  |
| --- | --- |
| 60923663 | The encoder is directly coupled with the load (e.g. machine table) and ensuring steady state accuracy. No special settings are required. |

## General Hints and Notes:

* Implemention of positive or negative backlash compensation is the same in TwinCAT (only the sign of the backlash value differs). A positive backlash is parameterized as positive value, a negative as negative value.
* A negative backlash is undesirable, because an axis with a backlash in the encoder system is difficult to control (stationery vibrations / oscillations). Typically there are further steps necessary to solve this problem.
* It is not necessary to differentiate between position interface (position control in the drive) and velocity interface (position control in TwinCAT), because they have the same effect. This applies to all variants of backlashes.
* In case of neutral backlash there is no compensation action necessary, even though there is a mechanical backlash. The encoder system is coupled to the machine table therefore enforcing steady state accuracy.
* If a referencing (homing) of an axis is necessary, do the homing with backlash compensation deactivated also position correction deactivated. The last driving direction defines if the left or the right edge is the point of reference by defining a reference position (see [NC Implementing the TwinCAT Backlash Compensation](ms-xhelp:///?Id=beckhoff-c6cf-409f-a065-cff6d797f318)).

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
