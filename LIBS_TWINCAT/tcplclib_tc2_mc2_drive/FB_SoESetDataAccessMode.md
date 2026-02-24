# FB_SoESetDataAccessMode

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoESetDataAccessMode

FB\_SoESetDataAccessMode Execute  BOOLMode  E\_SoEDataAccessModeBOOL  BusyBOOL  ErrorUINT  ErrId

The SoE parameter access mode is set with the function block FB\_SoESetDataAccessMode. Attributes & Value are accessed in parallel by default. If this access mode is not supported by the device manufacturer, sequential access can be enforced. Generally, however, parallel access is faster.

## VAR\_INPUT

```
VAR_INPUT  
    Execute : BOOL;  
    Mode    : E_SoEDataAccessMode := E_SoEDataAccessMode.eSoEDataAccessMode_Parallel;  
END_VAR
```

**Execute**: The function block is enabled via a positive edge at this input.

**Mode**: Defines the access mode.

## VAR\_OUTPUT

```
VAR_OUTPUT  
   Busy     :  BOOL;  
   Error    :  BOOL;  
   ErrId    :  UINT;  
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until a feedback is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**ErrId**: In the event of a set error output returns the ADS error code.
