# FB_KL6821Config

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Base](ms-xhelp:///?Id=beckhoff-48f6-479b-b1fc-0ba402ee9f92)
6. FB\_KL6821Config

# FB\_KL6821Config

![37966223](/tcplclib_tc2_dali/1033/Images/gif/4415798539__Web.gif)

This function block is used to configure the KL6821. The configuration is executed when the PLC program starts, or it can be triggered by a positive edge at the input *bConfigurate*. The parameters are stored in the respective registers of the KL6821 in a fail-safe manner. In addition, some general information, such as the firmware version, is read from the KL6821.

## Example

The function block is called in the same task as the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250).

![6151694](/tcplclib_tc2_dali/1033/Images/gif/4415802891__Web.gif)

The function block FB\_KL6821Config() is linked to the process image of the KL6821. Once the configuration is complete, the function block FB\_KL6821Communication() receives the process values of the KL6821. DALI commands cannot be sent during configuration.

**Example:** [DALI\_Sample\_KL6821Config.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_dali/Resources/zip/4420035723.zip)

## VAR\_INPUT

```
bConfigurate           : BOOL := FALSE;  
eCommandKBusWatchdog   : E_DALIV2ConfigurationCommands := eDALIV2CommandDoNothing;  
eCommandDI1RisingEdge  : E_DALIV2ConfigurationCommands := eDALIV2CommandOff;  
eCommandDI1FallingEdge : E_DALIV2ConfigurationCommands := eDALIV2CommandDoNothing;  
eCommandDI2RisingEdge  : E_DALIV2ConfigurationCommands := eDALIV2CommandRecallMaxLevel;  
eCommandDI2FallingEdge : E_DALIV2ConfigurationCommands := eDALIV2CommandDoNothing;  
ePowerSupplyMode       : E_DALIV2PowerSupplyMode := eDALIV2PowerSupplyModeOn;  
nOptions               : DWORD := 0;
```

**bConfigurate:** Configuration of the Bus Terminal is started by a positive edge at this input.

**eCommandKBusWatchdog**: Defines the DALI command that is sent as soon as the Bus Terminal is no longer addressed via the K-bus. ([E\_DALIV2ConfigurationCommands](ms-xhelp:///?Id=beckhoff-1e30-4878-9d3b-c9b756a6d4a0))

**eCommandDI1RisingEdge**: Defines the DALI command that is sent as soon as a rising edge is detected at input 1 of the Bus Terminal. ([E\_DALIV2ConfigurationCommands](ms-xhelp:///?Id=beckhoff-1e30-4878-9d3b-c9b756a6d4a0))

**eCommandDI1FallingEdge**: Defines the DALI command that is sent as soon as a falling edge is detected at input 1 of the Bus Terminal. ([E\_DALIV2ConfigurationCommands](ms-xhelp:///?Id=beckhoff-1e30-4878-9d3b-c9b756a6d4a0))

**eCommandDI2RisingEdge**: Defines the DALI command that is sent as soon as a rising edge is detected at input 2 of the Bus Terminal. ([E\_DALIV2ConfigurationCommands](ms-xhelp:///?Id=beckhoff-1e30-4878-9d3b-c9b756a6d4a0))

**eCommandDI2FallingEdge**: Defines the DALI command that is sent as soon as a falling edge is detected at input 2 of the Bus Terminal. ([E\_DALIV2ConfigurationCommands](ms-xhelp:///?Id=beckhoff-1e30-4878-9d3b-c9b756a6d4a0))

**ePowerSupplyMode:** Defines the operation mode of the internal DALI power supply. ([E\_DALIV2PowerSupplyMode](ms-xhelp:///?Id=beckhoff-b1aa-4632-9478-c4d7d4355197))

**nOptions**: reserved for future expansions.

## VAR\_OUTPUT

```
bBusy                      : BOOL;  
bError                     : BOOL;  
nErrorId                   : UDINT;  
nTerminalDescription       : WORD;  
nFirmwareVersion           : WORD;  
sDescription               : STRING;
```

**bBusy**: When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError**: This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Reactivating the function block via the *bConfigurate* input sets the output to FALSE again.

**nErrorId**: Contains the command-specific error code of the most recently executed command. It is reset to 0 by activating the function block again via the input *bConfigurate*. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nTerminalDescription**: Contains the terminal designation (e.g. 6821). Corresponds to register 8 of the Bus Terminal.

**nFirmwareVersion**: Contains the firmware version. Corresponds to register 9 of the Bus Terminal.

**sDescription**: Terminal designation and firmware version as string (e.g. "Terminal KL6821 / Firmware 2H").

## VAR\_IN\_OUT

```
stInDataTerminal         : ST_KL6821InData;  
stOutDataTerminal        : ST_KL6821OutData;  
stInData                 : ST_KL6821InData;  
stOutData                : ST_KL6821OutData;
```

**stInDataTerminal**: Reference to the structure for communication with the KL6821 (see [ST\_KL6821InData](ms-xhelp:///?Id=beckhoff-8da7-4e31-9fea-d54b237fb0b5)).

**stOutDataTerminal**: Reference to the structure for communication with the KL6821 (see [ST\_KL6821InData](ms-xhelp:///?Id=beckhoff-8da7-4e31-9fea-d54b237fb0b5)).

**stInData**: Reference to the internal structure for communication with the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821) (see [ST\_KL6821InData](ms-xhelp:///?Id=beckhoff-8da7-4e31-9fea-d54b237fb0b5)).

**stOutData**: Reference to the internal structure for communication with the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821) (see [ST\_KL6821InData](ms-xhelp:///?Id=beckhoff-8da7-4e31-9fea-d54b237fb0b5)).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.4 | Tc2\_DALI from v3.6.2.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
