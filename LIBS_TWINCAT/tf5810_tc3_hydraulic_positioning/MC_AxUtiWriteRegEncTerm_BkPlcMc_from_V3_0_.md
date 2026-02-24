# MC_AxUtiWriteRegEncTerm_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Parameter](ms-xhelp:///?Id=beckhoff-b417-4e0c-b473-d1906e164f8c)
4. MC\_AxUtiWriteRegEncTerm\_BkPlcMc (from V3.0)

# MC\_AxUtiWriteRegEncTerm\_BkPlcMc (from V3.0)

![41882373](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854895243__Web.gif)

The function block writes the contents of a register of the KL terminal, which is used as encoder interface for the axis.

```
VAR_INPUT  
    Execute:        BOOL;  
    Select:         INT;  
    RegData:        WORD;  
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

**Select**: The register number should be transferred here.

**RegData**: The value to be written should be transferred here.

**Busy**: Indicates that a command is being processed.

**Done**: Indicates successful writing of the parameter.

**CommandAborted**: Indicates abortion of the read operation.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block

The function block is activated by a rising edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If one of the pointers [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) and [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) is not initialised, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdPtrPlcMc.
* If the axis is enabled for operation, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.
* If **Select** is outside the permitted range of 0 to 63, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdTblIllegalIndex.
* If an I/O module, which does not support parameter communication, is set as nEncoder\_Type in the axis parameters, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdNotCompatible.

The writing process begins if these checks are carried out without problems.

A falling edge at **Execute** clears all the pending output signals. If **Execute** is set to FALSE while the writing process is still active, the process that had started continues unaffected. The signals at the end of the operation (**RegData, Done, CommandAborted, Error**, **ErrorID, Done**) are issued for one cycle.

|  |  |
| --- | --- |
| 41397042 | The drive types iTcMc\_EncoderKL3002, iTcMc\_EncoderKL3042, iTcMc\_EncoderKL3062, iTcMc\_EncoderKL3162, iTcMc\_EncoderKL5101, iTcMc\_EncoderKL5111, iTcMc\_EncoderKL2521, iTcMc\_EncoderKL2531 und iTcMc\_EncoderKL2541 support parameter communication. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
