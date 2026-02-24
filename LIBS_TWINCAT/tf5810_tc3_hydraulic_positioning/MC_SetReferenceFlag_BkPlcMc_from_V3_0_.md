# MC_SetReferenceFlag_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_SetReferenceFlag\_BkPlcMc (from V3.0)

# MC\_SetReferenceFlag\_BkPlcMc (from V3.0)

![26487069](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854681227__Web.gif)

(Function is not defined by PLCopen) The function block defines the referencing flag of the axis.

```
VAR_INPUT  
    Execute:        BOOL;  
    ReferenceFlag:  BOOL;  
END_VAR
```

```
VAR_OUTPUT  
    Done:       BOOL;  
    Busy:       BOOL;  
    Error:      BOOL;  
    ErrorID:    UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: A rising edge at this input sets the referencing flag of the axis.

**ReferenceFlag**: The new state of the referencing flag of the axis.

**Done**: This indicates successful processing of the command.

**Busy**: This output TRUE while the command is being processed.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block:

A rising edge at **Execute** causes the referencing flag in [ST\_TcHydAxRtData.nStateDWord](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) to be updated. To this end, the respective bit is cleared or set with dwTcHydNsDwReferenced, depending on **ReferenceFlag**. The successful execution of the function is indicated with **Done**. A falling edge at **Execute** clears all the pending output signals.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
