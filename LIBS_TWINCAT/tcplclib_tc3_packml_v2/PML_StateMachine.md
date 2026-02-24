# PML_StateMachine

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Function Blocks](ms-xhelp:///?Id=beckhoff-ee52-4b21-b081-24a6fe023487)
4. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-c5af-4380-9a85-ca27b4325379)
5. PML\_StateMachine

# PML\_StateMachine

![6789390](/tcplclib_tc3_packml_v2/1033/Images/png/1336616587__Web.png)

In the updated form the PML\_StateMachine function block has a common interface with the PackML Machine State Model V3. It is assumed that application-specific logic, such as state transitions, is programmed in external function blocks and that the PML\_StateMachine function block deals with the central logic of the state machine and the state representation. The Machine State Model has a different appearance due to the currently active UnitMode (eMode). Three basic modules are preconfigured for this ([E\_PMLProtectedUnitMode](ms-xhelp:///?Id=beckhoff-b620-40c0-ba5d-fb4bd7e074c7)).

## ePMLProtUnitMode\_Production

![61104516](/tcplclib_tc3_packml_v2/1033/Images/png/1336618251__Web.png)

## ePMLProtUnitMode\_Maintenance

![13069738](/tcplclib_tc3_packml_v2/1033/Images/png/1336619915__Web.png)

## ePMLProtUnitMode\_Manual

![50518786](/tcplclib_tc3_packml_v2/1033/Images/png/1336621579__Web.png)

Furthermore, other user-specific models can be created in a simple manner with the aid of the function block [PML\_UnitModeConfig](ms-xhelp:///?Id=beckhoff-564e-4dea-8389-a0e4e343e1c0) and are thus very flexible in use.

The logic for transitions, in particular between production, maintenance and manual mode, depends on the application. The states in which UnitMode changes are permissible for the basic models are described more precisely in the description of the function block [PML\_UnitModeManager](ms-xhelp:///?Id=beckhoff-0481-4c70-89e9-02ebee705a74).

## Inputs

```
VAR_INPUT  
    eMode               : DINT;    
    eCommand            : E_PMLCommand;   
    stSubUnitInfoRef    : ST_PMLSubUnitInfoRef;   
    stOptions           : ST_PMLStateMachineOptions;   
END_VAR
```

**eMode**: Current PML UnitMode.

**eCommand**: [Enumeration](ms-xhelp:///?Id=beckhoff-f1b2-40ea-8e95-dde7d67d373a) with the various PML commands of the function block.

**stSubUnitInfoRef**: [Structure](ms-xhelp:///?Id=beckhoff-cbd8-4722-b55f-ef785fcef721) that points to an array of the current PML states of subordinated machine units

**stOptions**: Not used at present

## Outputs

```
VAR_OUTPUT  
    eState     : E_PMLState;   
    bError     : BOOL;   
    nErrorId   : UDINT;   
END_VAR
```

**eState**: [Enumeration](ms-xhelp:///?Id=beckhoff-0bbc-43cb-ab15-bc789eae2d25) that delivers the current PML state of the automatic state machine.

**bError**: Becomes TRUE, as soon as an error occurs.

**nErrorID**: Supplies the error number when the output bError is set.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
