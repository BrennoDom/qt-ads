# MC_PlanarMover

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# MC\_PlanarMover

A Planar Mover object capable of moving within a plane. Limited movement vertical to the plane is available.

Do not call the main FB directly. Only use the available methods.

## 13727043 Methods

| Name | Description |
| --- | --- |
| [MoveToPosition](ms-xhelp:///?Id=beckhoff-811d-4e70-8caa-f2deed4a3328) | Initiates a direct movement to the specified position. |
| [JoinTrack](ms-xhelp:///?Id=beckhoff-4d52-4896-9e47-52da4edc42bd) | Initiates a direct movement to the specified track. At the end of the movement the mover joins the track. |
| [LeaveTrack](ms-xhelp:///?Id=beckhoff-e6e3-44a9-849e-25b2064cd306) | Initiates a direct movement to the specified position. At the beginning of the movement the track is left. |
| [MoveOnTrack](ms-xhelp:///?Id=beckhoff-6b6e-4a07-ab0f-beda8d9f45cd) | Initiates a movement on the track to the specified position and returns command ID. |
| [GearInPosOnTrack](ms-xhelp:///?Id=beckhoff-b696-4d70-bf83-ab45bd780852) | Initiates a GearInPos movement along a specified trail. |
| [GearInPosOnTrackWithMasterMover](ms-xhelp:///?Id=beckhoff-d179-457d-9250-3dc35907da6a) | Initiates a GearInPos movement along a specified trail, in which the master setpoints are provided by another PlanarMover. |
| [MoveZ](ms-xhelp:///?Id=beckhoff-0767-44c0-8bd2-3ace380f15fe) | Initiates a movement for the z component. |
| [MoveA](ms-xhelp:///?Id=beckhoff-d0a3-480d-91f6-d97ab7c1a690) | Initiates a movement for the a component. |
| [MoveB](ms-xhelp:///?Id=beckhoff-b7c4-4460-a405-e926639a07e8) | Initiates a movement for the b component. |
| [MoveC](ms-xhelp:///?Id=beckhoff-712b-4bd1-85f0-8da4ea4b8b78) | Initiates a movement for the c component. |
| [AdoptTrackOrientation](ms-xhelp:///?Id=beckhoff-95e8-4b57-af28-f4a3deccba53) | Initiates a movement for the c component. |
| [Halt](ms-xhelp:///?Id=beckhoff-bb18-4d0d-9e31-1380a14a89e3) | Initiates a halt. |
| [Enable](ms-xhelp:///?Id=beckhoff-ba00-4a28-8cbf-9804487c007b) | Starts enabling the Planar Mover. |
| [Disable](ms-xhelp:///?Id=beckhoff-0886-429a-8949-9ee68c3c6ec2) | Starts disabling the Planar Mover. |
| [Reset](ms-xhelp:///?Id=beckhoff-36cb-4389-94f2-38d7d273ffe9) | Starts resetting the Planar Mover. |
| [Update](ms-xhelp:///?Id=beckhoff-5376-4148-a200-5afd0044e918) | Updates internal state of the object, must be triggered each cycle. |
| [SetPosition](ms-xhelp:///?Id=beckhoff-99c1-4f4e-8093-4c4856c41b6f) | Sets the position of the Planar Mover. Only possible if the Planar Mover is disabled. |
| [StartExternalSetpointGeneration](ms-xhelp:///?Id=beckhoff-cf08-469e-92e9-8e72a74a6a30) | Starts the external setpoint generation, the user must supply setpoints from this PLC cycle on in every PLC cycle. |
| [StopExternalSetpointGeneration](ms-xhelp:///?Id=beckhoff-80d4-4588-8adc-7f264f822755) | Ends the external setpoint generation, called after last SetExternalSetpoint (in the same PLC cycle). |
| [SetExternalSetpoint](ms-xhelp:///?Id=beckhoff-1322-4b4d-9392-d5a998466650) | Sets the external setpoint for the Planar Mover, must be called each PLC cycle during external setpoint generation. |
| [AddToGroup](ms-xhelp:///?Id=beckhoff-71fd-4ccc-9eb7-184c6eb076ad) | Adds the Planar Mover to the given Planar Group. |
| [RemoveFromGroup](ms-xhelp:///?Id=beckhoff-7093-4a1a-98bf-176c12158fae) | Removes the Planar Mover from its current Planar Group, i.e. disables collision checks. |
| [GetPlanarObjectInfo](ms-xhelp:///?Id=beckhoff-dcca-405e-91d6-0817ba481060) | Returns mover object info (type: mover, id: OID of nc mover). |

## Required License

TC3 Planar Motion Base

## System Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT V3.1.4024.12  Advanced Motion Pack V3.1.10.11 | PC or CX (x64) | Tc3\_Mc3PlanarMotion, Tc3\_Physics |

Further Information

* [MoveToPosition](ms-xhelp:///?Id=beckhoff-811d-4e70-8caa-f2deed4a3328)
* [JoinTrack](ms-xhelp:///?Id=beckhoff-4d52-4896-9e47-52da4edc42bd)
* [LeaveTrack](ms-xhelp:///?Id=beckhoff-e6e3-44a9-849e-25b2064cd306)
* [MoveOnTrack](ms-xhelp:///?Id=beckhoff-6b6e-4a07-ab0f-beda8d9f45cd)
* [GearInPosOnTrack](ms-xhelp:///?Id=beckhoff-b696-4d70-bf83-ab45bd780852)
* [GearInPosOnTrackWithMasterMover](ms-xhelp:///?Id=beckhoff-d179-457d-9250-3dc35907da6a)
* [MoveZ](ms-xhelp:///?Id=beckhoff-0767-44c0-8bd2-3ace380f15fe)
* [MoveA](ms-xhelp:///?Id=beckhoff-d0a3-480d-91f6-d97ab7c1a690)
* [MoveB](ms-xhelp:///?Id=beckhoff-b7c4-4460-a405-e926639a07e8)
* [MoveC](ms-xhelp:///?Id=beckhoff-712b-4bd1-85f0-8da4ea4b8b78)
* [AdoptTrackOrientation](ms-xhelp:///?Id=beckhoff-95e8-4b57-af28-f4a3deccba53)
* [Halt](ms-xhelp:///?Id=beckhoff-bb18-4d0d-9e31-1380a14a89e3)
* [Enable](ms-xhelp:///?Id=beckhoff-ba00-4a28-8cbf-9804487c007b)
* [Disable](ms-xhelp:///?Id=beckhoff-0886-429a-8949-9ee68c3c6ec2)
* [Reset](ms-xhelp:///?Id=beckhoff-36cb-4389-94f2-38d7d273ffe9)
* [Update](ms-xhelp:///?Id=beckhoff-5376-4148-a200-5afd0044e918)
* [SetPosition](ms-xhelp:///?Id=beckhoff-99c1-4f4e-8093-4c4856c41b6f)
* [StartExternalSetpointGeneration](ms-xhelp:///?Id=beckhoff-cf08-469e-92e9-8e72a74a6a30)
* [StopExternalSetpointGeneration](ms-xhelp:///?Id=beckhoff-80d4-4588-8adc-7f264f822755)
* [SetExternalSetpoint](ms-xhelp:///?Id=beckhoff-1322-4b4d-9392-d5a998466650)
* [AddToGroup](ms-xhelp:///?Id=beckhoff-71fd-4ccc-9eb7-184c6eb076ad)
* [RemoveFromGroup](ms-xhelp:///?Id=beckhoff-7093-4a1a-98bf-176c12158fae)
* [GetPlanarObjectInfo](ms-xhelp:///?Id=beckhoff-dcca-405e-91d6-0817ba481060)
