# AdoptTrackOrientation

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# AdoptTrackOrientation

AdoptTrackOrientation commandFeedback  MC\_PlanarFeedbackconstraint  IPlcDynamicConstraintoptions  ST\_AdoptTrackOrientationOptions

Initiates a movement for the c component.

## Syntax

Definition:

```
METHOD AdoptTrackOrientation  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
    constraint      : IPlcDynamicConstraint;  
    options         : ST_AdoptTrackOrientationOptions;  
END_VAR
```

## 40293226 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
| constraint | IPlcDynamicConstraint | Dynamic constraints for this movement. |
| options | [ST\_AdoptTrackOrientationOptions](ms-xhelp:///?Id=beckhoff-8d2a-4ba1-bbe0-23615f190dea) | Options for the rotation. |
