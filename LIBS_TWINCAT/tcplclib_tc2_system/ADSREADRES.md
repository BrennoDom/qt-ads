# ADSREADRES

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [Expanded ADS function blocks](ms-xhelp:///?Id=beckhoff-e61a-44cc-ad9b-6f5534fc93c0)
4. ADSREADRES

# ADSREADRES

![57223682](/tcplclib_tc2_system/1033/Images/png/9007199285889163__Web.png)

The ADSREADRES function block is used to acknowledge indications of a PLC task. A response is sent to the ADS source device via a rising edge on the RESPOND input. The source device is addressed via the PORT and NETID parameters. The INVOKEID parameter sorts the responses to the requests for the source device and is adopted by the output of the [ADSREADIND](ms-xhelp:///?Id=beckhoff-acb7-4e42-9597-04eceb756e88) function block. An error code can be returned to the ADS source device via the RESULT parameter.

## VAR\_INPUT

```
VAR_INPUT  
    NETID     : T_AmsNetId;  
    PORT      : T_AmsPort;  
    INVOKEID  : UDINT;  
    RESULT    : UDINT;  
    LEN       : UDINT;  
    DATAADDR  : PVOID;  
    RESPOND   : BOOL;  
END_VAR
```

**NETID**: String containing the AMS network ID of the source device, to which the ADS command is to be sent (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**PORT**: Port number of the ADS source device, to which the response should be sent (type: [T\_AmsPort](ms-xhelp:///?Id=beckhoff-8526-4c85-aeea-045be9df1824)).

**INVOKEID**: Handle of the command, which was sent. The InvokeId is specified from the source device and serves to identify the commands.

**RESULT**: String containing the [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or the command-specific error code to be sent to the source device.

**LEN**: Number, in bytes, of the data to be read.

**DATAADDR**: Address of the data buffer, which should be read.

**RESPOND**: The function block is activated by a positive edge at this input.

## VAR\_OUTPUT

```
VAR_OUTPUT  
(*none*)  
END_VAR
```

**Example of calling the block in ST:**

* [Example with AdsReadInd /AdsReadRes function blocks](ms-xhelp:///?Id=beckhoff-de82-4f4e-869c-da07e36f9f66)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
