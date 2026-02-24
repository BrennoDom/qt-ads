# MC_GearOut_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_GearOut\_BkPlcMc (from V3.0)

# MC\_GearOut\_BkPlcMc (from V3.0)

![29507743](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854712843__Web.gif)

The function block releases a coupling between two axes. This coupling must have been established with an [MC\_GearIn\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4041-4933-b290-4cbdc9cd7d51) or an [MC\_GearInPos\_BkPlcMc](ms-xhelp:///?Id=beckhoff-cc38-448a-9d02-eed0b69f60f4) function block.

```
VAR_INPUT  
    Execute:        BOOL;  
END_VAR
```

```
VAR_OUTPUT  
    Busy:           BOOL;  
    Done:           BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
END_VAR
```

```
VAR_INOUT  
    Slave:          Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: A rising edge at this input releases the coupling.

**Busy**: Indicates that a command is being processed.

**Done**: Successful processing of the movement is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Slave**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block:

The function block is activated by a rising edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If the axis is not operated in a gear coupling, the function block immediately indicates **Done** and omits all further checks or activities.
* If the current set velocity of the axis is smaller than the velocity specified by pStAxParams.fCreepSpeed, the axis immediately assumes McState\_Standstill and dissipates the residual velocity. **Done** is indicated, and no further checks or activities take place.

If these checks could be performed without problem and **Done** is not already indicated for one of the reasons mentioned, the motion controlled by the gear coupling is converted to a continuous motion with the same velocity and direction, which is independent of the master. **Done** is indicated if this conversion was executed successfully, otherwise the system responds with **Error** and **ErrorID**:=error code.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
