# RemoveFromGroup

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# RemoveFromGroup

RemoveFromGroup commandFeedback  MC\_PlanarFeedback

Removes the Planar Mover from its current Planar Group, i.e. disables collision checks.

## Syntax

Definition:

```
METHOD RemoveFromGroup  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
END_VAR
```

## 33371781 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
