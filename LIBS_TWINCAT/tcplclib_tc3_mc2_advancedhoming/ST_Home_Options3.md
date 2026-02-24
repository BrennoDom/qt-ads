# ST_Home_Options3

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# ST\_Home\_Options3

```
TYPE MC_Home_Options3 :  
STRUCT  
    DisableDriveAccess  : BOOL;  
    InstantLagReduction : BOOL;  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| DisableDriveAccess | BOOL | When setting this flag, no modifications are made to the parameters of the hardware controller and the user is responsible for modifying them to an appropriate extent so that the actual referencing process is possible. |
| InstantLagReduction | BOOL | When referencing to a mechanical fixed stop, the sudden stop produces a position lag in the NC axis, which is dissipated with the parameterized dynamic values in the further course. This can lead to an assumed delay when observing the sequence, but it is purposeful in particular with "soft" fixed stops. The position lag is dissipated abruptly by setting this flag. |
