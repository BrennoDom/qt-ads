# FB_EnumRouteEntry

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_EnumRouteEntry

![62725128](/tcplclib_tc2_utilities/1033/Images/png/9007199290212875__Web.png)

This function block is used to transfer information to other TwinCAT systems via the AMS router connections (remote routes). If several connections are used the function block has to be called up repeatedly. Only one entry can be handled for each call. The input parameter *eCmd* is used for navigating through the list of entries. The *eCmd* input determines whether the first or the next input is read.

## VAR\_INPUT

```
VAR_INPUT  
    sNetID    : T_AmsNetID;  
    eCmd      : E_EnumCmdType := eEnumCmd_First;  
    bExecute  : BOOL;  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetID**: Here you can enter a string with the network address of the TwinCAT computer whose AMS router connections are to be read (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**eCmd**: Control command for the enumeration block (type: [E\_EnumCmdType](ms-xhelp:///?Id=beckhoff-cb91-427b-a901-37149aa7aa27)).

**bExecute**: the block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrId   : UDINT;  
    bEOE     : BOOL;  
    stRoute  : ST_AmsRouteEntry;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the *bError* output is set.

**bEOE**: End of enumeration was reached. During the first attempt to read a non-existing entry this output is set to TRUE. This means that read entries are valid as long as *bEOE* = FALSE and *bError* = FALSE.

**stRoute**: Structural element containing the last read connection parameters (type: [ST\_AmsRouteEntry](ms-xhelp:///?Id=beckhoff-4831-40ac-af33-243627af1c25)).

**Example:**

The configured AMS router connections are to be read on the local TwinCAT system and written into the TwinCAT System Manager logger output as messages.

```
PROGRAM P_EnumRouteEntries  
VAR  
    fbEnum : FB_EnumRouteEntry := ( sNetID := '', tTimeout := T#5s );  
    bEnum  : BOOL := TRUE;  
    nState : BYTE := 0;  
    sInfo  : T_MaxString;  
END_VAR
```

A rising edge at the bEnum variable triggers reading of the connection information.

```
CASE nState OF  
    0:  
    IF bEnum THEN (* flag set ? *)  
        bEnum := FALSE; (* reset flag *)  
        fbEnum.eCmd := eEnumCmd_First; (* enum first entry *)  
        nState := 1;  
    END_IF  
  
    1: (* enum one entry *)  
    fbEnum( bExecute := FALSE );  
    fbEnum( bExecute := TRUE );  
    nState := 2;  
  
    2: (* wait until function block not busy *)  
    fbEnum( bExecute := FALSE );  
    IF NOT fbEnum.bBusy THEN  
        IF NOT fbEnum.bError THEN  
            IF NOT fbEnum.bEOE THEN  
                sInfo := CONCAT( 'Name: ', fbEnum.stRoute.sName );  
                sInfo := CONCAT( sInfo, ' Address: ' );  
                sInfo := CONCAT( sInfo, fbEnum.stRoute.sAddress );  
                sInfo := CONCAT( sInfo, ' Transport: ' );  
                sInfo := CONCAT( sInfo, ROUTETRANSPORT_TO_STRING( fbEnum.stRoute.eTransport ) );  
                ADSLOGSTR( ADSLOG_MSGTYPE_HINT OR ADSLOG_MSGTYPE_LOG, 'ROUTE INFO: %s', sInfo );  
                    fbEnum.eCmd := eEnumCmd_Next; (* enum next entry *)  
                nState := 1;  
            ELSE (* no more route entries *)  
                nState := 0;  
            END_IF  
        ELSE (* log error *)  
            ADSLOGSTR( ADSLOG_MSGTYPE_ERROR OR ADSLOG_MSGTYPE_LOG, 'FB_EnumRouteEntry error:%s', DWORD_TO_HEXSTR( fbEnum.nErrID, 0, FALSE ) );  
            nState := 0;  
        END_IF  
    END_IF  
END_CASE
```

Log messages in the TwinCAT System Manager logger output:

![27655246](/tcplclib_tc2_utilities/1033/Images/gif/35475083__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
