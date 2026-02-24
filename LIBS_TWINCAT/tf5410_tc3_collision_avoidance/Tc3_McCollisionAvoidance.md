# Tc3_McCollisionAvoidance

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# Tc3\_McCollisionAvoidance

## Overview

| Function block | Description |
| --- | --- |
| **Motion** | |
| [MC\_MoveAbsoluteCA](ms-xhelp:///?Id=beckhoff-6454-4164-b2f9-0b8845f57f91) | Moves a single axis to an absolute position with collision avoidance. |
| [MC\_MoveRelativeCA](ms-xhelp:///?Id=beckhoff-4bdb-4f1f-9768-cde7f3241a6d) | Moves a single axis over a relative distance with collision avoidance. |
| [MC\_HaltCA](ms-xhelp:///?Id=beckhoff-084d-4a51-a17b-25a70cd3e5b7) | Stops a single axis with collision avoidance without locking it for further motion commands. |
| [MC\_GearInPosCA](ms-xhelp:///?Id=beckhoff-2bf6-4f70-9a09-385499e1b775) | Couples a slave axis with a gearing factor and collision avoidance to a master axis. |
| [MC\_ReadTrackPositions](ms-xhelp:///?Id=beckhoff-1d5e-43e1-8ab6-7f90ffe33377) | Returns the current XTS track and XTS part target positions with the corresponding object IDs. |
| [MC\_ActivateTrack](ms-xhelp:///?Id=beckhoff-7ec7-44a4-ace3-3d4b295e2d77) | Activates a track as a reference system, which can then be used in various motion function blocks for positioning. |

## Structures and enumerations

| Name | Description |
| --- | --- |
| [ST\_GearInPosCAOptions](ms-xhelp:///?Id=beckhoff-dfb7-4eea-8762-2deabb22447e) | Options for [MC\_GearInPosCA](ms-xhelp:///?Id=beckhoff-2bf6-4f70-9a09-385499e1b775). |
| [ST\_MoveAbsoluteCAOptions](ms-xhelp:///?Id=beckhoff-99e1-49c8-9293-0bfff325f298) | Options for [MC\_MoveAbsoluteCA](ms-xhelp:///?Id=beckhoff-6454-4164-b2f9-0b8845f57f91). |
| [ST\_MoveRelativeCAOptions](ms-xhelp:///?Id=beckhoff-ce42-4bb3-b92f-ef2291e430cc) | Options for [MC\_MoveRelativeCA](ms-xhelp:///?Id=beckhoff-4bdb-4f1f-9768-cde7f3241a6d). |
| [ST\_HaltCAOptions](ms-xhelp:///?Id=beckhoff-d249-4cfc-b9d5-739c1715ec56) | Options for [MC\_HaltCA](ms-xhelp:///?Id=beckhoff-084d-4a51-a17b-25a70cd3e5b7). |
| [MC\_GAP\_CONTROL\_MODE](ms-xhelp:///?Id=beckhoff-0e9a-45b7-a3fc-2f744339d69e) | Defines the gap control mode at function block level. |

Further Information

* [Function Blocks](ms-xhelp:///?Id=beckhoff-7624-48c9-a26a-4fb98c8ada2b)
* [Datatypes](ms-xhelp:///?Id=beckhoff-7fdd-4407-ba74-1bea4202e221)
