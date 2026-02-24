# Querying CPU data (generic)

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Samples](ms-xhelp:///?Id=beckhoff-dd90-45e9-9f88-58a3bde10416)
3. Querying CPU data (generic)

# Querying CPU data (generic)

This sample demonstrates access to CPU data by the IPC diagnostics via the generic function block [FB\_MDP\_ReadElement](ms-xhelp:///?Id=beckhoff-4d16-4e37-af82-66a75badda9c).

The program is structured in such a way that it can easily be adapted for access to other IPC diagnostics modules. Program lines, which have to be modified to adapt the program to other IPC diagnostics modules, are identified in the comment with the string //\*\*.

Following the program code of the sample you will find the textual [Description of the sample program](ms-xhelp:///?Id=beckhoff-2f62-4420-a862-28bd6bdb1935).

## Sample: access via the generic function block FB\_MDP\_ReadElement

Individual CPU data can be read via a subindex in module CPU in the Configuration Area of the IPC diagnostics. The generic function block FB\_MDP\_ReadElement is used for this purpose.

**Enumeration definition**

```
//** = simply adjust these lines if modifying code for own purposes  
   
// central definition of state machine states   
// (supports easy program modification)  
{attribute 'qualified_only'}  
TYPE E_State :  
(  
    Idle,   
    ReadCPUusageInit,      //** initiate reading CPU usage  
    ReadCPUusageProcess    //** process reading CPU usage  
);  
END_TYPE
```

**Variable Declaration**

```
PROGRAM MAIN  
VAR  
    // internal use  
    sAmsNetId           : STRING := '';       //** ADS Net ID (local = '')      
    eState              : E_State;            // Enum with index for state machine       
    bStart              : BOOL := TRUE;       // flag to trigger (re)start of statemachine  
    nData               : UINT;               // data storage for unsigned integer       
    stMDP_Addr          : ST_MDP_Addr;        // structure will include all address parameters    
      
    // FB instances  
    fbReadMDPElement    : FB_MDP_ReadElement; // instance of FB for reading MDP element    
  
    // results of execution  
    bError              : BOOL;               // error flag (indicator: error occured)  
    nErrID              : UDINT;              // last error ID  
    nCpuUsage           : UINT;               // buffer for CPU usage (%)  
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
            eState := E_State.ReadCPUusageInit; //** initiate first state  
        END_IF  
  
    E_State.ReadCPUusageInit:      
        stMDP_Addr.nArea    := INT_TO_BYTE(eMDP_Area_ConfigArea); //** set area address to "Config Area"  
        stMDP_Addr.nTableId := 1;              //** table ID in module for "cpu properties"  
        stMDP_Addr.nSubIdx  := 2;              //** subindex in table ID for "CPU usage"                       
          
        fbReadMDPElement(  
            bExecute    := TRUE,               // Flag: trigger execution of FB  
            eModuleType := eMDP_ModT_CPU,      //** desired module type = CPU           
            stMDP_Addr  := stMDP_Addr,         // MDP address structure. Dynamic module ID added internally.   
            iModIdx     := 0,                  //** instance of desired module type (0 = first instance)   
            pDstBuf     := ADR(nData),         // buffer for storing data  
            cbDstBufLen := SIZEOF(nData),      // length of buffer  
            sAmsNetId   := sAmsNetId,          // AMS Net ID  
            );                                 //** Note: fbReadMDPElement.tTimeOut must be > cycle time!  
  
        eState := E_State.ReadCPUusageProcess;  //** next state: process FB  
              
    E_State.ReadCPUusageProcess:                //** process FB: request CPU data  
        fbReadMDPElement(bExecute := FALSE);   // Flag: Get execution state of FB   
                                               //** Note: fbReadMDPElement.tTimeOut must be > cycle time!  
  
        IF NOT fbReadMDPElement.bBusy THEN     // FB executed?  
            IF fbReadMDPElement.bError THEN    // Error?  
                bError    := TRUE;             // set error flag  
                nErrID    := fbReadMDPElement.nErrID; // store error id (16#ECA60105 = BIOS or HW does   
                                               // not support this data (here: mainboard data))  
                eState    := E_State.Idle;     // finish state machine  
            ELSE                               // set parameters for next steps  
                bError    := FALSE;            // turn off error flag  
                nCpuUsage := nData;            //** store CPU usage in dedicated variable  
                eState    := E_State.ReadCPUusageInit; //** next state   
            END_IF  
        END_IF  
      
END_CASE 
```

## Description of the sample program

The function block FB\_MDP\_ReadElement requires at least the parameters listed below:

![14944322](/tcplclib_tc2_mdp/1033/Images/png/2181771275__Web.png)![281173](/tcplclib_tc2_mdp/1033/Images/png/2181772939__Web.png)

* A memory area for the MDP address structure
* The MDP module types
* The address and size of the memory area for the output data of the function block
* The AMS address (AMS Net ID)

The output values of the function block are described here for completeness:

![2530563](/tcplclib_tc2_mdp/1033/Images/png/2182109835__Web.png)

A very important role is played by the structure for addressing the desired information. It is described by the data type ST\_MDP\_Addr:

![22775067](/tcplclib_tc2_mdp/1033/Images/png/2182112267__Web.png)

There are two possibilities to determine the parameter "nArea":

* The individual areas are stored as enumerations in the Tc2\_MDP library. This entry can be used as easily readable input parameter (dashed red arrow).
* The value for the area can alternatively be taken from the index of a table (left-hand 4 bits - red arrow)

![3649016](/tcplclib_tc2_mdp/1033/Images/png/2182113931__Web.png)

The parameter "nModule" is NOT an input parameter. The module address (=ModuleID) determined by the function block is assigned to it after it has determined the desired module instance.

"nTableId" corresponds to the right-hand 4 bits of the table index (yellow arrow).

"Subindex" is the number of the entry in the table (blue arrow).

The "eModuleType" parameter specifies the type of the module. There is also an enumeration for the module type that can be used for better readability of the program:

![32841145](/tcplclib_tc2_mdp/1033/Images/png/2182117131__Web.png)

Alternatively the value can also be taken from the module description and entered directly.

## Structure of the state machine

The states of the state machine are defined via enumeration values in a DUT and can thus be adapted or extended centrally and easily.

![27134857](/tcplclib_tc2_mdp/1033/Images/png/2199057035__Web.png)

## Functional areas of the state machine

![42887128](/tcplclib_tc2_mdp/1033/Images/png/2199060363__Web.png)

## Input and output parameters of the sample program

![50439840](/tcplclib_tc2_mdp/1033/Images/png/2199062795__Web.png)![51305376](/tcplclib_tc2_mdp/1033/Images/png/2199064459__Web.png)![59095202](/tcplclib_tc2_mdp/1033/Images/png/2199066123__Web.png)

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
