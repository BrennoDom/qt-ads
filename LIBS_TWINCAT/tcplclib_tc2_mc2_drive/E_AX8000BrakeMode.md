# E_AX8000BrakeMode

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# E\_AX8000BrakeMode

Sets the mode for manual brake control using the [FB\_CoEAX8000BrakeControl](ms-xhelp:///?Id=beckhoff-d8d6-4334-b312-95ca78ea1c66).

```
TYPE E_AX8000BrakeMode : (  
    eAX8000BrakeMode_Automatic,  
    eAX8000BrakeMode_Lock,  
    eAX8000BrakeMode_Unlock  
) INT;  
END_TYPE
```

| Name | Description |
| --- | --- |
| eAX8000BrakeMode\_Automatic | The brake of the motor connected to the AX8000 is automatically opened or closed via the AX8000. |
| eAX8000BrakeMode\_Lock | The brake of the motor connected to an AX8000 remains permanently closed.  Enabling the axis via the MC\_Power does not release the brake. |
| eAX8000BrakeMode\_Unlock | The brake of the motor connected to an AX8000 is opened permanently.  Disabling the axis via the MC\_Power does not close the brake.  WARNING Vertical axes can fall down! |
