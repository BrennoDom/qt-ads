# LTOF

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-e7be-4338-8e06-ae5851914a22)
3. [Timer (LTIME)](ms-xhelp:///?Id=beckhoff-003b-415a-a03c-9e36a813ca24)
4. LTOF

# LTOF

![37212772](/tcplclib_tc2_standard/1033/Images/png/2260868619__Web.png)

Timer-off delay with 64-bit time data type (LTIME).

## VAR\_INPUT

```
VAR_INPUT  
   IN : BOOL; (*starts timer with falling edge, resets timer with rising edge*)  
   PT : LTIME; (*time to pass before Q is reset*)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Q  :  BOOL; (*is FALSE, PT seconds after IN had a falling edge*)  
    ET :  LTIME; (*elapsed time since falling edge at IN*)  
END_VAR
```

If IN is TRUE, the outputs are TRUE or 0. As soon as IN becomes FALSE, the time is incremented in nanoseconds in ET, until the value equals the value of PT. The value then remains constant. Q is FALSE, if IN = FALSE and ET = PT. Otherwise Q = TRUE. Q thus has a falling edge, once the time specified in nanoseconds in PT has elapsed.  
Graph showing LTOF over time:

![66479500](/tcplclib_tc2_standard/1033/Images/gif/74454923__en-US__Web.gif)

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
