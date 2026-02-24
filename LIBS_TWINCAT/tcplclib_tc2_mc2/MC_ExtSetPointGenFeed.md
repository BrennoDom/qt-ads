# MC_ExtSetPointGenFeed

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [External set value generator](ms-xhelp:///?Id=beckhoff-5236-4f1a-806c-02440c61d98c)
4. MC\_ExtSetPointGenFeed

# MC\_ExtSetPointGenFeed

![52301286](/tcplclib_tc2_mc2/1033/Images/png/9007199324987403__Web.png)

The MC\_ExtSetPointGenFeed function is used to feed set values from an external setpoint generator into an axis. The function copies the data instantaneously into the cyclic axis interface (fExtSetPos, fExtSetVelo, fExtSetAcc and nExtSetDirection). The function result of MC\_ExtSetPointGenFeed is not used and therefore always FALSE.

An external setpoint generator is usually a PLC function block that calculates cyclic set values for an axis and can therefore substitute the internal setpoint generator in an NC axis.

See also: [MC\_ExtSetPointGenEnable](ms-xhelp:///?Id=beckhoff-6eda-4db2-8650-05311e21328c) and [MC\_ExtSetPointGenDisable](ms-xhelp:///?Id=beckhoff-845c-4f7d-83db-63af7bf93769)

## Inputs

```
VAR_INPUT  
    Position     : LREAL;  
    Velocity     : LREAL;  
    Acceleration : LREAL;  
    Direction    : DINT;  
END_VAR
```

**Position:** Set position from an external setpoint generator

**Velocity:** Set velocity from an external setpoint generator

**Acceleration:** Set acceleration from an external setpoint generator

**Direction:** Set direction from an external setpoint generator. ( -1 = negative direction, 0 = standstill, 1 = positive direction)

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
