# Steinel

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Third-party function blocks](ms-xhelp:///?Id=beckhoff-3be5-46f6-9609-796403dd277e)
5. Steinel

# Steinel

## Function blocks

The company Steinel has defined its own DALI commands. These commands extend beyond the possible DALI commands in accordance with the IEC 62386 standard. However, these commands are only applicable to certain Steinel devices. Please contact Steinel for a more detailed description of the commands.

| Name | Description |
| --- | --- |
| [FB\_DALIV2xSteinelLiveLinkMotionSensor](ms-xhelp:///?Id=beckhoff-031b-4df0-9a94-45755ed269e0) | This function block evaluates the measured brightness and presence of the Steinel LiveLink DALI control unit. This function block can also be used to initialize the DALI control units. |
| **FB\_DALIV2xSteinelSetBrightnessChangeLevel** | Sets the *Brightness Change Level* value. |
| **FB\_DALIV2xSteinelSetBrightnessChangeTimer** | Sets the time for the *Brightness Change Timer*. |
| **FB\_DALIV2xSteinelSetEventFilter** | This function block sets the event filter for the respective control unit instance. |
| **FB\_DALIV2xSteinelSetMotionDetectionRange** | Sets the size of the detection area. |
| **FB\_DALIV2xSteinelSetMotionTimer** | Sets the time for the *Motion Timer*. |
| **FB\_DALIV2xSteinelSetMotionTimerRepeat** | Sets the time for *Motion Timer Repeat*. |
| **FB\_DALIV2xSteinelSetMotionVerificationLevel** | Sets the sensitivity for the motion sensor. |
| **FB\_DALIV2xSteinelSetSignalLedStatus** | Switches the LEDs in the control unit. |
| **FB\_DALIV2xSteinelQueryBrightnessChangeLevel** | Queries the *Brightness Change* Level value. |
| **FB\_DALIV2xSteinelQueryBrightnessChangeTime**r | Queries the time for the *Brightness Change* Timer. |
| **FB\_DALIV2xSteinelQueryEventFilter** | Queries the event filter for the respective control unit instance. |
| **FB\_DALIV2xSteinelQueryMotionDetectionRange** | Queries the size of the detection area. |
| **FB\_DALIV2xSteinelQueryMotionTimer** | Queries the time of the Motion Timer. |
| **FB\_DALIV2xSteinelQueryMotionTimerRepeat** | Queries the time of the *Motion Timer* Repeat. |
| **FB\_DALIV2xSteinelQueryMotionVerificationLevel** | Queries the sensitivity of the motion sensor. |
| **FB\_DALIV2xSteinelQuerySensorType** | Queries the sensor type. |
| **FB\_DALIV2xSteinelQuerySignalLedStatus** | Queries the LEDs in the control unit. |

Further Information

* [FB\_DALIV2xSteinelLiveLinkMotionSensor](ms-xhelp:///?Id=beckhoff-031b-4df0-9a94-45755ed269e0)

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
