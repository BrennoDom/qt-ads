# Interface ITComObject

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Appendix](ms-xhelp:///?Id=beckhoff-7a54-458a-984c-ff7aefcf1c19)
3. [Interfaces](ms-xhelp:///?Id=beckhoff-581c-4e1d-a450-dec7512fb73c)
4. Interface ITComObject

# Interface ITComObject

The ITComObject interface is implemented by every TwinCAT module. It makes basic functionalities available.

## Syntax

```
TCOM_DECL_INTERFACE("00000012-0000-0000-e000-000000000064", ITComObject)  
struct__declspec(novtable) ITComObject: public ITcUnknown
```

## 18334396 Methods

| Name | Description |
| --- | --- |
| [TcGetObjectId(OTCID& objId)](ms-xhelp:///?Id=beckhoff-67eb-4956-801e-b103adcc8ff6) | Saves the object ID using the given OTCID reference. |
| [TcSetObjectId](ms-xhelp:///?Id=beckhoff-9f7f-4d87-83fb-37aaf1eaf826) | Sets the object ID of the object to the given OTCID. |
| [TcGetObjectName](ms-xhelp:///?Id=beckhoff-f98a-49f7-a29d-b8a1fb27f33a) | Saves the object names in the buffer with the given length. |
| [TcSetObjectName](ms-xhelp:///?Id=beckhoff-afcb-4d69-9fa4-5a92f384c15f) | Sets the object name of the object to given CHAR\*. |
| [TcSetObjState](ms-xhelp:///?Id=beckhoff-18cf-4e91-972c-cdfdcb0f8d4d) | Initializes a transition to a predefined state. |
| [TcGetObjState](ms-xhelp:///?Id=beckhoff-2193-4be7-9e66-48ed38876beb) | Queries the current state of the object. |
| [TcGetObjPara](ms-xhelp:///?Id=beckhoff-e8f2-4f3a-a8ff-66131d1d1f4c) | Queries an object parameter identified with its PTCID. |
| [TcSetObjPara](ms-xhelp:///?Id=beckhoff-6a65-4d3a-8203-23076a4dd8b6) | Sets an object parameter identified with its PTCID. |
| [TcGetParentObjId](ms-xhelp:///?Id=beckhoff-574e-466e-8a01-53faef390ad6) | Saves the parent object ID with the help of the given OTCID reference. |
| [TcSetParentObject](ms-xhelp:///?Id=beckhoff-8f18-4030-960f-13b866102e01) | Sets the parent object ID to the given OTCID. |

## Comments

The ITComObject interface is implemented by every TwinCAT module. It makes functionalities available regarding the state machine and Information from/to the TwinCAT system.

Further Information

* [Method ITcComObject:TcGetObjectId(OTCID& objId)](ms-xhelp:///?Id=beckhoff-67eb-4956-801e-b103adcc8ff6)
* [Method ITcComObject:TcSetObjectId](ms-xhelp:///?Id=beckhoff-9f7f-4d87-83fb-37aaf1eaf826)
* [Method ITcComObject:TcGetObjectName](ms-xhelp:///?Id=beckhoff-f98a-49f7-a29d-b8a1fb27f33a)
* [Method ITcComObject:TcSetObjectName](ms-xhelp:///?Id=beckhoff-afcb-4d69-9fa4-5a92f384c15f)
* [Method ITcComObject:TcSetObjState](ms-xhelp:///?Id=beckhoff-18cf-4e91-972c-cdfdcb0f8d4d)
* [Method ITcComObject:TcGetObjState](ms-xhelp:///?Id=beckhoff-2193-4be7-9e66-48ed38876beb)
* [Method ITcComObject:TcGetObjPara](ms-xhelp:///?Id=beckhoff-e8f2-4f3a-a8ff-66131d1d1f4c)
* [Method ITcComObject:TcSetObjPara](ms-xhelp:///?Id=beckhoff-6a65-4d3a-8203-23076a4dd8b6)
* [Method ITcComObject:TcGetParentObjId](ms-xhelp:///?Id=beckhoff-574e-466e-8a01-53faef390ad6)
* [Method ITcComObject:TcSetParentObjId](ms-xhelp:///?Id=beckhoff-8f18-4030-960f-13b866102e01)

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
