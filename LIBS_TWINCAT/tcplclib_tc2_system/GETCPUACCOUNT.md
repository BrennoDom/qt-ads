# GETCPUACCOUNT

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [Time function blocks](ms-xhelp:///?Id=beckhoff-efc6-4ab5-9171-cb491091caca)
4. GETCPUACCOUNT

# GETCPUACCOUNT

|  |  |
| --- | --- |
| 33599791 | This functionality is not available on PLC runtime system under Windows CE. |

![33962670](/tcplclib_tc2_system/1033/Images/png/9007199285924363__Web.png)

The PLC task cycle ticker can be read with this function block. The PLC task cycle ticker is only incremented while the task is being executed. The numerical value is a 32 bit integer, which, independently of the CPU's internal clock rate, is output in a form converted into 100 ns ticks. The number is refreshed to a precision of 100 ns every time the PLC task is called, and can be used, for instance, for timing purposes. One unit is equivalent to 100 ns.

## VAR\_INPUT

```
VAR_INPUT  
(*none*)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    cpuAccountDW : UDINT;  
END_VAR
```

**cpuAccountDW**: Current value of the PLC task ticker

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
