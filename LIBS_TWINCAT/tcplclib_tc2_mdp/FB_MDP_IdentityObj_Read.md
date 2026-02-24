# FB_MDP_IdentityObj_Read

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-23a0-4133-855a-a7677f5f17f9)
3. [Specific](ms-xhelp:///?Id=beckhoff-f154-4692-ab80-393af7db6a55)
4. FB\_MDP\_IdentityObj\_Read

# FB\_MDP\_IdentityObj\_Read

![29605080](/tcplclib_tc2_mdp/1033/Images/gif/178809483__en-US__Web.gif)

Der Funktionsbaustein ermöglicht die Abfrage der Tabelle IdentityObject der General Area der IPC-Diagnose.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute  : BOOL; (* Function block execution is triggered by a rising edge at this input.*)  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT; (* States the time before the function is cancelled. *)  
    sAmsNetId : T_AmsNetId; (* keep empty '' for the local device *)  
END_VAR
```

**bExecute**: The function block is called by a rising edge on the input *bExecute*, if the block is not already active.

**tTimeout**: Specifies a maximum length of time for the execution of the function block.

**sAmsNetId**: To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy   : BOOL;  
    bError  : BOOL;  
    nErrID  : UDINT;  
    iErrPos : USINT;  
    stMDP_ModuleContent : ST_MDP_IdentityObject;  
END_VAR
```

**bBusy**: This output is TRUE as long as the function block is active.

**bError**: Becomes TRUE as soon as an error situation occurs.

**nErrID**: Returns an [error code](ms-xhelp:///?Id=beckhoff-dcf9-45e5-b79d-97610e81bb4a) if the bError output is set.

**iErrPos**: If an error occurred and this refers to an individual element, then this output indicates the position (subindex of the element) at which an error first occurred.

**stMDP\_ModuleContent**: The information from the table is displayed at this output in the form of the structure [ST\_MDP\_IdentityObject](ms-xhelp:///?Id=beckhoff-5815-4f68-8b1a-1f8fcee0cd33).

Serial number is no longer supported

|  |  |
| --- | --- |
| 65119131 | Outdated parameter leads to error situation  In the Identity Object the serial number of the IPC is read from the MDP General Area. This parameter is obsolete. The parameter is no longer supported for newer Beckhoff IPC devices. This causes the function block to return an error and name the error position (`iErrPos = 4`), which corresponds to the `iSerialNumber` parameter. Alternatively, the serial number can be read from the MDP Device Area. See corresponding [example](ms-xhelp:///?Id=beckhoff-07eb-450f-853d-70aa66ae6ea0). It is recommended to use the PLC library Tc3\_IPCDiag, which is the successor to the PLC library Tc2\_MDP. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
