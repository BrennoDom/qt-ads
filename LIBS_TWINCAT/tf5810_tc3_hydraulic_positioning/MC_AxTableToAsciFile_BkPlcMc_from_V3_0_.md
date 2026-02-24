# MC_AxTableToAsciFile_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [TableFunctions](ms-xhelp:///?Id=beckhoff-978e-49e7-b056-ee4189e74a33)
5. MC\_AxTableToAsciFile\_BkPlcMc (from V3.0)

# MC\_AxTableToAsciFile\_BkPlcMc (from V3.0)

![37356392](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854773643__Web.gif)

The function block writes the contents of a table to a text file.

```
VAR_INPUT  
    Execute:    BOOL:=FALSE;  
    pTable:     POINTER TO LREAL:=0;  
    LowIdx:     INT:=0;  
    HighIdx:    INT:=0;  
    FileName:   STRING(255):='';  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
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

**Execute**: The writing process is initiated by a rising edge at this input.

**pTable**: This parameter is used to transfer the address of an ARRAY[nFirstIdx..nLastIdx.1..2].

**LowIdx**: This parameter is used to transfer the lower index of the ARRAY, whose address is transferred as **pTable**.

**HighIdx**: This parameter is used to transfer the upper index of the ARRAY, whose address is transferred as **pTable**.

**FileName**: This parameter can be used to specify a file name.

**Busy**: Indicates that a command is being processed.

**Done**: Successful processing of the reference travel is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block

A rising edge at **Execute** causes the function block to examine the transferred parameters. A number of problems can be detected and reported during this process:

* If **LowIdx** is negative, the system responds with **Error** and **ErrorID**=dwTcHydErrCdTblEntryCount.
* If **pTable**=0, the system responds with **Error** and **ErrorID**=dwTcHydErrCdTblEntryCount.
* If **LowIdx** and **HighIdx** describe a table with fewer than five rows, the system responds with **Error** and **ErrorID**=dwTcHydErrCdTblEntryCount.

If these checks were performed without problems, the write operation is started. **Busy** is TRUE for the duration of the operation. This can lead to some further problems, which are indicated by various error codes. Successful writing of the file is indicated with **Done**.

A falling edge at **Execute** clears all the pending output signals. If **Execute** is set to FALSE while the operation is still active, the initiated operation continues unaffected. The signals at the end of the operation (**Error**, **ErrorID, Done**) apply for one cycle.

If a **FileName** is specified, it must be complete (including the drive letter and the path, if applicable, always including the file type), since it is used by function block without any further modification or amendment.

If no **FileName** is specified, the function block uses the path and the file name, which were specified through the [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) function block. File type TXT is used here, to distinguish from the parameter file with file type DAT.

|  |  |
| --- | --- |
| 663215 | The file contents can be read or modified with an ASCII editor. Changes of the content can make correct reading or the intended use impossible or change the effect of the table in a way that is difficult to trace. Manual changes should therefore be implemented very carefully, if at all, and only by competent persons. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
