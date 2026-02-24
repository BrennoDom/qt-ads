# LTP

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-e7be-4338-8e06-ae5851914a22)
3. [Timer (LTIME)](ms-xhelp:///?Id=beckhoff-003b-415a-a03c-9e36a813ca24)
4. LTP

# LTP

![10956331](/tcplclib_tc2_standard/1033/Images/png/2260968971__Web.png)

Pulse generator with 64-bit time data type (LTIME). This function block can be used to generate pulses with a defined pulse duration.

## VAR\_INPUT

```
VAR_INPUT  
    IN : BOOL; (*Trigger for Start of the Signal*)  
    PT : LTIME; (*The length of the High- Signal*)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Q  : BOOL; (*The pulse*)  
    ET : LTIME (*elapsed time since pulse start*)  
END_VAR
```

If IN is FALSE, the outputs are FALSE or 0. As soon as IN becomes TRUE, Q also becomes TRUE and remains TRUE for the pulse duration PT. As long as Q is TRUE, the time is incremented in nanoseconds in ET, until the value reaches PT. The value then remains constant. The output Q remains TRUE until the pulse duration has elapsed, irrespective of the state of the input IN. Q therefore supplies a signal over the interval specified in PT.  
Graph showing LTP over time:

![31498117](/tcplclib_tc2_standard/1033/Images/gif/74467723__en-US__Web.gif)

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
