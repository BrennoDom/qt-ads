# UDINT_TO_IDENTINGROUP

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# UDINT\_TO\_IDENTINGROUP

![2594873](/tf5410_tc3_collision_avoidance/1033/Images/png/1513203211__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 23353865 | 8858194 | 12614887 |

The UDINT\_TO\_IDENTINGROUP function is a conversion function that converts an integer value to IDENT\_IN\_GROUP\_REF. A PTP axis without spatial interpretation must be added to a [CA group](ms-xhelp:///?Id=beckhoff-db68-4aa8-b9c7-ce918ad20973). This conversion function returns a valid input for [MC\_AddAxisToGroup](ms-xhelp:///?Id=beckhoff-df68-43f9-9587-82ddf8974a7a) and [MC\_RemoveAxisFromGroup](ms-xhelp:///?Id=beckhoff-0251-4c0b-b999-19e4bb350a95). For axes intended for multi-dimensional motion (TF5420), see [IDENT\_IN\_GROUP\_REF](ms-xhelp:///?Id=beckhoff-ede2-46d7-9ee0-7c0526b88aa2).

|  |  |
| --- | --- |
| 46425119 | Use of integer values for the input IdentInGroup  The use of integer values for the input IdentInGroup is NOT supported and may lead to incompatibility with future releases. If integer values are used, it may no longer be possible to build the project. We recommend using [global variables](ms-xhelp:///?Id=beckhoff-ede2-46d7-9ee0-7c0526b88aa2) (e.g. MCS\_X) or the conversion function [UDINT\_TO\_IDENTINGROUP](ms-xhelp:///?Id=beckhoff-4e24-46b0-ba59-5c9ff8c98bdb). |

## 15172893 Inputs

```
VAR_INPUT  
    id               : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| id | UDINT | The unique identifier that an axis should have in the group. This does not have to be the axis ID of the cyclic axis interface. |

## Return value

| Name | Type | Description |
| --- | --- | --- |
| UDINT\_TO\_IDENTINGROUP | [IDENT\_IN\_GROUP\_REF](ms-xhelp:///?Id=beckhoff-ede2-46d7-9ee0-7c0526b88aa2) | Converts an integer value so that a PTP axis can be added to a motion group. |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
