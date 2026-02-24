# FB_NovRamReadWrite

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [NOV/DP-RAM](ms-xhelp:///?Id=beckhoff-a373-4cdd-a30b-97d1a774e645)
4. FB\_NovRamReadWrite

# FB\_NovRamReadWrite

The following description refers to TwinCAT Version 2.8. Starting from TwinCAT version 2.9 [Build 927], a function block will no longer be required for the writing/reading of PLC data to be secured in the NOVRAM.

![64665535](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314114059__Web.png)

The *FB\_NovRamReadWrite* function block accesses the NOV-RAM of the FCxxxx-000**2** fieldbus cards from a PLC program. Activation of the function block is triggered by a rising edge at the *bRead* or *bWrite* input. A certain number of data bytes is read from or written to the NOV-RAM. If both inputs, *bRead* and *bWrite*, are set simultaneously, the data are first written into the NOV-RAM and then read back.

**Comments:**

In order to determine the NOV-RAM address pointer, the *FB\_NovRamReadWrite* function block internally uses an instance of the ADSREAD function block. This address pointer is only determined when the *FB\_NovRamReadWrite* function block is called for the first time or in the event of a change in *nDevId*. This task requires several PLC cycles. The MEMCPY function is used to write data into the NOV-RAM or to read data from the NOV-RAM. This enables data to be written or read in the same PLC cycle. Internally the maximum byte length of the NOV-RAM is also determined, and the maximum data length that can be read or written is limited to this length.

## VAR\_INPUT

```
VAR_INPUT  
    nDevId     : UDINT;  
    bRead      : BOOL;  
    bWrite     : BOOL;  
    cbSrcLen   : UDINT;  
    cbDestLen  : UDINT;  
    pSrcAddr   : PVOID;  
    pDestAddr  : PVOID;  
    tTimeOut   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**nDevId:** The device ID of a NOV-RAM card. Via the **Id** the NOV-RAM of an FCxxxx-0002 card is specified for which write or read access is required via the function block. The device IDs are specified by the TwinCAT system during the hardware configuration.

**bRead**: The block is activated by a rising edge at this input, and *cbDestLen* data are copied from the NOV-RAM (from address offset NULL) into the buffer with address *pDestAddr*.

**bWrite**: The block is activated by a rising at this input, and *cbSrcLen* data are copied from the buffer with address *pSrcAddr* into the NOV-RAM (from address offset NULL).

**cbSrcLen:** : The byte length of the data to be written into the NOV-RAM.

**cbDestLen**: The byte length of the data to be read from the NOV-RAM.

**pSrcAddr** : The address pointer to a data buffer containing the data to be written into the NOV-RAM. The address pointer can be determined via the ADR operator.

**pDestAddr** : The address pointer to a data buffer with the data to be written into the NOV-RAM.

**tTimeOut**: States the length of the timeout that may not be exceeded during execution of the command/function.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrId    : UDINT;  
    cbRead    : UDINT;  
    cbWrite   : UDINT;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until execution of the function has been completed.

**bError**: This output is set if an error occurs during execution.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) when the *bError* output is set.

**cbRead**: Number of successfully read data bytes.

**cbWrite**: Number of successfully written data bytes.

**Example**:

```
PROGRAM MAIN  
VAR  
    fbNovRamReadWrite : FB_NovRamReadWrite;  
    bRead             : BOOL;  
    bWrite            : BOOL;  
    fromNovRam        : ARRAY[1..100] OF BYTE;  
    toNovRam          : ARRAY[1..100] OF BYTE;  
    bBusy             : BOOL;  
    bError            : BOOL;  
    nErrID            : UDINT;  
    cbRead            : UDINT;  
    cbWrite           : UDINT;  
END_VAR
```

![45118907](/tcplclib_tc2_iofunctions/1033/Images/gif/59376267__en-US__Web.gif)

In the example a rising edge at the *bRead* input led to 100 bytes of data being read from the NOV-RAM and copied into the *fromNovRam* array.

## Requirements

| Development environment | Target platform | IO Hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | FCxxxx cards with NOVRAM (FCxxxx-0002) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
