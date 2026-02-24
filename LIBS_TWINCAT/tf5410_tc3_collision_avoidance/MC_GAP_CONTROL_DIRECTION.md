# MC_GAP_CONTROL_DIRECTION

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_GAP\_CONTROL\_DIRECTION

## Gap Control Direction “mcGapCtrlDirectionPositive”

|  |  |
| --- | --- |
| **CA Group** | * The set gap control direction applies to the entire CA group. |
| **Successor** | * The size of the Gap is regulated in each case. * The successor is the only mover that controls the size of the Gap enclosed by both adjacent movers. |
| **Gap Control** Mode | * Gap Control Mode "mcGapCtrlModeStandard" or Gap Control Mode "mcGapCtrlModeFast" can be used to calculate the dynamic values of a directly following mover. * The initialization parameter Default Gap Control Mode sets the same Gap Control Mode as the default algorithm for each successor within a CA group. |
| **Individual** | * The motion function blocks MC\_MoveAbsoluteCA, MC\_MoveRelativeCA, MC\_HaltCA or MC\_GearInPosCA can be used to change the "Gap Control Mode" individually for each mover. |
| **Computing power** | * Gap Control Mode "mcGapCtrlModeStandard" generally requires less computing power than Gap Control Mode "mcGapCtrlModeFast". |

## Gap Control Direction „mcGapCtrlDirectionBoth“

|  |  |
| --- | --- |
| **Motion** profiles | * Allows more general motion profiles, for example reverse motion. |
| **CA Group** | * The set gap control direction applies to the entire CA group. |
| **Successor and predecessor** | * The size of the Gap is regulated in each case. * Both adjacent movers, predecessor and successor, control the size of the Gap they enclose. |
| **mcGapCtrlMode** Standard | * Each mover within a CA group uses the same Gap Control Mode to calculate its dynamic values: "mcGapCtrlModeStandard". * Gap Control Mode "mcGapCtrlModeFast" cannot be used. |

|  |  |
| --- | --- |
| 35729512 | A runtime error is triggered if the gap control direction mcGapCtrlDirectionBoth has been set for a CA group and a motion function block – MC\_MoveAbsoluteCA, MC\_MoveRelativeCA, MC\_HaltCA or MC\_GearInPosCA – is used to set the Gap Control Mode for a mover of this CA group to the value "mcGapCtrlModeFast". |

## Correlating control behavior

|  |  |
| --- | --- |
| **Neighborhood** | * The size of a gap between two adjacent movers is controlled. * Two gaps are (directly) adjacent if the mover separating them is both successor and predecessor. |
| **Chain** | * (Directly) adjacent gaps form a (non-trivial) chain. * Within a chain the control of the respective gaps is correlated. |
| **Gap Control Mode** | * Gap Control Mode influences the correlating control type. * Gap Control Mode "mcGapCtrlModeStandard" allows deviations from the target gap value for a single gap and for the gaps of a chain for softer control. |
