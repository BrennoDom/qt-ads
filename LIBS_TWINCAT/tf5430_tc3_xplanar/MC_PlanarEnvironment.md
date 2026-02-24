# MC_PlanarEnvironment

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# MC\_PlanarEnvironment

A Planar Environment object specifies the environment that Planar Movers can move in. It contains information about the stator objects and boundaries of the movement area.

Do not call the main FB directly. Only use the available methods.

## 37996203 Methods

| Name | Description |
| --- | --- |
| [Clear](ms-xhelp:///?Id=beckhoff-ee83-4040-8e39-5fcda1ad1a7d) | Clears the Planar Environment (stators and boundary). |
| [AddStator](ms-xhelp:///?Id=beckhoff-aefd-4727-935b-97a3ddf5be83) | Adds a stator to the Planar Environment. |
| [CreateBoundary](ms-xhelp:///?Id=beckhoff-3b47-40fb-993c-6eb602a14351) | Creates a boundary for the Planar Environment based on the previously added stator information or hardware information. |
| [Update](ms-xhelp:///?Id=beckhoff-f517-458a-a3ac-a91ec4490cce) | Updates internal state of the object, must be triggered each cycle. |
| [AddToGroup](ms-xhelp:///?Id=beckhoff-ea33-4e5a-9c83-c09326e936d5) | Adds the Planar Environment to the given Planar Group. |
| [RemoveFromGroup](ms-xhelp:///?Id=beckhoff-4e25-4c66-8d7b-57335b997872) | Removes the Planar Environment from its current Planar Group, i.e. disables collision checks. |
| [GetPlanarObjectInfo](ms-xhelp:///?Id=beckhoff-33db-477c-8af2-b5eabc0c11d3) | Returns environment object info (type: environment, id: OID of nc environment). |

## Required License

TC3 Planar Motion Base

## System Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT V3.1.4024.12  Advanced Motion Pack V3.1.10.11 | PC or CX (x64) | Tc3\_Mc3PlanarMotion, Tc3\_Physics |

Further Information

* [Clear](ms-xhelp:///?Id=beckhoff-ee83-4040-8e39-5fcda1ad1a7d)
* [AddStator](ms-xhelp:///?Id=beckhoff-aefd-4727-935b-97a3ddf5be83)
* [CreateBoundary](ms-xhelp:///?Id=beckhoff-3b47-40fb-993c-6eb602a14351)
* [Update](ms-xhelp:///?Id=beckhoff-f517-458a-a3ac-a91ec4490cce)
* [AddToGroup](ms-xhelp:///?Id=beckhoff-ea33-4e5a-9c83-c09326e936d5)
* [RemoveFromGroup](ms-xhelp:///?Id=beckhoff-4e25-4c66-8d7b-57335b997872)
* [GetPlanarObjectInfo](ms-xhelp:///?Id=beckhoff-33db-477c-8af2-b5eabc0c11d3)
