# MC_ReadDigitalOutput_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_ReadDigitalOutput\_BkPlcMc (from V3.0)

# MC\_ReadDigitalOutput\_BkPlcMc (from V3.0)

![24506125](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854661771__Web.gif)

The function block determines the current state of a digital output of a cam controller.

```
VAR_INPUT  
    Enable:         BOOL;  
    OutputNumber:   INT;  
END_VAR
```

```
VAR_OUTPUT  
    Done:       BOOL;  
    Busy:       BOOL;  
    Error:      BOOL;  
    ErrorID:    UDINT;  
    Value:      BOOL;  
END_VAR
```

```
VAR_INOUT  
    Output:     OUTPUT_REF_BkPlcMc;  
END_VAR
```

**Enable**: A rising edge at this input triggers an update of the state.

**OutputNumber**: The number of the output to be determined.

**Valid**: This indicates successful determination of the state.

**Busy**: This output TRUE while the command is being processed.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Value**: The state of the digital output.

**Output**: Here, the address of a variable of type [OUTPUT\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f9aa-4587-a859-7e05ee8c20f1) should be transferred.

## Behavior of the function block:

If **Enable** is TRUE, the function block checks the transferred parameters. During this process, a problem may be detected and reported:

* If the value of **OutputNumber** is not within the permissible range [0..31], the response is **Error** with **ErrorID**:=dwTcHydErrCdIllegalOutputNumber.

If these checks were carried out without problems, the state of the digital output is determined, and **Valid** is reported.

A falling edge at **Enable** clears all the pending output signals.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
