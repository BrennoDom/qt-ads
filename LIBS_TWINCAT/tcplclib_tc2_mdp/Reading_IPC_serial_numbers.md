# Reading IPC serial numbers

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Samples](ms-xhelp:///?Id=beckhoff-dd90-45e9-9f88-58a3bde10416)
3. Reading IPC serial numbers

# Reading IPC serial numbers

This sample illustrates access to the serial number of the IPCs and the serial number of the IPC's mainboard.

* The serial number of the mainboard can be read via a subindex in module Mainboard in the Configuration Area of the IPC diagnostics. The general function block [FB\_MDP\_ReadElement](ms-xhelp:///?Id=beckhoff-4d16-4e37-af82-66a75badda9c) is used for this purpose.
* The serial number of the IPC can be read via index 0xF9F0 in the Device Area of the IPC diagnostics. The general function block [FB\_MDP\_ReadIndex](ms-xhelp:///?Id=beckhoff-009c-48de-b8e2-7a8572890dc2) is used for this purpose.

## Sample: querying the serial number of a Beckhoff IPC

**Enumeration definition**

```
//** = simply adjust these lines if modifying code for own purposes  
   
// central definition of state machine states   
// (supports easy program modification)  
{attribute 'qualified_only'}  
TYPE E_State :  
(  
    Idle,                      // idle state  
    ReadSnoMainboardInit,      //** initiate reading serial number of mainboard  
    ReadSnoMainboardProcess,   //** process reading serial number of mainboard  
    ReadSnoIPCInit,            //** initiate reading serial number of IPC  
    ReadSnoIPCProcess          //** process reading serial number of IPC  
);  
END_TYPE
```

**Variable Declaration**

```
PROGRAM MAIN  
VAR  
    // internal use  
    sAmsNetId                : STRING := ''; //** ADS Net ID (local = '')  
    eState                   : E_State;      // Enum with index for state machine  
    bStart                   : BOOL := TRUE; // flag to trigger restart of statemachine  
    sData                    : STRING;       // data storage for string variable  
    stMDP_Addr               : ST_MDP_Addr;  // structure which will include all address parameters   
  
    // FB instances  
    fbReadMDPElement         : FB_MDP_ReadElement;  // instance of FB for reading MDP element   
    fbReadMDPIndex           : FB_MDP_ReadIndex;    // instance of FB for reading MDP index  
      
    // results of execution  
    bError                   : BOOL;         // error flag (indicator: error occured)  
    nErrID                   : UDINT;        // last error ID  
    sSerialNoMainboard       : STRING;       //** buffer for serial number of mainboard  
    sSerialNoIPC             : STRING;       //** buffer for serial number of IPC  
END_VAR
```

**Program code**

```
// For an easy re-use of the following code for own purposes, parts of this sample program use   
// "general" data names (and copy the results in specific variables after processing the code).  
  
CASE eState OF  
     E_State.Idle:   
         IF bStart THEN  
            bStart := FALSE;  
            eState := E_State.ReadSnoMainboardInit;  //** initiate first state  
         END_IF   
      
    //** read serial number of mainboard **************************************************************      
    E_State.ReadSnoMainboardInit:               //** trigger FB: request mainboard serial number      
        sData               := '';              // clear data buffer  
        sSerialNoMainboard  := '';              //** clear buffer for serial number of mainboard  
        stMDP_Addr.nArea    := INT_TO_BYTE(eMDP_Area_ConfigArea);  //** set area address to "Config Area"  
        stMDP_Addr.nTableId := 1;               //** table ID in index for "mainboard information"  
        stMDP_Addr.nSubIdx  := 2;               //** subindex in table ID for "serial number"                       
          
        fbReadMDPElement(  
            bExecute    := TRUE,                // Flag: trigger execution of FB  
            eModuleType := eMDP_ModT_Mainboard, //** desired module type / index = Mainboard            
            stMDP_Addr  := stMDP_Addr,          // MDP address structure. Dynamic module ID will be added internally.  
            iModIdx     := 0,                   //** Instance of desired module type (default: 0 = first instance)   
            pDstBuf     := ADR(sData),          // buffer for storing data  
            cbDstBufLen := SIZEOF(sData),       // length of buffer  
            sAmsNetId   := sAmsNetId,           // AMS Net ID  
            );  
          
        eState := E_State.ReadSnoMainboardProcess; //** next state: process FB  
              
    E_State.ReadSnoMainboardProcess:            //** process FB: request mainboard serial number  
        fbReadMDPElement(bExecute := FALSE);    // Flag: Get execution state of FB   
      
        IF NOT fbReadMDPElement.bBusy THEN      // FB executed?  
            IF fbReadMDPElement.bError THEN     // Error?  
                bError := TRUE;                 // set error flag  
                nErrID := fbReadMDPElement.nErrID; // store error id (16#ECA60105 = BIOS or HW does   
                                                // not support this data (here: mainboard data))  
                eState := E_State.Idle;         // finish state machine  
            ELSE                                // set parameters for next steps  
                bError := FALSE;                // turn off error flag  
                sSerialNoMainboard := sData;    //** store serial number of mainboard in dedicated variable  
                eState := E_State.ReadSnoIPCInit; //** next state   
            END_IF  
        END_IF  
      
    //** read serial number of IPC **************************************************************           
    E_State.ReadSnoIPCInit:                     //** trigger FB: request single index in MDP Device Area, IPC serial number  
        sData           := '';                  // clear data buffer  
        sSerialNoIPC    := '';                  //** clear buffer for serial number of IPC  
          
        fbReadMDPIndex(  
            bExecute    := TRUE,                // Flag: trigger execution of FB  
            nIndex      := 16#F9F0,             //** index: read serial number IPC (-> see docu 'MDP device area')  
            nSubIndex   := 0,                   //** first subdindex (there is only one available for index 16#F9F0)  
            pDstBuf     := ADR(sData),          // buffer for storing serial number  
            cbDstBufLen := SIZEOF(sData),       // length of buffer  
            sAmsNetId   := sAmsNetId,           // AMS Net ID  
            );  
      
        eState := E_State.ReadSnoIPCProcess;    //** next state: process FB  
              
    E_State.ReadSnoIPCProcess:                  //** process FB:: request single index in MDP Device Area, IPC serial number  
      
        fbReadMDPIndex(bExecute := FALSE);      // flag: Get execution state of FB   
      
        IF NOT fbReadMDPIndex.bBusy THEN        // FB executed?  
            IF fbReadMDPIndex.bError THEN       // error?  
                bError := TRUE;                 // set error flag  
                nErrID := fbReadMDPIndex.nErrID; // store error id (16#ECA60105 = BIOS or HW does   
                                                // not support this data (here: IPC serial number))  
                eState := E_State.Idle;         // finish state machine  
            ELSE                                // set parameters for next steps  
                bError := FALSE;                // turn off error flag  
                sSerialNoIPC := sData;          //** store serial number of mainboard  
                eState := E_State.Idle;         //** set here next state if expanding the state machine  
            END_IF  
        END_IF  
  
END_CASE
```

|  |  |
| --- | --- |
| 53022201 | Returning of the mainboard serial number instead of the IPC serial number  In older BIOS version (before Q4/2013) the serial number was not stored in the IPC BIOS. In these cases the return value is the serial number of the IPC mainboard. With older Beckhoff Automation Device Driver versions, the return value is also the serial number of the IPC mainboard. The serial number of the IPC mainboard can always be read via the mainboard module |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
