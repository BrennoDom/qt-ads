# TcBaseModuleRegistered

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-c8bb-4182-8afb-4dae11b93466)
3. TcBaseModuleRegistered

# TcBaseModuleRegistered

```
FUNCTION_BLOCK TcBaseModuleRegistered EXTENDS TcBaseModule  
VAR  
END_VAR
```

## Description

If something is inherited from this object, a TcCOM object can be created from a function block. The object is automatically registered at the object server and ramped up to OP state.

How this TcCOM object is created and can be globally used in the TwinCAT system, will be explained in detail in an [example](ms-xhelp:///?Id=beckhoff-490b-4ce8-bb26-cd2b92b103ef).

The TcBaseModule base class implements the ITComObject interface, which in turn expands the ITcUnknown interface.

## ITComObject Interface

The ITComObject interface is implemented by every TwinCAT module. It makes functionalities available regarding the state machine and Information from/to the TwinCAT system.

Further Information

* [TcAddRef](ms-xhelp:///?Id=beckhoff-71b0-42d4-ac1c-4063c7121acb)
* [TcGetObjectId](ms-xhelp:///?Id=beckhoff-4972-4d0b-b602-7ac6a87937ab)
* [TcGetObjectName](ms-xhelp:///?Id=beckhoff-88bc-4a06-9946-9f8d9000668c)
* [TcGetObjPara](ms-xhelp:///?Id=beckhoff-07cc-4dad-b30e-cf7682aa3a9e)
* [TcGetObjState](ms-xhelp:///?Id=beckhoff-cc33-4286-9f11-3c13d9700711)
* [TcQueryInterface](ms-xhelp:///?Id=beckhoff-7ed6-4f4a-9a7a-4e8f7eac46a8)
* [TcRelease](ms-xhelp:///?Id=beckhoff-d6c3-4ba5-a102-3fc759876ee1)
* [TcSetObjId](ms-xhelp:///?Id=beckhoff-2683-4751-960d-513853cbd982)
* [TcSetObjectName](ms-xhelp:///?Id=beckhoff-9eea-4949-bc84-461ecb10e87d)
* [TcSetObjPara](ms-xhelp:///?Id=beckhoff-cfae-46ef-9f01-39ba24eeca7d)
* [TcSetObjState](ms-xhelp:///?Id=beckhoff-db8c-4736-a307-8cb290750296)

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
