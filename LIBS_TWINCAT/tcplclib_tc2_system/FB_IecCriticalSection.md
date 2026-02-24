# FB_IecCriticalSection

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [General function blocks](ms-xhelp:///?Id=beckhoff-8c7f-4e24-ae22-527914ce956b)
4. FB\_IecCriticalSection

# FB\_IecCriticalSection

The function block is used to make critical sections mutually exclusive. Critical sections are characterized by modifications affecting one or usually several variables, which have an inconsistent state during modifications. It is therefore imperative that such modifications are only carried out by one task at a time. The function block provides the methods Enter() and Leave() for this purpose. A successful call of Enter() makes the critical section accessible; the section is then regarded as occupied. Once the modifications are complete, the critical section must be exited through Leave().

![36549175](assets/img/safety-logos/SmallWarningYellow.gif)CAUTION

Cycle timeout due to stopped task

If another task tries to access an occupied critical area through an Enter() call, it is blocked by the TwinCAT scheduler. The task is blocked until the section is enabled again! Once enabled, processing of the program code continues, and the critical section is entered.

* Ensure that the critical sections are kept short, in order to avoid cycle overruns in the waiting task. If several tasks are waiting to enter the critical section, access is granted based on their priority.

If a task is blocked by the TwinCAT scheduler because it attempted to enter an occupied critical area, this is done without "busy waiting". Low-priority tasks can therefore utilize the CPU capacity during this time.

|  |  |
| --- | --- |
| 60507121 | Windows CE  The functionality is supported under Windows CE operating systems from TwinCAT v3.1.4022.29 onwards. (In older TwinCAT versions the methods return FALSE.) |

## Alternative

Critical sections can also be realized with the function [TestAndSet()](ms-xhelp:///?Id=beckhoff-426b-4d4f-b70f-29aacfb4e2cb). The function can be used to select and check the content of a critical section. However, the function does not have a blocking effect, and it is possible that the section cannot be processed in a cycle.

As a rule, the number and length of the critical sections should be kept as small as possible.

## Enter() method

![7693179](/tcplclib_tc2_system/1033/Images/png/2326162571__Web.png)

The method marks the start of a critical section.

Possible return values:

TRUE:

* The critical section may be entered.

FALSE:

* The critical section may not be entered.
* The function block is not yet supported by the runtime.
* The critical section is occupied by another PLC task. This task is on stop in a break point. The return value FALSE avoids permanent blocking of the task and ensures updating of the I/O.

## Leave() method

![2129750](/tcplclib_tc2_system/1033/Images/png/2326164619__Web.png)

The method marks the end of a critical section. It must always be called when a critical section is completed.

Possible return values:

TRUE:

* The section was exited successfully.

FALSE:

* The function block is not supported by the runtime.
* The critical section was not occupied with Enter.

**Application sample for the function block:**

The function block FB\_IecCriticalSection enables access to shared files to be secured. The instance of the function block and the data to be secured are created globally.

```
VAR_GLOBAL  
    fbCrititcalSection : FB_IecCriticalSection;  
END_VAR  
  
IF fbCrititcalSection.Enter() THEN  
    (* start of critical section *)  
      
    (* end of critical section *)  
    fbCrititcalSection.Leave();  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4020 | PC or CX (x86, x64) WES, WES7, Win7, Win10 | Tc2\_System (system) |
| TwinCAT v3.1.4022.29 | PC or CX (x86, ARM) WinCE | Tc2\_System (system) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
