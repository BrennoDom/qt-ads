# ST_TcHybridAxRtData (from V3.0.44)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcHybridAxRtData (from V3.0.44)

# ST\_TcHybridAxRtData (from V3.0.44)

This structure contains additional runtime values of the servo-electric/hydraulic axis.

|  |  |
| --- | --- |
| 25105132 | The parameter sequence is not guaranteed. |

```
                                                                                                                                                                                                                                                        TYPE ST_TcHybridAxRtData :  
(* last modification: 05.12.2018 *)  
STRUCT  
    fPump_Angle:            LREAL;  
    fPump_ModuloAngle:        LREAL;   
    fPump_Speed:            LREAL;  
    fPump_Torque:            LREAL;  
  
    fMotor_N_max:            LREAL;  
    fMotor_RefCurrent:        LREAL;  
    fMotor_RefTorque:        LREAL;  
    fMotor_PeekCurrent:        LREAL;  
    fMotor_PeekTorque:        LREAL;  
    fMotor_NomCurrent:        LREAL;  
    fMotor_NomTorque:        LREAL;  
  
    fActive_Area_P:        LREAL;  
    fActive_Area_M:        LREAL;  
    fActive_Qmax_P:        LREAL;  
    fActive_Qmax_M:        LREAL;  
  
    fActive_Feed_P:        LREAL;   
    fActive_Feed_M:        LREAL;   
  
    fActive_N_max:            LREAL;   
  
    fActive_Vmax_P:        LREAL;   
    fActive_Vmax_M:        LREAL;   
  
    fFeed_RampRate_P:        LREAL;  
    fFeed_RampRate_M:        LREAL;  
    fRamping_Feed_P:        LREAL;  
    fRamping_Feed_M:        LREAL;  
  
    bPump_Switched:        BOOL;  
    bPump_AreaSwitched:        BOOL;  
    bMotor_EnablePwrMon:    BOOL;  
    bReRamp_FeedFactor:        BOOL;  
    bHydActualCall:        BOOL;   
END_STRUCT  
END_TYPE
```

**bHydActualCall:** This signal indicates that an instance of the function block MC\_AxRtHybridAxisActuals\_BkPlcMc () has been called for the servo-electric/hydraulic axis. Otherwise it is not ensured that the actual values of the axis are fully determined and the effects of pump or area switching are taken into account. In this case, the axis is set to the error state and a message is written to the log.

**bMotor\_EnablePwrMon:** This signal indicates that the current and torque parameters of the drive have been read and an accurate torque calculation is available.

**bPump\_AreaSwitched:** This signal indicates active activation of the areas for force mode.

**bPump\_Switched:** This signal indicates active switching of the pump to force mode.

**bReRamp\_FeedFactor:** This signal starts the ramp for switching between rapid and force mode.

**fActive\_Area\_M:** [mm2] The currently effective area on the M-side of the cylinder.

**fActive\_Area\_P:** [mm2] The currently effective area on the P-side of the cylinder.

**fActive\_Feed\_M:** [mm/rev] The currently available rotational feed rate on the M-side of the cylinder.

**fActive\_Feed\_P:** [mm/rev] The currently available rotational feed rate on the P-side of the cylinder.

**fActive\_N\_max:** [rpm] The currently available maximum speed of motor and pump.

**fActive\_Qmax\_M:** [cm3/rev] The currently available quantity on the M-side of the cylinder.

**fActive\_Qmax\_P:** [cm3/rev] The currently available quantity on the P-side of the cylinder.

**fActive\_Vmax\_M:** [mm/s] The currently available maximum velocity in negative direction.

**fActive\_Vmax\_P:** [mm/s] The currently available maximum velocity in positive direction.

**fFeed\_RampRate\_M:** [mm/rev/cycle] The cycle-related feed factor change of a current or already executed ramp in the negative direction of cylinder movement.

**fFeed\_RampRate\_P:** [mm/rev/cycle] The cycle-related feed factor change of a current or already executed ramp in the positive direction of cylinder movement.

**fMotor\_N\_max:** [rpm] The maximum speed of the motor.

**fMotor\_NomCurrent:** [A] The current rating of the motor.

**fMotor\_NomTorque:** [Nm] The torque rating of the motor.

**fMotor\_PeekCurrent:** [A] The current peak value of the motor.

**fMotor\_PeekTorque:** [Nm] The torque peak value of the motor.

**fMotor\_RefCurrent:** [A] The current reference value of the motor.

**fMotor\_RefTorque:** [Nm] The torque reference value of the motor.

**fPump\_Angle:** [°] The rotation-related actual angle of the motor and thus also of the pump in the range 0 ... 360°.

**fPump\_ModuloAngle:** [°] The cavity-related actual angle of the motor and thus also of the pump in the range 0 ... 360°/number\_of\_cavities.

**fPump\_Speed:** [°/s] The angular speed of the motor and thus also of the pump. This value corresponds to six times the speed in rpm.

**fPump\_Torque:** [%] The torque called up by the pump from the motor in relation to its rated torque.

**fRamping\_Feed\_M:** [mm/rev] The current ramped feed factor in positive direction of cylinder movement.

**fRamping\_Feed\_P:** [mm/rev] The current ramped feed factor in positive direction of cylinder movement.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
