# The ST_SyncMode data structure

## Library
tf5055_tc3_nc_flying_saw

## Category
Motion Control

1. [TF5055 TC3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
2. [Data types](ms-xhelp:///?Id=beckhoff-76b6-43c9-91cb-f1d97c3c996e)
3. The ST\_SyncMode data structure

# The ST\_SyncMode data structure

```
TYPE ST_SyncMode :  
STRUCT  
    (* mode *)  
    GearInSyncMode                          : E_GearInSyncMode;  
  
    (* 32 bit check mask ... *)  
    GearInSync_CheckMask_MinPos             : BOOL;  
    GearInSync_CheckMask_MaxPos             : BOOL;  
    GearInSync_CheckMask_MaxVelo            : BOOL;  
    GearInSync_CheckMask_MaxAcc             : BOOL;  
    GearInSync_CheckMask_MaxDec             : BOOL;  
    GearInSync_CheckMask_MaxJerk            : BOOL;  
    GearInSync_CheckMask_OptionalMinPos     : BOOL;  
    GearInSync_CheckMask_OptionalMaxPos     : BOOL;  
    GearInSync_CheckMask_OvershootPos       : BOOL;  
    GearInSync_CheckMask_UndershootPos      : BOOL;  
    GearInSync_CheckMask_OvershootVelo      : BOOL;  
    GearInSync_CheckMask_UndershootVelo     : BOOL;  
    GearInSync_CheckMask_OvershootVeloZero  : BOOL;  
    GearInSync_CheckMask_UndershootVeloZero : BOOL;  
  
    (* operation masks ... *)  
    GearInSync_OpMask_RollbackLock          : BOOL;  
    GearInSync_OpMask_InstantStopOnRollback : BOOL;  
    GearInSync_OpMask_PreferConstVelo       : BOOL;  
    GearInSync_OpMask_IgnoreMasterAcc       : BOOL;  
    GearInSync_OpMask_IgnoreSlaveAcc : BOOL;  
    GearInSync_OpMask_DetailedErrorCodes : BOOL;  
END_STRUCT  
END_TYPE  
  
TYPE E_GearInSyncMode :  
(  
    (* synchronization based on the master position, slave dynamics depend on master dynamics *)  
    GEARINSYNCMODE_POSITIONBASED,   
  
    (* synchronization based on a standalone slave PTP profile, master independet slave dynamics *)  
    GEARINSYNCMODE_TIMEBASED          
);  
END_TYPE
```

Note The time-based motion profile (GEARINSYNCMODE\_TIMEBASED) is currently only implemented for the function block MC\_GearInVelo.

**See also:**

* [Operation of the individual bits](https://infosys.beckhoff.com/english.php?content=../content/1033/tcncuniversalflyingsaw/html/tcncuniversalflyingsawboundaryconditions.htm&id=)
* [Error Codes](ms-xhelp:///?Id=beckhoff-7f23-4f8c-b101-b09e53ab1d43)

[TF5055 | TwinCAT 3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
