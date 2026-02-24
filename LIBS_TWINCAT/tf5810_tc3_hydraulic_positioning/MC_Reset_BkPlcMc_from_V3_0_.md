# MC_Reset_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_Reset\_BkPlcMc (from V3.0)

# MC\_Reset\_BkPlcMc (from V3.0)

![33762549](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854669067__Web.gif)

The function block eliminates an error state and puts the axis in an operational state.

```
VAR_INPUT  
    Execute:    BOOL;  
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

**Execute**: An axis reset is initiated by a rising edge at this input.

**Busy**: Indicates that a command is being processed.

**Done**: Successful execution of the axis reset is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block:

A rising edge at **Execute** triggers an axis reset. This puts the axis in an operational state, as far as possible, and **Done** is reported. If this is not possible, the function block reacts with **Error** and **ErrorID**:= the ErrorCode of the axis.

A falling edge at **Execute** clears all the pending output signals.

|  |  |
| --- | --- |
| 35427485 | In some drive types, signal exchange with an external device is required, in order to rectify certain errors. During the time required for this, the function block is unable to report a final result (Done or Error). Instead, Busy is used to indicate that the function is in progress. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
