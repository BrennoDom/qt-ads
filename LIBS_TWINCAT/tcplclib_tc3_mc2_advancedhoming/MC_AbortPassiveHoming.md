# MC_AbortPassiveHoming

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_AbortPassiveHoming

![25805135](/tcplclib_tc3_mc2_advancedhoming/1033/Images/png/1962498187__Web.png)

## 30919631 Inputs

```
VAR_INPUT  
    Execute : BOOL;  
    Options : ST_Home_Options;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | The command is executed with a rising edge at Execute input. |
| Options | ST\_Home\_Options | Currently not used. |

## 9841225 Outputs

```
VAR_OUTPUT  
    Done           : BOOL;  
    Busy           : BOOL;  
    Active         : BOOL;  
    CommandAborted : BOOL;  
    Error          : BOOL;  
    ErrorID        : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Done | BOOL | Becomes TRUE, if the command was completed successfully. |
| Busy | BOOL | The Busy output becomes TRUE when the command is started with Execute and remains TRUE as long as the command is processed. If Busy becomes FALSE again, the function block is ready for a new order. At the same time one of the outputs, Done, CommandAborted or Error, is set. |
| Active | BOOL | Indicates that the command is executed. |
| CommandAborted | BOOL | Becomes TRUE, if the command could not be fully executed. |
| Error | BOOL | Becomes TRUE, as soon as an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number. |

## 21462168 Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Axis | AXIS\_REF | Axis data structure of the type AXIS\_REF, which uniquely addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. |
