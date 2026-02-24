# E_AX5000ParkMode

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# E\_AX5000ParkMode

This ENUM determines whether the [FB\_SoEAX5000ParkAxis](ms-xhelp:///?Id=beckhoff-d8e6-4ce6-887a-222e2292b402) parks or releases the corresponding channel of the AX5000.

```
TYPE E_AX5000ParkMode : (  
    eAX5000ParkMode_Park,  
    eAX5000ParkMode_Release  
)INT;  
END_TYPE
```

| Name | Description |
| --- | --- |
| eAX5000ParkMode\_Park | AX5000 channel is to be parked. |
| eAX5000ParkMode\_Release | AX5000 channel is to be released. |
