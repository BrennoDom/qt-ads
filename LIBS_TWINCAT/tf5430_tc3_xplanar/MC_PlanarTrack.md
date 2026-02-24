# MC_PlanarTrack

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# MC\_PlanarTrack

A track within a plane which Planar Movers can follow. Planar Movers on the track automatically avoid collisions with each other. The Planar Track can consist of several consecutive segments and be joined with other Planar Tracks at its start/end.

Do not call the main FB directly. Only use the available methods.

## 18759701 Methods

| Name | Description |
| --- | --- |
| [Clear](ms-xhelp:///?Id=beckhoff-8fef-47d5-b457-940f6baae72f) | Clears the geometric information of the Planar Track. |
| [AppendPosition](ms-xhelp:///?Id=beckhoff-0328-444e-85e3-764dd20a4a10) | Appends a position to the Planar Track. |
| [AppendLine](ms-xhelp:///?Id=beckhoff-5c2e-4c8e-a67e-55ebbd1d251f) | Appends a line to the Planar Track. |
| [AppendCircle](ms-xhelp:///?Id=beckhoff-6a04-40ad-946f-79a41208697a) | Appends a circular arc to the Planar Track. |
| [CloseLoop](ms-xhelp:///?Id=beckhoff-deed-499f-ac7b-bb2c57368a69) | Closes the loop of the Planar Track, no further part can be appended. |
| [StartFromTrack](ms-xhelp:///?Id=beckhoff-1f24-4c7c-a6b8-c742bb01db27) | Sets the other Planar Tracks endpoint as start point of this Planar Track, transition is smooth. The other Planar Track is blocked for further changes (until it is cleared). |
| [EndAtTrack](ms-xhelp:///?Id=beckhoff-80c5-4713-9ebc-58e82ff790cc) | Appends a smooth transition from the end of this Planar Track to the other Planar Tracks start point. The Planar Track is blocked for further changes (until it is cleared). |
| [Enable](ms-xhelp:///?Id=beckhoff-822b-4eed-b551-a4866e41e4b3) | Starts enabling the Planar Track. |
| [Disable](ms-xhelp:///?Id=beckhoff-3e9e-4d43-8c38-a5e77f7d4d63) | Starts disabling the Planar Track. |
| [Reset](ms-xhelp:///?Id=beckhoff-caf2-42ce-a0e8-feb5274e964b) | Starts resetting the Planar Track. |
| [GetArcLengthClosestTo](ms-xhelp:///?Id=beckhoff-f2de-4536-b827-40ed25b73c62) | Calculate the arc length value where the Planar Track is closest to a geometry's center point. |
| [GetPositionAt](ms-xhelp:///?Id=beckhoff-4aa2-4f4f-af2c-0dc4f2712e05) | Get a position on the Planar Track at a specific arc length value. |
| [GetLength](ms-xhelp:///?Id=beckhoff-3fd9-4128-b974-6ff044daa1ee) | Returns the Planar Tracks length, -1 return value indicates no connection to Nc Track. |
| [GetPlanarObjectInfo](ms-xhelp:///?Id=beckhoff-b8c9-4bb2-9ed0-9af091f8c60d) | Returns track object info (type: track, id: OID of nc track). |
| [Update](ms-xhelp:///?Id=beckhoff-1136-479f-a0fd-5d707718bf64) | Updates internal state of the object, must be triggered each cycle. |
| [AddToGroup](ms-xhelp:///?Id=beckhoff-5821-4724-9573-4e27631b5a74) | Adds the Planar Track to the given Planar Group. |
| [RemoveFromGroup](ms-xhelp:///?Id=beckhoff-2353-4d5d-ba8d-16857905b732) | Removes the Planar Track from its current Planar Group, i.e. disables collision checks. |

## Required License

TC3 Planar Motion Base

## System Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT V3.1.4024.12  Advanced Motion Pack V3.1.10.11 | PC or CX (x64) | Tc3\_Mc3PlanarMotion, Tc3\_Physics |

Further Information

* [Clear](ms-xhelp:///?Id=beckhoff-8fef-47d5-b457-940f6baae72f)
* [AppendPosition](ms-xhelp:///?Id=beckhoff-0328-444e-85e3-764dd20a4a10)
* [AppendLine](ms-xhelp:///?Id=beckhoff-5c2e-4c8e-a67e-55ebbd1d251f)
* [AppendCircle](ms-xhelp:///?Id=beckhoff-6a04-40ad-946f-79a41208697a)
* [CloseLoop](ms-xhelp:///?Id=beckhoff-deed-499f-ac7b-bb2c57368a69)
* [StartFromTrack](ms-xhelp:///?Id=beckhoff-1f24-4c7c-a6b8-c742bb01db27)
* [EndAtTrack](ms-xhelp:///?Id=beckhoff-80c5-4713-9ebc-58e82ff790cc)
* [Enable](ms-xhelp:///?Id=beckhoff-822b-4eed-b551-a4866e41e4b3)
* [Disable](ms-xhelp:///?Id=beckhoff-3e9e-4d43-8c38-a5e77f7d4d63)
* [Reset](ms-xhelp:///?Id=beckhoff-caf2-42ce-a0e8-feb5274e964b)
* [GetArcLengthClosestTo](ms-xhelp:///?Id=beckhoff-f2de-4536-b827-40ed25b73c62)
* [GetPositionAt](ms-xhelp:///?Id=beckhoff-4aa2-4f4f-af2c-0dc4f2712e05)
* [GetLength](ms-xhelp:///?Id=beckhoff-3fd9-4128-b974-6ff044daa1ee)
* [GetPlanarObjectInfo](ms-xhelp:///?Id=beckhoff-b8c9-4bb2-9ed0-9af091f8c60d)
* [Update](ms-xhelp:///?Id=beckhoff-1136-479f-a0fd-5d707718bf64)
* [AddToGroup](ms-xhelp:///?Id=beckhoff-5821-4724-9573-4e27631b5a74)
* [RemoveFromGroup](ms-xhelp:///?Id=beckhoff-2353-4d5d-ba8d-16857905b732)
