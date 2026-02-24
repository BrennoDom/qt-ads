# Data type MC_FlyingSawCharacValues

## Library
tf5055_tc3_nc_flying_saw

## Category
Motion Control

1. [TF5055 TC3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
2. [Data types](ms-xhelp:///?Id=beckhoff-76b6-43c9-91cb-f1d97c3c996e)
3. Data type MC\_FlyingSawCharacValues

# Data type MC\_FlyingSawCharacValues

```
TYPE MC_FlyingSawCharacValues :  
STRUCT  
    (* Master Velocity*)  
    fMasterVeloNom     : LREAL; (* 1. master nominal velocity (normed:=> 1.0) *)  
  
    (* characteristic slave data *)  
    (*===========================*)  
  
    (* Start of cam table *)  
    fMasterPosStart    : LREAL; (* 2. master start position*)  
    fSlavePosStart     : LREAL; (* 3. slave start position *)  
    fSlaveVeloStart    : LREAL; (* 4. slave start velocity *)  
    fSlaveAccStart     : LREAL; (* 5. slave start acceleration *)  
    fSlaveJerkStart    : LREAL; (* 6. slave start jerk *)  
  
  
    (* End of cam table*)  
    fMasterPosEnd      : LREAL; (* 7. master end position *)  
    fSlavePosEnd       : LREAL; (* 8. slave end position *)  
    fSlaveVeloEnd      : LREAL; (* 9. slave end velocity *)  
    fSlaveAccEnd       : LREAL; (* 10. slave end acceleration *)  
    fSlaveJerkEnd      : LREAL; (* 11. slave end jerk *)  
  
    (* minimum slave position *)  
    fMPosAtSPosMin     : LREAL; (* 12. master position AT slave minimum position *)  
    fSlavePosMin       : LREAL; (* 13. slave minimum position *)  
  
    (* minimum Slave velocity *)  
    fMPosAtSVeloMin    : LREAL; (* 14. master position AT slave minimum velocity *)  
    fSlaveVeloMin      : LREAL; (* 15. slave minimum velocity *)  
  
    (* minimum slave acceleration *)  
    fMPosAtSAccMin     : LREAL; (* 16. master position AT slave minimum acceleration *)  
    fSlaveAccMin       : LREAL; (* 17. slave minimum acceleration *)  
    fSVeloAtSAccMin    : LREAL; (* 18. slave velocity AT slave minimum acceleration *)  
  
    (* minimum slave jerk and dynamic momentum *)  
    fSlaveJerkMin      : LREAL; (* 19. slave minimum jerk *)  
    fSlaveDynMomMin    : LREAL; (* 20. slave minimum dynamic momentum (NOT SUPPORTED YET !) *)  
  
    (* maximum slave position *)  
    fMPosAtSPosMax     : LREAL; (* 21. master position AT slave maximum position *)  
    fSlavePosMax       : LREAL; (* 22. slave maximum position *)  
  
    (* maximum Slave velocity *)  
    fMPosAtSVeloMax    : LREAL; (* 23. master position AT slave maximum velocity *)  
    fSlaveVeloMax      : LREAL; (* 24. slave maximum velocity *)  
  
    (* maximum slave acceleration *)  
    fMPosAtSAccMax     : LREAL; (* 25. master position AT slave maximum acceleration *)  
    fSlaveAccMax       : LREAL; (* 26. slave maximum acceleration *)  
    fSVeloAtSAccMax    : LREAL; (* 27. slave velocity AT slave maximum acceleration *)  
  
    (* maximum Slave slave jerk and dynamic momentum *)  
    fSlaveJerkMax      : LREAL; (* 28. slave maximum jerk *)  
    fSlaveDynMomMax    : LREAL; (* 29. slave maximum dynamic momentum (NOT SUPPORTED YET !) *)  
  
    (* mean and effective values *)  
    fSlaveVeloMean     : LREAL; (* 30. slave mean absolute velocity (NOT SUPPORTED YET !) *)  
    fSlaveAccEff       : LREAL; (* 31. slave effective acceleration (NOT SUPPORTED YET !) *)  
  
    (* reserved space for future extension *)  
    reserved           : ARRAY[32..47] OF LREAL;  
  
    (* organization structure of the cam table *)  
    CamTableID         : UDINT;  
    NumberOfRows       : UDINT; (* number of cam table entries, e.g. number of points *)  
    NumberOfColumns    : UDINT; (* number of table columns, typically 1 or 2 *)  
    TableType          : UINT; (* MC_TableType *)  
    Periodic           : BOOL;  
  
    reserved2          : ARRAY[1..121] OF BYTE;  
END_STRUCT  
END_TYPE
```

Type definition for the characteristic parameters of a flying saw synchronization.

[TF5055 | TwinCAT 3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
