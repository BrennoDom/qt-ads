# MC_DwellTimePreparation

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_DwellTimePreparation

![39390935](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8823264267__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 18974100 | 36549175 | 60507121 |

This function block appends a standstill job with a defined time to the table of segments in the PathData structure. The PathData table can be executed via MC\_MovePath. The function block MC\_DwellTimePreparation can be called several times per cycle.

## 7693179 VAR\_INPUT

```
VAR_INPUT  
    DwellTime      : Time;  
    BufferMode     : MC_BUFFER_MODE  := mcBuffered;  
    InvokeId       : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| DwellTime | Time | Time during which the path is stationary at velocity 0. Any timespan >= 0 is allowed. A DwellTime of zero leads to an exact stop, even if the surrounding segments would allow a transition with a velocity > 0. |
| BufferMode | MC\_BUFFER\_MODE | Defines how successive motion commands are to be processed (see [MC\_BUFFER\_MODE](ms-xhelp:///?Id=beckhoff-c38c-47ca-b279-280774eefed0)). Only mcBuffered and mcAborting are allowed here. |
| InvokeId | UDINT | Segment ID for analysis purposes. |

## 2129750 19167756 VAR\_IN\_OUT

```
VAR_IN_OUT  
    PathData       : MC_PATH_DATA_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| PathData | MC\_PATH\_DATA\_REF | Table containing the segments of a path. The table is written by the Preparation function blocks, like this one, and executed by MC\_MovePath (see MC\_PATH\_DATA\_REF). |

## 38292076 VAR\_OUTPUT

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
