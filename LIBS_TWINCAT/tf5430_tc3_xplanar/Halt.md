# Halt

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Halt

Halt commandFeedback  MC\_PlanarFeedbackconstraint  IPlcDynamicConstraint

Initiates a halt.

## Syntax

Definition:

```
METHOD Halt  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
    constraint      : IPlcDynamicConstraint;  
END_VAR
```

## 27094719 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
| constraint | IPlcDynamicConstraint | Dynamic constraints for this movement. |
