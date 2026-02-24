# F_GetTaskTime

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [Time functions](ms-xhelp:///?Id=beckhoff-7720-4bec-b15f-879f9571ce77)
4. F\_GetTaskTime

# F\_GetTaskTime

![32787233](/tcplclib_tc2_system/1033/Images/png/3623371403__Web.png)

This function can be used to read the start time of the task (time at which the task should start). The function always returns the start time of the task in which the function was called. The time stamp is a 64-bit integer value with an accuracy of 100 ns. It can be used for timing tasks or time measurements, among other things. One unit corresponds to 100 ns. The time represents the number of 100 ns intervals since 1 January 1601.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    F_GetTaskTime : ULINT;  
END_VAR
```

The return value contains the time stamp.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1 | PC or CX (x86, x64, ARM) | Tc2\_System (system) >= 3.4.17.0 |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
