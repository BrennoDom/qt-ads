# Tag Details

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine Tags](ms-xhelp:///?Id=beckhoff-0c75-4616-a6ff-b521c2c6af13)
3. Tag Details

# Tag Details

The following section provides an overview of the tags. Command, state and administration PackTags are listed in the following tables.

## **Command structure PMLc**

|  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
|  |  |  |  |  | **Tag Name** | **Data Type** |
| PMLc |  |  |  |  | PMLc | ST\_PMLc |
|  | UnitMode |  |  |  | PMLc.UnitMode | DINT |
|  | UnitModeChangeRequest |  |  |  | PMLc.UnitModeChangeRequest | BOOL |
|  | MachSpeed |  |  |  | PMLc.MachSpeed | REAL |
|  | MaterialInterlock |  |  |  | PMLc.MaterialInterlock | DINT |
|  | CntrlCmd |  |  |  | PMLc.CntrlCmd | DINT |
|  | CmdChangeRequest |  |  |  | PMLc.CmdChangeRequest | BOOL |
|  | RemoteInterface[#] |  |  |  | PMLc.RemoteInterface[#] | ST\_Interface |
|  |  | Number |  |  | PMLc.RemoteInterface[#] | DINT |
|  |  | ControlCmdNumber |  |  | PMLc.RemoteInterface[#] | DINT |
|  |  | CmdValue |  |  | PMLc.RemoteInterface[#] | DINT |
|  |  | Parameter[#] |  |  | PMLc.RemoteInterface[#].Parameter[#] | ST\_Descriptor |
|  |  |  | Id |  | PMLc.RemoteInterface[#].Parameter[#].Id | DINT |
|  |  |  | Name |  | PMLc.RemoteInterface[#].Parameter[#].Name | STRING |
|  |  |  | Unit |  | PMLc.RemoteInterface[#].Parameter[#].Unit | STRING(5) |
|  |  |  | Value |  | PMLc.RemoteInterface[#].Parameter[#].Value | REAL |
|  | Parameter[#] |  |  |  | PMLc.Parameter[#] | ST\_Descriptor |
|  |  | Id |  |  | PMLc..Parameter[#].Id | DINT |
|  |  | Name |  |  | PMLc..Parameter[#].Name | STRING |
|  |  | Unit |  |  | PMLc..Parameter[#].Unit | STRING(5) |
|  |  | Value |  |  | PMLc..Parameter[#].Value | REAL |
|  | Product[#] |  |  |  | PMLc.Product[#] | ST\_Product |
|  |  | ProductId |  |  | PMLc.Product[#] | DINT |
|  |  | ProcessVariables[#] |  |  | PMLc.Product[#].ProcessVariables[#] | ST\_Descriptor |
|  |  |  | Id |  | PMLc.Product[#].ProcessVariables[#].Id | DINT |
|  |  |  | Name |  | PMLc.Product[#].ProcessVariables[#].Name | STRING |
|  |  |  | Unit |  | PMLc.Product[#].ProcessVariables[#].Unit | STRING(5) |
|  |  |  | Value |  | PMLc.Product[#].ProcessVariables[#].Value | REAL |
|  |  | Ingredients[#] |  |  | PMLc.Product[#].Ingredients[#] | ST\_Ingredient |
|  |  |  | IngredientId |  | PMLc.Product[#].Ingredients[#].IngredientId | DINT |
|  |  |  | Parameter[#] |  | PMLc.Product[#].Ingredients[#].Parameter[#] | ST\_Descriptor |
|  |  |  |  | Id | PMLc.Product[#].Ingredients[#].Parameter[#].Id | DINT |
|  |  |  |  | Name | PMLc.Product[#].Ingredients[#].Parameter[#].Name | STRING |
|  |  |  |  | Unit | PMLc.Product[#].Ingredients[#].Parameter[#].Unit | STRING(5) |
|  |  |  |  | Value | PMLc.Product[#].Ingredients[#].Parameter[#].Value | REAL |

## State structure PMLs

|  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
|  |  |  |  |  | **Tag Name** | **Data Type** |
| PMLs |  |  |  |  | PMLs | ST\_PMLs |
|  | UnitModeCurrent |  |  |  | PMLs.UnitModeCurrent | DINT |
|  | UnitModeRequested |  |  |  | PMLs.UnitModerequested | DINT |
|  | UnitModeChangeInProcess |  |  |  | PMLs.UnitModeChangeInProcess | BOOL |
|  | StateCurrent |  |  |  | PMLs.StateCurrent | DINT |
|  | StateRequested |  |  |  | PMLs.StateRequested | DINT |
|  | StateChangeInProcess |  |  |  | PMLs.StateChangeInProcess | BOOL |
|  | MachineSpeed |  |  |  | PMLs.MachineSpeed | REAL |
|  | CurMachineSpeed |  |  |  | PMLs.CurMachineSpeed | REAL |
|  | MaterialInterlock |  |  |  | PMLs.MaterialInterlock | DINT |
|  | EquipmentInterlock |  |  |  | PMLs.EquipmentInterlock | ST\_Equipment |
|  |  | Blocked |  |  | PMLs.EquipmentInterlock.Blocked | BOOL |
|  |  | Starved |  |  | PMLs.EquipmentInterlock.Starved | BOOL |
|  | RemoteInterface[#] |  |  |  | PMLs.RemoteInterface[#] | ST\_Interface |
|  |  | Number |  |  | PMLs.RemoteInterface[#] | DINT |
|  |  | ControlCmdNumber |  |  | PMLs.RemoteInterface[#] | DINT |
|  |  | CmdValue |  |  | PMLs.RemoteInterface[#] | DINT |
|  |  | Parameter[#] |  |  | PMLs.RemoteInterface[#].Parameter[#] | ST\_Descriptor |
|  |  |  | Id |  | PMLs.RemoteInterface[#].Parameter[#].Id | DINT |
|  |  |  | Name |  | PMLs.RemoteInterface[#].Parameter[#].Name | STRING |
|  |  |  | Unit |  | PMLs.RemoteInterface[#].Parameter[#].Unit | STRING(5) |
|  |  |  | Value |  | PMLs.RemoteInterface[#].Parameter[#].Value | REAL |
|  | Parameter[#] |  |  |  | PMLs.Parameter[#] | ST\_Descriptor |
|  |  | Id |  |  | PMLs..Parameter[#].Id | DINT |
|  |  | Name |  |  | PMLs..Parameter[#].Name | STRING |
|  |  | Unit |  |  | PMLs..Parameter[#].Unit | STRING(5) |
|  |  | Value |  |  | PMLs..Parameter[#].Value | REAL |
|  | Product[#] |  |  |  | PMLc.Product[#] | ST\_Product |
|  |  | ProductId |  |  | PMLc.Product[#] | DINT |
|  |  | ProcessVariables[#] |  |  | PMLc.Product[#].ProcessVariables[#] | ST\_Descriptor |
|  |  |  | Id |  | PMLc.Product[#].ProcessVariables[#].Id | DINT |
|  |  |  | Name |  | PMLc.Product[#].ProcessVariables[#].Name | STRING |
|  |  |  | Unit |  | PMLc.Product[#].ProcessVariables[#].Unit | STRING(5) |
|  |  |  | Value |  | PMLc.Product[#].ProcessVariables[#].Value | REAL |
|  |  | Ingredients[#] |  |  | PMLc.Product[#].Ingredients[#] | ST\_Ingredient |
|  |  |  | IngredientId |  | PMLc.Product[#].Ingredients[#].IngredientId | DINT |
|  |  |  | Parameter[#] |  | PMLc.Product[#].Ingredients[#].Parameter[#] | ST\_Descriptor |
|  |  |  |  | Id | PMLc.Product[#].Ingredients[#].Parameter[#].Id | DINT |
|  |  |  |  | Name | PMLc.Product[#].Ingredients[#].Parameter[#].Name | STRING |
|  |  |  |  | Unit | PMLc.Product[#].Ingredients[#].Parameter[#].Unit | STRING(5) |
|  |  |  |  | Value | PMLc.Product[#].Ingredients[#].Parameter[#].Value | REAL |

## PMLa administration structure

|  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
|  |  |  |  |  | **Tag Name** | **Data Type** |
| PMLa |  |  |  |  | Admin | ST\_PMLa |
|  | Parameter[#] |  |  |  | PMLa.Parameter[#] | ST\_Descriptor |
|  |  | Id |  |  | PMLa..Parameter[#].Id | DINT |
|  |  | Name |  |  | PMLa..Parameter[#].Name | STRING |
|  |  | Unit |  |  | PMLa..Parameter[#].Unit | STRING(5) |
|  |  | Value |  |  | PMLa..Parameter[#].Value | REAL |
|  | Alarm[#] |  |  |  | PMLa.Alarm[#] | ST\_Alarm |
|  |  | Trigger |  |  | PMLa.Alarm[#].Trigger | BOOL |
|  |  | Id |  |  | PMLa.Alarm[#].Id | DINT |
|  |  | Value |  |  | PMLa.Alarm[#].Value | DINT |
|  |  | Message |  |  | PMLa.Alarm[#].Message | STRING |
|  |  | Category |  |  | PMLa.Alarm[#].Category | DINT |
|  |  | DateTime |  |  | PMLa.Alarm[#].DateTime | ARRAY [0..6] OF DINT |
|  |  |  | Year |  | PMLa.Alarm[#].DateTime[0] | DINT |
|  |  |  | Month |  | PMLa.Alarm[#].DateTime[1] | DINT |
|  |  |  | Day |  | PMLa.Alarm[#].DateTime.[2] | DINT |
|  |  |  | Hour |  | PMLa.Alarm[#].DateTime[3] | DINT |
|  |  |  | Minute |  | PMLa.Alarm[#].DateTime[4] | DINT |
|  |  |  | Second |  | PMLa.Alarm[#].DateTime[5] | DINT |
|  |  |  | mSec |  | PMLa.Alarm[#].DateTime[6] | DINT |
|  |  | AckDateTime |  |  | PMLa.Alarm[#].AckDateTime | ARRAY [0..6] OF DINT |
|  |  |  | Year |  | PMLa.Alarm[#].AckDateTime[0] | DINT |
|  |  |  | Month |  | PMLa.Alarm[#].AckDateTime[1] | DINT |
|  |  |  | Day |  | PMLa.Alarm[#].AckDateTime[2] | DINT |
|  |  |  | Hour |  | PMLa.Alarm[#].AckDateTime[3] | DINT |
|  |  |  | Minute |  | PMLa.Alarm[#].AckDateTime[4] | DINT |
|  |  |  | Second |  | PMLa.Alarm[#].AckDateTime[5] | DINT |
|  |  |  | mSec |  | PMLa.Alarm[#].AckDateTime[6] | DINT |
|  | AlarmExtent |  |  |  | PMLa.AlarmExtent | DINT |
|  | AlarmHistory[#] |  |  |  | PMLa.AlarmHistory[#] | ST\_Alarm |
|  |  | Trigger |  |  | PMLa.AlarmHistory[#].Trigger | BOOL |
|  |  | Id |  |  | PMLa.AlarmHistory[#].Id | DINT |
|  |  | Value |  |  | PMLa.AlarmHistory[#].Value | DINT |
|  |  | Message |  |  | PMLa.AlarmHistory[#].Message | STRING |
|  |  | Category |  |  | PMLa.AlarmHistory[#].Category | DINT |
|  |  | DateTime |  |  | PMLa.AlarmHistory[#].DateTime | ARRAY [0..6] OF DINT |
|  |  |  | Year |  | PMLa.AlarmHistory[#].DateTime[0] | DINT |
|  |  |  | Month |  | PMLa.AlarmHistory[#].DateTime[1] | DINT |
|  |  |  | Day |  | PMLa.AlarmHistory[#].DateTime[2] | DINT |
|  |  |  | Hour |  | PMLa.AlarmHistory[#].DateTime[3] | DINT |
|  |  |  | Minute |  | PMLa.AlarmHistory[#].DateTime[4] | DINT |
|  |  |  | Second |  | PMLa.AlarmHistory[#].DateTime[5] | DINT |
|  |  |  | mSec |  | PMLa.AlarmHistory[#].DateTime[6] | DINT |
|  |  | AckDateTime |  |  | PMLa.AlarmHistory[#].AckDateTime | ARRAY [0..6] OF DINT |
|  |  |  | Year |  | PMLa.AlarmHistory[#].AckDateTime[0] | DINT |
|  |  |  | Month |  | PMLa.AlarmHistory[#].AckDateTime[1] | DINT |
|  |  |  | Day |  | PMLa.AlarmHistory[#].AckDateTime[2] | DINT |
|  |  |  | Hour |  | PMLa.AlarmHistory[#].AckDateTime[3] | DINT |
|  |  |  | Minute |  | PMLa.AlarmHistory[#].AckDateTime[4] | DINT |
|  |  |  | Second |  | PMLa.AlarmHistory[#].AckDateTime[5] | DINT |
|  |  |  | mSec |  | PMLa.AlarmHistory[#].AckDateTime[6] | DINT |
|  | AlarmHistoryExtent |  |  |  | PMLa.AlarmHistoryExtent | DINT |
|  | StopReason[#] |  |  |  | PMLa.StopReason[#] | ST\_Alarm |
|  |  | Trigger |  |  | PMLa.StopReason[#].Trigger | BOOL |
|  |  | Id |  |  | PMLa.StopReason[#].Id | DINT |
|  |  | Value |  |  | PMLa.StopReason[#].Value | DINT |
|  |  | Message |  |  | PMLa.StopReason[#].Message | STRING |
|  |  | Category |  |  | PMLa.StopReason[#].Category | DINT |
|  |  | DateTime |  |  | PMLa.StopReason[#].DateTime | ARRAY [0..6] OF DINT |
|  |  |  | Year |  | PMLa.StopReason[#].DateTime[0] | DINT |
|  |  |  | Month |  | PMLa.StopReason[#].DateTime[1] | DINT |
|  |  |  | Day |  | PMLa.StopReason[#].DateTime[2] | DINT |
|  |  |  | Hour |  | PMLa.StopReason[#].DateTime[3] | DINT |
|  |  |  | Minute |  | PMLa.StopReason[#].DateTime[4] | DINT |
|  |  |  | Second |  | PMLa.StopReason[#].DateTime[5] | DINT |
|  |  |  | mSec |  | PMLa.StopReason[#].DateTime[6] | DINT |
|  |  | AckDateTime |  |  | PMLa.StopReason[#].AckDateTime | ARRAY [0..6] OF DINT |
|  |  |  | Year |  | PMLa.StopReason[#].AckDateTime[0] | DINT |
|  |  |  | Month |  | PMLa.StopReason[#].AckDateTime[1] | DINT |
|  |  |  | Day |  | PMLa.StopReason[#].AckDateTime[2] | DINT |
|  |  |  | Hour |  | PMLa.StopReason[#].AckDateTime[3] | DINT |
|  |  |  | Minute |  | PMLa.StopReason[#].AckDateTime[4] | DINT |
|  |  |  | Second |  | PMLa.StopReason[#].AckDateTime[5] | DINT |
|  |  |  | mSec |  | PMLa.StopReason[#].AckDateTime[6] | DINT |
|  | StopReasonExtent |  |  |  | PMLa.StopReasonExtent | DINT |
|  | Warning[#] |  |  |  | PMLa.Warning[#] | ST\_Alarm |
|  |  | Trigger |  |  | PMLa.Warning [#].Trigger | BOOL |
|  |  | Id |  |  | PMLa.Warning[#].Id | DINT |
|  |  | Value |  |  | PMLa.Warning[#].Value | DINT |
|  |  | Message |  |  | PMLa.Warning[#].Message | STRING |
|  |  | Category |  |  | PMLa.Warning[#].Category | DINT |
|  |  | DateTime |  |  | PMLa.Warning[#].DateTime | ARRAY [0..6] OF DINT |
|  |  |  | Year |  | PMLa.Warning[#].DateTime[0] | DINT |
|  |  |  | Month |  | PMLa.Warning[#].DateTime[1] | DINT |
|  |  |  | Day |  | PMLa.Warning[#].DateTime[2] | DINT |
|  |  |  | Hour |  | PMLa.Warning[#].DateTime[3] | DINT |
|  |  |  | Minute |  | PMLa.Warning[#].DateTime[4] | DINT |
|  |  |  | Second |  | PMLa.Warning[#].DateTime[5] | DINT |
|  |  |  | mSec |  | PMLa.Warning[#].DateTime[6] | DINT |
|  |  | AckDateTime |  |  | PMLa.Warning[#].AckDateTime | ARRAY [0..6] OF DINT |
|  |  |  | Year |  | PMLa.Warning[#].AckDateTime[0] | DINT |
|  |  |  | Month |  | PMLa.Warning[#].AckDateTime[1] | DINT |
|  |  |  | Day |  | PMLa.Warning[#].AckDateTime[2] | DINT |
|  |  |  | Hour |  | PMLa.Warning[#].AckDateTime[3] | DINT |
|  |  |  | Minute |  | PMLa.Warning[#].AckDateTime[4] | DINT |
|  |  |  | Second |  | PMLa.Warning[#].AckDateTime[5] | DINT |
|  |  |  | mSec |  | PMLa.Warning[#].AckDateTime[6] | DINT |
|  | WarningExtent |  |  |  | PMLa.WarningExtent | DINT |
|  | ModeCurrentTime[#] |  |  |  | PMLa.ModeCurrentTime[#] | DINT |
|  | ModeCummulativeTime[#] |  |  |  | PMLa.ModeCummulativeTime[#] | DINT |
|  | StateCurrentTime[#,#] |  |  |  | PMLa.StateCurrentTime[#,#] | DINT |
|  | StateCummulativeTime[#,#] |  |  |  | PMLa.StateCummulativeTime[#,#] | DINT |
|  | ProdConsumedCount[#] |  |  |  | PMLa.ProdConsumedCount[#] |  |
|  |  | Id |  |  | PMLa.ProdConsumedCount[#].Id | DINT |
|  |  | Name |  |  | PMLa.ProdConsumedCount[#].Name | STRING |
|  |  | Unit |  |  | PMLa.ProdConsumedCount[#].Unit | STRING(5) |
|  |  | Count |  |  | PMLa.ProdConsumedCount[#].Count | DINT |
|  |  | AccCount |  |  | PMLa.ProdConsumedCount[#].AccCount | DINT |
|  | ProdProcessedCount[#] |  |  |  | PMLa.ProdProcessedCount[#] |  |
|  |  | Id |  |  | PMLa.ProdProcessedCount[#].Id | DINT |
|  |  | Name |  |  | PMLa.ProdProcessedCount[#].Name | STRING |
|  |  | Unit |  |  | PMLa.ProdProcessedCount[#].Unit | STRING(5) |
|  |  | Count |  |  | PMLa.ProdProcessedCount[#].Count | DINT |
|  |  | AccCount |  |  | PMLa.ProdProcessedCount[#].AccCount | DINT |
|  | ProdDefectiveCount[#] |  |  |  | PMLa.ProdDefectiveCount[#] |  |
|  |  | Id |  |  | PMLa.ProdDefectiveCount[#].Id | DINT |
|  |  | Name |  |  | PMLa.ProdDefectiveCount[#].Name | STRING |
|  |  | Unit |  |  | PMLa.ProdDefectiveCount[#].Unit | STRING(5) |
|  |  | Count |  |  | PMLa.ProdDefectiveCount[#].Count | DINT |
|  |  | AccCount |  |  | PMLa.ProdDefectiveCount[#].AccCount | DINT |
|  | AccTimeSinceReset |  |  |  | PMLa.AccTimeSinceReset | DINT |
|  | MachDesignSpeed |  |  |  | PMLa.MachDesignSpeed | REAL |
|  | StatesDisabled |  |  |  | PMLa.StatesDisabled | DINT |
|  | PlcDateTime |  |  |  | PMLa.PlcDateTime | ARRAY [0..6] OF DINT |
|  |  | Year |  |  | PMLa.PlcDateTime[0] | DINT |
|  |  | Month |  |  | PMLa.PlcDateTime[1] | DINT |
|  |  | Day |  |  | PMLa.PlcDateTime[2] | DINT |
|  |  | Hour |  |  | PMLa.PlcDateTime[3] | DINT |
|  |  | Minute |  |  | PMLa.PlcDateTime[4] | DINT |
|  |  | Second |  |  | PMLa.PlcDateTime[5] | DINT |
|  |  | mSec |  |  | PMLa.PlcDateTime[6] | DINT |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
