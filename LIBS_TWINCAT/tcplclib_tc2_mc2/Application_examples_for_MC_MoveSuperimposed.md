# Application examples for MC_MoveSuperimposed

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Superposition](ms-xhelp:///?Id=beckhoff-1c4d-4ef6-81de-ab45bc73a928)
4. Application examples for MC\_MoveSuperimposed

# Application examples for MC\_MoveSuperimposed

The function block [MC\_MoveSuperimposed](ms-xhelp:///?Id=beckhoff-5d13-4934-bf02-f97d70604dd7) starts a superimposed movement on an axis that is already moving. For this superposition various applications are available that are described below.

## Distance correction for products on a conveyor belt

A conveyor belt consists of individual segments, each driven by an axis. The conveyor belt is used for transporting packages, the spacing of which is to be corrected. To this end a conveying segment must briefly run faster or slower relative to a following segment.

![26597492](/tcplclib_tc2_mc2/1033/Images/gif/70323211__en-US__Web.gif)The measured distance is 1800 mm and is to be reduced to 1500 mm. Conveyor belt 1 should be accelerated in order to reduce the distance. The correction must be completed by the time the end of belt 1 is reached in order to prevent the package being pushed onto the slower belt 2.

Since in this situation conveyor 1 has to be accelerated the drive system requires a velocity reserve, assumed to be 500 mm/s in this case. In practice this value can be determined from the difference between the maximum conveyor speed and the current set velocity.

For parameterization of function block [MC\_MoveSuperimposed](ms-xhelp:///?Id=beckhoff-5d13-4934-bf02-f97d70604dd7) this means:

Distance = 1800 mm - 1500 mm = 300 mm (distance correction)

Length = 1000 mm (available distance up to the end of belt 1)

Mode = SUPERPOSITIONMODE\_VELOREDUCTION\_LIMITEDMOTION

VelocityDiff = 500 mm/s

The "mode" defines that the distance "Length" up to the end of the conveyor belt is used for the correction and that the correction is completed at this point. The system uses the internally calculated velocity as degree of freedom. "VelocityDiff" therefore is the upper limit for the velocity change in this case.

Alternatively the correction could be achieved by decelerating belt 2. In this case, "Distance" must be specified as a negative value, and the available correction distance "Length" is the distance between the packet on the right and the end of the belt. The maximum possible velocity change "VelocityDiff" corresponds to the current set velocity. Belt 2 could therefore be decelerated down to zero, if necessary.

## Phase shift of a print roller

A print roller rotates with constant peripheral velocity at the same speed as conveyor belt on which a workpiece to be printed is transported. For synchronization with the workpiece the print roller is to be advanced by a certain angle (phase shift).

![38050837](/tcplclib_tc2_mc2/1033/Images/gif/70326411__en-US__Web.gif)

The phase shift can be implemented in two ways:

* The angle can be corrected as quickly as possible, resulting in a short-term strong increase in the velocity of the print roller.
* A correction distance can be defined within which the correction can take place, e.g. a full roller revolution. This results in the following possibilities for parameterization of the function block [MC\_MoveSuperimposed](ms-xhelp:///?Id=beckhoff-5d13-4934-bf02-f97d70604dd7).

**Fast correction:**

Distance = 7.1°

Length = 360° (maximum possible correction distance)

Mode = SUPERPOSITIONMODE\_LENGTHREDUCTION\_LIMITEDMOTION

VelocityDiff = 30°/s (velocity reserve)

The "mode" specifies that the correction distance should be as short as possible. The stated value for "Length" therefore is an upper limit that can be chosen freely (but not too small).

Alternatively SUPERPOSITIONMODE\_VELOREDUCTION\_ADDITIVEMOTION can be used as "Mode". In this case the whole correction distance would be up to 367.1°. Since the distance should be as short as possible both modes are equivalent in this case.

**Slow correction:**

Distance = 7.1°

Length = 360° (correction distance)

Mode = SUPERPOSITIONMODE\_VELOREDUCTION\_LIMITEDMOTION

VelocityDiff = 30°/s (velocity reserve)

The mode specifies that the correction distance should be utilized fully and the velocity change should be kept as small as possible. The stated value for "VelocityDiff" therefore is an upper limit that can be chosen freely (but not too small).

## Drilling unit

A drilling unit should drill two holes in a moving workpiece. Synchronization for the first hole is assumed to be achieved via the flying saw (MC\_GearInPos) and is not be considered here. After the first operation the device must be moved by certain distance relative to the moving workpiece.

![6913218](/tcplclib_tc2_mc2/1033/Images/gif/70329611__en-US__Web.gif)

The drilling unit is to be advanced by 250 mm relative to the workpiece after the first hole has been drilled. Meanwhile the workpiece covers a distance of 400 mm. From this position the drilling unit is once again synchronous with the workpiece and the second hole can be drilled.

Here too two options are available that differ in terms of the velocity change of the drilling device and therefore in the mechanical strain.

Parameterization of function block [MC\_MoveSuperimposed](ms-xhelp:///?Id=beckhoff-5d13-4934-bf02-f97d70604dd7):

**Fast correction:**

Distance = 250 mm

Length = 400 mm

Mode = SUPERPOSITIONMODE\_LENGTHREDUCTION\_ADDITIVEMOTION

VelocityDiff = 500 mm/s (velocity reserve of the drilling device)

The mode specifies that the correction distance should be as short as possible. The stated value for "Length" therefore is an upper limit that can be chosen freely (but not too small). The drilling unit can travel a larger distance since "Length" refers to the workpiece plus a relative change in position.

**Slow correction:**

Distance = 250 mm

Length = 400 mm

Mode = SUPERPOSITIONMODE\_VELOREDUCTION\_ADDITIVEMOTION

VelocityDiff = 500 mm/s (velocity reserve of the drilling device)

"Mode" specifies that the correction distance should be utilized fully and the velocity change should be kept as small as possible. The stated value for "VelocityDiff" therefore is an upper limit that can be chosen freely (but not too small). During the change in position the workpiece covers the distance "Length", the drilling unit travels 650 mm due to the additional correction distance (Length + Distance).

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
