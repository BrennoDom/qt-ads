# ADSWRITEIND

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [Expanded ADS function blocks](ms-xhelp:///?Id=beckhoff-e61a-44cc-ad9b-6f5534fc93c0)
4. ADSWRITEIND

# ADSWRITEIND

![33018140](/tcplclib_tc2_system/1033/Images/png/9007199285882763__Web.png)

The function block registers ADSWRITE-Requests to a PLC task as indications and allows them to be processed. The queuing of an indication is reported at the VALID output port by means of a rising edge. The indication is shown to have been processed by a rising edge at the CLEAR in put. A falling edge releases the function block for the processing of further indications. After an indication has been processed a response must be sent to the source device via the [ADSWRITERES](ms-xhelp:///?Id=beckhoff-0928-434d-a060-a06dd97eeaec) function block. The PORT and NETID parameters can be used to address the source device for this purpose. The INVOKEID parameter sorts the responses to the requests for the source device and is also sent back as parameter to the source device.

## VAR\_INPUT

```
VAR_INPUT  
    CLEAR : BOOL;  
END_VAR
```

**CLEAR**: With a rising edge at this input an indication is reported as processed and the outputs of the ADSWRITEIND function block are reset ( DATAADDR = 0, LENGTH = 0 !). A falling edge releases the function block for the processing of further indications.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    VALID     : BOOL;  
    NETID     : T_AmsNetId;  
    PORT      : T_AmsPort;  
    INVOKEID  : UDINT;  
    IDXGRP    : UDINT;  
    IDXOFFS   : UDINT;  
    LENGTH    : UDINT;  
    DATAADDR  : PVOID;  
END_VAR
```

**VALID**: The output is set if an indication was registered from the function block and remains set until the latter was reported as processed by a raising edge at the CLEAR input.

**NETID**: String containing the AMS network ID of the source device, from which the ADS command was sent (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**PORT**: Port number of the ADS source device, from which the ADS command was sent (type: [T\_AmsPort](ms-xhelp:///?Id=beckhoff-8526-4c85-aeea-045be9df1824)).

**INVOKEID**: Handle of the command, which was sent. The InvokeId is specified from the source device and serves to identify the commands.

**IDXGRP**: Index group number (32 bit, unsigned) of the requested ADS service.

**IDXOFFS**: Index offset number (32 bit, unsigned) of the requested ADS service.

**LENGTH**: Length, in bytes, of the data to be written.

**DATAADDR**: Address of the data buffer, in which the data written is located.

**Example of calling the block in ST:**

* [Example with AdsWriteInd/AdsWriteRes function blocks](ms-xhelp:///?Id=beckhoff-df36-470c-be4c-e70e98c6738d)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
