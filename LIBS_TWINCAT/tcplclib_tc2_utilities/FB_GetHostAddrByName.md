# FB_GetHostAddrByName

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetHostAddrByName

![17937528](/tcplclib_tc2_utilities/1033/Images/png/9007199290248075__Web.png)

This function block can be used to read the (IPv4) Internet protocol network address for the specified host name. The address is returned as string and byte array.

## VAR\_INPUT

```
VAR_INPUT  
    sNetID    : T_AmsNetId;  
    sHostName : T_MaxString := '';  
    bExecute  : BOOL;  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetID**: Here you can specify the network address of the TwinCAT computer on which the command is to be executed (type: T\_AmsNetID). For the local computer (default) an empty string may be specified.

**sHostName**: Host name as string (type: T\_MaxString). E.g.: 'DataServer1'.

**bExecute**: the block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrID   : UDINT;  
    sAddr    : T_IPv4Addr := '';  
    arrAddr  : T_IPv4AddrArr :=[ 0, 0, 0, 0];  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the *bError* output is set.

**sAddr**: Internet protocol network address (IPv4) as string (type: T\_Ipv4Addr). E.g.: '172.16.7.199'

**arrAddr**: Internet protocol network address as byte array (type: T\_Ipv4AddrArr).

**Sample:**

```
PROGRAM MAIN  
VAR  
    fbGet   : FB_GetHostAddrByName;  
    bGet    : BOOL := TRUE;  
    bError  : BOOL;  
    nErrID  : UDINT;  
    sIPv4   : T_IPv4Addr;(* Result: '87.106.8.100' *)  
    arrIPv4 : T_IPv4AddrArr;  
    state   : BYTE;  
END_VAR
```

```
CASE state OF  
0:  
    IF bGet THEN  
        bGet := FALSE;  
        sIPv4 := '';  
        fbGet( bExecute:= FALSE );  
        fbGet( bExecute:= TRUE, sHostName := 'www.beckhoff.com' );  
        state := 1;  
    END_IF  
1:  
    fbGet( bExecute:= FALSE, bError=>bError, nErrID=>nErrID, sAddr=>sIPv4, arrAddr=>arrIPv4 );  
    IF NOT fbGet.bBusy THEN  
        state := 0;  
    END_IF  
END_CASE
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7) | Tc2\_Utilities (System) |
