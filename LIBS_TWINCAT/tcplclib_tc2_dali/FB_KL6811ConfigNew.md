# FB_KL6811ConfigNew

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Base](ms-xhelp:///?Id=beckhoff-48f6-479b-b1fc-0ba402ee9f92)
6. FB\_KL6811ConfigNew

# FB\_KL6811ConfigNew

![46555465](/tcplclib_tc2_dali/1033/Images/gif/4439182731__Web.gif)

This function block is used to configure the KL6811. The configuration is executed when the PLC program starts, or it can be triggered by a positive edge at the input *bConfigurate*. The parameters are stored in the respective registers of the KL6811 in a fail-safe manner. In addition, some general information, such as the firmware version, is read from the KL6811.

|  |  |
| --- | --- |
| 16346001 | This function block replaces FB\_KL6811Config from library version 3.6.2.0 |

## Example:

The function block is called in the same task as the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6).

![12896286](/tcplclib_tc2_dali/1033/Images/gif/4515396491__Web.gif)

The function block FB\_KL6811ConfigNew() is linked to the process image of the KL6811. Once the configuration is complete, the function block FB\_KL6811CommunicationNew() receives the process values of the KL6811. DALI commands cannot be sent during configuration.

**Example:** [DALI\_Sample\_KL6811Config.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_dali/Resources/zip/4515401995.zip)

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

**nOptions:** Reserved for future expansions.

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

**nErrorId:** Contains the command-specific error code of the most recently executed command. It is reset to 0 by activating the function block again via the input *bConfigurate*. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nTerminalDescription:** Contains the terminal designation (e.g. 6811). Corresponds to register 8 of the Bus Terminal.

**nFirmwareVersion:** Contains the firmware version. Corresponds to register 9 of the Bus Terminal.

**sDescription:** Terminal designation and firmware version as string (e.g. "Terminal KL6811 / Firmware 2H").

## VAR\_IN\_OUT

```
stInDataTerminal  : ST_KL6811InData;  
stOutDataTerminal : ST_KL6811OutData;  
stInData          : ST_KL6811InData;  
stOutData         : ST_KL6811OutData;
```

**stInDataTerminal:** Reference to the structure for communication with the KL6811 (see [ST\_KL6811InData](ms-xhelp:///?Id=beckhoff-dccd-4fd7-8cb9-1937ea392bcd) ).

**stOutDataTerminal:** Reference to the structure for communication with the KL6811 (see [ST\_KL6811OutData](ms-xhelp:///?Id=beckhoff-899f-4690-b8a5-8d44960469d0)).

**stInData:** Reference to the structure for communication with the [FB\_KL6811Communication](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) function block (see [ST\_KL6811InData](ms-xhelp:///?Id=beckhoff-dccd-4fd7-8cb9-1937ea392bcd)).

**stOutData:** Reference to the structure for communication with the [FB\_KL6811Communication](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) function block (see [ST\_KL6811OutData](ms-xhelp:///?Id=beckhoff-899f-4690-b8a5-8d44960469d0)).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.4 | Tc2\_DALI from v3.6.2.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
