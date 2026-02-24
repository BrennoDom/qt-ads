# GETTASKTIME

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [[Obsolete]](ms-xhelp:///?Id=beckhoff-e729-4de7-9481-4905b7f6ef80)
4. GETTASKTIME

# GETTASKTIME

|  |  |
| --- | --- |
| 29760277 | This function block is replaced by the newer function F\_GetTaskTime(), which only needs one return value, not two. |

![66515904](/tcplclib_tc2_system/1033/Images/png/9007199285917963__Web.png)

This function block can be used to read the start time of the task (time at which the task should start). The function block always returns the start time of the task in which the function block instance was called. The time stamp is a 64-bit integer value with an accuracy of 100 ns. It can be used for timing tasks or time measurements, among other things. One unit corresponds to 100 ns. The time represents the number of 100 ns intervals since 1 January 1601.

See: [F\_GetTaskTime](ms-xhelp:///?Id=beckhoff-141f-4f79-b883-63b678c2af66)

## VAR\_INPUT

```
VAR_INPUT  
(*none*)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    timeLoDW : UDINT;  
    timeHiDW : UDINT;  
END_VAR
```

**timeLoDW**: Contains the low-value 4 bytes of the time stamp.

**timeHiDW**: Contains the high-value 4 bytes of the time stamp.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
