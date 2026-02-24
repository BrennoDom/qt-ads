# FB_WritePersistentData

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_WritePersistentData

![48735027](/tcplclib_tc2_utilities/1033/Images/png/9007199290344075__Web.png)

The function block FB\_WritePersistentData is an extended version of the [WritePersistentData](ms-xhelp:///?Id=beckhoff-1774-419f-81e7-bff0bfa2ac30) function block. The [system behavior for writing the persistent data](ms-xhelp:///?Id=beckhoff-7dbf-469d-9b3d-bb346f7d2cc4) (data consistency/task cycle time overrun) can be influenced via the MODE parameter.

## VAR\_INPUT

```
VAR_INPUT  
    NETID   : T_AmsNetId;  
    PORT    : UINT;  
    START   : BOOL;  
    TMOUT   : TIME := DEFAULT_ADS_TIMEOUT;  
    MODE    : E_PersistentMode;  
END_VAR
```

**NETID**: This parameter can be used to specify the AmsNetID of the TwinCAT computer whose persistent data are to be saved (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**PORT**: The PORT parameter specifies the runtime system whose persistent data is to be stored.

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

**MODE** : Mode in which the persistent data are to be written (type: [E\_PersistentMode](ms-xhelp:///?Id=beckhoff-d922-4389-8eb8-82fb561e5965)).

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY   : BOOL;  
    ERR    : BOOL;  
    ERRID  : UDINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

**Example:**

See: [Writing of persistent data: system behavior.](ms-xhelp:///?Id=beckhoff-7dbf-469d-9b3d-bb346f7d2cc4)

See: [Example in the documentation for the WritePersistentData function block.](ms-xhelp:///?Id=beckhoff-1774-419f-81e7-bff0bfa2ac30)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
