# Data type MC_TableType

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_TableType

# Data type MC\_TableType

```
TYPE MC_TableType :  
(  
   (* n*m tabular with equidistant ascending master values *)  
   MC_TABLETYPE_EQUIDISTANT      := 10,  
  
   (* n*m tabular with strictly monotone ascending master values (not imperative equidistant) *)  
   MC_TABLETYPE_NONEQUIDISTANT   := 11,  
  
   (* motion function calculated in runtime *)   
   MC_TABLETYPE_MOTIONFUNCTION   := 22  
);  
END_TYPE
```

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
