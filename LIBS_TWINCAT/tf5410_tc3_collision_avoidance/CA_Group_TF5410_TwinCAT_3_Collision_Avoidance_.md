# CA Group (TF5410 TwinCAT 3 Collision Avoidance)

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# CA Group (TF5410 TwinCAT 3 Collision Avoidance)

The CA group links axes to add collision avoidance to the PTP functionalities.

## Dynamic values

* Velocity **Vel**: Velocity,
* Acceleration **Acc**: Positive acceleration,
* Deceleration **Dec**: Braking acceleration, negative acceleration,
* Jerk: Jerk.

|  |  |
| --- | --- |
| **Set values and limits** | * An axis traverses set dynamic values. During this motion, the maximum dynamic values set the limits for the dynamic profile. |
| **CA Group** | * A CA group offers parameters that can be used to set defaults for dynamic values. These default values are used for Standby Gap Control. They are not used as default parameters for Motion commands if no parameter has been specified. |
| **Axis** | * The maximum values for the dynamic limits can be set in the axis parameters. * These maximum values can be determined by the physical properties (inertia, mass, maximum current, motor size, ..) of the axis or a workpiece, for example. |

## Gap

|  |  |
| --- | --- |
| **Neighborhood** | * A gap requires two or more adjacent axes (movers). * A gap is always located between two directly adjacent movers. |
| **Counting direction** | * The gap is defined in positive counting direction from the current mover to the mover directly ahead. * This positive counting direction corresponds to the counting direction of the set value generation. |
| **Successor;** predecessor | * Current mover: directly following mover, successor. * Mover directly ahead: predecessor. |
| **Size** | * Size of a respective Gaps = (set position predecessor) - (set position successor). |
| **Lower** limit | * The Gap size is regulated to a lower limit that must not be undercut. For this lower limit, the "Default Gap" parameter sets a value for the entire CA group as long as no other gap size is set for a current mover. An individual value for this lower limit of the Gap size can be applied as input value to each of the motion function blocks: "MC\_MoveAbsoluteCA", "MC\_MoveRelativeCA", "MC\_HaltCA" or "MC\_GearInPosCA". |
| **Gap Control** Mode | * "Gap Control Mode" mcGapCtrlModeFast generally controls closer to this lower Gap size limit than "Gap Control Mode" mcGapCtrlModeStandard. |
| **Gap Control** Direction | * "Gap Control Direction" mcGapCtrlDirectionPositive: The successor is the only mover that controls the size of the Gap enclosed by the predecessor and successor. * "Gap Control Direction" mcGapCtrlDirectionBoth: Both adjacent movers control the size of the Gap they enclose. |

## Open the dialog "Parameter (Init)"

![13077833](/tf5410_tc3_collision_avoidance/1033/Images/png/3235016843__Web.png)

Root node of a CA group.

![50591634](/tf5410_tc3_collision_avoidance/1033/Images/png/9305449355__Web.png)

Parameters for a CA group.  
The table column "Value" shows the preset parameter value. The table column "Comment" contains brief parameter descriptions.

| Name | Comment |
| --- | --- |
| Geometry |  |
| Rail Length | Length of Rail  Length of the rail on which the axes (movers) are mounted. |
| Rail Is Ring | Specifies that the rail is closed, i.e. in loop shape or the last mover is in front of first one  If TRUE, Collision Avoidance is enabled between the first mover in the line and the last mover. |
| Gap Control |  |
| Default Gap Control Mode | Specifies the default gap control mode  Different modes are available for distance control (see "[MC\_DEFAULT\_GAP\_CONTROL\_MODE](ms-xhelp:///?Id=beckhoff-d90d-4490-ac5e-9994968809c8)"). |
| Gap Control Direction | Specifies the direction in which the gap control acts.  Various settings are available for the control direction of the Gap (see section "[MC\_GAP\_CONTROL\_DIRECTION](ms-xhelp:///?Id=beckhoff-9d74-4819-bd75-10657920d058)“). |
| Standby Gap Control | Specifies whether the collision avoidance is active when no FB is active.  If TRUE, Collision Avoidance is always active, even if no motion command was issued to the axis.  Note The axes move directly after MC\_GroupEnable when Standby Gap Control is TRUE. If the distance between two axes (movers) is smaller than the default gap (see next parameter), the axes move in such a way that they achieve the required distance. This movement is independent of any motion command. This behavior also applies if the axes are too close to each other after a group reset. |
| Default Gap | Size of Gap between Movers when it is not specified in Motion Command.  This distance is used for Standby Gap Control and when no distance has been specified for a CA motion command. |
| Default Velocity | Velocity used for gap control if no Motion Command is active (e.g. directly after GroupEnable).  This velocity is used for Standby Gap Control. It is not used as the default velocity for a motion command if no velocity has been set. |
| Default Acceleration | Acceleration used for gap control if no Motion Command is active (e.g. directly after GroupEnable).  This acceleration is used for Standby Gap Control. It is not used as the default acceleration for a motion command if no acceleration has been specified. |
| Default Deceleration | Deceleration used for gap control if no Motion Command is active (e.g. directly after GroupEnable).  This deceleration is used for Standby Gap Control. It is not used as the default deceleration for a motion command if no deceleration has been set. |
| Default Jerk | Jerk used for gap control if no Motion Command is active (e.g. directly after GroupEnable).  This jerk is used for Standby Gap Control. It is not used as the default jerk for a motion command if no jerk is specified. |
| GearInPosDefaultDynamicsAfterSync (hidden!) | Specifies the default dynamics used for MC\_GearInPosCA AfterSyncDynamics. By default, the value is set to 'JobDynamics'. The parameter is not available for older projects (created with versions < 3.1.10) but is set internally to 'MaximumSlaveDynamics'.  Specifies the default dynamics used in MC\_GearInPosCA AfterSyncDynamics. In the default state, the value "JobDynamics" is set. The parameter is not available for older projects (created with versions < 3.1.10), but is internally set to 'MaximumSlaveDynamics'. Attention: After reloading the TMC file "JobDynamics" is set as default value (see [MC\_GearInPosDefaultDynamicsAfterSync](ms-xhelp:///?Id=beckhoff-b4d1-44fc-b47c-a9e32a7f94f1)). |

:   If an NC configuration has already been added, the MOTION subtree contains an SAF task subtree.
:   The SAF task subtree contains the "Objects" subtree.
:   The "Objects" subtree can contain a CA group.

:   1. Double-click the root node of the CA group whose parameters you want to view or set.
:   2. Select the "Parameters (Init)" tab.

:   The "Parameter (Init)" dialog opens.
:   It contains a table with parameters for the selected CA group.
:   These parameters are divided into the groups "Geometry", "Gap Control" and "„Misc.", if applicable.
