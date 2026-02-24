# LTON

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-e7be-4338-8e06-ae5851914a22)
3. [Timer (LTIME)](ms-xhelp:///?Id=beckhoff-003b-415a-a03c-9e36a813ca24)
4. LTON

# LTON

![61444595](/tcplclib_tc2_standard/1033/Images/png/2260966411__Web.png)

Timer-on delay with 64-bit time data type (LTIME).

## VAR\_INPUT

```
VAR_INPUT  
    IN : BOOL; (*starts imter with rising edge, resets timer with falling edge*)  
    PT : LTIME; (*time to pass before Q is set.*)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Q  : BOOL; (*is TRUE, PT seconds after IN had a rising edge*)  
    ET : LTIME (*elapsed time since rising edge at IN*)  
END_VAR
```

If IN is FALSE, the outputs are FALSE or 0. As soon as IN becomes TRUE, the time is incremented in nanoseconds in ET, until the value reaches PT. The value then remains constant. Q is TRUE, if IN = TRUE and ET = PT. Otherwise Q = FALSE. Q thus has a rising edge, once the time specified in nanoseconds in PT has elapsed.  
Graph showing LTON over time:

![16130451](/tcplclib_tc2_standard/1033/Images/gif/74461323__en-US__Web.gif)

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
