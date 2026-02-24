# ST_Home_Options2

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# ST\_Home\_Options2

```
TYPE MC_Home_Options2 :  
STRUCT  
    DisableDriveAccess : BOOL;  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| DisableDriveAccess | BOOL | When setting this flag, no modifications are made to the parameters of the hardware controller and the user is responsible for modifying them to an appropriate extent so that the actual referencing process is possible. |
