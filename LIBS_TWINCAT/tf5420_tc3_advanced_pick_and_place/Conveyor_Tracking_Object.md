# Conveyor Tracking Object

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# Conveyor Tracking Object

A Conveyor Tracking object can be used to synchronize an axes group with a conveyor belt. It is added as a child object to a Coordinate Frame object. While the Coordinate Frame describes the static transformation (translation and/or rotation) to the conveyor belt system, the Conveyor Tracking object handles the dynamic part of the tracking.

The Conveyor Tracking parameters are listed in the following table. The dynamics parameters are default values that are used when MC\_DEFAULT is chosen for the corresponding parameter in the MC\_TrackConveyorBelt function block instance.

| Parameter | Description | Unit |
| --- | --- | --- |
| Velocity | Default velocity for synchronization. | mm s-1 |
| Acceleration | Default acceleration for synchronization. | mm s-2 |
| Deceleration | Default deceleration for synchronization. | mm s-2 |
| Jerk | Default jerk for synchronization. | mm s-3 |
| Default Tracking Behavior | Conveyor tracking behavior after `InSync` has been reached. |  |
| Synchronization Tolerance Distance | Distance to tracking target in which the tracking is considered synchronized (InSync = TRUE). Usage of this parameter might be useful if the master signal is noisy. This parameter only has influence if MC Group Coordinated Motion is in use. | mm |
