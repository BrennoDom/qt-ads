# MC_GroupReadBlockerStatus

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_GroupReadBlockerStatus

![23313778](/tf5410_tc3_collision_avoidance/1033/Images/png/8823266187__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 8497414 | 9367865 | 17201924 |

This function block reads the current blocker status.

## 20599592 VAR\_INPUT

```
VAR_INPUT  
    Enable         : BOOL;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Enable | BOOL | Activates reading of the current blocker status. |

## 51178607 57954280 VAR\_IN\_OUT

```
VAR_IN_OUT  
    AxesGroup      : AXES_GROUP_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to an axis group (see [Cyclic Group Interface](ms-xhelp:///?Id=beckhoff-d971-4c2c-bc13-01a1eba0d39b)). |

## 51826478 VAR\_OUTPUT

```
VAR_OUTPUT  
    Valid          : BOOL;  
    Blocked        : BOOL;  
    BlockerId      : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Valid | BOOL | Returns `TRUE` if a valid group type is used. Only the group type MC Group Coordinated Motion is allowed. |
| Blocked | BOOL | Returns `TRUE` if a blocking job is active, i.e. execution of the path is stopped. Returns `FALSE` if no blocking job is active. |
| BlockerId | UDINT | Id of the blocker. Can be any UDINT >0. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT V3.1.4024.7  TF5400 Advanced Motion Pack V3.1.10.1 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
