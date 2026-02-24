# FB_MDP_Device_Read_DevName

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-23a0-4133-855a-a7677f5f17f9)
3. [Specific](ms-xhelp:///?Id=beckhoff-f154-4692-ab80-393af7db6a55)
4. FB\_MDP\_Device\_Read\_DevName

# FB\_MDP\_Device\_Read\_DevName

![33115615](/tcplclib_tc2_mdp/1033/Images/gif/178806283__en-US__Web.gif)

The function block enables the device name to be queried. This information can be found in the [general area of the IPC diagnostics](https://infosys.beckhoff.com/content/1033/devicemanager/36028797281945355.html).

## VAR\_INPUT

```
VAR_INPUT  
    bExecute  : BOOL;           (* Function block execution is triggered by a rising edge at this input.*)  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT; (* States the time before the function is cancelled. *)  
    sAmsNetId : T_AmsNetId;     (* keep empty '' for the local device *)  
END_VAR
```

**bExecute**: The function block is called by a rising edge on the input *bExecute*, if the block is not already active.

**tTimeout**: Specifies a maximum length of time for the execution of the function block.

**sAmsNetId**: To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrID   : UDINT;  
    sDevName : T_MaxString;  
END_VAR
```

**bBusy**: This output is TRUE as long as the function block is active.

**bError**: Becomes TRUE as soon as an error situation occurs.

**nErrID**: Returns an [error code](ms-xhelp:///?Id=beckhoff-dcf9-45e5-b79d-97610e81bb4a) if the bError output is set.

**sDevName**: The queried name is output as a string at this output.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
