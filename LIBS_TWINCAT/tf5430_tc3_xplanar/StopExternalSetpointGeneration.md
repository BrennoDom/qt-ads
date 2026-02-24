# StopExternalSetpointGeneration

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# StopExternalSetpointGeneration

StopExternalSetpointGeneration commandFeedback  MC\_PlanarFeedback

Ends the external setpoint generation, called after last SetExternalSetpoint (in the same PLC cycle).

## Syntax

Definition:

```
METHOD StopExternalSetpointGeneration  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
END_VAR
```

## 12350826 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
