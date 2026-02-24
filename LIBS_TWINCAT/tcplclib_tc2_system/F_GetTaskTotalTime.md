# F_GetTaskTotalTime

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. F\_GetTaskTotalTime

# F\_GetTaskTotalTime

![64205424](/tcplclib_tc2_system/1033/Images/png/8831037067__Web.png)

For a task index the function F\_GetTaskTotalTime returns the total execution time of this task from the last cycle. The total execution time is the sum of the computing times of all modules that are registered on to the task.

If 0 is passed as task index, the value for the task in which the function is called is determined. If an invalid task index is passed, the function returns 0 as the total execution time.

The total execution time that was determined is shown as a multiple of 100 ns and returned by the function as a return parameter.

## FUNCTION F\_GetTaskTotalTime: UDINT

```
VAR_INPUT  
    nTaskIndex : DINT;  
END_VAR
```

**nTaskIndex**: Index of the task whose total execution time is to be determined. If 0 is passed as task index, the value for the task in which the function is called is determined.

**See also:**

* [GETCURTASKINDEX](ms-xhelp:///?Id=beckhoff-64d8-4e29-89aa-2ceaa17c08d2)

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.11 | PC or CX (x86, x64, ARM) | Tc2\_System (System) >= 3.4.24.0 |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
