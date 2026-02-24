# FB_KL27x1Config

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Bus Terminal configuration](ms-xhelp:///?Id=beckhoff-3cb2-479f-9e6d-9be9b4908ab5)
4. FB\_KL27x1Config

# FB\_KL27x1Config

![35513827](/tcplclib_tc2_iofunctions/1033/Images/png/9007201339450123__Web.png)

Function block for parameterizing a [KL2751 / KL2761](https://infosys.beckhoff.com/content/1033/kl2751_kl2761/index.html): Single-channel dimmer terminal.

## VAR\_INPUT

```
VAR_INPUT  
    bConfigurate            : BOOL;  
    bReadConfig             : BOOL;  
    iSetSensorType          : INT;  
    bSetDimRampAbsolute     : BOOL;  
    iSetRampTime            : INT;  
    bSetWatchdogDisable     : BOOL;  
    iSetWatchdogTimeout     : UINT;  
    iSetTimeoutOnValue      : UINT;  
    iSetTimeoutOffValue     : UINT;  
    iSetDimmerMode          : INT;  
    bSetOnAfterShortCircuit : BOOL;  
    bSetLineFrequency60Hz   : BOOL;  
    tTimeout                : TIME;  
END_VAR
```

**bConfigurate:** A rising edge starts the configuration page. First, the general terminal data, i.e. "terminal designation", "special version" and "firmware version", are read. Then, the specified settings are written to the corresponding registers and finally read again for verification and information. The read information is displayed at the function block outputs. During this sequence the output *bBusy* is TRUE, and no further command, e.g. *bReadConfig*, is accepted.

**bReadConfig:** A rising edge only starts a read sequence. The general terminal data, i.e. "terminal designation", "special version" and "firmware version", are read, followed by the set configuration parameters. The read information is displayed at the function block outputs. During the read sequence the output *bBusy* is TRUE, and no further command, e.g. *bConfigurate*, is accepted.

**bSetDimRampAbsolute:** FALSE: The set ramp time *iSetRampTime* refers to the complete data area (0 - 32767). The smaller the discontinuity, the shorter the ramp time. TRUE: Each switching step, whatever the size, requires the same time, as entered under *iSetRampTime*.

**iSetRampTime:** Ramp time input. The setting is based on the table below.

**bSetWatchdogDisable:** The internal watchdog is disabled.

**iSetWatchdogTimeout:** Watchdog time as multiple of 10 ms.

**iSetTimeoutOnValue:** This input specifies the light value that is output when a fieldbus error occurs with current process data > 0.

**iSetTimeoutOffValue:** This input specifies the light value that is output when a fieldbus error occurs with current process data = 0.

**iSetDimmerMode:** This input is used to set the dimmer mode. The setting is based on the table below.

**bSetOnAfterShortCircuit:** FALSE: After a short circuit the light remains switched off. TRUE: The light is switched on again after a short circuit.

**bSetLineFrequency60Hz:** FALSE: mains frequency = 50 Hz. TRUE: mains frequency = 60 Hz.

**tTimeout:** The terminal configuration and reading of the configuration must be complete within the time entered here. Otherwise an error with a corresponding error number is issued at the outputs *bError* and *iErrorId*.

| iSetRampTime | Element |
| --- | --- |
| 0 | 50 ms |
| 1 | 100 ms |
| 2 | 200 ms |
| 3 | 500 ms |
| 4 | 1 s |
| 5 | 2 s |
| 6 | 5 s |
| 7 | 10 s |

| iSetDimmerMode | Element |
| --- | --- |
| 0 | Automatic detection |
| 1 | Trailing edge phase control |
| 2 | Leading edge phase control |
| 3 | Rectifier mode, positive (positive half-wave with leading edge phase control) |
| 4 | Rectifier mode, negative (negative half-wave with leading edge phase control) |

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

**iTerminalType:** Contents of register 8 (terminal designation). If the correct terminal is used, the content should be 0x0ABF (2751dec) or 0x0AC9 (2761dec).

**iSpecialType:** Contents of register 29 (special version).

**iFirmwareVersion:** Contents of register 9 (firmware version).

**sDescription:** Terminal designation, special version and firmware version as string (e.g. 'terminal KL27x1-0000 / firmware 1C').

**bDimRampAbsolute:** TRUE: The dimming ramp is set absolute, i.e. each switching step requires the same ramp time, as specified under *iSetRampTime*.

**sRampTime:** Set ramp time in plain text.

**bWatchdogDisable:** TRUE: Watchdog is disabled.

**tWatchdogTimeout:** Set watchdog time.

**iTimeoutOnValue:** Set light value, which is output when a fieldbus error occurs with current process data > 0.

**–iTimeoutOffValue:** Set light value, which is output when a fieldbus error occurs with current process data = 0.

**sDimmerMode:** Set dimmer mode in plain text.

**sAfterShortCircuit:** Set behavior after short circuit in plain text.

**sLineFrequency:** Set mains frequency in plain text.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stInData  : ST_KL27x1InData;  
    stOutData : ST_KL27x1OutData;  
END_VAR
```

**stInData :** Reference to the structure of the input process image (type: [ST\_KL27x1InData](ms-xhelp:///?Id=beckhoff-b14b-4907-ac5c-2a7680da2e8b)).

**stOutData :** Reference to the structure of the output process image (type: [ST\_KL27x1OutData](ms-xhelp:///?Id=beckhoff-2f65-4590-b2dc-7b257cef5ca9)).

## Requirements

| Development environment | Target platform | IO Hardware | PLC libraries to include |
| --- | --- | --- | --- |
| TwinCAT v3.1.4018.26 | PC/CX | KL2751, KL2761 | Tc2\_IoFunctions from v3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
