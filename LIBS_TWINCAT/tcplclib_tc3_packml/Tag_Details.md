# Tag Details

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine Functional Tag Description](ms-xhelp:///?Id=beckhoff-cfa1-4cf2-bed5-de71541a6707)
3. Tag Details

# Tag Details

The following section is a summary listing of the tags. Tables below list the command, status and admin PackTags.

## Command structure PMLc

|  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
|  |  |  |  |  | **Tag Name** | **Data Type** |
| PMLc |  |  |  |  | PMLc | ST\_PMLc |
|  | UnitMode |  |  |  | PMLc.UnitMode | DINT |
|  | UnitModeChangeRequest |  |  |  | PMLc.UnitModeChangeRequest | BOOL |
|  | ProcMode |  |  |  | PMLc.ProcMode | DINT |
|  | ProcModeChangeRequest |  |  |  | PMLc.ProcModeChangeRequest | BOOL |
|  | CurMachSpeed |  |  |  | PMLc.CurMachSpeed | DINT |
|  | MatReady |  |  |  | PMLc.MatReady | ST\_Material |
|  |  | RawMaterial |  |  | PMLc.MatReady.RawMaterial | BOOL |
|  |  | CO2 |  |  | PMLc.MatReady.CO2 | BOOL |
|  |  | Container |  |  | PMLc.MatReady.Container | BOOL |
|  |  | Lubrication |  |  | PMLc.MatReady.Lubrication | BOOL |
|  |  | Water |  |  | PMLc.MatReady.Water | BOOL |
|  |  | ContainerClosures |  |  | PMLc.MatReady.ContainerClosure | BOOL |
|  |  | Unused0 |  |  | PMLc.MatReady.Unused0 | BOOL |
|  |  | Unused1 |  |  | PMLc.MatReady.Unused1 | BOOL |
|  |  | Unused2 |  |  | PMLc.MatReady.Unused2 | BOOL |
|  |  | Unused3 |  |  | PMLc.MatReady.Unused3 | BOOL |
|  |  | Unused4 |  |  | PMLc.MatReady.Unused4 | BOOL |
|  |  | Unused5 |  |  | PMLc.MatReady.Unused5 | BOOL |
|  |  | Unused6 |  |  | PMLc.MatReady.Unused6 | BOOL |
|  |  | Unused7 |  |  | PMLc.MatReady.Unused7 | BOOL |
|  |  | Unused8 |  |  | PMLc.MatReady.Unused8 | BOOL |
|  |  | Unused9 |  |  | PMLc.MatReady.Unused9 | BOOL |
|  | MatLow |  |  |  | PMLc.MatLow | ST\_Material |
|  |  | RawMaterial |  |  | PMLc.MatLow.RawMaterial | BOOL |
|  |  | CO2 |  |  | PMLc.MatLow.CO2 | BOOL |
|  |  | Container |  |  | PMLc.MatLow.Container | BOOL |
|  |  | Lubrication |  |  | PMLc.MatLow.Lubrication | BOOL |
|  |  | Water |  |  | PMLc.MatLow.Water | BOOL |
|  |  | ContainerClosures |  |  | PMLc.MatLow.ContainerClosures | BOOL |
|  |  | Unused0 |  |  | PMLc.MatLow.Unused0 | BOOL |
|  |  | Unused1 |  |  | PMLc.MatLow.Unused1 | BOOL |
|  |  | Unused2 |  |  | PMLc.MatLow.Unused2 | BOOL |
|  |  | Unused3 |  |  | PMLc.MatLow.Unused3 | BOOL |
|  |  | Unused4 |  |  | PMLc.MatLow.Unused4 | BOOL |
|  |  | Unused5 |  |  | PMLc.MatLow.Unused5 | BOOL |
|  |  | Unused6 |  |  | PMLc.MatLow.Unused6 | BOOL |
|  |  | Unused7 |  |  | PMLc.MatLow.Unused7 | BOOL |
|  |  | Unused8 |  |  | PMLc.MatLow.Unused8 | BOOL |
|  |  | Unused9 |  |  | PMLc.MatLow.Unused9 | BOOL |
|  | State |  |  |  | PMLc.State | DINT |
|  | StateChangeRequest |  |  |  | PMLc.StateChangeRequest | BOOL |
|  | CntrlCmd |  |  |  | PMLc.CntrlCmd | DINT |
|  | Node[#] |  |  |  | PMLc.Node[#] | ST\_Node |
|  |  | Number |  |  | PMLc.Node[#].Number | DINT |
|  |  | ControlCmdNumber |  |  | PMLc.Node[#].ControlCmdNumber | DINT |
|  |  | CmdValue |  |  | PMLc.Node[#]CmdValue | DINT |
|  |  | Parameter[#] |  |  | PMLc.Node[#].Parameter[#] | ST\_Descriptor |
|  |  |  | Id |  | PMLc.Node[#].Parameter[#].Id | DINT |
|  |  |  | Name |  | PMLc.Node[#].Parameter[#].Name | STRING |
|  |  |  | Unit |  | PMLc.Node[#].Parameter[#].Unit | STRING |
|  |  |  | Value |  | PMLc.Node[#].Parameter[#].Value | REAL |
|  | ProcessVariables[#] |  |  |  | PMLc.ProcessVariables[#] | ST\_Descriptor |
|  |  | Id |  |  | PMLc.ProcessVariables[#].Id | DINT |
|  |  | Name |  |  | PMLc.ProcessVariables[#].Name | STRING |
|  |  | Unit |  |  | PMLc.ProcessVariables[#].Unit | STRING |
|  |  | Value |  |  | PMLc.ProcessVariables[#].Values | REAL |
|  | Product[#] |  |  |  | PMLc.Product[#] | ST\_Product |
|  |  | ProductId |  |  | PMLc.Product[#].ProductId | DINT |
|  |  | ProcessVariables[#] |  |  | PMLc.Product[#].ProcessVariables[#] | ST\_Descriptor |
|  |  |  | Id |  | PMLc.Product[#].ProcessVariables[#].Id | DINT |
|  |  |  | Name |  | PMLc.Product[#].ProcessVariables[#].Name | STRING |
|  |  |  | Unit |  | PMLc.Product[#].ProcessVariables[#].Unit | STRING |
|  |  |  | Value |  | PMLc.Product[#].ProcessVariables[#].Value | REAL |
|  |  | Ingredients[#] |  |  | PMLc.Product[#].Ingredients[#] | ST\_Ingredient |
|  |  |  | IngredientId |  | PMLc.Product[#].Ingredients[#].IngredientId | DINT |
|  |  |  | Parameter[#] |  | PMLc.Product[#].Ingredients[#].Parameter[#] | ST\_Descriptor |
|  |  |  |  | Id | PMLc.Product[#].Ingredients[#].Parameter[#].Id | DINT |
|  |  |  |  | Name | PMLc.Product[#].Ingredients[#].Parameter[#].Name | STRING |
|  |  |  |  | Unit | PMLc.Product[#].Ingredients[#].Parameter[#].Unit | STRING |
|  |  |  |  | Value | PMLc.Product[#].Ingredients[#].Parameter[#].Value | REAL |
|  | Limits[#] |  |  |  | PMLc.Limits[#] | ST\_Descriptor |
|  |  | Id |  |  | PMLc.Limits[#].Id | DINT |
|  |  | Name |  |  | PMLc.Limits[#].Name | STRING |
|  |  | Unit |  |  | PMLc.Limits[#].Unit | STRING |
|  |  | Value |  |  | PMLc.Limits[#].Value | REAL |
|  | TargetDownstreamNodeID |  |  |  | PMLc.TargetDownstreamNodeId | DINT |
|  | TargetUpstreamNodeID |  |  |  | PMLc.TargetUpstreamNodeId | DINT |
|  | ChangeNodeServicedUpstream |  |  |  | PMLc.ChangeNodeServicedUpstream | DINT |
|  | ChangeNodeServicedDownstream |  |  |  | PMLc.ChangeNodeServicedDownstream | DINT |

## Status structure PMLs

|  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
|  |  |  |  |  | **Tag Name** | **Data Type** |
| PMLs |  |  |  |  | PMLs | ST\_PMLs |
|  | CommandRejected |  |  |  | PMLs.CommandRejected | BOOL |
|  | UnitModeCurrent |  |  |  | PMLs.UnitModeCurrent | DINT |
|  | UnitModeRequested |  |  |  | PMLs.UnitModerequested | DINT |
|  | UnitModeChangeInProcess |  |  |  | PMLs.UnitModeChangeInProcess | BOOL |
|  | ProcModeCurrent |  |  |  | PMLs.ProcModeCurrent | DINT |
|  | ProcModeRequested |  |  |  | PMLs.ProcModeRequested | DINT |
|  | ProcModeChangeInProcess |  |  |  | PMLs.ProcModeChangeInProcess | BOOL |
|  | StateCurrent |  |  |  | PMLs.StateCurrent | DINT |
|  | StateRequested |  |  |  | PMLs.StateRequested | DINT |
|  | StateChangeInProcess |  |  |  | PMLs.StateChangeInProcess | BOOL |
|  | StateChangeProgress |  |  |  | StatusStateChangeProgress | DINT |
|  | StateLastCompleted |  |  |  | PMLs.StateLastCompleted | DINT |
|  | SeqNumber |  |  |  | PMLs.SeqNumber | DINT |
|  | CurMachSpd |  |  |  | PMLs.CurMachSpd | DINT |
|  | MatReady |  |  |  | PMLs.MatReady | ST\_Material |
|  |  | RawMaterial |  |  | PMLs.MatReady.RawMaterial | BOOL |
|  |  | CO2 |  |  | PMLs.MatReady.CO2 | BOOL |
|  |  | Container |  |  | PMLs.MatReady.Container | BOOL |
|  |  | Lubrication |  |  | PMLs.MatReady.Lubrication | BOOL |
|  |  | Water |  |  | PMLs.MatReady.Water | BOOL |
|  |  | ContainerClosures |  |  | PMLs.MatReady.ContainerClosures | BOOL |
|  |  | Unused0 |  |  | PMLs.MatReady.Unused0 | BOOL |
|  |  | Unused1 |  |  | PMLs.MatReady.Unused1 | BOOL |
|  |  | Unused2 |  |  | PMLs.MatReady.Unused2 | BOOL |
|  |  | Unused3 |  |  | PMLs.MatReady.Unused3 | BOOL |
|  |  | Unused4 |  |  | PMLs.MatReady.Unused4 | BOOL |
|  |  | Unused5 |  |  | PMLs.MatReady.Unused5 | BOOL |
|  |  | Unused6 |  |  | PMLs.MatReady.Unused6 | BOOL |
|  |  | Unused7 |  |  | PMLs.MatReady.Unused7 | BOOL |
|  |  | Unused8 |  |  | PMLs.MatReady.Unused8 | BOOL |
|  |  | Unused9 |  |  | PMLs.MatReady.Unused9 | BOOL |
|  | MatLow |  |  |  | PMLs.MatLow | ST\_Material |
|  |  | RawMaterial |  |  | PMLs.MatLow.RawMaterial | BOOL |
|  |  | CO2 |  |  | PMLs.MatLow.CO2 | BOOL |
|  |  | Container |  |  | PMLs.MatLow.Container | BOOL |
|  |  | Lubrication |  |  | PMLs.MatLow.Lubrication | BOOL |
|  |  | Water |  |  | PMLs.MatLow.Water | BOOL |
|  |  | ContainerClosures |  |  | PMLs.MatLow.ContainerClosures | BOOL |
|  |  | Unused0 |  |  | PMLs.MatLow.Unused0 | BOOL |
|  |  | Unused1 |  |  | PMLs.MatLow.Unused1 | BOOL |
|  |  | Unused2 |  |  | PMLs.MatLow.Unused2 | BOOL |
|  |  | Unused3 |  |  | PMLs.MatLow.Unused3 | BOOL |
|  |  | Unused4 |  |  | PMLs.MatLow.Unused4 | BOOL |
|  |  | Unused5 |  |  | PMLs.MatLow.Unused5 | BOOL |
|  |  | Unused6 |  |  | PMLs.MatLow.Unused6 | BOOL |
|  |  | Unused7 |  |  | PMLs.MatLow.Unused7 | BOOL |
|  |  | Unused8 |  |  | PMLs.MatLow.Unused8 | BOOL |
|  |  | Unused9 |  |  | PMLs.MatLow.Unused9 | BOOL |
|  | MachDesignSpeed |  |  |  | PMLs.MachDesignSpeed | REAL |
|  | MachCycle |  |  |  | PMLs.MachCycle | DINT |
|  | ProdRatio |  |  |  | PMLs.ProdRatio | DINT |
|  | Dirty |  |  |  | PMLs.Dirty | BOOL |
|  | Clean |  |  |  | PMLs.Clean | BOOL |
|  | TimeToDirty |  |  |  | PMLs.TimeToDirty | DINT |
|  | EquipmentAllocatedToUnitModelID |  |  |  | PMLs.EquipmentAllocatedToUnitModelID | DINT |
|  | MachineReusableForUnitModelID |  |  |  | PMLs.MachineReusableForUnitModelID | DINT |
|  | MachineReusableTimeLeft |  |  |  | PMLs.MachineReusableTimeLeft | DINT |
|  | MachineStoringProductID |  |  |  | PMLs.MachineStoringProductID | DINT |
|  | MachineTransferringProductID |  |  |  | PMLs.MachineTransferringProductID | DINT |
|  | Node[#] |  |  |  | PMLs.Node[#] | ST\_Node |
|  |  | Number |  |  | PMLs.Node[#].Number | DINT |
|  |  | ControlCmdNumber |  |  | PMLs.Node[#].ControlCmdNumber | DINT |
|  |  | CmdValue |  |  | PMLs.Node[#].CmdValue | DINT |
|  |  | Parameter[#] |  |  | PMLs.Node[#].Parameter[#] | ST\_Descriptor |
|  |  |  | Id |  | PMLs.Node[#].Parameter[#].Id | DINT |
|  |  |  | Name |  | PMLs.Node[#].Parameter[#].Name | STRING |
|  |  |  | Unit |  | PMLs.Node[#].Parameter[#].Unit | STRING |
|  |  |  | Value |  | PMLs.Node[#].Parameter[#].Value | REAL |
|  | ProcessVariables[#] |  |  |  | PMLs.ProcessVariables[#] | ST\_Descriptor |
|  |  | Id |  |  | PMLs.ProcessVariables[#].Id | DINT |
|  |  | Name |  |  | PMLs.ProcessVariables[#].Name | STRING |
|  |  | Unit |  |  | PMLs.ProcessVariables[#].Unit | STRING |
|  |  | Value |  |  | PMLs.ProcessVariables[#].Value | REAL |
|  | Product[#] |  |  |  | PMLs.Product[#] | ST\_Product |
|  |  | ProductId |  |  | PMLs.Product[#].ProductId | DINT |
|  |  | ProcessVariables[#] |  |  | PMLs.Product[#].ProcessVariables[#] | ST\_Descriptor |
|  |  |  | Id |  | PMLs.Product[#].ProcessVariables[#].Id | DINT |
|  |  |  | Name |  | PMLs.Product[#].ProcessVariables[#].Name | STRING |
|  |  |  | Unit |  | PMLs.Product[#].ProcessVariables[#].Unit | STRING |
|  |  |  | Value |  | PMLs.Product[#].ProcessVariables[#].Value | REAL |
|  |  | Ingredients[#] |  |  | PMLs.Product[#].Ingredients[#] | ST\_Ingedient |
|  |  |  | IngredientId |  | PMLs.Product[#].Ingredients[#].IngredientId | DINT |
|  |  |  | Parameter[#] |  | PMLs.Product[#].Ingredients[#].Parameter[#] | ST\_Descriptor |
|  |  |  |  | Id | PMLs.Product[#].Ingredients[#].Parameter[#].Id | DINT |
|  |  |  |  | Name | PMLs.Product[#].Ingredients[#].Parameter[#].Name | STRING |
|  |  |  |  | Unit | PMLs.Product[#].Ingredients[#].Parameter[#].Unit | STRING |
|  |  |  |  | Value | PMLs.Product[#].Ingredients[#].Parameter[#].Value | REAL |
|  | Limits[#] |  |  |  | PMLs.Limits[#] | ST\_Descriptor |
|  |  | Id |  |  | PMLs.Limits[#].Id | DINT |
|  |  | Name |  |  | PMLs.Limits[#].Name | STRING |
|  |  | Unit |  |  | PMLs.Limits[#].Unit | STRING |
|  |  | Value |  |  | PMLs.Limits[#].Value | REAL |

## Admin structure PMLa

|  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
|  |  |  |  |  | **Tag Name** | **Data Type** |
| PMLa |  |  |  |  | Admin | ST\_PMLa |
|  | Alarm[#] |  |  |  | PMLa.Alarm[#] | ST\_Alarm |
|  |  | Id |  |  | PMLa.Alarm[#].Id | DINT |
|  |  | Value |  |  | PMLa.Alarm[#].Value | DINT |
|  |  | Message |  |  | PMLa.Alarm[#].Message | STRING |
|  |  | TimeEvent |  |  | PMLa.Alarm[#].TimeEvent | ST\_TimeStamp |
|  |  |  | Year |  | PMLa.Alarm[#].TimeEvent.Year | DINT |
|  |  |  | Month |  | PMLa.Alarm[#].TimeEvent.Month | DINT |
|  |  |  | Day |  | PMLa.Alarm[#].TimeEvent.Day | DINT |
|  |  |  | Hour |  | PMLa.Alarm[#].TimeEvent.Hour | DINT |
|  |  |  | Minute |  | PMLa.Alarm[#].TimeEvent.Minute | DINT |
|  |  |  | Second |  | PMLa.Alarm[#].TimeEvent.Second | DINT |
|  |  |  | mSec |  | PMLa.Alarm[#].TimeEvent.mSec | DINT |
|  |  | TimeAck |  |  | PMLa.Alarm[#].TimeAck | ST\_TimeStamp |
|  |  |  | Year |  | PMLa.Alarm[#].TimeAck.Year | DINT |
|  |  |  | Month |  | PMLa.Alarm[#].TimeAck.Month | DINT |
|  |  |  | Day |  | PMLa.Alarm[#].TimeAck.Day | DINT |
|  |  |  | Hour |  | PMLa.Alarm[#].TimeAck.Hour | DINT |
|  |  |  | Minute |  | PMLa.Alarm[#].TimeAck.Minute | DINT |
|  |  |  | Second |  | PMLa.Alarm[#].TimeAck.Second | DINT |
|  |  |  | mSec |  | PMLa.Alarm[#].TimeAck.mSec | DINT |
|  | ModeCurrentTime[#] |  |  |  | PMLa.Alarm[#].ModeCurrentTime[#] | DINT |
|  | ModeCummulativeTime[#] |  |  |  | PMLa.Alarm[#].ModeCummulativeTime[#] | DINT |
|  | StateCurrentTime[#,#] |  |  |  | PMLa.Alarm[#].StateCurrentTime[#,#] | DINT |
|  | StateCummulativeTime[#,#] |  |  |  | PMLa.Alarm[#].StateCummulativeTime[#,#] | DINT |
|  | ProdProcessed |  |  |  | PMLa.Alarm[#].ProdProcessed | DINT |
|  | DefectProd |  |  |  | PMLa.Alarm[#].DefectProd | DINT |
|  | ReworkProd |  |  |  | PMLa.Alarm[#].ReworkProd | DINT |
|  | ResetTimersCounters |  |  |  | PMLa.Alarm[#].ResetTimersCounters | DINT |
|  | UpstreamMessage |  |  |  | PMLa.Alarm[#].UpstreamMessage | DINT |
|  | DownstreamMessage |  |  |  | PMLa.Alarm[#].DownStreamMessage | DINT |
|  | CurrentDownstreamNodeID[#] |  |  |  | PMLa.Alarm[#].CurrentDownstreamNodeId[#] | DINT |
|  | CurrentUpstreamNodeID[#] |  |  |  | PMLa.Alarm[#].CurrentUpstreamNodeId[#] | DINT |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
