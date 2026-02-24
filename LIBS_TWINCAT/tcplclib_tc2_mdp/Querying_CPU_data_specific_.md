# Querying CPU data (specific)

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Samples](ms-xhelp:///?Id=beckhoff-dd90-45e9-9f88-58a3bde10416)
3. Querying CPU data (specific)

# Querying CPU data (specific)

This sample demonstrates access to CPU data by the IPC diagnostics via the specific function block [FB\_MDP\_CPU\_Read](ms-xhelp:///?Id=beckhoff-c070-434a-a495-bd512c854849).

This sample cannot be modified for access to other IPC diagnostics modules such as fan data.

Following the program code of the sample you will find the textual [Description of the sample program](ms-xhelp:///?Id=beckhoff-1801-4b92-bfa2-515f342c3357).

## Sample: access via the specific function block FB\_MDP\_CPU\_Read

The specific function block FB\_MDP\_CPU\_Read facilitates access to selected data of the CPU module in the Configuration Area of the IPC diagnostics.

**Enumeration definition**

```
//** = simply adjust these lines if modifying code for own purposes  
   
// central definition of state machine states   
// (supports easy program modification)  
{attribute 'qualified_only'}  
TYPE E_State :  
(  
    Idle,  
    ReadCPUDataInit,        //** initiate reading CPU data  
    ReadCPUDataProcess      //** process reading CPU data  
);  
END_TYPE
```

**Variable Declaration**

```
PROGRAM MAIN  
VAR  
    // internal use  
    sAmsNetId           : STRING := '';       //** ADS Net ID (local = '')      
    eState              : E_State;            // Enum with index for state machine       
    bStart              : BOOL := TRUE;       // flag to trigger (re)start of statemachine  
      
    // FB instances  
    fbReadCPUData       : FB_MDP_CPU_Read;    // instance of FB for reading CPU data    
  
    // results of execution  
    bError              : BOOL;               // error flag (indicator: error occured)  
    nErrID              : UDINT;              // last error ID   
    stHeaderCpuMod      : ST_MDP_ModuleHeader; // buffer for header data of CPU module   
    stCPUData           : ST_MDP_CPU;         // structure which will contain CPU data  
END_VAR
```

**Program code**

```
// For an easy reuse of the following code for own purposes, parts of this sample program use   
// "general" data names (and copy the results in specific variables after processing the code).  
  
CASE eState OF  
    E_State.Idle:   
        IF bStart THEN  
            bStart := FALSE;  
            eState := E_State.ReadCPUDataInit; //** initiate first state  
        END_IF       
      
    E_State.ReadCPUDataInit:                   //** trigger FB: request CPU data  
        fbReadCPUData(  
            bExecute    := TRUE,               // Flag: trigger execution of FB  
            iModIdx     := 0,                  //** Instance of desired module type (0 = first instance)   
            sAmsNetId   := sAmsNetId);         // AMS Net ID  
          
        eState := E_State.ReadCPUDataProcess;  //** next state: process FB  
              
    E_State.ReadCPUDataProcess:                //** process FB: request CPU data  
        fbReadCPUData(bExecute := FALSE);      // Flag: Get execution state of FB   
      
        IF NOT fbReadCPUData.bBusy THEN        // FB executed?  
            IF fbReadCPUData.bError THEN       // Error?  
                bError := TRUE;                // set error flag  
                nErrID := fbReadCPUData.nErrID; // store error id   
                eState := E_State.Idle;         // finish state machine  
            ELSE                               // set parameters for next steps  
                bError         := FALSE;       // turn off error flag  
                stHeaderCpuMod := fbReadCPUData.stMDP_ModuleHeader;  //** store CPU module header data  
                stCPUData      := fbReadCPUData.stMDP_ModuleContent; //** store CPU data   
                eState         := E_State.ReadCPUDataInit;           //** read next set of CPU data  
            END_IF                                                            
        END_IF  
  
END_CASE 
```

## Description of the sample program

The function block "FB\_MDP\_CPU\_READ" requires a minimum of two parameters:

* The AMS Net ID as input parameter for the address of the IPC (local: ‘‘)
* A structure stMDP\_ModuleContent that contains the data after calling the function block.

![62094776](/tcplclib_tc2_mdp/1033/Images/png/2145124235__Web.png)

the function block does not supply the CPU temperature; this can only be read via the generic sample program. The value "CPU temperature" is not supported by all IPCs.

The parameters and the function block are used at these points in the program:

![21982073](/tcplclib_tc2_mdp/1033/Images/png/2148140427__Web.png)

## The state machine

![63620936](/tcplclib_tc2_mdp/1033/Images/png/2148144523__Web.png)

The states of the state machine are listed as constants in order to enable simple adaptation of the program. The desired "State" value thus only needs to be centrally changed once. The statuses are defined as enumeration declarations in the PLC project in subfolder "DUTs" as DUT under the name "E-State".

The various areas of the state machine and their functions are explained below:

![35717517](/tcplclib_tc2_mdp/1033/Images/png/2145129995__Web.png)

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
