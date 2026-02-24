# Data type MC_CamInfoData

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_CamInfoData

# Data type MC\_CamInfoData

```
TYPE MC_CamInfoData :  
STRUCT  
   Execute                      : BOOL;  
   TableType                    : MC_TableType;  
   Periodic                     : BOOL;  
   InterpolationType            : MC_InterpolationType;  
   NumberOfRows                 : UDINT; (* number of cam table entries, e. g. number of points *)  
   NumberOfColumns              : UDINT; (* number of table columns, typically 1 or 2 *)  
   MasterCamStartPos            : LREAL; (* Master pos. of the first cam table point (raw, unscaled cam table pos.) *)  
   SlaveCamStartPos             : LREAL; (* Slave pos. of the first cam table point (raw, unscaled cam table pos.) *)  
   RawMasterPeriod              : LREAL; (* raw, unscaled difference between last and first cam point *)  
   RawSlaveStroke               : LREAL; (* raw, unscaled difference between last and first cam point *)  
   MasterAxisCouplingPos        : LREAL; (* Master axis position when slave has been coupled *)  
   SlaveAxisCouplingPos         : LREAL; (* Slave axis position when slave has been coupled *)  
   MasterAbsolute               : BOOL; (* raw, unscaled distance from first to last master cam table position *)  
   SlaveAbsolute                : BOOL; (* raw, unscaled distance from first to last slave cam table position *)  
   MasterOffset                 : LREAL; (* total master offset *)  
   SlaveOffset                  : LREAL; (* total slave offset *)  
   MasterScaling                : LREAL; (* total master scaling factor *)  
   SlaveScaling                 : LREAL; (* total slave scaling factor *)  
   SumOfSlaveStrokes            : LREAL; (* sum of the slave strokes up to ActualMasterAxisPos *)  
   SumOfSuperpositionDistance   : LREAL; (* sum of additional moves through MC_MoveSuperimposed *)  
   ActualMasterAxisPos          : LREAL; (* absolute set position of the master axis *)  
   ActualSlaveAxisPos           : LREAL; (* absolute set position of the slave axis *)  
   ActualMasterCamPos           : LREAL; (* raw, unscaled cam table position of the master *)  
   ActualSlaveCamPos            : LREAL; (* raw, unscaled cam table position of the slave *)  
  
   (* mode for the scaling of cam tables *)  
   ScalingPending               : BOOL; (* a change is currently pending *)  
   ScalingActivationMode        : MC_CamActivationMode;  
   ScalingActivationPos         : LREAL;  
   ScalingMasterScalingMode     : MC_CamScalingMode;  
   ScalingSlaveScalingMode      : MC_CamScalingMode;  
  
   (* mode for online changes of cam table data *)  
   CamDataQueued                : BOOL; (* a change is currently pending *)  
   OnlineChangeActivationMode   : MC_CamActivationMode;  
   OnlineChangeActivationPos    : LREAL;  
   OnlineChangeMasterScalingMode: MC_CamScalingMode;  
   OnlineChangeSlaveScalingMode : MC_CamScalingMode;  
  
   (* mode for exchanging cam tables with MC_CamIn *)  
   CamTableQueued               : BOOL; (* a change is currently pending *)  
   CamExchangeCamTableID        : MC_CAM_ID;  
   CamExchangeActivationMode    : MC_CamActivationMode;  
   CamExchangeActivationPos     : LREAL;  
   CamExchangeMasterScalingMode : MC_CamScalingMode;  
   CamExchangeSlaveScalingMode  : MC_CamScalingMode;  
END_STRUCT  
END_TYPE
```

The data structure *MC\_CamInfoData* contains data on the current state of a cam plate coupling. The data are determined with the function block [MC\_CamInfo](ms-xhelp:///?Id=beckhoff-a6a4-4e81-a1cb-507ce7b2b5c1).

The structure contains absolute axis positions relating to the master or slave axis coordinate system. It also contains cam plate positions which refer to the cam plate coordinate system (e.g. *ActualMasterCamPos* and *ActualSlaveCamPos*). All cam positions relate to the non-scaled cam plate coordinate system and can be converted to the scaled coordinate system, if required. A master cam position can be multiplied with the *MasterScaling* factor, a slave cam position can be multiplied with the *SlaveScaling* factor.

The activation positions *ActivationPos* relate to the master axis coordinate system or the cam plate coordinate system, depending on the *ActivationMode*. In the latter case non-scaled cam plate positions are specified.

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
