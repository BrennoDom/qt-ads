# MC_WriteBoolParameter_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_WriteBoolParameter\_BkPlcMc (from V3.0)

# MC\_WriteBoolParameter\_BkPlcMc (from V3.0)

![37057034](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854683659__Web.gif)

This function block writes the boolean parameters of an axis. The [MC\_WriteParameter\_BkPlcMc](ms-xhelp:///?Id=beckhoff-37ac-4014-b387-f8451c1ea86a) function block is available for non-boolean parameters.

```
VAR_INPUT  
    Enable:             BOOL;  
    ParameterNumber:    INT;  
    Value:              BOOL;  
END_VAR
```

```
VAR_OUTPUT  
    Busy:       BOOL;  
    Done:       BOOL;  
    Error:      BOOL;  
    ErrorID:    UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Enable**: A write process is initiated by a rising edge at this input.

**ParameterNumber**: This code number specifies the parameter that is to be read. Only named constants from [E\_TcMCParameter](ms-xhelp:///?Id=beckhoff-ea11-4506-b969-56d5e1515b02) should be used.

**Value**: The value of the parameter is to be provided here.

**Busy**: Indicates that a command is being processed.

**Done**: Successful execution of the writing process is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block:

The function block is activated by a rising edge at **Enable**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If an unsupported value is given to **ParameterNumber** the function block responds with **Error** and **ErrorID**:=dwTcHydErrCdNotSupport.

If these checks could be performed without problems, **Value** is entered in the required parameter value, and **Done** is reported. If the parameter is changed during this process, [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).[ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).bParamsUnsave is set.

A falling edge at **Enable** clears all the pending output signals.

|  |  |
| --- | --- |
| 65077851 | This function block requires no time for executing its tasks. The output Busy will never assume the value TRUE and only exists for compatibility reasons. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
