# Modulo positioning

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-7ffe-4e9a-b17d-c6d5be097acd)
3. [Point to point motion](ms-xhelp:///?Id=beckhoff-619b-45f3-96f0-b675ba1121b8)
4. Modulo positioning

# Modulo positioning

Modulo positioning ([MC\_MoveModulo](ms-xhelp:///?Id=beckhoff-1762-48bc-84a8-3831de16ade0)) is possible irrespective of the axis type. If may be used both for linear or rotary axes, because TwinCAT makes no distinction between these types. A modulo axis has a consecutive absolute position in the range ±∞. The modulo position of the axis is simply a piece of additional information about the absolute axis position. Modulo positioning represents the required target position in a different way. Unlike absolute positioning, where the user specifies the target unambiguously, modulo positioning has some risks, because the required target position may be interpreted in different ways.

## Settings in the AXIS\_REF parameters

Modulo positioning generally refers to a modulo period to be set under *Axis-Parameter. ModuloFactor* of the corresponding AXIS\_REF. In addition, appropriate settings are required in the drive parameters (e.g. EL72xx). The examples on this page assume a rotary axis with a modulo period of 360°.

![64215808](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/9007199325035403__Web.png)

## Special features of axis resets

Axis positioning always refers to the set position. The set position of an axis is normally the target position of the last travel command. An axis reset ([MC\_Reset](ms-xhelp:///?Id=beckhoff-4930-455a-b236-c5815ef9d98d), controller enable with [MC\_Power](ms-xhelp:///?Id=beckhoff-fea8-4855-9315-57e90dde8578)) can lead to a set position that is different from that expected by the user, because in this case the current actual position is used as the set position. The axis reset resets any lag error that may have occurred as a result of this procedure. If this possibility is not considered, subsequent positioning may lead to unexpected behavior.

**Example:**

An axis is positioned to 90°, with the result that subsequently the set position of the axis is exactly 90°. A further modulo travel command to 450° in positive direction results in a full turn, with the subsequent modulo position of the axis is once again exactly 90°. If an axis reset is then carried out, the set position can randomly be somewhat smaller or slightly larger than 90°. The new value depends on the actual value of the axis at the time of the reset. However, the next travel command will lead to different results. If the set position is slightly less than 90°, a new travel command to 90° in positive direction only leads to minimum motion. The deviation created by the reset is compensated, and the subsequent set position is once again exactly 90°. However, if the set position after the axis reset is slightly more than 90°, the same travel command leads to a full turn to reach the exact set position of 90°. This problem occurs if complete turns by 360° or multiples of 360° were initiated. For positioning to an angle that is significantly different from the current modulo position, the travel command is unambiguous.

![41071365](/tcplclib_tc3_drivemotioncontrol/1033/Images/gif/70297611__en-US__Web.gif)

## Modulo positioning by less than one turn

Modulo positioning from a starting position to a non-identical target position is unambiguous and requires no special consideration. A modulo target position in the range [0 ≤ position < 360] reaches the required target in less than one whole turn. No motion occurs if target position and starting position are identical. Target positions of more than 360° lead to one or more full turns before the axis travels to the required target position.

For a movement from 270° to 0°, a modulo target position of 0° (not 360°) should therefore be specified, because 360° is outside the basic range and would lead to an additional turn.

For modulo positioning, a distinction is made between three different directions, i.e. positive direction, negative direction and along shortest path ([MC\_Direction](ms-xhelp:///?Id=beckhoff-6e77-4e66-be8f-f38f46a90f29)). For positioning along the shortest path, target positions of more than 360° are not sensible, because the movement towards the target is always direct. In contrast to positive or negative direction, it is therefore not possible to carry out several turns before the axis moves to the target.

|  |  |
| --- | --- |
| 34097968 | For modulo positioning with start type "along shortest path", only modulo target positions within the basic period (e.g. less than 360°) are permitted, otherwise an error is returned. |

The following table shows some positioning examples:

| Direction (modulo start type) | Absolute starting position | Modulo target position | Relative travel path | Absolute end position | Modulo end position |
| --- | --- | --- | --- | --- | --- |
| Positive direction | 90.00 | 0.00 | 270.00 | 360.00 | 0.00 |
| Positive direction | 90.00 | 360.00 | 630.00 | 720.00 | 0.00 |
| Positive direction | 90.00 | 720.00 | 990.00 | 1080.00 | 0.00 |
|  | | | | | |
| Negative direction | 90.00 | 0.00 | -90.00 | 0.00 | 0.00 |
| Negative direction | 90.00 | 360.00 | -450.00 | -360.00 | 0.00 |
| Negative direction | 90.00 | 720.00 | -810.00 | -720.00 | 0.00 |
|  | | | | | |
| Along shortest path | 90.00 | 0.00 | -90.00 | 0.00 | 0.00 |

## Modulo positioning with full turns

In principle, modulo positioning by one or full turns are no different than positioning to an angle that differs from the starting position. No motion occurs if target position and starting position are identical. For a full turn, 360° has to be added to the starting position.

The reset behavior described above shows that positioning with full turns requires particular attention. The following table shows positioning examples for a starting position of approximately 90°.

| Direction (modulo start type) | Absolute starting position | Modulo target position | Relative travel path | Absolute end position | Modulo end position |
| --- | --- | --- | --- | --- | --- |
| Positive direction | 90.00 | 90.00 | 0.00 | 90.00 | 90.00 |
| Positive direction | 91.10 | 90.00 | 358.90 | 450.00 | 90.00 |
| Positive direction | 88.90 | 90.00 | 1.10 | 90.00 | 90.00 |
|  | | | | | |
| Positive direction | 90.00 | 450.00 | 360.00 | 450.00 | 90.00 |
| Positive direction | 91.10 | 450.00 | 718.90 | 810.00 | 90.00 |
| Positive direction | 88.90 | 450.00 | 361.10 | 450.00 | 90.00 |
|  | | | | | |
| Positive direction | 90.00 | 810.00 | 720.00 | 810.00 | 90.00 |
| Positive direction | 91.10 | 810.00 | 1078.90 | 1,170.00 | 90.00 |
| Positive direction | 88.90 | 810.00 | 721.10 | 810.00 | 90.00 |
|  | | | | | |
| Negative direction | 90.00 | 90.00 | 0.00 | 90.00 | 90.00 |
| Negative direction | 91.10 | 90.00 | -1.10 | 90.00 | 90.00 |
| Negative direction | 88.90 | 90.00 | -358.90 | -270.00 | 90.00 |
|  | | | | | |
| Negative direction | 90.00 | 450.00 | -360.00 | -270.00 | 90.00 |
| Negative direction | 91.10 | 450.00 | -361.10 | -270.00 | 90.00 |
| Negative direction | 88.90 | 450.00 | -718.90 | -630.00 | 90.00 |
|  | | | | | |
| Negative direction | 90.00 | 810.00 | -720.00 | -630.00 | 90.00 |
| Negative direction | 91.10 | 810.00 | -721.10 | -630.00 | 90.00 |
| Negative direction | 88.90 | 810.00 | -1078.90 | -990.00 | 90.00 |

## Modulo calculations within the PLC program

All positioning jobs on an axis are executed based of the set position. The current actual position is only used for control purposes. If a new target position is to be calculated in a PLC program based on the current position, this calculation must be performed with the current set position of the axis (Axis.Status.ModuloSetPos and Axis.Status.ModuloSetTurns).

It is not advisable to perform order calculations based on the actual modulo position, which is available in the axis status (ModuloActPos and ModuloActTurns), Due to the greater or lesser control deviation of the axis, errors in the programmed sequence, such as undesired rotations, could occur.

## Application example

Within a system, a rotational axis carries out an operation. The starting position for each operation is 90°, and with each cycle the axis is to be positioned by 360° in positive direction. Reverse positioning is not permitted for mechanical reasons. Small reverse positioning is acceptable as part of position control movements.

Since the axis may only be pre-positioned, the motion command [MC\_MoveModulo](ms-xhelp:///?Id=beckhoff-1762-48bc-84a8-3831de16ade0) with the modulo startup type "positive direction" (MC\_Positive\_Direction) is used. The modulo target position is specified as 450°, since the original orientation is to be reached again after a full turn by 360°. A modulo target position of 90° would not lead to any motion.

The process starts with a basic positioning movement ([MC\_MoveModulo](ms-xhelp:///?Id=beckhoff-1762-48bc-84a8-3831de16ade0)) to ensure that the starting position is accurate. The step sequence then changes into an execution cycle. In the event of a fault, the axis is reset with [MC\_Reset](ms-xhelp:///?Id=beckhoff-4930-455a-b236-c5815ef9d98d) and subsequently (at the start of the step sequence) moved to its valid starting position. In this case, 90° is specified as the target position so that this position is approached as quickly as possible. No motion occurs if the axis is already at the starting position.

![38446258](/tcplclib_tc3_drivemotioncontrol/1033/Images/gif/70300811__en-US__Web.gif)

Alternatively, the reset step may be carried out at the start of the step sequence, so that the axis is initialized at the start of the process.

## Requirements

| Development environment | PLC libraries to include |
| --- | --- |
| TwinCAT 3.1.4024.11 | Tc3\_DriveMotionControl |

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
