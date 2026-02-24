# AddStator

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# AddStator

AddStator commandFeedback  MC\_PlanarFeedbacklowerX  LREALlowerY  LREAL

Adds a stator to the Planar Environment.

## Syntax

Definition:

```
METHOD AddStator  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
    lowerX          : LREAL;  
    lowerY          : LREAL;  
END_VAR
```

## 57793596 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
| lowerX | LREAL | The lower x position of the stator. |
| lowerY | LREAL | The lower y position of the stator. |
