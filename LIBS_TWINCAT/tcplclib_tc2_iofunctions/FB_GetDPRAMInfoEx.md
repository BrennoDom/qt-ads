# FB_GetDPRAMInfoEx

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [NOV/DP-RAM](ms-xhelp:///?Id=beckhoff-a373-4cdd-a30b-97d1a774e645)
4. FB\_GetDPRAMInfoEx

# FB\_GetDPRAMInfoEx

![7954964](/tcplclib_tc2_iofunctions/1033/Images/png/2240424459__Web.png)

The FB\_GetDPRAMInfo function block determines the address pointer and the configured size of the NOV/DP-RAM of a fieldbus card. The address pointer can be used, for example, for direct write or read access of the NOV-RAM of the Fcxxx-0002 (Beckhoff) cards or the DPRAM of cards that are not supported by TwinCAT (third-party manufacturers). First, the card has to be configured as general NOV/DP-RAM within the TwinCAT system.

Along with the address (pCardAddress) and the size (iCardMemSize) of the NOV/DP-RAM the stInfo output also returns the type of access (eAccessType).

If the NOV/DP-RAM does not require special access (BYTE or WORD aligned), the MEMCPY, MEMSET or MEMCMP functions can be used in the PLC program to be able to have read/write access to a random memory offset. If the NOV/DP-RAM requires special access (BYTE or WORD aligned), then access is only possible with the appropriate data size. For this purpose use FB\_NovRamReadWriteEx.

```
VAR_INPUT  
    nDevId      :    UDINT; (*Device id of the FCxxxx or other DPRAM card (Map the FC card as generic DPRAM/NOVRAM card im System Manager first)*)  
    bExecute    :    BOOL; (*Rising edge starts function block execution*)  
    tTimeOut    :    TIME; (*Max. timeout for this command*)  
END_VAR
```

**nDevId**: The device ID of a NOV/DP-RAM card. The ID is used to specify the card from which information is to be read. The device IDs are specified by the TwinCAT system during the hardware configuration.

**bExecute**: The function block is activated via a rising edge at this input.

**tTimeOut**: States the length of the timeout that may not be exceeded during execution of the command/function.

```
VAR_OUTPUT  
    bBusy     :    BOOL;  
    bError    :    BOOL;  
    nErrid    :    UDINT;  
    stInfo    :    ST_NovRamAddrInfoEx;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until execution of the function has been completed.

**bError**: This output is set if an error occurs during the execution.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) when the bError output is set.

**stInfo**: A structure containing the address and size of the NOV/DP-RAM (type: [ST\_NovRamAddrInfoEx](ms-xhelp:///?Id=beckhoff-044d-4809-869f-f0cd549b810e)).

## Example

In MAIN a pointer to a BYTE is declared. This pointer is initialized with the address of the NOV/DP-RAM at the start of the program. Referencing the pointer makes read/write access to the NOV/DP-RAM possible.

```
PROGRAM MAIN  
VAR  
    nDevId       : UDINT := 1; //device 1, see ID of NOV/DP-RAM device  
    pNOVRAM      : POINTER TO BYTE;  
    cbNOVRAM     : DWORD;  
    fbGetInfo    : FB_GetDPRAMInfoEx;  
    bInit        : BOOL := FALSE;  
    eAccessType  : E_IOACCESSTYPE;  
    bByteAccess  : BOOL;  
    bWordAccess  : BOOL;  
    bDWordAccess : BOOL;  
END_VAR  
  
IF NOT bInit THEN  
    fbGetInfo(  
        nDevId   := nDevId,  
        bExecute := TRUE,  
        tTimeOut := T#5S  
    );  
  
    IF NOT fbGetInfo.bBusy THEN  
        IF NOT fbGetInfo.bError THEN  
            pNOVRAM     := fbGetInfo.stInfo.pCardAddress;  
            cbNOVRAM    := fbGetInfo.stInfo.iCardMemSize;  
            eAccessType := fbGetInfo.stInfo.eAccessType;  
  
            bDWordAccess := FALSE;  
            bByteAccess  := FALSE;  
            bWordAccess  := FALSE;  
  
            CASE eAccessType OF  
                eIOAccess_Default:  
                    bDWordAccess := TRUE;  
                    //access via MEMCPY,  MEMSET,  MEMCMP possible  
                eIOAccess_Byte:  
                    bByteAccess := TRUE;  
                    //access via POINTER to BYTE possible  
                eIOAccess_WordSwap:  
                    bWordAccess := TRUE;  
                    //access via POINTER to WORD +  
                    //swapping of high and low byte possible  
            END_CASE  
  
            bInit := TRUE;  
        END_IF  
        fbGetInfo(bExecute := FALSE);  
    END_IF  
END_IF
```

## Requirements

| Development environment | Target platform | IO Hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | FCxxxx cards with NOVRAM (FCxxxx-0002) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
