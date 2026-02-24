# FB_KL320xConfig

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Bus Terminal configuration](ms-xhelp:///?Id=beckhoff-3cb2-479f-9e6d-9be9b4908ab5)
4. FB\_KL320xConfig

# FB\_KL320xConfig

![51188993](/tcplclib_tc2_iofunctions/1033/Images/png/9007201339475467__Web.png)

Function block for parameterizing a [KL3201, KL3202 or KL3204](https://infosys.beckhoff.com/content/1033/kl320x/index.html): Input terminal for resistance sensors.

|  |  |
| --- | --- |
| 58047761 | The function block only parameterizes one terminal channel. For parameterizing all channels, the corresponding number of function blocks has to be instantiated. A mixed configuration (e.g. different sensor types) is possible. |

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
| 0 | PT100 |
| 1 | NI100 |
| 2 | PT1000 |
| 3 | PT500 |
| 4 | PT200 |
| 5 | NI1000 |
| 6 | NI120 |
| 7 | Output 10.0 Ω - 5000.0 Ω |
| 8 | Output 10.0 Ω – 1200.0 Ω |
| 9 | PT1000 - two-wire connection - **not permitted with KL3204!** |

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy               : BOOL;  
    bError              : BOOL;  
    iErrorId            : UDINT;  
    iState              : USINT;  
    iDataIn             : INT;  
    iTerminalType       : WORD;  
    iSpecialType        : WORD;  
    iFirmwareVersion    : WORD;  
    sDescription        : STRING;  
    sSensorType         : STRING;  
    bTwoWiredConnection : BOOL;  
END_VAR
```

**bBusy:** As long as the read or configuration sequence is in progress, this output is TRUE.

**bError:** This output is switched to TRUE, if an error occurred while a command (Configure or Read) is executed. The command-specific error code is contained in *iErrorId*.

**iErrorId:** contains the command-specific error code of the most recently executed command. It is reset to 0 by activating the function block again via the inputs *bConfigurate* or *bReadConfig*. [See Error codes](ms-xhelp:///?Id=beckhoff-0d09-48c9-8316-370fd0466394).

**iState:** Corresponds to the status variable of the process data, i.e. *stInData*.iState, see VAR\_IN\_OUT. During command execution (*bBusy* = TRUE) this output is set to 0. This output is suitable for status assessment during normal terminal operation. Spurious states during configuration and reading through the register communication are hidden.

**iDataIn:** Corresponds to the data variable of the process data, i.e. *stInData.iDataIn*, see VAR\_IN\_OUT. During command execution (*bBusy* = TRUE) this output retains the value it had before the command was called. This output is suitable for direct process data processing during normal terminal operation. Spurious states during configuration and reading through the register communication are hidden.

**iTerminalType:** Contents of register 8 (terminal designation). The register content must match the terminal used: 0xC81 for KL3201, 0xC82 for KL3202 and 0xC84 for KL3204.

**iSpecialType:** Contents of register 29 (special version).

**iFirmwareVersion:** Contents of register 9 (firmware version).

**sDescription:** Terminal designation, special version and firmware version as string (e.g. 'terminal KL320x-0010 / firmware 1C').

**sSensorType:** Set sensor type in plain text.

**bTwoWiredConnection:** The sensor type is parameterized in the two-wire connection.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stInData  : ST_KL320xInData;  
    stOutData : ST_KL320xOutData;  
END_VAR
```

**stInData :** Reference to the structure of the input process image (type: [ST\_KL320xInData](ms-xhelp:///?Id=beckhoff-06af-4aaa-8bcd-633b12beeefd)).

**stOutData :** Reference to the structure of the output process image (type: [ST\_KL320xOutData](ms-xhelp:///?Id=beckhoff-e802-44ab-b9af-725291488f81)).

## Requirements

| Development environment | Target platform | IO Hardware | PLC libraries to include |
| --- | --- | --- | --- |
| TwinCAT v3.1.4018.26 | PC/CX | KL3201, KL3202, KL3204 | Tc2\_IoFunctions from v3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
