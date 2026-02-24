# PML_UnitModeConfig

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Function Blocks](ms-xhelp:///?Id=beckhoff-ee52-4b21-b081-24a6fe023487)
4. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-c5af-4380-9a85-ca27b4325379)
5. PML\_UnitModeConfig

# PML\_UnitModeConfig

![52015891](/tcplclib_tc3_packml_v2/1033/Images/png/9007201139028363__Web.png)

Machines may have unit modes other than "Production", "Maintenance" and "Manual". This function block enables the user to configure further models (UnitModes).

The number of the new model, the existing states and the states in which a model change is possible can be freely defined.

## Inputs

```
VAR_INPUT  
    eMode                           : DINT;  
    sName                           : STRING;  
  
    bDisableClearing                : BOOL;  
    bDisableStarting                : BOOL;  
    bDisableSuspended               : BOOL;  
    bDisableStopping                : BOOL;  
    bDisableAborting                : BOOL;  
    bDisableHolding                 : BOOL;  
    bDisableHeld                    : BOOL;  
    bDisableUnholding               : BOOL;  
    bDisableSuspending              : BOOL;  
    bDisableUnsuspending            : BOOL;  
    bDisableResetting               : BOOL;  
    bDisableIdle                    : BOOL;  
    bDisableCompleting              : BOOL;  
    bDisableComplete                : BOOL;  
    bEnableUnitModeChangeStopped    : BOOL;  
    bEnableUnitModeChangeIdle       : BOOL;  
    bEnableUnitModeChangeSuspended  : BOOL;  
    bEnableUnitModeChangeExecute    : BOOL;  
    bEnableUnitModeChangeAborted    : BOOL;  
    bEnableUnitModeChangeHeld       : BOOL;  
    bEnableUnitModeChangeComplete   : BOOL;  
END_VAR
```

**eMode**: Number of the new PML UnitMode [4..31].

**sName**: Name of the new PML UnitMode.

**bDisableClearing**: Deactivates the PMLState "Clearing".

**bDisableStarting**: Deactivates the PMLState "Starting".

**bDisableSuspended**: Deactivates the PMLState "Suspended".   
The deactivation of the static state also causes the PMLStates "Suspending" and "Unsuspending" to be deactivated.

**bDisableStopping**: Deactivates the PMLState "Stopping".

**bDisableAborting**: Deactivates the PMLState "Aborting".

**bDisableHolding**: Deactivates the PMLState "Holding".

**bDisableHeld**: Deactivates the PMLState "Held".   
The deactivation of the static state also causes the PMLStates "Holding" and "Unholding" to be deactivated.

**bDisableUnholding**: Deactivates the PMLState "Unholding".

**bDisableSuspending**: Deactivates the PMLState "Suspending".

**bDisableUnsuspending**: Deactivates the PMLState "Unsuspending".

**bDisableResetting**: Deactivates the PMLState "Resetting".

**bDisableIdle**: Deactivates the PMLState "Idle".   
The deactivation of the static state also causes the PMLState "Resetting" to be deactivated.

**bDisableCompleting**: Deactivates the PMLState "Completing".

**bDisableComplete**: Deactivates the PMLState "Complete".   
The deactivation of the static state also causes the PMLState "Completing" to be deactivated

**bEnableUnitModeChangeStopped**: Enables a mode change in the PMLState "Stopped".

**bEnableUnitModeChangeIdle**: Enables a mode change in the PMLState "Idle".

**bEnableUnitModeChangeSuspended**: Enables a mode change in the PMLState "Suspended".

**bEnableUnitModeChangeExecute**: Enables a mode change in the PMLState "Execute".

**bEnableUnitModeChangeAborted**: Enables a mode change in the PMLState "Aborted".

**bEnableUnitModeChangeHeld**: Enables a mode change in the PML state "Held".

**bEnableUnitModeChangeComplete**: Enables a mode change in the PMLState "Complete".

## Outputs

```
VAR_OUTPUT  
    bError     : BOOL;  
    nErrorID   : UDINT;  
END_VAR
```

**bError**: Becomes TRUE, as soon as an error occurs.

**nErrorID**: Supplies the error number when the output bError is set.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
