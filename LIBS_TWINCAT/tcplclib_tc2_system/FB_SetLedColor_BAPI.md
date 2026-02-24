# FB_SetLedColor_BAPI

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [General function blocks](ms-xhelp:///?Id=beckhoff-8c7f-4e24-ae22-527914ce956b)
4. FB\_SetLedColor\_BAPI

# FB\_SetLedColor\_BAPI

![19167756](/tcplclib_tc2_system/1033/Images/png/4566938891__Web.png)

The function block FB\_SetLedColor\_BAPI can be used to switch the user LED to PCs and embedded PCs with BIOS API support. The LED color is switched via a positive edge at bExecute and the eNewColor parameter. The LED can be switched off (eNewColor = eUsrLED\_Off) or set to red (eNewColor = eUsrLED\_Red), blue (eNewColor = eUsrLED\_Blue) or green (eNewColor = eUsrLED\_Green).

## VAR\_INPUT

```
VAR_INPUT  
    sNetID         : T_AmsNetID;  
    eNewColor      : E_UsrLED_Color;  
    bExecute       : BOOL;  
    tTimeout       : TIME;  
END_VAR
```

**sNetID**: AMS network identifier of the device (empty string or local network identifier) (type [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2))

**eNewColor**: New LED color (type [E\_UsrLED\_Color](ms-xhelp:///?Id=beckhoff-0b64-4f94-be1e-0df9066c6cdd))

**bExecute**: The command is executed with a positive edge.

**tTimeout**: Time until the internal ADS communication is aborted

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrID   : UDINT;  
END_VAR
```

**bBusy**: TRUE, as long as the function block is active.

**bError**: TRUE if an error occurs during command execution.

**nErrID**: Contains the ADS error code or the command-specific error code of the last executed command. Is reset to 0 by the execution of a command at the inputs.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) v3.4.14 |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
