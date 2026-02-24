# AddToGroup

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# AddToGroup

AddToGroup commandFeedback  MC\_PlanarFeedback↔group  MC\_PlanarGroup

Adds the Planar Mover to the given Planar Group.

## Syntax

Definition:

```
METHOD AddToGroup  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
END_VAR  
VAR_IN_OUT  
    group           : MC_PlanarGroup;  
END_VAR
```

## 60892825 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |

## 11164516 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| group | [MC\_PlanarGroup](ms-xhelp:///?Id=beckhoff-ec24-4f60-b85c-91abba557f89) | The Planar Group that the Planar Mover joins. |
