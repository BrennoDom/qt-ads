# SetExternalSetpoint

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# SetExternalSetpoint

SetExternalSetpoint setPosition  MoverVectorsetVelocity  MoverVectorsetAcceleration  MoverVector

Sets the external setpoint for the Planar Mover, must be called each PLC cycle during external setpoint generation.

## Syntax

Definition:

```
METHOD SetExternalSetpoint  
VAR_INPUT  
    setPosition     : MoverVector;  
    setVelocity     : MoverVector;  
    setAcceleration : MoverVector;  
END_VAR
```

## 44048571 Inputs

| Name | Type | Description |
| --- | --- | --- |
| setPosition | MoverVector | Position that is send to the Planar Mover. |
| setVelocity | MoverVector | Velocity that is send to the Planar Mover. |
| setAcceleration | MoverVector | Acceleration that is send to the Planar Mover. |
