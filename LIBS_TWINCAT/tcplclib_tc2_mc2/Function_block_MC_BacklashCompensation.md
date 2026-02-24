# Function block MC_BacklashCompensation

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Appendix](ms-xhelp:///?Id=beckhoff-cdf2-455c-a8c9-c0f6b150df73)
3. [NC Backlash Compensation](ms-xhelp:///?Id=beckhoff-67c2-4819-9161-d59c0787cef9)
4. Function block MC\_BacklashCompensation

# Function block MC\_BacklashCompensation

![54391657](/tcplclib_tc2_mc2/1033/Images/png/9749698443__Web.png)

MC\_BacklashCompensation is used together with the axis parameter *Position Correction* for backlash compensation. It is possible to compensate negative as well as positive backlash.

|  |  |
| --- | --- |
| 19762867 | Application Note and Preparing Actions in TwinCAT:    * The functionality described here works with the parameter Position Correction. Therefore this parameter has to be activated in TwinCAT XAE or with ADS (see [TC3 NC PTP Axes](ms-xhelp:///?Id=beckhoff-6a15-4f4e-a76b-505364b54959)). The function backlash compensation in XAE remains merely for compatibility issues. Do not use them within new projects.  * If the user wants to use the function Position Correction for other purposes in addition to MC\_BacklashCompensation (whose implementation bases on the function Position Correction), this can be achieved with the PLC by inputting the sum of both requirements to the function block MC\_PositionCorrectionLimiter. |

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis                         : AXIS_REF;  
END_VAR
```

**Axis:** The input Axis exhibits AXIS\_REF type and refers to an axis (see [AXIS\_REF](ms-xhelp:///?Id=beckhoff-1610-445d-9b44-15a5aa4e120c)).

## VAR\_INPUT

```
VAR_INPUT  
    Enable                       : BOOL;     
    Backlash                     : LREAL;   
    CompensationInPositiveDirection  : BOOL;   
    Ramp                         : LREAL;   
    DisableMode                  : E_DisableMode;   
    Options                      : ST_BacklashCompensationOptions;   
END_VAR
```

**Enable:** Switch to activate backlash compensation.

**Backlash:** Signed backlash value [mm]. When using default value, the internal nc backlash value will be read by ADS and used in this FB.

**CompensationInPositiveDirection:** Compensation is just working in the selected working direction; FALSE (default): Backlash compensation must be done when driving in negative direction; TRUE: Backlash compensation must be done when driving in positive direction.

**Ramp:** Velocity limit for feeded backlash compensation (constant velocity and linear position sub profile for backlash compensation) [mm/s].

**DisableMode:** (0)=HOLD, (1)=RESET

**Options:** Optional parameters (NOT USED YET)

## VAR\_OUTPUT

```
VAR_OUTPUT      
    Enabled                      : BOOL;   
    Busy                         : BOOL;   
    Error                        : BOOL;  
    ErrorId                      : UDINT;  
    CurrentBacklash              : LREAL;   
    Limiting                     : BOOL;   
END_VAR
```

**Enabled:** This output becomes TRUE, when backlash compensation was activated without errors.

**Busy:** This output becomes TRUE, when the command is started with Execute as long as the function block is executing the command. When Busy becomes FALSE again, the function block is ready for a new command.

**Error:** This output becomes TRUE if an error occurs as the command is executed.

**ErrorId:** Contains the command-specific error code of the most recently executed command.

**CurrentBacklash:** Current actual backlash value [mm].

**Limiting:** This output becomes TRUE if the function block is currently limiting the backlash correction.

## TYPE E\_DisableMode:

```
(  
    DisableModeHold         :=0, (* hold on the last output value (default) *)  
    DisableModeReset        :=1 (* reset the output value to zero (jump to zero) *)  
(*DisableModeRamp           :=2 *) (* ramp down the output to zero (NOT NEEDED YET) *)  
);  
END_TYPE
```

## Requirements

| Development Environment | Target System Type | PLC Libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
