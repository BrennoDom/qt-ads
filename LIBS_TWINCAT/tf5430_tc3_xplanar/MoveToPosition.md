# MoveToPosition

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# MoveToPosition

MoveToPosition commandFeedback  MC\_PlanarFeedbackconstraint  IPlcDynamicConstraintoptions  ST\_MoveToPositionOptions↔targetPosition  PositionXYC

Initiates a direct movement to the specified position.

## Syntax

Definition:

```
METHOD MoveToPosition  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
    constraint      : IPlcDynamicConstraint;  
    options         : ST_MoveToPositionOptions;  
END_VAR  
VAR_IN_OUT  
    targetPosition  : PositionXYC;  
END_VAR
```

## 56434525 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
| constraint | IPlcDynamicConstraint | Dynamic constraints for this movement. |
| options | [ST\_MoveToPositionOptions](ms-xhelp:///?Id=beckhoff-ad51-4006-bfe8-646e51b51443) | Options for the movement. |

## 38148684 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| targetPosition | PositionXYC | Target position for the movement. |
