# E_TcMCFbState (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. E\_TcMCFbState (from V3.0)

# E\_TcMCFbState (from V3.0)

The constants listed here are used to identify the runtime states of the axes.

```
TYPE E_TcMCFbState :  
(  
McState_Standstill := 0,  
McState_DiscreteMotion,  
McState_Continousmotion,  
McState_Synchronizedmotion,  
McState_Stopping,  
McState_Errorstop,  
McState_Homing,  
McState_Disabled  
);  
END_TYPE
```

**McState\_Standstill**: The axis does not have a transport instruction. Active position control, repositioner monitoring, the output of a press control value or none of these will be carried out, depending on the parameterization.

**McState\_DiscreteMotion**: The axis executes a movement with a defined destination position and velocity.

**McState\_Continousmotion**: The axis executes a movement without any defined destination position. Only the velocity is specified.

**McState\_Synchronizedmotion**: The axis performs a movement, which is derived from the movement of another axis.

**McState\_Stopping**: The axis is carrying out a stop.

**McState\_Errorstop**: The axis has been stopped because of a problem. It cannot at present be started, and requires a reset before it will be in a condition from which it can start.

**McState\_Homing**: The axis is homing.

**McState\_Disabled**: The controller enable of the axis is FALSE.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
