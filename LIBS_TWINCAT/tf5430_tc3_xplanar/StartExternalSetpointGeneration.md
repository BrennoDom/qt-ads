# StartExternalSetpointGeneration

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# StartExternalSetpointGeneration

StartExternalSetpointGeneration commandFeedback  MC\_PlanarFeedbackoptions  ST\_ExternalSetpointGenerationOptions

Starts the external setpoint generation, the user must supply setpoints from this PLC cycle on in every PLC cycle.

## Syntax

Definition:

```
METHOD StartExternalSetpointGeneration  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
    options         : ST_ExternalSetpointGenerationOptions;  
END_VAR
```

## 31198475 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
| options | [ST\_ExternalSetpointGenerationOptions](ms-xhelp:///?Id=beckhoff-fe54-4023-958d-7f17da14e689) | Options for the movement. |
