# ST_DriveMoveVelocityOptions

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [SimplePlcMotion](ms-xhelp:///?Id=beckhoff-d730-4dec-8474-8785da774c32)
4. ST\_DriveMoveVelocityOptions

# ST\_DriveMoveVelocityOptions

The structure ST\_DriveMoveVelocityOptions describes additional parameters of the function blocks [FB\_CoEDriveMoveVelocity](ms-xhelp:///?Id=beckhoff-e3ae-44bf-90c3-921f66b078e1) and [FB\_SoEDriveMoveVelocity](ms-xhelp:///?Id=beckhoff-4850-4b6e-8ac5-f3d3df3419aa).

```
TYPE ST_DriveMoveVelocityOptions :  
STRUCT  
    bVelocityUnitRPM          : BOOL;  
    fVelocityThreshold        : LREAL;  
    fVelocityScalingFactor    : LREAL;  
    fFilterTimeActualVelocity : LREAL;  
    bInvertDirection          : BOOL;  
END_STRUCT  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
