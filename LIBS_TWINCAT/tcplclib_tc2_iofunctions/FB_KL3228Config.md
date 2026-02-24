# FB_KL3228Config

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Bus Terminal configuration](ms-xhelp:///?Id=beckhoff-3cb2-479f-9e6d-9be9b4908ab5)
4. FB\_KL3228Config

# FB\_KL3228Config

![38233575](/tcplclib_tc2_iofunctions/1033/Images/png/9007201339513355__Web.png)

Function block for parameterizing a [KL3228](https://infosys.beckhoff.com/content/1033/kl3208_kl3228/index.html): 8-channel input terminal for resistance sensors.

|  |  |
| --- | --- |
| 8557861 | The function block only parameterizes one terminal channel. For parameterizing all channels, the corresponding number of function blocks has to be instantiated. A mixed configuration (e.g. different sensor types) is possible. |

## VAR\_INPUT

```
VAR_INPUT  
    bConfigurate   : BOOL;  
    bReadConfig    : BOOL;  
    iSetSensorType : INT;  
    tTimeout       : TIME;  
END_VAR
```

**bConfigurate:** A rising edge starts the configuration page. First, the general terminal data, i.e. "terminal designation", "special version" and "firmware version", are read. Then, the specified settings are written to the corresponding registers and finally read again for verification and information. The read information is displayed at the function block outputs. During this sequence the output *bBusy* is TRUE, and no further command, e.g. *bReadConfig*, is accepted.

**bReadConfig:** A rising edge only starts a read sequence. The general terminal data, i.e. "terminal designation", "special version" and "firmware version", are read, followed by the set configuration parameters. The read information is displayed at the function block outputs. During the read sequence the output *bBusy* is TRUE, and no further command, e.g. *bConfigurate*, is accepted.

**iSetSensorType:** This input is used to set the sensor. The setting is based on the table below.

**tTimeout:** The terminal configuration and reading of the configuration must be complete within the time entered here. Otherwise an error with a corresponding error number is issued at the outputs *bError* and *iErrorId*.

| iSetSensorType | Element |
| --- | --- |
| 0 | PT1000 |
| 1 | NI1000 |
| 2 | RSNI1000 (NI1000 based on Landis & Staefa characteristics: 1000 Ω at 0 °C and 1500 Ω at 100 °C) |

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy            : BOOL;  
    bError           : BOOL;  
    iErrorId         : UDINT;  
    iState           : USINT;  
    iDataIn          : INT;  
    iTerminalType    : WORD;  
    iSpecialType     : WORD;  
    iFirmwareVersion : WORD;  
    sDescription     : STRING;  
    sSensorType      : STRING;  
END_VAR
```

**bBusy:** As long as the read or configuration sequence is in progress, this output is TRUE.

**bError:** This output is switched to TRUE, if an error occurred while a command (Configure or Read) is executed. The command-specific error code is contained in *iErrorId*.

**iErrorId:** contains the command-specific error code of the most recently executed command. It is reset to 0 by activating the function block again via the inputs *bConfigurate* or *bReadConfig*. [See Error codes](ms-xhelp:///?Id=beckhoff-0d09-48c9-8316-370fd0466394).

**iState:** Corresponds to the status variable of the process data, i.e. *stInData*.iState, see VAR\_IN\_OUT. During command execution (*bBusy* = TRUE) this output is set to 0. This output is suitable for status assessment during normal terminal operation. Spurious states during configuration and reading through the register communication are hidden.

**iDataIn:** Corresponds to the data variable of the process data, i.e. *stInData.iDataIn*, see VAR\_IN\_OUT. During command execution (*bBusy* = TRUE) this output retains the value it had before the command was called. This output is suitable for direct process data processing during normal terminal operation. Spurious states during configuration and reading through the register communication are hidden.

**iTerminalType:** Contents of register 8 (terminal designation). When used with the correct terminal, the content should be 0x0C9C (3228dec).

**iSpecialType:** Contents of register 29 (special version).

**iFirmwareVersion:** Contents of register 9 (firmware version).

**sDescription:** Terminal designation, special version and firmware version as string (e.g. 'terminal KL3228-0000 / firmware 1C').

**sSensorType:** Set sensor type in plain text.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stInData  : ST_KL3228InData;  
    stOutData : ST_KL3228OutData;  
END_VAR
```

**stInData :** Reference to the structure of the input process image (type: [ST\_KL3228InData](ms-xhelp:///?Id=beckhoff-82eb-4f90-bd81-2a13d3588dd9)).

**stOutData :** Reference to the structure of the output process image (type: [ST\_KL3228OutData](ms-xhelp:///?Id=beckhoff-3a1a-41b7-bfdd-8d59bd2ba98e)).

## Requirements

| Development environment | Target platform | IO Hardware | PLC libraries to include |
| --- | --- | --- | --- |
| TwinCAT v3.1.4018.26 | PC/CX | KL3228 | Tc2\_IoFunctions from v3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
