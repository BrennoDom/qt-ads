# AXIS_REF

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# AXIS\_REF

```
PROGRAM MAIN  
VAR  
    axis: AXIS_REF;  
END_VAR
```

```
axis.ReadStatus();
```

## MC axis variable

![4811061](/tf50x0_tc3_nc_ptp/1033/Images/png/9007202152039947__Web.png)

The PLC axis variable `MAIN.axis` has the data type `AXIS_REF`.

The data type `AXIS_REF:`

* contains information about an axis,
* is an interface between the PLC and the NC and
* is given to the MC function blocks as a reference to an axis.

|  |  |
| --- | --- |
| 43299552 | Refreshing the status data structure in `AXIS_REF`  The status data structure `Status` of the type `ST_AxisStatus` contains additional or prepared status and diagnostic information about an axis. The structure is not cyclically refreshed, but has to be updated by the PLC program  Calling the `ReadStatus()` action from `AXIS_REF` updates the status data structure and should be done once at the beginning of each PLC cycle.  The status information does not change within a PLC cycle. After calling `ReadStatus(),` the current status information can be accessed in `AXIS_REF` within the entire PLC program.  The nature of the status data structure is purely informative. Therefore, its use is not mandatory. |
