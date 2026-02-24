# FB_CoEAX8000BrakeTest

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_CoEAX8000BrakeTest

FB\_CoEAX8000BrakeTest Execute  BOOLSucceeded  BOOLTorque  LREALVelocityLimit  LREALTimeout  TIME↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUDINT  ErrorID

The function block FB\_CoEAX8000BrakeTest can be used to implement a functional brake test.

This function block is used to switch the AX8000 to torque mode. The torque parameterized at the input is transmitted to the drive as a setpoint. The torque is held until the "Timeout" has elapsed or a feedback ("Succeeded") is sent to the function block. This feedback is typically sent from the safety controller to the PLC. The AX8000 is then set to the original operation mode.

If the brake was not closed before the FB\_CoEAX8000BrakeTest was called, or if the brake does not hold the required test torque, then the speed limitation integrated in the AX8000 prevents uncontrolled acceleration of the axis. The velocity limit is parameterized via the "VelocityLimit" variable.

Information about necessary changes in the configuration of the AX8000 can be found in the [AX8000 | Multi-axis servo system functional description](https://download.beckhoff.com/download/document/motion/ax8000_funktionsbeschreibung_en.pdf).

## 21145081 Inputs

```
VAR_INPUT  
    Execute : BOOL;  
    Succeeded : BOOL;  
    Torque : LREAL;  
    VelocityLimit : LREAL;  
    Timeout : TIME  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | The function block is enabled via a positive edge at this input. |
| Succeeded | BOOL | Feedback that the brake has held the specified torque. This feedback usually comes from the safety controller. |
| Torque | LREAL | Torque that should be effective. |
| VelocityLimit | LREAL | Velocity limit to prevent uncontrolled acceleration in torque mode. |
| Timeout | TIME | Maximum time for which the specified torque is effective. |

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   Axis : AXIS_REF;  
END_VAR
```

**Axis**: The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other things it contains the current status of the axis such as the position, the velocity and the error state.

## 56088004 Outputs

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
