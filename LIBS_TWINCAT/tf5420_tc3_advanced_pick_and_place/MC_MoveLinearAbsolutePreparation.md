# MC_MoveLinearAbsolutePreparation

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_MoveLinearAbsolutePreparation

![36667404](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/1427998475__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 61571180 | 17269710 | 21209668 |

The function block adds an absolute linear movement to the table of segments in the PathData structure. After creating a table, it can be executed via [MC\_MovePath](ms-xhelp:///?Id=beckhoff-33b6-48b3-b766-e02fd42bf25f). The function block MC\_MoveLinearAbsolutePreparation can be called several times per cycle. A maximum of 30 entries are allowed per PathData table.

## 56669285 VAR\_INPUT

```
VAR_INPUT  
    Position                 : POINTER TO LREAL;  
    PositionCount            : UDINT;  
    Velocity                 : MC_LREAL := MC_INVALID;  
    Acceleration             : MC_LREAL := MC_DEFAULT;  
    Deceleration             : MC_LREAL := MC_DEFAULT;  
    Jerk                     : MC_LREAL := MC_DEFAULT;  
    BufferMode               : MC_BUFFERMODE := mcAborting;  
    TransitionMode           : MC_TRANSITION_MODE := mcTransModeNone;   
    TransitionParameter      : POINTER TO LREAL;   
    TransitionParameterCount : UDINT;  
    InvokeId                 : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Position | POINTER TO LREAL | Pointer to an array [1..PositionCount] of the target position vector. |
| PositionCount | UDINT | Dimension of the position vector. Must match the number of axes in the axis convention (see [MC Group Coordinated Motion](https://infosys.beckhoff.de/index.php?content=../content/1033/tcinfosys3/63050399112241419.html&id=8561246045262201294) or [MC Group with Pick-and-Place](ms-xhelp:///?Id=beckhoff-7ae8-4d8f-ae10-53ca658b7d2e)). |
| Velocity | MC\_LREAL | The maximum velocity for the programmed segment. The velocity does not always have to be reached. The velocity must be set >0. |
| Acceleration | MC\_LREAL | Maximum path acceleration for the programmed segment. [Special input values](ms-xhelp:///?Id=beckhoff-aff8-4bc7-b1a4-f5f4b932866a) can be used. MC\_DEFAULT executes the command with standard axis values. MC\_MAXIMUM executes the command with the maximum axis values. |
| Deceleration | MC\_LREAL | Maximum path deceleration for the programmed segment. [Special input values](ms-xhelp:///?Id=beckhoff-aff8-4bc7-b1a4-f5f4b932866a) can be used. MC\_DEFAULT executes the command with standard axis values. MC\_MAXIMUM executes the command with the maximum axis values. |
| Jerk | MC\_LREAL | Path jerk for the programmed segment. [Special input values](ms-xhelp:///?Id=beckhoff-aff8-4bc7-b1a4-f5f4b932866a) can be used. MC\_DEFAULT executes the command with standard axis values. |
| BufferMode | MC\_BUFFERMODE | Defines how successive motion commands are to be processed (see [MC\_BUFFER\_MODE](ms-xhelp:///?Id=beckhoff-c38c-47ca-b279-280774eefed0)). |
| Transition mode | MC\_TRANSITION\_MODE | Defines the blending mode (see [MC\_TRANSITION\_MODE](ms-xhelp:///?Id=beckhoff-a830-4416-b43e-ba3145cb1246)). |
| TransitionParameter | POINTER TO LREAL | Pointer to array [1..TransitionParameterCount] of blending parameters. Transition parameters define the blending from the last programmed position (see [MC\_TRANSITION\_MODE](ms-xhelp:///?Id=beckhoff-a830-4416-b43e-ba3145cb1246)). |
| TransitionParameterCount | UDINT | Number of blending parameters (see [MC\_TRANSITION\_MODE](ms-xhelp:///?Id=beckhoff-a830-4416-b43e-ba3145cb1246)). |
| InvokeId | UDINT | Segment ID for analysis purposes. |

## 40261524 26809401 VAR\_IN\_OUT

```
VAR_IN_OUT  
    PathData                 : MC_PATH_DATA_REF;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| PathData | MC\_PATH\_DATA\_REF | Table containing the segments of a path. The table is written by MC\_Move…Preparation and executed by [MC\_MovePath](ms-xhelp:///?Id=beckhoff-33b6-48b3-b766-e02fd42bf25f) (see [MC\_PATH\_DATA\_REF](ms-xhelp:///?Id=beckhoff-db53-4190-b062-b31e45596782)). |

|  |  |
| --- | --- |
| 39958021 | Resetting a table  A table is not reset during execution. To reset, the method `ClearPath()` must be called from MC\_PATH\_DATA\_REF. |

## 24077873 VAR\_OUTPUT

```
VAR_OUTPUT  
    Error                    : BOOL;  
    ErrorId                  : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Error | BOOL | This output becomes TRUE if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the[ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38)or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
