# St_StateEV

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Structures](ms-xhelp:///?Id=beckhoff-9706-4771-ad0e-639d770876a0)
5. St\_StateEV

# St\_StateEV

Information on the state of the EV.

```
TYPE St_StateEV :  
STRUCT  
  bFlow_with_closed_valve : BOOL;  
  bAir_bubbles            : BOOL;  
  bFlow_not_reached       : BOOL;  
  bPower_not_realized     : BOOL;  
  bGear_disengaged        : BOOL;  
END_STRUCT  
END_TYPE
```

**bFlow\_with\_closed\_valve:** Flow rate with closed valve. Check valve.

**bAir\_bubbles:** Too many air bubbles (system venting inadequate). Flow measurement no longer exact. EV switches from volume flow control to position control.

**bFlow\_not\_reached:** Flow rate not reached, despite the fact that the ball valve is fully open. Check hydraulics, switch on pump or increase pump pressure.

**bPower\_not\_realized:** Power not reached. In addition to position control and volume flow control, the EV can be used to supply power. Primary side provides too little flow or dT.

**bGear\_disengaged:** Gear disengagement active. Manual adjustment possible on site. For other MP drives this information can be read with MP\_Get\_State.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.32 | Tc2\_MPBus from 3.4.6.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
