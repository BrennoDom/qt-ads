# TOF

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-e7be-4338-8e06-ae5851914a22)
3. [Timer](ms-xhelp:///?Id=beckhoff-74e5-4299-886b-306073fff5a0)
4. TOF

# TOF

![294043](/tcplclib_tc2_standard/1033/Images/png/74451723__Web.png)

Timer off-delay

## VAR\_INPUT

```
VAR_INPUT  
    IN : BOOL; (* starts timer with falling edge, resets timer with rising edge *)   
    PT : TIME; (* time to pass, before Q is set *)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Q  : BOOL; (* is FALSE, PT seconds after IN had a falling edge *)  
    ET : TIME; (* elapsed time *)  
END_VAR
```

When IN is TRUE, Q is TRUE and ET is 0.As soon as IN becomes FALSE, the time will begin to be counted in milliseconds in ET until its value is equal to that of PT. It will then remain constant. Q is FALSE when IN is FALSE and ET is equal to PT. Otherwise it is TRUE. Thus, Q has a falling edge when the time indicated in PT in milliseconds has run out.  
Graphic display of TOF behavior over time:

![2646389](/tcplclib_tc2_standard/1033/Images/gif/74454923__en-US__Web.gif)

The function TOF requires 15 byte data.

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
