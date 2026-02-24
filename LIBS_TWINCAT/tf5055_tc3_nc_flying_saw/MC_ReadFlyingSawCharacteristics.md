# MC_ReadFlyingSawCharacteristics

## Library
tf5055_tc3_nc_flying_saw

## Category
Motion Control

1. [TF5055 TC3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
2. [Flying saw](ms-xhelp:///?Id=beckhoff-0f55-447a-861e-cd3f87251e76)
3. MC\_ReadFlyingSawCharacteristics

# MC\_ReadFlyingSawCharacteristics

MC\_ReadFlyingSawCharacteristics Execute  BOOL↔Slave  Reference To AXIS\_REF↔CamTableCharac  Reference To MC\_FlyingSawCharacValuesBOOL  DoneBOOL  BusyBOOL  ErrorUDINT  ErrorID

The *MC\_ReadFlyingSawCharacteristics* function allows the characteristic figures for the synchronization phase of the Universal Flying Saw to be read.

## Inputs

```
VAR_INPUT  
    Execute : BOOL;  
END_VAR
```

**Execute**: A rising edge initiates reading the characteristic values from the TwinCAT NC. **Notice**: The data calculated is not available until the Universal Flying Saw starts.

## Outputs

```
VAR_OUTPUT  
    Done    : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

**Done**: Is set to TRUE when the data record has been successfully read.

**Busy:** The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs, *Done* or *Error*, is set.

**Error**: Becomes TRUE, as soon as an error occurs.

**ErrorID**: If the error output is set, this parameter supplies the error number

## Inputs/outputs

```
VAR_IN_OUT  
    Slave          : AXIS_REF;  
    CamTableCharac : MC_FlyingSawCharacValues;  
END_VAR
```

**Slave**: Axis structure of the slave.

**CamTableCharac:** Structure containing the [characteristic values](ms-xhelp:///?Id=beckhoff-5cb9-4d89-aef0-e46fe87b569d).

The axis data structure of type AXIS\_REF addresses an axis uniquely within the system. Among other parameters it contains the current axis status, including position, velocity or error status.

[TF5055 | TwinCAT 3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
