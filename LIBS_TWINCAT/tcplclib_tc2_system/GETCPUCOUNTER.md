# GETCPUCOUNTER

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [Time function blocks](ms-xhelp:///?Id=beckhoff-efc6-4ab5-9171-cb491091caca)
4. GETCPUCOUNTER

# GETCPUCOUNTER

![37228582](/tcplclib_tc2_system/1033/Images/png/9007199285921163__Web.png)

The CPU cycle counter can be read with this function block. The numerical value is a relative 64 bit integer, which, independently of the CPUs internal clock rate, is output in a form converted into 100 ns ticks. The number is refreshed to a precision of 100 ns with every call by the PLC system, and can be used, for instance, for timing tasks. One unit is equivalent to 100 ns. The reason for which this service is implemented as a block and not as a function is simply in the fact that two values must be returned, which, by definition, cannot be done by a function.

## VAR\_INPUT

```
VAR_INPUT  
(*none*)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    cpuCntLoDW : UDINT;  
    cpuCntHiDW : UDINT;  
END_VAR
```

**cpuCntLoDW**: Low-value 4 bytes of the numerical value.

**cpuCntHiDW**: High-value 4 bytes of the numerical value.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
