# MC_BufferMode_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. MC\_BufferMode\_BkPlcMc (from V3.0)

# MC\_BufferMode\_BkPlcMc (from V3.0)

The constants in this list are used for controlling blending according to PLC Open.

```
TYPE MC_BufferMode_BkPlcMc :  
(  
Aborting_BkPlcMc := 0,  
Buffered_BkPlcMc,  
BlendingLow_BkPlcMc,  
BlendingPrevious_BkPlcMc,  
BlendingNext_BkPlcMc,  
BlendingHigh_BkPlcMc  
);  
END_TYPE
```

**Aborting\_BkPlcMc**: The default case: The new command becomes active immediately and cancels any other command that may already be active. The function block monitoring the aborted command will respond with **CommandAborted**.

**Buffered\_BkPlcMc**: For axes with command buffer: This command is started automatically once all previous commands have been fully processed.

**BlendingLow\_BkPlcMc**: For axes with command buffer: This command follows the previous command without intermediate stop. If possible, the transition point is passed with the lower velocity of the commands involved.

**BlendingPrevious\_BkPlcMc**: For axes with command buffer: This command follows the previous command without intermediate stop. If possible, the transition point is passed with the commanded velocity of the previous command.

**BlendingNext\_BkPlcMc**: For axes with command buffer: This command follows the previous command without intermediate stop. If possible, the transition point is passed with the commanded velocity of the new command.

**BlendingHigh\_BkPlcMc**: For axes with command buffer: This command follows the previous command without intermediate stop. If possible, the transition point is passed with the higher velocity of the commands involved.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
