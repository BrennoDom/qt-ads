# MoveB

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# MoveB

MoveB commandFeedback  MC\_PlanarFeedbacktargetPosition  LREALconstraint  IPlcDynamicConstraint

Initiates a movement for the b component.

## Syntax

Definition:

```
METHOD MoveB  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
    targetPosition  : LREAL;  
    constraint      : IPlcDynamicConstraint;  
END_VAR
```

## 45236689 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
| targetPosition | LREAL | Target position for the movement. |
| constraint | IPlcDynamicConstraint | Dynamic constraints for this movement. |
