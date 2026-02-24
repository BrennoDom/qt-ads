# UDINT_TO_IDENTINGROUP

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# UDINT\_TO\_IDENTINGROUP

![35443891](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/1513203211__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 50559563 | 52382884 | 1683911 |

The UDINT\_TO\_IDENTINGROUP function is a conversion function that converts an integer value to IDENT\_IN\_GROUP\_REF. A PTP axis without spatial interpretation must be added to a CA group. This conversion function returns a valid input for [MC\_AddAxisToGroup](ms-xhelp:///?Id=beckhoff-1d2e-4871-be85-88820a29d9a3) and [MC\_RemoveAxisFromGroup](ms-xhelp:///?Id=beckhoff-58c7-4525-a05e-7a391e849e01). For axes intended for multi-dimensional motion (TF5420), see [IDENT\_IN\_GROUP\_REF](ms-xhelp:///?Id=beckhoff-f9b9-42c9-b78d-9fcb08c26c63).

|  |  |
| --- | --- |
| 15155206 | Use of integer values for the input IdentInGroup  The use of integer values for the input IdentInGroup is NOT supported and may lead to incompatibility with future releases. If integer values are used, it may no longer be possible to build the project. We recommend using [global variables](ms-xhelp:///?Id=beckhoff-f9b9-42c9-b78d-9fcb08c26c63) (e.g. MCS\_X) or the conversion function [UDINT\_TO\_IDENTINGROUP](ms-xhelp:///?Id=beckhoff-51e0-4922-8e57-997279beac86). |

## 2179128 Inputs

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
| UDINT\_TO\_IDENTINGROUP | [IDENT\_IN\_GROUP\_REF](ms-xhelp:///?Id=beckhoff-f9b9-42c9-b78d-9fcb08c26c63) | Converts an integer value so that a PTP axis can be added to a motion group. |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
