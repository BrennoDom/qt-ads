# MC_AxUtiUpdateRegDriveTerm_BkPlcMc (from V3.0.7)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Parameter](ms-xhelp:///?Id=beckhoff-b417-4e0c-b473-d1906e164f8c)
4. MC\_AxUtiUpdateRegDriveTerm\_BkPlcMc (from V3.0.7)

# MC\_AxUtiUpdateRegDriveTerm\_BkPlcMc (from V3.0.7)

![24632334](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854885515__Web.gif)

The function block writes a parameter set into the registers of a KL terminal. It uses [MC\_AxUtiReadRegDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6cad-4416-a595-99af3f7e4d4d) and [MC\_AxUtiWriteRegDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-278e-4ad1-9a74-c27725e3bc65) function blocks for this purpose.

```
VAR_INPUT  
    Execute:        BOOL;  
END_VAR
```

```
VAR_OUTPUT  
    Done:           BOOL;  
    Busy:           BOOL;  
    CommandAborted: BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
    RegData:        ST_TcPlcRegDataTable;  
END_VAR
```

**Execute**: The writing process is initiated by a rising edge at this input.

**RegData**: Here, the address of parameter set should be specified, whose content is to be written into the terminal.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

**Done**: Indicates successful writing of the parameter.

**Busy**: Indicates that a command is being processed.

**CommandAborted**: Indicates abortion of the read operation.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

## Behavior of the function block:

The function block is activated by a rising edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If one of the pointers [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) and [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) is not initialized, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdPtrPlcMc.
* If the axis is enabled for operation, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.
* If **Select** is outside the permitted range of 0 to 63, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdTblIllegalIndex.
* If an I/O module, which does not support parameter communication, is set as nDrive\_Type in the axis parameters, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdNotCompatible.
* The value in [ST\_TcPlcRegDataTable](ms-xhelp:///?Id=beckhoff-0216-4cca-a486-a37a23eb2ef4).RegDataItem[...].**Access** determines how the element is treated.

+ 0: Element is ignored.
+ 1: The register addressed through **Select** is read. Its contents are compared with **RegData**. **If the contents differ, the write operation is aborted with Error** and **ErrorID**:=16#FFFFFFFF.
+ 2: The register addressed through **Select** is read. Its contents are compared with **RegData**. If the contents are not larger, the write operation is aborted with **Error** and **ErrorID**:=16#FFFFFFFF.
+ 3: The register addressed through **Select** is read. Its contents are compared with **RegData**. If the contents are not smaller, the write operation is aborted with **Error** and **ErrorID**:=16#FFFFFFFF.
+ 4: The register addressed through **Select** is read. Its contents are compared with **RegData**. If the contents are not larger or equal, the write operation is aborted with **Error** and **ErrorID**:=16#FFFFFFFF.
+ 5: The register addressed through **Select** is read. Its contents are compared with **RegData**. If the contents are not smaller or equal, the write operation is aborted with **Error** and **ErrorID**:=16#FFFFFFFF.
+ 10: The register addressed through **Select** is written with **RegData**.
+ Other values are currently ignored. Future versions of the library may support additional functions. An empty element should therefore always be identified with 0.

A falling edge at **Execute** clears all the pending output signals. If **Execute** is set to FALSE while the writing process is still active, the process that had started continues unaffected. The signals at the end of the operation (**Done, CommandAborted, Error**, **ErrorID**) are issued for one cycle.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
