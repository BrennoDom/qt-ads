# Data type MC_ValueSelectType

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_ValueSelectType

# Data type MC\_ValueSelectType

```
TYPE MC_ValueSelectType :  
(  
   (* a bitmask can be created by adding the following values *)  
   MC_VALUETYPE_POSITION      := 1,  
   MC_VALUETYPE_VELOCITY      := 2,  
   MC_VALUETYPE_ACCELERATION  := 4,  
   MC_VALUETYPE_JERK          := 8  
);  
END_TYPE
```

Type definition for access to value tables with the function block [MC\_ReadMotionFunctionValues](ms-xhelp:///?Id=beckhoff-c700-4d39-8ab1-f177c91e11de).

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
