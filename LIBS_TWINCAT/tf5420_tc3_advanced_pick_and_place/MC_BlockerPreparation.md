# MC_BlockerPreparation

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_BlockerPreparation

![16323738](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8823262347__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 12695920 | 47154420 | 21736599 |

This function block appends a blocking job to the list of segments in the PathData structure. The PathData table can be executed via MC\_MovePath. The function block MC\_BlockerPreparation can be called several times per cycle. A maximum of 30 entries are allowed per PathData table.

A blocking job is an entry that suspends execution of the path until it is resolved with [MC\_ReleaseBlocker](ms-xhelp:///?Id=beckhoff-1b37-4ab1-a1ec-67adc9e2ef62). As long as the blocker is not resolved, the execution of the path is stopped at this segment. Each blocker has an Id so that the individual blockers can be distinguished in the PLC.

When a blocking job is active, the group status is still "moving".  
If the override is changed while the blocking job is active, it will take effect for the next moving job.  
If a new job with BufferMode mcAborting is executed while the blocking job is active, the blocking job is aborted.  
If [MC\_GroupHalt](ms-xhelp:///?Id=beckhoff-9eba-4f7f-92c4-29ed75daabd6) or [MC\_GroupStop](ms-xhelp:///?Id=beckhoff-a918-4761-908a-7e5bf8151565) are executed while the blocking job is active, the path is terminated and the blocking job is automatically released.

## 61411666 VAR\_INPUT

```
VAR_INPUT  
    BlockerId      : UDINT;  
    BufferMode     : MC_BUFFER_MODE  := mcBuffered;  
    InvokeId       : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| BlockerId | UDINT | Id of the blocker. Can be any UDINT >0. |
| BufferMode | MC\_BUFFER\_MODE | Defines how successive motion commands are to be processed (see [MC\_BUFFER\_MODE](ms-xhelp:///?Id=beckhoff-c38c-47ca-b279-280774eefed0)). Only mcBuffered and mcAborting are allowed here. |
| InvokeId | UDINT | Segment ID for analysis purposes. |

## 15834086 8289053 VAR\_IN\_OUT

```
VAR_IN_OUT  
    PathData       : MC_PATH_DATA_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| PathData | MC\_PATH\_DATA\_REF | Table containing the segments of a path. The table is written by the Preparation function blocks, like this one, and executed by MC\_MovePath (see MC\_PATH\_DATA\_REF). |

## 7492614 VAR\_OUTPUT

```
VAR_OUTPUT  
    Error          : BOOL;  
    ErrorId        : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Error | BOOL | This output becomes TRUE if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the[ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38)or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT V3.1.4024.7  TF5400 Advanced Motion Pack V3.1.10.1 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
