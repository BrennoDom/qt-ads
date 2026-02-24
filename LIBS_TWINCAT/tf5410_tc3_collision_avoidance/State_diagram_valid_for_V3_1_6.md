# State diagram valid for V3.1.6

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# State diagram valid for V3.1.6

The state diagram describes the state of an axis group. The states described here can be read from the PLC using the function block MC\_GroupReadStatus.

![52671525](/tf5410_tc3_collision_avoidance/1033/Images/png/8988668683__Web.png)![4281684](/tf5410_tc3_collision_avoidance/1033/Images/png/8988666251__Web.png)

|  |  |
| --- | --- |
| **Note** | **Description** |
| 1 | Applicable for all non-administrative (movement) function blocks. |
| 2 | In the GroupStopping state all function blocks can be called but they are not executed, with the exception of MC\_GroupDisable and MC\_UngroupAllAxes, which cancel the stop and create the transition to GroupDisabled. |
| 3 | MC\_GroupStop.DONE AND NOT MC\_GroupStop.EXECUTE |
| 4 | Transition is applicable when the last axis is removed from the group. |
| 5 | Transition is applicable while the group is not empty. |
| 6 | MC\_GroupDisable and MC\_UngroupAllAxes can be output in all states. They change the state to GroupDisabled. If they are output in an error state, the state changes to GroupErrorDisabled. |
| 7 | From any state with EnableRequested TRUE. |
| 8 | If "bIsControlLoopClosed" is TRUE for all axes and the group is not empty. "bPositiveDirection"/"bNegativeDirection" do not have be enabled. |
| 9 | MC\_GroupEnable returns an error if the group is empty. |
| 10 | MC\_GroupReset has no effect if the state is different from GroupErrorStop. |
| 11 | In the error states all administrative function blocks are permitted with the exception of MC\_GroupEnable. However, in the error states you can only create state transitions, e.g. to GroupErrorDisabled for MC\_GroupDisable or MC\_UngroupAllAxes and MC\_RemoveAxisFromGroup, when the last axis is removed. |
| 12 | MC\_GroupReset must be called to exit the GroupErrorStop state. |
