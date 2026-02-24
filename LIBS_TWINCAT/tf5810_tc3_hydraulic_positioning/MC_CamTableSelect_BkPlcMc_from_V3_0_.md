# MC_CamTableSelect_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_CamTableSelect\_BkPlcMc (from V3.0)

# MC\_CamTableSelect\_BkPlcMc (from V3.0)

![57865663](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854695819__Web.gif)

The function block initializes a variable of type [MC\_CAM\_ID\_BkPlcMc](ms-xhelp:///?Id=beckhoff-c699-42ea-8202-bcc2f3dbf8c5), thereby preparing a cam plate for the coupling of two axes.

```
VAR_INPUT  
    Execute:            BOOL;  
    Periodic:           BOOL;  
    MasterAbsolute:     BOOL;  
    SlaveAbsolute:      BOOL;  
ND_VAR
```

```
VAR_OUTPUT  
    Busy:               BOOL;  
    Done:               BOOL;  
    Error:              BOOL;  
    ErrorID:            UDINT;  
    CamTableId:         MC_CAM_ID_BkPlcMc;  
END_VAR
```

```
VAR_INOUT  
    Master:             Axis_Ref_BkPlcMc;  
    Slave:              Axis_Ref_BkPlcMc;  
    CamTable:           MC_CAM_REF_BkPlcMc;  
END_VAR
```

**Execute**: A rising edge at this input starts the command.

**Periodic**: Not supported: FALSE should be transferred at present.

**MasterAbsolute**: Not supported: TRUE should be transferred at present.

**SlaveAbsolute**: Not supported: TRUE should be transferred at present.

**Busy**: Indicates that a command is being processed.

**Done**: This indicates successful initialization of CamTableId.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**CamTableId**: Returns a variable of type [MC\_CAM\_ID\_BkPlcMc](ms-xhelp:///?Id=beckhoff-c699-42ea-8202-bcc2f3dbf8c5), which can be passed on to a function block of type [MC\_CamIn\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f22a-44e5-b98f-a23a18918289).

**Master, Slave**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

**CamTable**: A variable of type [MC\_CAM\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6249-4c3b-aefb-f2fdf2745e46) should be transferred here.

## Behavior of the function block:

The function block is activated by a rising edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If **CamTable**.pTable is not initialized, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdPtrPlcMc.
* If **CamTable**.nLastIdx is not greater than **CamTable**.nFirstIdx, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdTblEntryCount.
* If **CamTable**.nFirstIdx and **CamTable**.nLastIdx define a table with more than 100 rows, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdTblLineCount.
* If **MasterAbsolute** or **SlaveAbsolute** are not set or **Periodic** is set, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdNotSupport.

If these checks could be performed without problem, **CamTableId** is initialized. The data from **CamTable** and the input data of function block are used for this purpose. **CamTableId** is marked as valid and modified. **Done** is used to report execution of the command.

A falling edge at **Execute** clears all the pending output signals.

|  |  |
| --- | --- |
| 51028923 | This function block requires no time for executing its tasks. The output Busy will never assume the value TRUE and only exists for compatibility reasons. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
