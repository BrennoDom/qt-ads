# TcEventConfirmationState

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# TcEventConfirmationState

Defines the confirmation state of an alarm.

## Syntax

Definition:

```
{attribute 'qualified_only'}  
TYPE TcEventConfirmationState : (  
   NotSupported := 0,   
   NotRequired  := 1,   
   WaitForConfirmation := 2,   
   Confirmed := 3,   
   Reset     := 4);  
END_TYPE
```

## Parameter

| Name | Description |
| --- | --- |
| Confirmed | Confirmed |
| NotRequired | Confirmation not necessary in the current state. (Alarm not currently in the Raised state). |
| NotSupported | Was initialized without confirmation. |
| Reset | Initial state |
| WaitForConfirmation | Waiting for confirmation. |
