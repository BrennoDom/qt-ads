# Group State Diagram

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# Group State Diagram

The state diagram describes the state of a motion group. The states described here can be read from PLC by using function block MC\_GroupReadStatus.

![66410939](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/18014407497531403__Web.png)![60827539](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8988666251__Web.png)

|  |  |
| --- | --- |
| **Note** | **Description** |
| 1 | Applicable for all non-administrative (moving) function blocks. |
| 2 | In the state GroupStopping, all Function Blocks can be called, although they will not be executed, except MC\_GroupDisable and MC\_UngroupAllAxes, which will abort the stop and generate the transition to GroupDisabled. |
| 3 | MC\_GroupStop.DONE AND NOT MC\_GroupStop.EXECUTE |
| 4 | - |
| 5 | - |
| 6 | MC\_GroupDisable and MC\_UngroupAllAxes can be issued in all states and will change the state to GroupDisabled. If issued in any error state, the state changes to GroupErrorDisabled. |
| 7 | From any state with EnableRequested TRUE. |
| 8 | If "bIsControlLoopClosed" is true for all axes and the group is not empty. "bPositiveDirection"/"bNegativeDirection" need not be enabled. |
| 9 | "bIsControlLoopClosed" and both flags "bPositiveDirection"/"bNegativeDirection" have to be set to TRUE. |
| 10 | MC\_GroupReset has no effect if issued in any other state than GroupErrorStop. |
| 11 | In the error states, all administrative Function Blocks except MC\_GroupEnable are allowed. They can, however, only generate state transitions inside the error states, e.g. to GroupErrorDisabled for MC\_GroupDisable or MC\_UngroupAllAxes and MC\_RemoveAxisFromGroup if the last axis is removed. |
| 12 | To leave the state GroupErrorStop, MC\_GroupReset must be called. |
