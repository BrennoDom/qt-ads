# PS_PackML_StateMachine_Auto

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-a3d4-4ab9-9d45-3f6129419cf0)
3. [Function Blocks](ms-xhelp:///?Id=beckhoff-d344-4d05-8a23-383f6f3f0200)
4. PS\_PackML\_StateMachine\_Auto

# PS\_PackML\_StateMachine\_Auto

![7151914](/tcplclib_tc3_packml/1033/Images/png/1109212171__Web.png)

Packaging Machine State Function Blocks, in updated form, provide a common interface to the PackML Machine State Model V3. It is expected that the application specific logic including the transitions between states is programmed in external function blocks, but the central logic of the state machine and the status representation should be handled by the Pack\_ML\_State\_Machine Function block. Therefore, this FB comes with a recommendation how to combine with other logic.

The logic for transitions depends on the application, especially for those between manual, semi-automatic and automatic mode.

![64367227](/tcplclib_tc3_packml/1033/Images/gif/9007200074655243__Web.gif)

## VAR\_INPUT

```
VAR_INPUT  
    Start           : BOOL;    
    Hold            : BOOL;   
    unHold          : BOOL;   
    Suspend         : BOOL;   
    unSuspend       : BOOL;   
    Abort           : BOOL;   
    Stop            : BOOL;   
    Complete        : BOOL;   
    Clear           : BOOL;   
    Reset           : BOOL;   
    StateComplete   : BOOL;   
END_VAR
```

**Start**: Execute State Machine from rising edge, to Starting

**Hold**: to Holding or Held

**UnHold**: to un-Holding

**Suspend**: to Suspending or Suspend

**UnSuspend**: to un-Suspending

**Abort**: to Aborting

**Stop**: to Stopping

**Complete**: to Resetting

**Clear**: to Clearing

**Reset**: to Resetting

**StateComplete**: Transition

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Status          : WORD;   
    ST_Starting     : BOOL;   
    ST_Completing   : BOOL;   
    ST_Resetting    : BOOL;   
    ST_Holding      : BOOL;   
    ST_UnHolding    : BOOL;   
    ST_Suspending   : BOOL;   
    ST_UnSuspending : BOOL;   
    ST_Clearing     : BOOL;   
    ST_Stopping     : BOOL;   
    ST_Aborting     : BOOL;   
    ST_Execute      : BOOL;   
    ST_Complete     : BOOL;   
    ST_Idle         : BOOL;   
    ST_Held         : BOOL;   
    ST_Suspended    : BOOL;   
    ST_Stopped      : BOOL;   
    ST_Aborted      : BOOL;   
    Error           : BOOL;   
    ErrorID         : UDINT;   
    ePMLState       : E_PMLState;  
END_VAR
```

**Status**: Status Word representing the status of the State Machine.

**ST\_Starting**: True if State Machine is in state Starting

**ST\_Completing**: True if State Machine is in state Completing

**ST\_Resetting**: True if State Machine is in state Resetting.

**ST\_Holding**: True if State Machine is in state Holding.

**ST\_UnHolding**: True if State Machine is in state UnHolding.

**ST\_Suspending**: True if State Machine is in state Suspending.

**ST\_UnSuspending**: True if State Machine is in state UnSuspending.

**ST\_Clearing**: True if State Machine is in state Clearing

**ST\_Stopping**: True if State Machine is in state Stopping

**ST\_Aborting**: True if State Machine is in state Aborting

**ST\_Execute**: True if State Machine is in state Execute

**ST\_Complete**: True if State Machine is in state Complete

**ST\_Idle**: True if State Machine is in state Idle.

**ST\_Held**: True if State Machine is in state Held

**ST\_Suspended**: True if State Machine is in state Suspended

**ST\_Stopped**: True if State Machine is in state Stopped

**ST\_Aborted**: True if State Machine is in state Aborted

**Error**: Becomes TRUE, as soon as an error occurs.

**ErrorID**: If the error output is set, this parameter supplies the error number.

**ePMLState**: Current PML state of the automatic state machine.

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
