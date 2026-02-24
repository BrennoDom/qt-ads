# MC_AxParamAuxLabelsLoad_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Parameter](ms-xhelp:///?Id=beckhoff-b417-4e0c-b473-d1906e164f8c)
4. MC\_AxParamAuxLabelsLoad\_BkPlcMc (from V3.0)

# MC\_AxParamAuxLabelsLoad\_BkPlcMc (from V3.0)

![10190321](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854868491__Web.gif)

The function block loads the label texts for the customer-specific axis parameters from a file. These texts can be generated with a simple text editor such as Microsoft Notepad.

|  |  |
| --- | --- |
| 24604028 | The file must be structured according to the rules specified below. Otherwise, significant problems may occur, including system crash. |

This function block is generally not called directly by the application. If possible, a function block of type [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) should be used, which uses a function block of type **MC\_AxParamAuxLabelsLoad\_BkPlcMc**.

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

* If one of the pointers has not been initialised the function block reacts with **Error** and with **ErrorID**:=dwTcHydErrCdPtrPlcMc or dwTcHydErrCdPtrMcPlc.

The loading process begins if these checks are carried out without problems.

A falling edge at **Execute** clears all the pending output signals. If **Execute** is set to FALSE while the loading process is still active, the process that had started continues unaffected. The signals provided at the end of the operation (**Error**, **ErrorID, Done**) are made available for one cycle.

|  |  |
| --- | --- |
| 20109663 | The number of rows in the file must match the number specified in the global constants of the library as iTcHydfCustDataMaxIdx (currently: 20). The maximum number of characters in each row is 20 (included spaces, without line breaks). |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
