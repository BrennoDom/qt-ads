# Data type MC_CamOperationMode

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_CamOperationMode

# Data type MC\_CamOperationMode

The *CamOperationMode* is used for managing couplings with superimposed cam plates with the function block [MC\_CamIn\_V2](ms-xhelp:///?Id=beckhoff-b46a-4343-a1d4-b2c35fe9a410) (multi-cam). Cam plates can be added, switched or removed.

```
TYPE MC_CamOperationMode :  
(  
   CAMOPERATIONMODE_DEFAULT,  (* same as additive *)  
   CAMOPERATIONMODE_ADDITIVE, (* additive cam in a multi cam scenario *)  
   CAMOPERATIONMODE_EXCHANGE, (* exchange existing cam in a multi cam scenario *)  
   CAMOPERATIONMODE_REMOVE    (* remove cam from a multi cam scenario *)  
 );  
END_TYPE
```

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
