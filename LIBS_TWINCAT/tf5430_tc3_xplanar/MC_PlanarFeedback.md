# MC_PlanarFeedback

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# MC\_PlanarFeedback

MC\_PlanarFeedback BOOL  ActiveBOOL  BusyBOOL  DoneBOOL  AbortedBOOL  ErrorUDINT  ErrorIdPlanarObjectInfo  objectInfo

Displays specific command status information for an associated command, given back by the MC Project.

## Syntax

Definition:

```
FUNCTION_BLOCK MC_PlanarFeedback  
VAR_OUTPUT  
    Active     : BOOL;  
    Busy       : BOOL;  
    Done       : BOOL;  
    Aborted    : BOOL;  
    Error      : BOOL;  
    ErrorId    : UDINT;  
    objectInfo : PlanarObjectInfo;  
END_VAR
```

## 38481481 Outputs

| Name | Type | Description |
| --- | --- | --- |
| Active | BOOL | Indicates an active command, i.e. command was accepted and is being executed. |
| Busy | BOOL | Indicates a busy command, i.e. command is being processed, waiting for execution, or already executing (= also active). |
| Done | BOOL | Indicates the command is done, i.e. execution of the command finished successfully. |
| Aborted | BOOL | Indicates the command is aborted, i.e. execution of the command finished due the start of other commands. |
| Error | BOOL | Indicates the command has an error. |
| ErrorId | UDINT | Indicates the error id of the command error. |
| objectInfo | [PlanarObjectInfo](ms-xhelp:///?Id=beckhoff-abe7-4f58-bb2e-7d272cbe17e6) | Indicates which object one would collide with. |

## 10789009 Methods

| Name | Description |
| --- | --- |
| [Update](ms-xhelp:///?Id=beckhoff-0a96-475d-98ee-cfe0adf81850) | Updates internal state of the object. |

## Required License

TC3 Planar Motion Base

## System Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT V3.1.4024.12  Advanced Motion Pack V3.1.10.11 | PC or CX (x64) | Tc3\_Mc3PlanarMotion, Tc3\_Physics |

Further Information

* [Update](ms-xhelp:///?Id=beckhoff-0a96-475d-98ee-cfe0adf81850)
