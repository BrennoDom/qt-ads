# ST_ExternalSetpointGenerationOptions

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# ST\_ExternalSetpointGenerationOptions

Options for the "ExternalSetpointGeneration" command of the Planar Mover.

## Syntax

Definition:

```
TYPE ST_ExternalSetpointGenerationOptions :  
STRUCT  
    mode : MC_EXTERNAL_SET_POSITION_MODE;  
END_STRUCT  
END_TYPE
```

## Parameters

| Name | Type | Default | Description |
| --- | --- | --- | --- |
| mode | MC\_EXTERNAL\_SET\_POSITION\_MODE | MC\_EXTERNAL\_SET\_POSITION\_MODE.Absolute | Mode can be relative or absolute, relative can be used parallel to all other commands, absolute only alone. |
