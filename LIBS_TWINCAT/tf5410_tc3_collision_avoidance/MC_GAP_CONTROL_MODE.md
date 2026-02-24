# MC_GAP_CONTROL_MODE

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_GAP\_CONTROL\_MODE

The MC\_GAP\_CONTROL\_MODE data type can be used to specify the Gap Control Mode at the function block level.

```
TYPE MC_GAP_CONTROL_MODE :  
(  
    mcGapControlModeGroupDefault := 16#0,  
    mcGapControlModeStandard := 16#1,  
    mcGapControlModeFast := 16#2  
    mcGapControlModeNone := 16#3  
) UDINT;  
END_TYPE
```

This data type can only be used at the "GapControlMode" FB input, which is present in all motion function blocks in [Tc3\_McCollisionAvoidance](ms-xhelp:///?Id=beckhoff-c15f-4bbe-8970-db11b2d02a22).

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| mcGapControlModeGroupDefault | UDINT | This value indicates that the GapControlMode set in the group parameters should be used for this motion command. |
| mcGapControlModeStandard | UDINT | See the description for [MC\_DEFAULT\_GAP\_CONTROL\_MODE](ms-xhelp:///?Id=beckhoff-d90d-4490-ac5e-9994968809c8). |
| mcGapControlModeFast | UDINT | See the description for [MC\_DEFAULT\_GAP\_CONTROL\_MODE](ms-xhelp:///?Id=beckhoff-d90d-4490-ac5e-9994968809c8). |
| mcGapControlModeNone | UDINT | This value indicates that the Gap Control is not active in the command. After the command, the Standby Gap Control takes effect again with the mode, which is set in the group and the gap size of the last valid command. |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
