# Querying the fan state (generic)

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Samples](ms-xhelp:///?Id=beckhoff-dd90-45e9-9f88-58a3bde10416)
3. Querying the fan state (generic)

# Querying the fan state (generic)

This sample illustrates access to the fan speed data via the generic function block [FB\_MDP\_ReadElement](ms-xhelp:///?Id=beckhoff-4d16-4e37-af82-66a75badda9c). It can be used to diagnose a fan failure (fan speed = 0).

A prerequisite is the presence of a fan. If no fan is available in the IPC, the IPC does not support the addressed module type, and the access attempt results in the error message 16#EC800002.

The contents of the FAN module are described in the Configuration Area of the IPC diagnostics. The generic function block FB\_MDP\_ReadElement is used for the access.

A description of the structure of this sample program can be found in the sample: [Querying CPU data (generic)](ms-xhelp:///?Id=beckhoff-2f62-4420-a862-28bd6bdb1935).

## Sample: access via the generic function block FB\_MDP\_ReadElement

**Enumeration definition**

```
//** = simply adjust these lines if modifying code for own purposes  
  
// central definition of state machine states   
// (supports easy program modification)  
{attribute 'qualified_only'}  
TYPE E_State :  
(  
    Idle,                    // idle state  
    ReadFanSpeedInit,        //** initiate reading fan speed  
    ReadFanSpeedProcess      //** process reading fan speed  
);  
END_TYPE
```

```
    PROGRAM MAIN  
VAR  
    // internal use  
    sAmsNetId           : STRING := '';        //** ADS Net ID (local = '')   
    eState              : E_State;             // Enum with index for state machine   
    bStart              : BOOL := TRUE;        // flag to trigger restart of statemachine  
    nData               : UINT;                // data storage for unsigned integer    
    stMDP_Addr          : ST_MDP_Addr;         // structure will include all address parameters   
    nModuleIndex        : USINT := 0;          //** Fan index (no. of fan)      
      
    // FB instances  
    fbReadMDPElement    : FB_MDP_ReadElement;  // instance of FB for reading MDP element   
   
    // results of execution  
    bError              : BOOL;                // error flag (indicator: error occured)     
    nErrID              : UDINT;               // last error ID  
    aFanSpeed           : ARRAY[0..1] OF UINT; //** buffer for speed of fans  
END_VAR
```

**Program code**

```
// For an easy re-use of the following code for own purposes, parts of this sample program use  
// "general" data names (and copy the results in specific variables after processing the code).  
// Remark: Error 16#EC800002 means module type not supported (IPC does not provide this type of information, e.g. does not have fans)  
  
CASE eState OF  
    E_State.Idle:   
        IF bStart THEN  
            bStart := FALSE;   
            eState := E_State.ReadFanSpeedInit;    //** initiate first state  
        END_IF  
   
    E_State.ReadFanSpeedInit:                 //**  
        stMDP_Addr.nArea := INT_TO_BYTE(eMDP_Area_ConfigArea); //** set area address to "Config Area"  
        stMDP_Addr.nTableId := 1;             //** table ID in module for "Fan properties"  
        stMDP_Addr.nSubIdx := 1;              //** subindex in table ID for "Fan speed"   
  
        fbReadMDPElement(  
            bExecute := TRUE,                 // Flag: trigger execution of FB  
            eModuleType := eMDP_ModT_Fan,     //** desired module type = Fan   
            stMDP_Addr := stMDP_Addr,         // MDP address structure. Dynamic module ID added internally.   
            iModIdx := nModuleIndex,          //** instance of desired module type (0 = first instance)   
            pDstBuf := ADR(nData),            // buffer for storing data  
            cbDstBufLen := SIZEOF(nData),     // length of buffer  
            sAmsNetId := sAmsNetId,           // AMS Net ID  
            );                                //** Note: fbReadMDPElement.tTimeOut must be > cycle time!  
  
  
        eState := E_State.ReadFanSpeedProcess;//** next state: process FB  
  
    E_State.ReadFanSpeedProcess:              //** process FB: request fan data  
        fbReadMDPElement(bExecute := FALSE);  // Flag: Get execution state of FB   
                                              //** Note: fbReadMDPElement.tTimeOut must be > cycle time!  
  
        IF NOT fbReadMDPElement.bBusy THEN    // FB executed?  
            IF fbReadMDPElement.bError THEN   // Error?  
                bError := TRUE;               // set error flag  
                nErrID := fbReadMDPElement.nErrID; // store error id (16#ECA60105 = BIOS or HW does   
                                              // not support this data (here: mainboard data))  
                eState := E_State.Idle;       // finish state machine  
            ELSE                              // set parameters for next steps  
                bError := FALSE;              // turn off error flag  
                aFanSpeed[nModuleIndex] := nData; //** store fan speed in dedicated array  
                IF nModuleIndex = 0 THEN      //** Current fan = fan 1?   
                    nModuleIndex := 1;        //** Read fan 2 (= second module instance) in next loop  
                ELSE                          //**  
                    nModuleIndex := 0;        //** Read fan 1 (= first module instance) in next loop  
                END_IF                        //**  
                eState := E_State.ReadFanSpeedInit; //** next state   
            END_IF  
        END_IF  
  
END_CASE 
```

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
