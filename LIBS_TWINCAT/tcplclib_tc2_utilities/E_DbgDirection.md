# E_DbgDirection

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_DbgDirection

This variable type can be used by buffer blocks or protocol blocks for configuring the debug output.

```
TYPE E_DbgDirection :  
(  
    eDbgDirection_OFF := 0,(* Disabled (no debug oputput) *)  
    eDbgDirection_IN  := 1,(* Enabled only for incomming data *)  
    eDbgDirection_OUT := 2,(* Enabled only for outgoing data *)  
    eDbgDirection_ALL := 3(* Enabled for incomming and outgoing data *)  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| eDbgDirection\_OFF | Disables the debug output |
| eDbgDirection\_IN | Activates output of incoming telegrams |
| eDbgDirection\_OUT | Activates output of outgoing telegrams |
| eDbgDirection\_ALL | Activates output of incoming and outgoing telegrams |

**Example:**

The debug output itself can be realized with the ADSLOGSTR function, for example.

In a ring buffer the debug output could be controlled via the variable in the following way, for example:

* If the value is *eDbgDirection\_IN* or *eDbgDirection\_ALL* the debug output is triggered if a new value is added to the buffer;
* If the value is *eDbgDirection\_out* or *eDbgDirection\_ALL* the debug output is triggered if a value is removed from the buffer;

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
