# FB_BasicPID

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_BasicPID

![27990155](/tcplclib_tc2_utilities/1033/Images/png/9007199290190475__Web.png)

The function block is a simple discretized PID element.

## Transfer function:

![50584809](/tcplclib_tc2_utilities/1033/Images/gif/35452683__en-US__Web.gif)

## Action diagram:

![52610097](/tcplclib_tc2_utilities/1033/Images/gif/35455883__en-US__Web.gif)

## VAR\_INPUT

```
VAR_INPUT  
    fSetpointValue : LREAL; (* setpoint value *)  
    fActualValue   : LREAL; (* actual value *)  
    bReset         : BOOL;  
    fCtrlCycleTime : LREAL; (* controller cycle time in seconds [s] *)  
    fKp            : LREAL; (* proportional gain Kp (P) *)  
    fTn            : LREAL; (* integral gain Tn (I) [s] *)  
    fTv            : LREAL; (* derivative gain Tv (D-T1) [s] *)  
    fTd            : LREAL; (* derivative damping time Td (D-T1) [s] *)  
END_VAR
```

**fSetpointValue** : Set value of the controlled variable.

**fActualValue** : Actual value of the controlled variable.

**bReset**: TRUE at this input resets the internal state variables and the controller output.

**fCtrlCycleTime**: Cycle time with which the function block is called and with which the control loop is processed [s].

Here you **must** specify the cycle time of the PLC task, if the block is to be called in each PLC cycle,

otherwise the required multiple of the PLC task cycle time.

**fKp**  : Controller amplification / controller coefficient

**fTn**  : Integral action time [s]

**fTv**  : Rate time [s]

**fTd**  : Damping time [s]

## VAR\_OUTPUT

```
VAR_OUTPUT  
    fCtrlOutput  : LREAL;  
    nErrorStatus : UINT  
END_VAR
```

**fCtrlOutput** : Output of the PID-element.

**nErrorStatus**: Indicates the error number in the event of an error (nErrorStatus <> 0).

**Error Codes:**

| Value | Constant | Error description |
| --- | --- | --- |
| 0 | **nERR\_NOERROR** | No error |
| 1 | **nERR\_INVALIDPARAM** | Invalid parameter |
| 2 | **nERR\_INVALIDCYCLETIME** | Invalid cycle time. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
