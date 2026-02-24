# CloseLoop

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# CloseLoop

CloseLoop commandFeedback  MC\_PlanarFeedback

Closes the loop of the Planar Track, no further part can be appended.

## Syntax

Definition:

```
METHOD CloseLoop  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
END_VAR
```

## 45601378 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
