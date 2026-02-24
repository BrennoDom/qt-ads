# FB_SoEAX5000ParkAxis

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEAX5000ParkAxis

FB\_SoEAX5000ParkAxis Execute  BOOLMode  E\_AX5000ParkMode↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUDINT  ErrorId

This function block enables the parking functionality of an AX5000. A parked channel of an AX5000 is temporarily disabled.

In the case of a modular machine concept, certain motors may not be available. So that this does not lead directly to errors (e.g. feedback errors), the channels can be deactivated via this.

## 57246722 Inputs

```
VAR_INPUT  
    Execute : BOOL;  
    Mode : E_AX5000ParkMode  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | The function block is enabled via a positive edge at this input. |
| Mode | [E\_AX5000ParkMode](ms-xhelp:///?Id=beckhoff-a1a5-4670-a3c1-594658b4e139) | Mode for selecting whether the FB parks or releases the axis. |

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   Axis : AXIS_REF;  
END_VAR
```

**Axis**: The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other things it contains the current status of the axis such as the position, the velocity and the error state.

## 45458457 Outputs

```
VAR_OUTPUT  
    Busy : BOOL;  
    Error : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Busy | BOOL | This output is set when the function block is activated, and remains set until a feedback is received. |
| Error | BOOL | This output is set after the Busy output has been reset when an error occurs in the transmission of the command. |
| ErrorID | UDINT | In the event of a set error output returns the ADS error code. |

## Requirements

| Development environment | Target platform type | PLC libraries to include | Firmware version | Revision |
| --- | --- | --- | --- | --- |
| TwinCAT ≥ 4022.32  TwinCAT ≥ 4024.6 | PC or CX (x86 or x64) | Tc2\_MC2\_Drive ≥V3.3.21.0 |  |  |
