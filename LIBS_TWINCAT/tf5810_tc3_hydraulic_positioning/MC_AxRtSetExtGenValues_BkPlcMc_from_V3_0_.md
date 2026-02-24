# MC_AxRtSetExtGenValues_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Runtime](ms-xhelp:///?Id=beckhoff-6898-463a-a8a2-80cf35a5250d)
5. MC\_AxRtSetExtGenValues\_BkPlcMc (from V3.0)

# MC\_AxRtSetExtGenValues\_BkPlcMc (from V3.0)

![324668](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854814987__Web.gif)

The function block supplies an axis with command variables, which do not originate from the axis' own generator.

```
VAR_INPUT  
    Enable:             BOOL;  
    Position:           LREAL:=0.0;  
    Velocity:           LREAL:=0.0;  
    TargetPosition:     LREAL:=0.0;  
END_VAR
```

```
VAR_OUTPUT  
    Error:              BOOL;  
    ErrorID:            UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:               Axis_Ref_BkPlcMc;  
END_VAR
```

**Enable**: TRUE at this input activates the transfer of the command variables provided.

**Position**: [mm] Set position value to be transferred cyclically.

**Velocity**: [mm/s] Set velocity value to be transferred cyclically.

**TargetPosition**: [mm] Target position value for the current motion to be transferred cyclically.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block investigates the axis interface that has been passed to it every time it is called. If a positive edge is detected at **Execute**, the axis is put in state **McState\_Synchronizedmotion** and **iTcHydStateExtGenerated**.

If Execute is TRUE, the values of **Position, Velocity** and **TargetPosition** are entered in the runtime variables of the axis. The purpose is to model the behavior of the generator function block for a comparable motion, as far as possible.

If a negative edge is detected at Execute, the function block puts the axis in state **McState\_Standstill**. If the axis is not at standstill at this time, it is stopped via the time-controlled ramp set in fStopRamp.

|  |  |
| --- | --- |
| 2922015 | The generator function block of the axis should still be called cyclically. It deals with position control and updates further internal variables. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
