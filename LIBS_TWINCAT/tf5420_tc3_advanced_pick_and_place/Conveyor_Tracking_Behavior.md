# Conveyor Tracking Behavior

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# Conveyor Tracking Behavior

The Default Tracking Behavior defines the kind of default disturbance rejection during tracking. A disturbance may be an unexpected impulse or a conveyor indexing movement.

## mcTrackingBehaviorDynLimited

Velocity synchronization to the `ConveyorBelt` is maintained using the given `Acceleration`, `Deceleration` and `Jerk`.  
Relevant when disturbances are not known precisely or disturbance dynamics are significant.  
Dynamic limits are input to the `MC_TrackConveyorBelt` function block. The values from the Conveyor Tracking Object will be used when `MC_Default` is input to the function block. When the conveyor indexes, the response will be limited by the dynamic parameters.  
When the `DynLimited` setting is used, the response is compensated with the jerk limit. The function block output `MC_TrackConveyorBelt.InSync` indicates when there is synchronization.

|  |  |
| --- | --- |
| 39482434 | InSync  Using the `mcTrackingBehaviorDynLimited` operation mode the `InSync = TRUE` output may disappear when the synchronized position has been lost. Staying within the parameterized dynamics the algorithm tries to return to the synchronized position on its own. When the synchronized position has been reached the `InSync = TRUE` output appears, again. |

## mcTrackingBehaviorStayInSync

Velocity synchronization to the `ConveyorBelt` is maintained with non-limited Acceleration, Deceleration and Jerk.  
When the conveyor indexes, the tracking response will not be limited. Rather, the tracking response intends to remain synchronized and follow the conveyor unconditionally. The function block output `MC_TrackConveyorBelt.InSync` indicates when there is synchronization.

|  |  |
| --- | --- |
| 19797588 | InSync  Using the `mcTrackingBehaviorStayInSync` operation mode when the `InSync` signal has once become `TRUE`, it stays `TRUE` as long as the command is active. |
