# PS_UnitModeManager

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-a3d4-4ab9-9d45-3f6129419cf0)
3. [Function Blocks](ms-xhelp:///?Id=beckhoff-d344-4d05-8a23-383f6f3f0200)
4. PS\_UnitModeManager

# PS\_UnitModeManager

![45508046](/tcplclib_tc3_packml/1033/Images/png/1109249035__Web.png)

Packaging machinery has unit modes other than “automatic”, as noted above. Each unit mode is a defined by its own state model. In order to manage the change from one mode to the next a procedure known as a “mode manager” must be defined. The mode manager determines how, and in what state a machine may change unit modes; ie. the mode manager includes interlocks that prevent the machine changing at inappropriate states.

|  |  |
| --- | --- |
| 6919237 | The logic for transitions between Modes depends on the application, especially for those between manual, semi-automatic and automatic mode. Additionally, these mode changes may require interlocks by means of hardware or safety related equipment. Responsibility for proper application of mode switching resides with whoever implements such means. |

See the below figure for example.

![62273137](/tcplclib_tc3_packml/1033/Images/gif/9007200074672267__Web.gif)

## VAR\_INPUT

```
VAR_INPUT  
    Execute         : BOOL;  
    eModeCommand    : E_PMLUnitMode;  
    ePMLState       : E_PMLState;  
END_VAR
```

**Execute**: Mode change on rising edge.

**eModeCommand**: Requested Unit Mode. ([E\_PMLUnitMode](ms-xhelp:///?Id=beckhoff-7a25-4c05-b61b-3fdfb8e1fa91))

**ePMLState**: Current PML state of the current mode. ([E\_PMLState](ms-xhelp:///?Id=beckhoff-5649-47bf-9a59-23f0af14766c))

## VAR\_OUTPUT

```
VAR_OUTPUT  
    eModeStatus     : E_PMLUnitMode;  
    Done            : BOOL;  
    Error           : BOOL;  
    ErrorID         : UDINT;  
END_VAR
```

**eModeStatus**: Current Unit Mode. ([E\_PMLUnitMode](ms-xhelp:///?Id=beckhoff-7a25-4c05-b61b-3fdfb8e1fa91))

**Done**: True if mode change was successfully performed

**Error**: Signals that an error has occurred within Function Block, e.g. mode change not permitted

**ErrorID**: If the error output is set, this parameter supplies the error number.  
 0 = No error;  
 1 = mode switch not permitted. The ePMLState is not in idle, stopped, aborted, held, suspended or completed or the corresponding state does not exist in the requested mode.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    Machine_ID      : MACHINE_REF;    (* Identifies the axis which position shall be latched at the trigger event *)  
END_VAR
```

**Machine\_ID:**To identify the machine executed by the state model.

## Implementation

The mode change is restricted to certain modes, see implementation below.

|  |  |
| --- | --- |
| 23587323 | Not all modes are yet implemented. |

```
rTrig(CLK:= Execute);  
IF rTrig.Q THEN  
    Done := FALSE;  
    Error := FALSE;  
    ErrorID := 0;  
    CASE eModeStatus OF  
    ePMLUnitMode_AUTOMATIC:  
        IF (ePMLState = ePMLState_STOPPED) OR (ePMLState = ePMLState_ABORTED) OR (ePMLState = ePMLState_IDLE) THEN  
            eModeStatus := eModeCommand;  
            Done := TRUE;  
        ELSIF ((ePMLState = ePMLState_SUSPENDED) OR (ePMLState = ePMLState_HELD) OR (ePMLState = ePMLState_COMPLETE))  
        AND (eModeCommand = ePMLUnitMode_SEMIAUTOMATIC) THEN  
            eModeStatus := eModeCommand;  
            Done := TRUE;  
        ELSIF (ePMLState = ePMLState_HELD) AND (eModeCommand = ePMLUnitMode_MAINTENANCE) THEN  
            eModeStatus := eModeCommand;  
            Done := TRUE;  
        ELSE  
            Error := TRUE;  
            ErrorID := 1;  
        END_IF  
    ePMLUnitMode_MAINTENANCE:  
        IF (ePMLState = ePMLState_STOPPED) OR (ePMLState = ePMLState_ABORTED) OR (ePMLState = ePMLState_IDLE) THEN  
            eModeStatus := eModeCommand;  
            Done := TRUE;  
        ELSIF (ePMLState = ePMLState_HELD) AND ((eModeCommand = ePMLUnitMode_AUTOMATIC) OR (eModeCommand = ePMLUnitMode_SEMIAUTOMATIC))         THEN  
            eModeStatus := eModeCommand;  
            Done := TRUE;  
        ELSE  
            Error := TRUE;  
            ErrorID := 1;  
        END_IF  
    ePMLUnitMode_MANUAL:  
        IF (ePMLState = ePMLState_STOPPED) OR (ePMLState = ePMLState_ABORTED) OR (ePMLState = ePMLState_IDLE) THEN  
            eModeStatus := eModeCommand;  
            Done := TRUE;  
        ELSE  
            Error := TRUE;  
            ErrorID := 1;  
        END_IF  
    ePMLUnitMode_SEMIAUTOMATIC:  
        IF (ePMLState = ePMLState_STOPPED) OR (ePMLState = ePMLState_ABORTED) OR (ePMLState = ePMLState_IDLE) THEN  
            eModeStatus := eModeCommand;  
            Done := TRUE;  
        ELSIF ((ePMLState = ePMLState_SUSPENDED) OR (ePMLState = ePMLState_HELD) OR (ePMLState = ePMLState_COMPLETE))  
        AND (eModeCommand = ePMLUnitMode_AUTOMATIC) THEN  
            eModeStatus := eModeCommand;  
            Done := TRUE;  
        ELSIF (ePMLState = ePMLState_HELD) AND (eModeCommand = ePMLUnitMode_MAINTENANCE) THEN  
            eModeStatus := eModeCommand;  
            Done := TRUE;  
        ELSE  
            Error := TRUE;  
            ErrorID := 1;  
        END_IF  
    ePMLUnitMode_IDLE:  
        IF (ePMLState = ePMLState_STOPPED) OR (ePMLState = ePMLState_ABORTED) OR (ePMLState = ePMLState_IDLE) THEN  
            eModeStatus := eModeCommand;  
            Done := TRUE;  
        ELSE  
            Error := TRUE;  
            ErrorID := 1;  
        END_IF  
    ePMLUnitMode_ESTOP:  
        IF (ePMLState = ePMLState_STOPPED) OR (ePMLState = ePMLState_ABORTED) OR (ePMLState = ePMLState_IDLE) THEN  
            eModeStatus := eModeCommand;  
            Done := TRUE;  
        ELSE  
            Error := TRUE;  
            ErrorID := 1;  
        END_IF  
    ELSE  
        eModeStatus := eModeCommand;  
        Done := TRUE;  
   END_CASE  
END_IF
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
