# FB_GetDPRAMInfo

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [NOV/DP-RAM](ms-xhelp:///?Id=beckhoff-a373-4cdd-a30b-97d1a774e645)
4. FB\_GetDPRAMInfo

# FB\_GetDPRAMInfo

![8340425](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314126859__Web.png)

The *FB\_GetDPRAMInfo* function block determines the address pointer and the configured size of the NOV/DP-RAM of a fieldbus card. The address pointer can be used, for example, for direct write or read access of the NOV-RAM of the FCxxx-0002 (Beckhoff) cards or the DPRAM of cards that are not supported by TwinCAT (third-party manufacturers). First, the card has to be configured as general NOV/DP-RAM within the TwinCAT system. The MEMCPY, MEMSET or MEMCMP functions of the PLC program can then be used for write/read access to any memory offset.

This function block returns a *Service Not Supported* error (16#701) if the NOV/DP-RAM requires a special access method (e.g. BYTE, aligned WORD). In this case the FB\_NovRamReadWriteEx block can be used to read data from the NOV/DP-RAM or to write data into the NOV/DP RAM, e.g. the NOV-RAM of the *CX9000* permits only BYTE accesses, so the FB\_NovRamReadWriteEx block should be used in this case.

## VAR\_INPUT

```
VAR_INPUT  
    nDevId     : UDINT;  
    bExecute   : BOOL;   
    tTimeOut   : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**nDevId:** The device ID of a NOV/DP-RAM card. The ID is used to specify the card from which information is to be read. The device IDs are specified by the TwinCAT system during the hardware configuration.

**bExecute**: The function block is activated via a rising edge at this input.

**tTimeOut**: States the length of the timeout that may not be exceeded during execution of the command/function.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrId    : UDINT;  
    stInfo    : ST_NovRamAddrInfo;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until execution of the function has been completed.

**bError**: This output is set if an error occurs during execution.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) when the *bError* output is set.

**stInfo**: A structure containing the address and size of the NOV/DP-RAM (type: [ST\_NovRamAddrInfo](ms-xhelp:///?Id=beckhoff-f39f-40bb-ab80-401f60824d92)).

**Example:**

A pointer to an instance of the ST\_NOVRAM structure variable is declared in MAIN. This pointer is initialized with the address of the NOV/DP-RAM at the start of the program. By referencing the pointer, the individual structure elements (and the NOV/DP-RAM) can be accessed for writing or reading.

```
TYPE ST_NOVRAM :  
STRUCT  
    dwParam_0 : DWORD;  
    dwParam_1 : DWORD;  
    dwParam_2 : DWORD;  
    dwParam_3 : DWORD;  
  
    cbSize : DWORD;  
    wCounter : WORD;  
    func : BYTE;  
    sMsg : STRING(20);  
  
    (* ...other NOV-/DP-RAM variables *)  
END_STRUCT  
END_TYPE
```

```
PROGRAM MAIN  
VAR  
    pNOVRAM      : POINTER TO ST_NOVRAM;  
    cbNOVRAM     : DWORD;  
    fbGetInfo    : FB_GetDPRAMInfo;  
    state        : INT := 0;  
    bInit        : BOOL := FALSE;  
    timer        : TON;  
    bReset       : BOOL;  
END_VAR
```

```
CASE state OF  
0:  
    IF NOT bInit THEN  
        state := 1;  
    END_IF  
  
1:  
    fbGetInfo( bExecute := FALSE ); (* reset fb *)  
 fbGetInfo( nDevId:= 3,  
    bExecute:= TRUE, (* start fb execution *)  
 tTimeOut:= T#10s );  
    state := 2;  
2:  
    fbGetInfo( bExecute := FALSE );  
    IF NOT fbGetInfo.bBusy THEN  
        IF NOT fbGetInfo.bError THEN  
            IF fbGetInfo.stInfo.pCardAddress <> 0 THEN  
                pNOVRAM := fbGetInfo.stInfo.pCardAddress;  
                cbNOVRAM := fbGetInfo.stInfo.iCardMemSize;  
                bInit := TRUE;  
                state := 0; (* ready, go to the idle step *)  
         ELSE  
                state := 100; (* error *)  
         END_IF  
        ELSE  
            state := 100; (* error *)  
     END_IF  
    END_IF  
  
100:  
    ; (* error, stay here *)  
END_CASE  
  
  
IF bInit THEN  
 (* read from or write to NOV-/DP-RAM*)  
 IF bReset THEN (* reset all bytes to 0 *)  
     bReset := FALSE;  
        MEMSET( pNOVRAM, 0, cbNOVRAM );  
    END_IF  
  
    timer( IN := TRUE, PT := T#1s );  
    IF timer.Q THEN  
        timer( IN := FALSE );  
        pNOVRAM^.dwParam_0 := pNOVRAM^.dwParam_0 + 1;  
        pNOVRAM^.dwParam_1 := pNOVRAM^.dwParam_1 - 1;  
    END_IF  
END_IF
```

## Requirements

| Development environment | Target platform | IO Hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | FCxxxx cards with NOVRAM (FCxxxx-0002) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
