# E_SuperpositionMode

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Motion](ms-xhelp:///?Id=beckhoff-2107-47ed-8b8e-b9259019655e)
4. E\_SuperpositionMode

# E\_SuperpositionMode

```
TYPE E_SuperpositionMode :  
(  
    SUPERPOSITIONMODE_VELOREDUCTION_ADDITIVEMOTION := 1,  
    SUPERPOSITIONMODE_VELOREDUCTION_LIMITEDMOTION,  
    SUPERPOSITIONMODE_LENGTHREDUCTION_ADDITIVEMOTION,  
    SUPERPOSITIONMODE_LENGTHREDUCTION_LIMITEDMOTION,  
    SUPERPOSITIONMODE_ACCREDUCTION_ADDITIVEMOTION, (from TwinCAT 2.11)  
    SUPERPOSITIONMODE_ACCREDUCTION_LIMITEDMOTION (from TwinCAT 2.11)  
);  
END_TYPE
```

E\_SuperpositionMode determines how a superimposed motion is carried out with the function block [MC\_MoveSuperImposed](ms-xhelp:///?Id=beckhoff-5d13-4934-bf02-f97d70604dd7).

The modes referred to as "Veloreduction" execute a superimposed movement with minimum velocity change, preferentially over the full parameterized compensation section. Conversely, the modes referred to as "Lengthreduction" use the maximum possible velocity and therefore reduce the required distance. In both cases same distance is compensated.

In cases referred to as "Additivemotion", the superimposed axis executes a longer or shorter movement than indicated by "Length", with the difference described by Distance. These modes are used, for example, if the Length parameter refers to a reference axis and the superimposed axis may move by a longer or shorter distance in comparison.

In cases referred to as "Limitedmotion", the superposition is completed within the parameterized distance. These modes are used, for example, if the Length parameter refers to the superimposed axis itself. With these modes it should be noted that the superimposed Distance must be significantly shorter than the available "Length".

**SUPERPOSITIONMODE\_VELOREDUCTION\_ADDITIVEMOTION**

The superimposed motion takes place over the whole "Length". The specified maximum change in velocity "VelocityDiff" is reduced in order to reach the required "Distance" over this length.

"Length" refers to a reference axis without superimposed movement (e.g. master axis). The travel path of the axis affected by this compensation is Length + Distance.

**SUPERPOSITIONMODE\_VELOREDUCTION\_LIMITEDMOTION**

The superimposed motion takes place over the whole "Length". The specified maximum change in velocity "VelocityDiff" is reduced in order to reach the required "Distance" over this length.

The "Length" refers to the axis affected by the compensation. During compensation, the travel path of this axis is "Length".

**SUPERPOSITIONMODE\_LENGTHREDUCTION\_ADDITIVEMOTION**

The distance of the superimposed motion is as short as possible and the speed is as high as possible. Although neither the maximum velocity change "VelocityDiff" nor the maximum "Length" are exceeded.

"Length" refers to a reference axis without superimposed movement (e.g. master axis). The maximum travel path of the axis affected by this compensation is "Length + Distance".

**SUPERPOSITIONMODE\_LENGTHREDUCTION\_LIMITEDMOTION**

The distance of the superimposed motion is as short as possible and the speed is as high as possible. Although neither the maximum velocity change "VelocityDiff" nor the maximum "Length" are exceeded.

The "Length" refers to the axis affected by the compensation. During compensation, the maximum travel path of this axis is "Length".

**SUPERPOSITIONMODE\_ACCREDUCTION\_ADDITIVEMOTION** (from TwinCAT 2.11)

The superimposed movement takes place over the whole "Length". The specified maximum acceleration (parameter "Acceleration" or "Deceleration") is reduced as far as possible, in order to reach the specified "Distance" on this path.

"Length" refers to a reference axis without superimposed movement (e.g. master axis). The travel path of the axis affected by this compensation is "Length + Distance".

**SUPERPOSITIONMODE\_ACCREDUCTION\_LIMITEDMOTION** (from TwinCAT 2.11)

The superimposed movement takes place over the whole "Length". The specified maximum acceleration (parameter "Acceleration" or "Deceleration") is reduced as far as possible, in order to reach the specified "Distance" on this path.

The "Length" refers to the axis affected by the compensation. During compensation, the travel path of this axis is "Length".

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
