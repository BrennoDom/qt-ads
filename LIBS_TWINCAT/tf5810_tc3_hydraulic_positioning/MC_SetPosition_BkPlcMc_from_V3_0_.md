# MC_SetPosition_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_SetPosition\_BkPlcMc (from V3.0)

# MC\_SetPosition\_BkPlcMc (from V3.0)

![25182135](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854678795__Web.gif)

The function block sets the actual position of an axis.

```
VAR_INPUT  
    Execute:    BOOL;  
    Position:   LREAL;  
    Mode:       BOOL;  
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

**Execute**: A positive edge at this input sets the actual position of the axis.

**Position**: [mm] The new actual position of the axis.

**Mode**: This parameter specifies the operating mode. If **Mode** = TRUE, the actual position is changed by **Position**, if **Mode** = FALSE, the actual position is set to **Position.**

**Done**: This indicates successful processing of the command.

**Busy**: This output is TRUE while the command is being processed.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block is activated by a positive edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* Depending on the encoder type specified in **Axis.pStAxParams^.nEnc\_Type**, either ST\_TcHydAxRtData.fEnc\_RefShift or ST\_TcHydAxParam.fEnc\_ZeroShift is updated such that the actual position of the axis assumes the required value. If the encoder types is unknown or the encoder does not permit the actual value to be set, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdEncType.
* If ST\_TcHydAxParam.fEnc\_ZeroShift changes recognizable during this process, [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).[ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).bParamsUnsave is set.

|  |  |
| --- | --- |
| 25312629 | This function block may cause the actual position and/or the target position of the currently processed motion to be moved after an active software limit switch. This is not monitored by the function block. |

If these checks could be performed without problem, all other affected elements in ST\_TcHydAxRtData are automatically updated. This function block can therefore also be activated for axes, which perform an active motion. The successful execution of the function is indicated with **Done**. A negative edge at **Execute** clears all the pending output signals.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
