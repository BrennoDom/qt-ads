# DRAND

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [General function blocks](ms-xhelp:///?Id=beckhoff-8c7f-4e24-ae22-527914ce956b)
4. DRAND

# DRAND

![39390935](/tcplclib_tc2_system/1033/Images/png/9007199285898763__Web.png)

The function block permits generation of a (pseudo-) random number of type LREAL.

## VAR\_INPUT

```
VAR_INPUT  
    Seed : INT;  
END_VAR
```

**Seed**: Initial value for specification of the random number series.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Num : LREAL;  
END_VAR
```

**Num**: This output returns a pseudo-random number in the range 0.0 .. 1.0 with double accuracy. The generator here creates a number series with 1075 stochastic values per period.

**Example of the function block in FBD:**

![18974100](/tcplclib_tc2_system/1033/Images/png/9007199285901963__Web.png)

In the example the LREAL value 0.643412 is generated and returned. The input parameter Seed affects the initial value of the series. If, for instance, a deterministically reproducible random number series is desired in different sessions, and identical Seed value must be used.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
