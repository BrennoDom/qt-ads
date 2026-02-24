# MC_AxUtiWriteCoeEncTerm_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Parameter](ms-xhelp:///?Id=beckhoff-b417-4e0c-b473-d1906e164f8c)
4. MC\_AxUtiWriteCoeEncTerm\_BkPlcMc (from V3.0)

# MC\_AxUtiWriteCoeEncTerm\_BkPlcMc (from V3.0)

![38905106](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854890379__Web.gif)

The function block writes the contents of a register of the EL terminal, which is used as encoder interface for the axis.

```
VAR_INPUT  
    Execute:        BOOL;  
    Pdata:          POINTER TO BYTE:=0;  
    ByteCount:      BYTE:=0;  
    Index:          WORD:=0;  
    Subindex:       BYTE:=0;  
END_VAR
```

```
VAR_OUTPUT  
    Busy:           BOOL;  
    Done:           BOOL;  
    CommandAborted: BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: The writing process is initiated by a rising edge at this input.

**Pdata**: Here, the address of the variable is specified, whose content is to be written into the terminal.

**ByteCount**: Here, the size of the variable is specified in bytes.

**Index**, **Subindex**: Here, the addressing of parameter in the terminal is specified.

**Busy**: Indicates that a command is being processed.

**Done**: Indicates successful writing of the parameter.

**CommandAborted**: Indicates abortion of the read operation.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block

The function block is activated by a rising edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If the axis is enabled for operation, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.
* If **Index** or **Subindex** are outside the permitted range, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdTblIllegalIndex.
* If **ByteCount** or **Pdata** are outside the permitted range, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdTblIllegalIndex.
* If an I/O module, which does not support parameter communication, is set as nEncoder\_Type in the axis parameters, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdNotCompatible.
* If problems occur during the ADS communication with the terminal, the corresponding ADS error code is returned as **ErrorID**, and **Error** is indicated. The following [codes](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) may occur:

+ 16#0006 = 6 = The port number of the ADS address used is invalid: Check the mapping of the InfoData element of the terminal!
+ 16#0007 = 7 = The AmsNetID of the ADS address used is invalid: 16#0006 = 6 = The port number of the ADS address used is invalid:
+ 16#0702 = 1794 = dwTcHydAdsErrInvalidIdxGroup = The terminal does not support the CoE protocol.
+ 16#0703 = 1795 = dwTcHydAdsErrInvalidIdxOffset = The address in index and subindex is not supported in the terminal.
+ 16#0745 = 1861 = dwTcHydAdsErrTimeout = Timeout.

A falling edge at **Execute** clears all the pending output signals. If **Execute** is set to FALSE while the writing process is still active, the process that had started continues unaffected. The signals at the end of the operation (**Done, CommandAborted, Error**, **ErrorID**) are issued for one cycle.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
