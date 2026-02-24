# MoveC

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# MoveC

MoveC commandFeedback  MC\_PlanarFeedbacktargetPosition  LREALconstraint  IPlcDynamicConstraintoptions  ST\_MoveCOptions

Initiates a movement for the c component.

## Syntax

Definition:

```
METHOD MoveC  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
    targetPosition  : LREAL;  
    constraint      : IPlcDynamicConstraint;  
    options         : ST_MoveCOptions;  
END_VAR
```

## 4477025 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
| targetPosition | LREAL | Target position for the movement. |
| constraint | IPlcDynamicConstraint | Dynamic constraints for this movement. |
| options | [ST\_MoveCOptions](ms-xhelp:///?Id=beckhoff-d8d6-43c4-84f9-16985b97f7a2) | Options for the rotation. |
