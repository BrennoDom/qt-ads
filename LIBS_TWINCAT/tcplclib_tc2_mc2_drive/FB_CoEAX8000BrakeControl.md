# FB_CoEAX8000BrakeControl

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_CoEAX8000BrakeControl

FB\_CoEAX8000BrakeControl Execute  BOOLMode  E\_AX8000BrakeMode↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUDINT  ErrorID

This function block can be used to manually open or close the brake of a motor that is operated on an AX8000.

It should be noted that the brake is permanently closed or opened via "Lock" or "Unlock".

It is recommended to open or close the brake manually only for the necessary duration. The brake should then be set back to "Automatic" mode using the function block.

## 58256364 Inputs

```
VAR_INPUT  
    Execute : BOOL;  
    Mode : E_AX8000BrakeMode;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | The function block is enabled via a positive edge at this input. |
| Mode | [E\_AX8000BrakeMode](ms-xhelp:///?Id=beckhoff-b332-4300-8b5e-cbe31ecd3711) | The mode with which the brake is controlled. |

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   Axis : AXIS_REF;  
END_VAR
```

**Axis**: The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other things it contains the current status of the axis such as the position, the velocity and the error state.

## 54545236 Outputs

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
| TwinCAT ≥ 4022.36  TwinCAT ≥ 4024.15 | PC or CX (x86 or x64) | Tc2\_MC2\_Drive ≥V3.3.23.0 |  |  |
