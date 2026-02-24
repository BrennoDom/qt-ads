# FB_KL6831KL6841Config

## Library
tcplclib_tc2_smi

## Category
Motion Control

# FB\_KL6831KL6841Config

![24171358](/tcplclib_tc2_smi/1033/Images/gif/3249684235__Web.gif)

This function block is used to configure the KL6831/KL6841. The configuration is executed when the PLC program starts, or it can be triggered by a positive edge at the input *bConfigurate*. The parameters are stored in the respective registers of the KL6831/KL6841 in a non-volatile manner. In addition, some general information, such as the firmware version, is read from the KL6831/KL6841.

**Example:**

The function block is called in the same task as the function block [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7).

![16215635](/tcplclib_tc2_smi/1033/Images/gif/3249603467__Web.gif)

The function block FB\_KL6831KL6841Config() is linked to the process image of the KL6831/KL6841. Once the configuration is complete, the function block [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) received the process values of the KL6831/KL6841. No SMI commands can be sent while the configuration is in progress.

[TwinCAT 3 sample project](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_smi/Resources/zip/3248663563.zip)

## VAR\_INPUT

```
bConfigurate           : BOOL := FALSE;  
eCommandKBusWatchdog   : E_SMIConfigurationCommands := eSMICommandDoNothing;  
eCommandDI1RisingEdge  : E_SMIConfigurationCommands := eSMICommandUp;  
eCommandDI1FallingEdge : E_SMIConfigurationCommands := eSMICommandStop;  
eCommandDI2RisingEdge  : E_SMIConfigurationCommands := eSMICommandDown;  
eCommandDI2FallingEdge : E_SMIConfigurationCommands := eSMICommandStop;  
dwOptions              : DWORD := 0;
```

**bConfigurate:** Configuration of the Bus Terminal is started by a positive edge at this input.

**eCommandKBusWatchdog:** Defines the SMI command that is sent as soon as the Bus Terminal is no longer addressed via the K-bus (see [E\_SMIConfigurationCommands](ms-xhelp:///?Id=beckhoff-6d3d-4fad-b8b9-fb7247d5c299)). Corresponds to register 33 to 35 of the Bus Terminal.

**eCommandDI1RisingEdge:** Defines the SMI command that is sent as soon as a rising edge is detected at input 1 of the Bus Terminal (see [E\_SMIConfigurationCommands](ms-xhelp:///?Id=beckhoff-6d3d-4fad-b8b9-fb7247d5c299)). Corresponds to register 36 to 38 of the Bus Terminal.

**eCommandDI1FallingEdge:** Defines the SMI command that is sent as soon as a falling edge is detected at input 1 of the Bus Terminal (see [E\_SMIConfigurationCommands](ms-xhelp:///?Id=beckhoff-6d3d-4fad-b8b9-fb7247d5c299)). Corresponds to register 39 to 41 of the Bus Terminal.

**eCommandDI2RisingEdge:** Defines the SMI command that is sent as soon as a rising edge is detected at input 2 of the Bus Terminal (see [E\_SMIConfigurationCommands](ms-xhelp:///?Id=beckhoff-6d3d-4fad-b8b9-fb7247d5c299)). Corresponds to register 42 to 44 of the Bus Terminal.

**eCommandDI2FallingEdge:** Defines the SMI command that is sent as soon as a falling edge is detected at input 2 of the Bus Terminal (see [E\_SMIConfigurationCommands](ms-xhelp:///?Id=beckhoff-6d3d-4fad-b8b9-fb7247d5c299)). Corresponds to register 45 to 47 of the Bus Terminal.

**dwOptions:** Reserved for future extensions.

## VAR\_OUTPUT

```
bBusy                : BOOL;  
bError               : BOOL;  
udiErrorId           : UDINT;  
wTerminalDescription : WORD;  
wFirmwareVersion     : WORD;  
sDescription         : STRING;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. Reactivating the function block via the *bConfigurate* input sets the output to FALSE again.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. It is reset to 0 by activating the function block again via the input *bConfigurate*. See Error codes.

**wTerminalDescription:** Contains the terminal designation (e.g. 6831). Corresponds to register 8 of the Bus Terminal.

**wFirmwareVersion:** Contains the firmware version. Corresponds to register 9 of the Bus Terminal.

**sDescription:** Terminal designation and firmware version as string (e.g. 'Terminal KL6831 / Firmware 1D').

## VAR\_IN\_OUT

```
stInDataTerminal  : ST_KL6831KL6841InData;  
stOutDataTerminal : ST_KL6831KL6841OutData;  
stInData          : ST_KL6831KL6841InData;  
stOutData         : ST_KL6831KL6841OutData;
```

**stInDataTerminal:** Reference to the structure for communication with the KL6831/KL6841 (see [ST\_KL6831KL6841InData](ms-xhelp:///?Id=beckhoff-a24c-4afa-b979-d7030f7fcf67)).

**stOutDataTerminal:** Reference to the structure for communication with the KL6831/KL6841 (see [ST\_KL6831KL6841OutData](ms-xhelp:///?Id=beckhoff-acfb-4280-bad8-ec342196d7dc)).

**stInData:** Reference to the structure for communication with the function block [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) (see [ST\_KL6831KL6841InData](ms-xhelp:///?Id=beckhoff-a24c-4afa-b979-d7030f7fcf67)).

**stOutData:** Reference to the structure for communication with the function block [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) (see [ST\_KL6831KL6841OutData](ms-xhelp:///?Id=beckhoff-acfb-4280-bad8-ec342196d7dc)).

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.32 | Tc2\_SMI from 3.3.6.0 |
