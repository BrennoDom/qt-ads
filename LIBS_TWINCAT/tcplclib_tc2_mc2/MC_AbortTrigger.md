# MC_AbortTrigger

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Touch probe](ms-xhelp:///?Id=beckhoff-25dd-4c8d-a7d8-31a337a1e535)
4. MC\_AbortTrigger

# MC\_AbortTrigger

![39471735](/tcplclib_tc2_mc2/1033/Images/png/70236811__en-US__Web.png)

The function block MC\_AbortTrigger cancels a probe cycle started by MC\_TouchProbe. MC\_TouchProbe initiates a measuring probe cycle by activating a position latch in external encoder or drive hardware. The function block MC\_AbortTrigger can be used to terminate the procedure before the trigger signal has activated the position latch. If the measuring probe cycle has completed successfully, it is not necessary to call up this function block.

## Inputs

```
VAR_INPUT  
    Execute : BOOL;  
END_VAR
```

**Execute:** The command is executed with the positive edge and the external position latch is deactivated.

## Outputs

```
VAR_OUTPUT  
    Done    : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

**Done:** TRUE as soon as the measuring probe cycle has been successfully terminated.

**Busy:** TRUE as soon as the function block is active. FALSE if it is in the default state.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

## Inputs/outputs

```
VAR_IN_OUT  
    Axis         : AXIS_REF;  
    TriggerInput : TRIGGER_REF;   
END_VAR
```

**Axis:** Axis data structure (type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

**TriggerInput:** Data structure for describing the trigger source (type: [TRIGGER\_REF](ms-xhelp:///?Id=beckhoff-4fad-4a66-9893-e6ef0842d838)). This data structure must be parameterized before the function block is called for the first time.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
