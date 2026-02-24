# MC_GearInPosDefaultDynamicsAfterSync

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_GearInPosDefaultDynamicsAfterSync

```
TYPE MC_GearInPosDefaultDynamicsAfterSync  :  
(    MaximumSlaveDynamics  := 16#0,  
     JobDynamics  := 16#1  
);  
END_TYPE
```

Defines the default dynamics used for the MC\_GearInPosCA command after the slave axis has become synchronous for the first time (see [ST\_GearInPosCAOptions](ms-xhelp:///?Id=beckhoff-dfb7-4eea-8762-2deabb22447e)).

|  |  |
| --- | --- |
| **MaximumSlaveDynamics:** | The maximum slave axis dynamics (velocity, acceleration, deceleration) is used as the default value for the AfterSyncDynamics. The jerk is not limited. |
| **JobDynamics:** | Job Dynamics (GearInPosCAs velocity, acceleration, deceleration and jerk) is used as the default value for AfterSyncDynamics. |
