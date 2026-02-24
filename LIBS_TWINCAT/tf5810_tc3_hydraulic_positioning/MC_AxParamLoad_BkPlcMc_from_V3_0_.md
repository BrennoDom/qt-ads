# MC_AxParamLoad_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Parameter](ms-xhelp:///?Id=beckhoff-b417-4e0c-b473-d1906e164f8c)
4. MC\_AxParamLoad\_BkPlcMc (from V3.0)

# MC\_AxParamLoad\_BkPlcMc (from V3.0)

![46769243](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854870923__Web.gif)

The function block loads the parameters for an axis from a file. A function block of type [MC\_AxParamSave\_BkPlcMc](ms-xhelp:///?Id=beckhoff-aaf6-41ce-bb18-a1a64bda1099) must be used to generate a compatible parameter file.

This function block is generally not called directly by the application. If possible, a function block of type [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) should be used, which uses a function block of type **MC\_AxParamLoad\_BkPlcMc**.

```
VAR_INPUT  
    Execute:        BOOL;  
END_VAR
```

```
VAR_OUTPUT  
    Done:           BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: The loading process is initiated by a rising edge at this input.

**Done**: Successful loading of the parameters is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block

The function block is activated by a rising edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If the file cannot be opened for reading, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdPtrPlcMc or dwTcHydErrCdPtrMcPlc.

The loading process begins if these checks are carried out without problems. The file version is determined, and any parameters that are not specified by the file are replaced with neutral default values. If the file contains parameters that are not used or no longer used, these are ignored.

A falling edge at **Execute** clears all the pending output signals. If **Execute** is set to FALSE while the loading process is still active, the process that had started continues unaffected. The signals provided at the end of the operation (**Error**, **ErrorID, Done**) are made available for one cycle.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
