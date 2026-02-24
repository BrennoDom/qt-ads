# E_TcPlcBufferedCmdType_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. E\_TcPlcBufferedCmdType\_BkPlcMc

# E\_TcPlcBufferedCmdType\_BkPlcMc

The constants in this list are used to identify buffered axis commands. See [MC\_BufferMode\_BkPlcMc](ms-xhelp:///?Id=beckhoff-627d-413d-9066-b092a4bae445).

```
TYPE E_TcPlcBufferedCmdType_BkPlcMc : (  
(* last modification: xx.xx.2009 *)  
iBufferedCmd_NoOperation,  
iBufferedCmd_MoveAbsolute,  
iBufferedCmd_MoveRelative,  
iBufferedCmd_MoveVelocity,  
(**)  
iBufferedCmd_Stop,  
iBufferedCmd_ResetAndStop,  
iBufferedCmd_Halt,  
iBufferedCmd_CamIn,  
iBufferedCmd_GearIn,  
iBufferedCmd_Power,  
iBufferedCmd_Home,  
iBufferedCmd_StepAbsSwitch,  
iBufferedCmd_StepLimitSwitch,  
iBufferedCmd_StepBlock,  
iBufferedCmd_StepDirect,  
iBufferedCmd_FinishHoming,  
(**)  
iBufferedCmdEx_Jerk:=100,  
iBufferedCmdEx_Acc,  
iBufferedCmdEx_Velo,  
iBufferedCmdEx_Creep,  
(**)  
iBufferedCmd_  
);  
END_TYPE
```

**iBufferedCmd\_NoOperation**: This constant is used as initial value for call parameters of function blocks and in variables.

**iBufferedCmd\_MoveAbsolute**: The cached command was entered by an MC\_MoveAbsolute\_BkPlcMc block. See note #1.

**iBufferedCmd\_MoveRelative**: The cached command was entered by an MC\_MoveRelative\_BkPlcMc block. See note #1.

**iBufferedCmd\_MoveVelocity**: The cached command was entered by an MC\_MoveVelocity\_BkPlcMc block. See note #1.

**iBufferedCmd\_Stop**: reserved, not implemented.

**iBufferedCmd\_ResetAndStop**: reserved, not implemented.

**iBufferedCmd\_Halt**: reserved, not implemented.

**iBufferedCmd\_CamIn**: reserved, not implemented.

**iBufferedCmd\_GearIn**: reserved, not implemented.

**iBufferedCmd\_Power**: reserved, not implemented.

**iBufferedCmd\_Home**: reserved, not implemented.

**iBufferedCmd\_StepAbsSwitch**: reserved, not implemented.

**iBufferedCmd\_StepLimitSwitch**: reserved, not implemented.

**iBufferedCmd\_StepBlock**: reserved, not implemented.

**iBufferedCmd\_StepDirect**: reserved, not implemented.

**iBufferedCmd\_FinishHoming**: reserved, not implemented.

**iBufferedCmdEx\_Jerk**: The command component associated with constant-jerk motion was entered by a function block. See note #2.

**iBufferedCmdEx\_Acc**: The command component associated with constant acceleration or deceleration was entered by a function block. See note #2.

**iBufferedCmdEx\_Velo**: The command component associated with constant-velocity motion was entered by a function block. See note #2.

**iBufferedCmdEx\_Creep**: reserved, not implemented.

|  |  |
| --- | --- |
| 14620318 | #1 If the axis uses a set value generator type without look-ahead, complete commands are entered as a buffer element. |

|  |  |
| --- | --- |
| 64473998 | #2 If the axis uses a set value generator type with look-ahead, commands are split into sections and entered as a package typically consisting of seven buffer elements (jerk, acceleration, jerk, velocity, jerk, deceleration, jerk). |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
