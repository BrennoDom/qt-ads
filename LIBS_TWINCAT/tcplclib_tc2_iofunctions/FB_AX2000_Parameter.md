# FB_AX2000_Parameter

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [AX200x Profibus](ms-xhelp:///?Id=beckhoff-348f-457a-b6d5-7c82d7b5dd86)
4. FB\_AX2000\_Parameter

# FB\_AX2000\_Parameter

![30804749](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314142859__Web.png)

Reading/writing the parameters via the parameter channel.

## VAR\_INPUT

```
VAR_INPUT  
    iSlaveAddress   : BYTE := 0;(* Station Address of the Slave *)  
    iPnu            : WORD := 16#03A2;(* Parameter-Number *)  
    nAxis           : BYTE := 1;(* Number of Axis *)  
    iLength         : BYTE := 4;(* Length of the parameter (2 or 4) *)  
    iParameterValue : DWORD := 2;(* Parameter value *)  
    iFC310xDeviceId : WORD := 1;(* Device-ID of the FCxxxx *)  
    bStartRead      : BOOL;(* StartFlag to start the PKW-Read *)  
    bStartWrite     : BOOL;(* StartFlag to start the PKW-Write *)  
    tTimeOut        : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**iSlaveAddress**: Station address.

**iPnu**: Selection of the parameter to be read or written. List of the available [parameter numbers](ms-xhelp:///?Id=beckhoff-7ba6-47e6-b037-4a9b81f7e18e).

**nAxis**: Axis ID.

**iLength**: Length of the parameter (2 or 4).

**iParameterValue** : Value of the parameter to be read or written.

**iFC310xDeviceId** : Device-Id

**bStartRead** : A rising edge at this boolean input sends a command to the axis to start reading the parameters selected with "Pnu".

**bStartWrite** : A rising edge at this boolean input sends a command to the axis to start writing the parameters selected with "Pnu". When changing operating mode, the write command is only effective if Stop = TRUE at the [FB\_AX2000\_AXACT](ms-xhelp:///?Id=beckhoff-a25c-44dc-959e-5a805f716f17) block.

**tTimeOut**: Maximum time allowed for the execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy      :BOOL;  
    iErrorId   :DWORD;  
    iReadValue :DINT;  
END_VAR
```

**bBusy**: This output remains TRUE until the block has executed a command. While Busy = TRUE, no new command will be accepted at the inputs. Please note that it is not the execution of the service but its acceptance whose time is monitored.

**iErrorId**: contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs.

**iReadValue:** Parameter value as a response to the "StartRead" command.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | AX2000 Profibus box | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
