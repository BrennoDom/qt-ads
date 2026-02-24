# FB_KL1501Config

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Bus Terminal configuration](ms-xhelp:///?Id=beckhoff-3cb2-479f-9e6d-9be9b4908ab5)
4. FB\_KL1501Config

# FB\_KL1501Config

![61747774](/tcplclib_tc2_iofunctions/1033/Images/png/9007201339505163__Web.png)

Function block for parameterizing a [KL1501](https://infosys.beckhoff.com/content/1033/kl1501/index.html): Single-channel counter terminal.

|  |  |
| --- | --- |
| 18859061 | This function block does not follow the alternative output format, since the process image shifts during conversion to this format. |

## VAR\_INPUT

```
VAR_INPUT  
    bConfigurate         : BOOL;  
    bReadConfig          : BOOL;  
    iSetCounterType      : INT;  
    bSetBackwardCounting : BOOL;  
    tTimeout             : TIME;  
END_VAR
```

**bConfigurate:** A rising edge starts the configuration page. First, the general terminal data, i.e. "terminal designation", "special version" and "firmware version", are read. Then, the specified settings are written to the corresponding registers and finally read again for verification and information. The read information is displayed at the function block outputs. During this sequence the output *bBusy* is TRUE, and no further command, e.g. *bReadConfig*, is accepted.

**bReadConfig:** A rising edge only starts a read sequence. The general terminal data, i.e. "terminal designation", "special version" and "firmware version", are read, followed by the set configuration parameters. The read information is displayed at the function block outputs. During the read sequence the output *bBusy* is TRUE, and no further command, e.g. *bConfigurate*, is accepted.

**iSetCounterType:** Counter type input. The setting is based on the table below.

**bSetBackwardCounting:** TRUE at this input reverses the count direction.

**tTimeout:** The terminal configuration and reading of the configuration must be complete within the time entered here. Otherwise an error with a corresponding error number is issued at the outputs *bError* and *iErrorId*.

| iSetCounterType | Counter type |
| --- | --- |
| 0 | 32 bit up/down counter |
| 1 | 2 x 16 bit up counter |
| 2 | 32-bit gated counter, gate input Low disables the counter |
| 3 | 32-bit gated counter, gate input High disables the counter |

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy             : BOOL;  
    bError            : BOOL;  
    iErrorId          : UDINT;  
    iState            : USINT;  
    iDataIn0          : UINT;  
    iDataIn1          : UINT;  
    iDataIn           : UDINT;  
    iTerminalType     : WORD;  
    iSpecialType      : WORD;  
    iFirmwareVersion  : WORD;  
    sDescription      : STRING;  
    sCounterType      : STRING;  
    bBackwardCounting : BOOL;  
END_VAR
```

**bBusy:** As long as the read or configuration sequence is in progress, this output is TRUE.

**bError:** This output is switched to TRUE, if an error occurred while a command (Configure or Read) is executed. The command-specific error code is contained in *iErrorId*.

**iErrorId:** contains the command-specific error code of the most recently executed command. It is reset to 0 by activating the function block again via the inputs *bConfigurate* or *bReadConfig*. [See Error codes](ms-xhelp:///?Id=beckhoff-0d09-48c9-8316-370fd0466394).

**iState:** Corresponds to the status variable of the process data, i.e. *stInData*.iState, see VAR\_IN\_OUT. During command execution (*bBusy* = TRUE) this output is set to 0. This output is suitable for status assessment during normal terminal operation. Spurious states during configuration and reading through the register communication are hidden.

**iDataIn0:** Corresponds to the data variable of the process data, i.e. *stInData.arrDataIn[0]*, see VAR\_IN\_OUT. During command execution (*bBusy* = TRUE) this output retains the value it had before the command was called. This output is suitable for direct process data processing during normal terminal operation. Spurious states during configuration and reading through the register communication are hidden.

**iDataIn1:** Corresponds to the data variable of the process data, i.e. *stInData.arrDataIn[1]*, see VAR\_IN\_OUT. During command execution (*bBusy* = TRUE) this output retains the value it had before the command was called. This output is suitable for direct process data processing during normal terminal operation. Spurious states during configuration and reading through the register communication are hidden.

**iDataIn:** This variable of type UDINT is used for improved evaluation, if a 32-bit counter is selected. It consists of the two variables *iDataIn0* and *iDataIn1* (both of type UINT) referred to above. *iDataIn0* is used for the low-order part, *iDataIn1* for the high-order part.

**iTerminalType:** Contents of register 8 (terminal designation). When used with the correct terminal, the content should be 0x05DD (1501dec).

**iSpecialType:** Contents of register 29 (special version).

**iFirmwareVersion:** Contents of register 9 (firmware version).

**sDescription:** Terminal designation, special version and firmware version as string (e.g. 'terminal KL1501-0000 / firmware 1C').

**sCounterType:** Set counter mode in plain text.

**bBackwardCounting:** TRUE: The count direction was reversed.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stInData   : ST_KL1501InData;  
    stOutData  : ST_KL1501OutData;  
END_VAR
```

**stInData :** Reference to the structure of the input process image (type: [ST\_KL1501InData](ms-xhelp:///?Id=beckhoff-2a18-4f10-b9f6-b1ec68b12361)).

**stOutData :** Reference to the structure of the output process image (type: [ST\_KL1501OutData](ms-xhelp:///?Id=beckhoff-7600-4f87-a6e2-395246949b43)).

## Requirements

| Development environment | Target platform | IO Hardware | PLC libraries to include |
| --- | --- | --- | --- |
| TwinCAT v3.1.4018.26 | PC/CX | KL1501 | Tc2\_IoFunctions from v3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
