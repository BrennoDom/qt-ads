# MC_Power

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-290a-4455-9df4-a3a3057c631c)
3. [Axis functions](ms-xhelp:///?Id=beckhoff-cb3e-4c30-994c-476bbe2bf879)
4. MC\_Power

# MC\_Power

![53754023](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/8873666059__Web.png)

MC\_Power activates software enable for an axis. At Status output operational readiness of the axis is indicated.

|  |  |
| --- | --- |
| 14024165 | In addition to software enable it may be necessary to activate a hardware enable signal in order to enable a drive. This signal is not influenced by MC\_Power and must be activated separately by the PLC. |

## Inputs

```
VAR_INPUT  
    Enable          : BOOL;  
END_VAR
```

**Enable:** General software enable for the axis.

## Outputs

```
VAR_OUTPUT  
    Status  : BOOL;  
    Busy    : BOOL;  
    Active  : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

**Status:** TRUE when the axis is ready for operation.

**Busy:** TRUE, as long as the function block is called with Enable = TRUE.

**Active:** Indicates that the command is executed.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-1610-445d-9b44-15a5aa4e120c))

## Requirements

| Development environment | PLC libraries to include |
| --- | --- |
| TwinCAT 3.1.4024.11 | Tc3\_DriveMotionControl |

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
