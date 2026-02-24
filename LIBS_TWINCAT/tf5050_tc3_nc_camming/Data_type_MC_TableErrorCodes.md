# Data type MC_TableErrorCodes

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_TableErrorCodes

# Data type MC\_TableErrorCodes

```
TYPE MC_TableErrorCodes :  
(  
   (* Cam Table Error Codes *)  
   MC_ERROR_POINTER_INVALID      := 16#4B30, (* invalid pointer (address) value *)  
   MC_ERROR_ARRAYSIZE_INVALID    := 16#4B31, (* invalid size of data structure *)  
   MC_ERROR_CAMTABLEID_INVALID   := 16#4B32, (* invalid cam table ID (not [1..255]) *)  
   MC_ERROR_POINTID_INVALID      := 16#4B33, (* invalid point ID *)  
   MC_ERROR_NUMPOINTS_INVALID    := 16#4B34,  
   MC_ERROR_MCTABLETYPE_INVALID  := 16#4B35,  
   MC_ERROR_NUMROWS_INVALID      := 16#4B36,  
   MC_ERROR_NUMCOLUMNS_INVALID   := 16#4B37,  
   MC_ERROR_INCREMENT_INVALID    := 16#4B38  
)  
END_TYPE
```

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
