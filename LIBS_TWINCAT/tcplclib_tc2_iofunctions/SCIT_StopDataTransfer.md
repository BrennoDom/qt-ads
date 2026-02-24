# SCIT_StopDataTransfer

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Third party devices](ms-xhelp:///?Id=beckhoff-8141-420b-ab48-e4c3c40c9d6b)
4. [Phoenix IBS SC/I-T](ms-xhelp:///?Id=beckhoff-5871-41bd-a1ed-a635485281c8)
5. SCIT\_StopDataTransfer

# SCIT\_StopDataTransfer

![58259743](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314238859__Web.png)

The "SCIT\_StopDataTransfer" function block serves as an auxiliary block in order to carry out a **Stop\_Data\_Transfer** on the Interbus card that is addressed by the NETID and the PORT. A **Stop\_Data\_Transfer** places the card into the [ACTIVE](ms-xhelp:///?Id=beckhoff-63cf-4976-9bf4-876fc243051c) state, but the outputs are *not* reset.

## VAR\_INPUT

```
VAR_INPUT  
    NETID : T_AmsNetId;  
    PORT  : T_AmsPort;  
    WRTRD : BOOL;  
    TMOUT : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: The network address of the computer in which the card is installed can be entered here (type: T\_AmsNetID). If the card is located within the same system, it is also possible to give an empty string.

**PORT**: Contains the ADS port number of the card that was assigned by the TwinCAT system (type: T\_AmsPort).

**WRTRD**: The function block is activated by a positive edge at this value.

**TMOUT**: Maximum time allowed for the execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY       : BOOL;  
    ERR        : BOOL;  
    ERRID      : UDINT;  
    RESULT     : WORD;  
    ADDERRINFO : WORD;  
END_VAR
```

**BUSY**: After activation of the function block the busy signal remains asserted until an feedback is received.

**ERR**: If an error occurs while the command is being transferred, the ERR output is set once the BUSY signal is cancelled.

**ERRID**: Returns the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) in the case of error.

**RESULT**: Returns the result from the card (provided that fault-free ADS transport has occurred (ERR = FALSE)). RESULT = 0 identifies successful execution of the command. A value other than 0 contains the error number from the Phoenix card.

**ADDERRINFO**: If feedback from the card is negative, this contains additional error information (cf. the Phoenix card error descriptions).

## Requirements

| Development environment | Target platform | IO Hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | None. This functionality is not supported by TwinCAT 3 at present! | Phoenix: IBS SC/I-T; IBS SC/RI/RT-LK | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
