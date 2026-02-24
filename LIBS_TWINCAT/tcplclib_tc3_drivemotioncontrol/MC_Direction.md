# MC_Direction

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Data types](ms-xhelp:///?Id=beckhoff-6026-4a24-928a-c60b12336bae)
3. [Motion](ms-xhelp:///?Id=beckhoff-689f-4b20-bea7-256b1f6b652f)
4. MC\_Direction

# MC\_Direction

This enumeration type contains the possible directions of movement for the function blocks [MC\_MoveVelocity](ms-xhelp:///?Id=beckhoff-0eb3-4623-9d72-92f2c021292a) and [MC\_MoveModulo](ms-xhelp:///?Id=beckhoff-1762-48bc-84a8-3831de16ade0).

```
TYPE MC_Direction :  
(  
    MC_Undefined_Direction  := 0,  
    MC_Positive_Direction   := 1,  
    MC_Shortest_Way         := 2,  
    MC_Negative_Direction   := 3  
);  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
