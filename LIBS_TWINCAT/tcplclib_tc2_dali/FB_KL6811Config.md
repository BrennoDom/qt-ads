# FB_KL6811Config

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [[obsolete]](ms-xhelp:///?Id=beckhoff-eb1c-4b28-ba1b-364cf88c04c2)
5. FB\_KL6811Config

# FB\_KL6811Config

![60346796](/tcplclib_tc2_dali/1033/Images/gif/3255322379__en-US__Web.gif)

This function block is used to configure the KL6811. The configuration is executed when the PLC program starts, or it can be triggered by a positive edge at the input *bConfigurate*. The parameters are stored in the respective registers of the KL6811 in a fail-safe manner. In addition, some general information, such as the firmware version, is read from the KL6811.

## VAR\_INPUT

```
bConfigurate                       : BOOL := FALSE;  
eOperationMode                     : E_DALIV2OperationMode := eDALIV2OperationModeDALI;  
bDisableInternalPowerSupply        : BOOL := FALSE;  
bEnableCountingDevicesAfterStartup : BOOL := FALSE;  
nOptions                           : DWORD := 0;
```

**bConfigurate:** Configuration of the Bus Terminal is started by a positive edge at this input.

**eOperationMode:** Defines the operation mode of the terminal (DALI or DSI) (see [E\_DALIV2OperationMode](ms-xhelp:///?Id=beckhoff-3864-4814-bd88-bb17a7d5309c)). Corresponds to register 32, bits 12 to 15 of the Bus Terminal.

**bDisableInternalPowerSupply:** If this input is TRUE, the internal DALI power supply of the terminal is disabled by the configuration. Corresponds to register 32, bit 3 of the Bus Terminal.

**bEnableCountingDevicesAfterStartup:** If this input is TRUE, the number of DALI devices is counted when the terminal starts. Corresponds to register 32, bit 4 of the Bus Terminal.

**nOptions:** Reserved for future extensions.

## VAR\_OUTPUT

```
bBusy                : BOOL;  
bError               : BOOL;  
nErrorId             : UDINT;  
nTerminalDescription : WORD;  
nFirmwareVersion     : WORD;  
sDescription         : STRING;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Reactivating the function block via the *bConfigurate* input sets the output to FALSE again.

**nErrorId:** Contains the command-specific error code of the most recently executed command. It is reset to 0 by activating the function block again via the input *bConfigurate* (see [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f)).

**nTerminalDescription:** Contains the terminal designation (e.g. 6811). Corresponds to register 8 of the Bus Terminal.

**nFirmwareVersion:** Contains the firmware version. Corresponds to register 9 of the Bus Terminal.

**sDescription:** Terminal designation and firmware version as string (e.g. 'Terminal KL6811 / Firmware 2H').

## VAR\_IN\_OUT

```
stInDataTerminal  : ST_DALIV2InData;  
stOutDataTerminal : ST_DALIV2OutData;  
stInData          : ST_DALIV2InData;  
stOutData         : ST_DALIV2OutData;
```

**stInDataTerminal:** Reference to the structure for communication with the KL6811 (see [ST\_DALIV2InData](ms-xhelp:///?Id=beckhoff-1dfe-4c40-a48b-5f314b982fef)).

**stOutDataTerminal:** Reference to the structure for communication with the KL6811 (see [ST\_DALIV2OutData](ms-xhelp:///?Id=beckhoff-1b01-4a19-bd19-87de7e897cf3)).

**stInData:** Reference to the structure for communication with the [FB\_DALIV2Communication()](ms-xhelp:///?Id=beckhoff-d5b3-457e-91f9-d1f3e8f70687) function block (see [ST\_DALIV2InData](ms-xhelp:///?Id=beckhoff-1dfe-4c40-a48b-5f314b982fef)).

**stOutData:** Reference to the structure for communication with the [FB\_DALIV2Communication()](ms-xhelp:///?Id=beckhoff-d5b3-457e-91f9-d1f3e8f70687) function block.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
