# ST_TcHybridAxParam (from V3.0.44)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcHybridAxParam (from V3.0.44)

# ST\_TcHybridAxParam (from V3.0.44)

This structure contains additional parameters of the servo-electric/hydraulic axis. Under Setup (partly in preparation), suitable procedures for axis commissioning are presented.

|  |  |
| --- | --- |
| 19365543 | The order of the parameters is not guaranteed. |

```
TYPE ST_TcHybridAxParam :  
(* last modification: 20.02.2019 *)  
STRUCT  
    fPump_N_max:          LREAL;  
    fPump_N_min:          LREAL;   
  
    fPump_P_max:          LREAL;   
    fPump_P_min:          LREAL;   
  
    fPump_Q_fast_P:       LREAL;   
    fPump_Q_slow_P:       LREAL;   
  
    fPump_Q_fast_M:       LREAL;   
    fPump_Q_slow_M:       LREAL;   
  
    fPump_Q_leak:         LREAL;   
  
    fPump_Enc_Offset:     LREAL;   
  
    fCylinder_A_addP:     LREAL;   
    fCylinder_A_addM:     LREAL;   
  
    fRampTime:            LREAL;   
  
    fAside_PrsScaling:    LREAL;   
    fBside_PrsScaling:    LREAL;   
    fSystem_PrsScaling:   LREAL;   
  
    nPumpCavities:        DINT;   
    nConcept:             DINT;   
  
    nPump_EncType:        E_TcMcEncoderType:=iTcMc_EncoderSim;   
  
    bRegenerative:        BOOL;   
    bVirtual_A_addP:      BOOL;   
    bVirtual_A_addM:      BOOL;   
    bAside_PrsHiResADC:   BOOL;   
    bBside_PrsHiResADC:   BOOL;   
    bSystem_PrsHiResADC:  BOOL;   
  
END_STRUCT  
END_TYPE
```

**bAside\_PrsHiResADC:** This parameter indicates that the pressure sensor of the area with positive direction of action is read with a 24-bit input terminal.

**bBside\_PrsHiResADC:** This parameter indicates that the pressure sensor of the area with negative direction of action is read with a 24-bit input terminal.

**bSystem\_PrsHiResADC:** This parameter indicates that the pressure sensor at the pressurized hydraulic reservoir is read with a 24-bit input terminal.

**bRegenerative:** This parameter indicates that the smaller cylinder area is operated in oil exchange with the larger cylinder area.

**bVirtual\_A\_addM:** If an area that can be activated in the negative direction of action is effective for the oil demand but not for the force build-up, it must be identified here.

**bVirtual\_A\_addP:** If an area that can be activated in the positive direction of action is effective for the oil demand but not for the force build-up, it must be identified here.

**fAside\_PrsScaling, fBside\_PrsScaling, fSystem\_PrsScaling:** The scaling pressures for the A-side, the B-side and the system pressure detection are to be set here.

**fCylinder\_A\_addM:** If, depending on the situation, an area effective for oil demand is connected in the negative direction of action, it must be identified here. This can also be an oil demand required by an apparent area, which actually bypasses the cylinder. In this case, the area should be identified as "virtual".

**fCylinder\_A\_addP:** If, depending on the situation, an area effective for oil demand is connected in the positive direction of action, it must be identified here. This can also be an oil demand required by an apparent area, which actually bypasses the cylinder. In this case, the area should be identified as "virtual".

**fPump\_Enc\_Offset:** reserved.

**fPump\_N\_min, fPump\_N\_max:** [rpm] The minimum and maximum permissible pump speeds.

**fPump\_P\_min, fPump\_P\_max:** [bar] The minimum and maximum permissible operating pressure of the pump.

**fPump\_Q\_fast\_M, fPump\_Q\_slow\_M:** [cm3/rev] The rotation-related flow rate of the pump in rapid or force mode at the cylinder connection acting in the negative direction.

**fPump\_Q\_fast\_P, fPump\_Q\_slow\_P:** [cm3/rev] The rotation-related flow rate of the pump in rapid or force mode at the cylinder connection acting in the positive direction.

**fPump\_Q\_leak:** reserved.

**fRampTime:** When switching between rapid and force mode, the weighting factor for the velocity output and the maximum attainable velocity are changed. A ramp can be defined here, in order to avoid a discontinuity.

**nConcept:** The circuit concept used for the servo-electric/hydraulic axis must be specified here.

**nPumpCavities:** Enter the number of pump chambers here. For piston pumps the number of pistons must be set. For internal gear pumps, the number of teeth on the internal pinion must be set.

**nPump\_EncType:** The [encoder type](ms-xhelp:///?Id=beckhoff-1819-4c81-9982-5253100bd275) of the pump drive is defined here. Only a small selection of encoder types is available.

|  |  |
| --- | --- |
| 40072161 | This is not the encoder on the cylinder. |

See Setup for more information about axis commissioning.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
