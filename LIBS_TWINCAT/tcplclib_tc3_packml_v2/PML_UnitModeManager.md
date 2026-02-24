# PML_UnitModeManager

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Function Blocks](ms-xhelp:///?Id=beckhoff-ee52-4b21-b081-24a6fe023487)
4. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-c5af-4380-9a85-ca27b4325379)
5. PML\_UnitModeManager

# PML\_UnitModeManager

![65489840](/tcplclib_tc3_packml_v2/1033/Images/png/9007200592122507__Web.png)

Machines have system modes other than “Production”. Each unit mode is defined by its own state model. A "Mode Manager" must be defined for transitions between the modes. The “Mode Manager” decides how and in which state a machine can change unit modes; i.e. built-in barriers prevent the machine from changing to unsuitable states. These barriers are permanently defined for the base modes “Production”, “Maintenance” and “Manual”, as the illustration below shows. This can be individually specified for other modes defined via the [PML\_UnitModeConfig](ms-xhelp:///?Id=beckhoff-564e-4dea-8389-a0e4e343e1c0) function block.

|  |  |
| --- | --- |
| 52537648 | The logic for transitions between the modes depends on the application, especially for transitions between "Manual" and "Production" mode. In addition, hardware barriers or safety equipment may be necessary for such mode changes. The responsibility for proper mode changes lies with whoever implements them. |

![3076790](/tcplclib_tc3_packml_v2/1033/Images/png/1336797707__Web.png)

## Inputs

```
VAR_INPUT  
    bExecute        : BOOL;  
    eModeCommand    : DINT;  
    ePMLState       : E_PMLState;  
END_VAR
```

**bExecute**: On a rising edge at this input, an attempt is made to perform the mode change.

**eModeCommand**: Requested mode.

**ePMLState**: [Enumeration](ms-xhelp:///?Id=beckhoff-0bbc-43cb-ab15-bc789eae2d25) that delivers the current PML state of the automatic state machine.

## Outputs

```
VAR_OUTPUT  
    eModeStatus     : DINT;  
    sModeStatus     : STRING;  
    bDone           : BOOL;  
    bError          : BOOL;  
    bErrorID        : UDINT;  
END_VAR
```

**eModeStatus**: Current PML UnitMode.

**sModeStatus**: Name of the current PML UnitMode.

**bDone**: Becomes TRUE as soon as the mode change has been successfully carried out.

**bError**: Becomes TRUE, as soon as an error occurs.

**nErrorID**: Supplies the error number when the bError output is set.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
