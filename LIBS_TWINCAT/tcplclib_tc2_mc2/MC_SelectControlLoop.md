# MC_SelectControlLoop

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Special extensions](ms-xhelp:///?Id=beckhoff-8c7a-4985-bc2a-8740f4381d5f)
4. MC\_SelectControlLoop

# MC\_SelectControlLoop

![8936292](/tcplclib_tc2_mc2/1033/Images/png/9007206882205195__Web.png)

The function block MC\_SelectControlLoop switches between the control loops of an axis. The prerequisite is that two or more control loops have been created below the axis in the system configuration.

[See detailed description of the control loop switching]

## Inputs

```
    VAR_INPUT  
    Execute : BOOL;
```

```
        EncoderIndex : UINT;
```

```
        SelectType : E_SelectControlLoopType;
```

```
        SyncValue : LREAL;
```

```
        ExtSetPointGen : BOOL;
```

```
END_VAR
```

**Execute**: The command is executed with a positive edge.

**EncoderIndex:** The sequential number [0..9] of the axis control loop to be activated.

**SelectType**: Defines how the control loop switching is performed.

Only SelectControlLoopType\_Standard is **applicable** at the moment.

**SyncValue: Not applicable yet.**

**ExtSetPointGen: Not applicable yet.**

## Outputs

```
    VAR_OUTPUT  
    Done : BOOL;
```

```
        Busy : BOOL;
```

```
        Error : BOOL;
```

```
        ErrorID : UDINT;
```

```
END_VAR
```

**Done**: TRUE if the command was executed without errors.

**Busy:** TRUE as soon as the command is started with Execute and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
