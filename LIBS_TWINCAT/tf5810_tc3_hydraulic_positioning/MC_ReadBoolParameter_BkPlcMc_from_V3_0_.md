# MC_ReadBoolParameter_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_ReadBoolParameter\_BkPlcMc (from V3.0)

# MC\_ReadBoolParameter\_BkPlcMc (from V3.0)

![14387121](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854659339__Web.gif)

This function block reads the boolean parameters of an axis. The function block [MC\_ReadParameter\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f72f-4a3c-9ffa-5adf447fe918) is available for non-boolean parameters.

```
VAR_INPUT  
    Enable:             BOOL;  
    ParameterNumber:    INT;  
END_VAR
```

```
VAR_OUTPUT  
    Busy:               BOOL;  
    Done:               BOOL;  
    Error:              BOOL;  
    ErrorID:            UDINT;  
    Value:              BOOL;  
END_VAR
```

```
VAR_INOUT  
    Axis:               Axis_Ref_BkPlcMc;  
END_VAR
```

**Enable**: A reading process is initiated by a rising edge at this input.

**ParameterNumber**: This code number specifies the parameter that is to be read. Only named constants from [E\_TcMCParameter](ms-xhelp:///?Id=beckhoff-ea11-4506-b969-56d5e1515b02) should be used.

**Busy**: Indicates that a command is being processed.

**Done**: Successful execution of the reading process is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Value**: The value of the parameter is made available here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block:

The function block is activated by a rising edge at **Enable**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If an unsupported value is given to **ParameterNumber** the function block responds with **Error** and **ErrorID**:=dwTcHydErrCdNotSupport.

The desired parameter value is made available at **Value**, and **Done** is asserted if these checks can be carried out without problems.

A falling edge at **Enable** clears all the pending output signals.

|  |  |
| --- | --- |
| 62375226 | This function block requires no time for executing its tasks. The output Busy will never assume the value TRUE and only exists for compatibility reasons. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
