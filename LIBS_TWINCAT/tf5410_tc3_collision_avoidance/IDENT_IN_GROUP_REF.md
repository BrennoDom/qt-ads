# IDENT_IN_GROUP_REF

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# IDENT\_IN\_GROUP\_REF

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
| MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 66570199 | 62260885 | 23477058 |

IDENT\_IN\_GROUP\_REF defines how an axis is interpreted in a group. For multi-dimensional movements global variables can be used. For PTP Collision Avoidance groups the function [UDINT\_TO\_IDENTINGROUP](ms-xhelp:///?Id=beckhoff-4e24-46b0-ba59-5c9ff8c98bdb) has to be called.

|  |  |
| --- | --- |
| 9966935 | Using integer values for input IdentInGroup  Using integer values for input IdentInGroup is NOT supported and may lead to incompatibility to future releases. Using integer values the project may not build anymore. It is recommended to use [global variables](ms-xhelp:///?Id=beckhoff-ede2-46d7-9ee0-7c0526b88aa2) (e.g. MCS\_X) or conversion function [UDINT\_TO\_IDENTINGROUP](ms-xhelp:///?Id=beckhoff-4e24-46b0-ba59-5c9ff8c98bdb). |

The constants below define axes as Cartesian axes in the machine coordinate system (MCS). A to C define the rotation axis (C: Rotation around Z; B: Rotation around Y; A: Rotation around X). The number defines the rotation order. For example if one axis is defined MCS\_C1 and another MCS\_B2 the system rotates first around Z axis and second around Y axis

```
VAR_GLOBAL  
    MCS_X                           : IDENT_IN_GROUP_REF;  
    MCS_Y                           : IDENT_IN_GROUP_REF;  
    MCS_Z                           : IDENT_IN_GROUP_REF;  
      
    MCS_A1                          : IDENT_IN_GROUP_REF;  
    MCS_A2                          : IDENT_IN_GROUP_REF;  
    MCS_A3                          : IDENT_IN_GROUP_REF;  
      
    MCS_B1                          : IDENT_IN_GROUP_REF;  
    MCS_B2                          : IDENT_IN_GROUP_REF;  
    MCS_B3                          : IDENT_IN_GROUP_REF;  
      
    MCS_C1                          : IDENT_IN_GROUP_REF;  
    MCS_C2                          : IDENT_IN_GROUP_REF;  
    MCS_C3                          : IDENT_IN_GROUP_REF;  
  
//new from V3.1.10.1, only compatible with MC Group Coordinated Motion  
    ADDAX1                          : IDENT_IN_GROUP_REF;  
    ADDAX2                          : IDENT_IN_GROUP_REF;  
    ADDAX3                          : IDENT_IN_GROUP_REF;  
    ADDAX4                          : IDENT_IN_GROUP_REF;  
END_VAR
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
