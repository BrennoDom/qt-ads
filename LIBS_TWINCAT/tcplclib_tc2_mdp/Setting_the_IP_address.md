# Setting the IP address

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Samples](ms-xhelp:///?Id=beckhoff-dd90-45e9-9f88-58a3bde10416)
3. Setting the IP address

# Setting the IP address

This sample illustrates write access to IPC diagnostics data via general function blocks. In the same way all other elements of the IPC diagnostics modules can be accessed.

|  |  |
| --- | --- |
| 7437765 | Active network connection  Changing these settings requires an active network connection for the selected Ethernet/EtherCAT adapter. Without an active network connection no parameters can be (pre-)set. |

## Sample: setting the IP address of a Beckhoff IPC

**Variable Declaration**

```
PROGRAM MAIN  
// First DHCP is set off and then the given new IP address is set.  
// The program code is executed only one time. To restart the program set bStart TRUE again.  
VAR  
    bStart     : BOOL := TRUE;  
    nState     : INT := 100;  
    fbScan     : FB_MDP_ScanModules;  
    fbWrite    : FB_MDP_Write;  
    stMDPAddr  : ST_MDP_Addr;  
    bDHCP      : BOOL;  
    sIP        : T_IPv4Addr := '174.18.3.154'; // the new ip address   
    bError     : BOOL;  
    nErrID     : UDINT;  
END_VAR 
```

**Program code**

```
CASE nState OF  
100: // idle  
    IF bStart THEN  
        bStart := FALSE;  
        nState := 00;  
    END_IF  
  
00: (* scan MDP module list for dyn.module id of NIC module *)  
    fbScan(  
        bExecute    := TRUE,  
        nModuleType := eMDP_ModT_NIC,  
        iModIdx     := 0, (* index of NIC module / network port *)  
        sAmsNetId   := ''  
        );  
   
    nState := 01;  
   
01:   
    fbScan( bExecute:= FALSE );  
   
    IF NOT fbScan.bBusy THEN  
        IF NOT fbScan.bError THEN  
            stMDPAddr.nArea     := INT_TO_BYTE(eMDP_Area_ConfigArea);  
            stMDPAddr.nModuleId := fbScan.nDynModuleId;  
            stMDPAddr.nTableId  := 1;  
            nState              := 10;  
        ELSE  
            bError              := TRUE;  
            nErrID              := fbScan.nErrID;  
            nState              := 00;  
        END_IF  
    END_IF  
  
10: // set DHCP off  
    stMDPAddr.nSubIdx := 4; // DHCP  
    bDHCP             := FALSE;  
   
    fbWrite(  
        bExecute      := TRUE,  
        stMDP_DynAddr := stMDPAddr,  
        pSrcBuf       := ADR(bDHCP),  
        cbSrcBufLen   := SIZEOF(bDHCP),  
        sAmsNetId     := ''  
         );  
   
    nState:= 11;  
  
11:  
    fbWrite( bExecute:= FALSE );  
    IF NOT fbWrite.bBusy THEN  
        IF NOT fbWrite.bError THEN  
            nState     := 20;  
        ELSE  
            bError     := TRUE;  
            nErrID     := fbWrite.nErrID;  
            nState     := 10;  
        END_IF  
    END_IF  
  
20: // set new IP address  
    stMDPAddr.nSubIdx := 2; // IP address  
    fbWrite(  
        bExecute      := TRUE,  
        stMDP_DynAddr := stMDPAddr,  
        pSrcBuf       := ADR(sIP),  
        cbSrcBufLen   := LEN(sIP),  
        sAmsNetId     := ''  
    );  
   
    nState := 21;  
  
21:  
    fbWrite( bExecute:= FALSE );  
    IF NOT fbWrite.bBusy THEN  
        IF NOT fbWrite.bError THEN  
            nState     := 100; (* NIC settings executed *)  
        ELSE  
            bError     := TRUE;  
            nErrID     := fbWrite.nErrID;  
            nState     := 20;  
        END_IF  
    END_IF  
END_CASE 
```

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
