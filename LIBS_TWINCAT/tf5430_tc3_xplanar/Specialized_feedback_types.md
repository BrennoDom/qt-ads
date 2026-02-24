# Specialized feedback types

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Specialized feedback types

In addition to the general MC\_PlanarFeedback type, which is accepted by most commands, certain commands may require a specialized feedback type. [Planar Feedback](ms-xhelp:///?Id=beckhoff-cb94-4ca3-8efe-c1c971af05f5) that apply to the general feedback also apply to these types.

Specialized feedbacks can have a subset of the outputs of the general feedback, depending on their type. This includes information about whether a command is active or whether it caused an error, etc. In addition, specialized feedback types may have other outputs or functions that correspond to their scope of application.

**MC\_PlanarFeedbackGearInPosOnTrack**

This feedback type is accepted by a [Example "Synchronizing a Planar mover on a track with one axis"](ms-xhelp:///?Id=beckhoff-601e-4ac1-ac69-f22aa6a5fa8b). It has an additional output `inSync`, which indicates whether the executing mover is synchronous with the master axis.

**MC\_PlanarFeedbackGearInPosOnTrackWithMasterMover**

This feedback type is accepted by a [Example: "Synchronizing a Planar mover on a track with another Planar mover"](ms-xhelp:///?Id=beckhoff-1246-47be-8dc9-d0045da148ba). It has an additional output `inSync`, which indicates whether the executing mover is synchronous with the Master Planar Mover.
