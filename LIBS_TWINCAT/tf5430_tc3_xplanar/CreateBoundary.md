# CreateBoundary

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# CreateBoundary

CreateBoundary commandFeedback  MC\_PlanarFeedback

Creates a boundary for the Planar Environment based on the previously added stator information or hardware information.

## Syntax

Definition:

```
METHOD CreateBoundary  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
END_VAR
```

## 50380316 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
