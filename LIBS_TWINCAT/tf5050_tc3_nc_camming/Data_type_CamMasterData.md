# Data type CamMasterData

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type CamMasterData

# Data type CamMasterData

Data of type CamMasterData are optionally transferred by function block [MC\_ReadCamTableMasterPosition](ms-xhelp:///?Id=beckhoff-d1e3-4bbb-a352-98a9c418a54a).

```
TYPE CamMasterData :  
STRUCT  
   Valid               : BOOL;  (* position information is valid *)  
   MasterAxisPosition  : LREAL; (* absolute master axis position *)  
   MasterCamPosition   : LREAL; (* local master cam position *)  
   SlaveOffset         : LREAL; (* slave cam offset corresponding to the master position *)  
END_STRUCT  
END_TYPE
```

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
