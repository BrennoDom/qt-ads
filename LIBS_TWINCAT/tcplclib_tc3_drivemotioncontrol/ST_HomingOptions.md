# ST_HomingOptions

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Data types](ms-xhelp:///?Id=beckhoff-6026-4a24-928a-c60b12336bae)
3. [Homing](ms-xhelp:///?Id=beckhoff-3b23-4663-895d-2e53b7962810)
4. ST\_HomingOptions

# ST\_HomingOptions

```
TYPE ST_HomingOptions :  
STRUCT  
(  
    SearchDirection   : MC_Direction := MC_Direction.MC_Undefined_Direction;                                        (* search direction *)  
    SearchVelocity    : LREAL;                                                                                      (* search velocity *)  
    SyncDirection     : MC_Direction := MC_Direction.MC_Undefined_Direction;                                        (* synchronization direction *)  
    SyncVelocity      : LREAL;                                                                                      (* synchronization velocity *)  
    ReferenceMode     : E_EncoderReferenceMode := E_EncoderReferenceMode.ENCODERREFERENCEMODE_CAMATDIGITALINPUT;    (* Mode of reference sequence *)  
  
    Acceleration      : LREAL;                                                                                      (* user defined acceleration *)  
    Deceleration      : LREAL;                                                                                      (* user defined deceleration *)  
);  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
