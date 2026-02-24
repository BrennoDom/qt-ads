# MC_MoveCircularAbsolutePreparation

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_MoveCircularAbsolutePreparation

![15374270](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/2647253387__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 4150710 | 37356392 | 663215 |

The function block adds an absolute circular motion to the table of segments in the PathData structure. After creating a table, it can be executed via MC\_MovePath. The function block MC\_MoveCircularAbsolutePreparation can be called several times per cycle. A maximum of 30 entries are allowed per PathData table.

|  |  |
| --- | --- |
| 5968939 | Resetting a table  A table is not reset during execution. To reset, the method `ClearPath()` must be called from [MC\_PATH\_DATA\_REF](ms-xhelp:///?Id=beckhoff-db53-4190-b062-b31e45596782). |

## 53720453 VAR\_INPUT

```
VAR_INPUT  
    CircMode                 : MC_CIRC_MODE := mcCircModeInvalid;  
    AuxPoint                 : POINTER TO MC_LREAL;  
    AuxPointCount            : UDINT;  
    EndPoint                 : POINTER TO MC_LREAL;   
    EndPointCount            : UDINT;   
    PathChoice               : MC_CIRC_PATHCHOICE := mcCircPathchoiceCounterClockwise;  
    Velocity                 : MC_LREAL := MC_INVALID;  
    Acceleration             : MC_LREAL := MC_DEFAULT;  
    Deceleration             : MC_LREAL := MC_DEFAULT;  
    Jerk                     : MC_LREAL := MC_DEFAULT;  
    BufferMode               : MC_BUFFER_MODE := mcAborting;  
    TransitionMode           : MC_TRANSITION_MODE := mcTransModeNone;  
    TransitionParameter      : POINTER TO MC_LREAL;  
    TransitionParameterCount : UDINT;  
    InvokeId                 : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| CircMode | MC\_CIRC\_MODE | Specifies which circle definition is used to program the circle. Specifies the meaning of the "AuxPoint" input signal (see [MC\_CIRC\_MODE](ms-xhelp:///?Id=beckhoff-d6b3-4f72-ab46-0bafb3bace8c)). |
| AuxPoint | POINTER TO MC\_LREAL | Pointer to an array [1..AuxPointCount] of the AuxPoint vector. The interpretation of the AuxPoint vector depends on the rotation convention (see [MC Group Coordinated Motion](ms-xhelp:///?Id=beckhoff-02a8-413e-810b-f959e700e534) or [MC Group with Pick-and-Place](ms-xhelp:///?Id=beckhoff-7ae8-4d8f-ae10-53ca658b7d2e)) and is always (x, y, z). |
| AuxPointCount | UDINT | Dimension of the AuxPoint vector. Must be 3. If a 2D rotation convention (see [MC Group Coordinated Motion](ms-xhelp:///?Id=beckhoff-02a8-413e-810b-f959e700e534) or [MC Group with Pick-and-Place](ms-xhelp:///?Id=beckhoff-7ae8-4d8f-ae10-53ca658b7d2e)) is used, the input value must also be 3. With a 2D rotation convention and CircMode of *mcCircModeBorder* or *mcCircModeCenter*, the component that is independent of the working plane must be set to MC\_Ignore (see [MC\_LREAL/Special Input Values](ms-xhelp:///?Id=beckhoff-aff8-4bc7-b1a4-f5f4b932866a)). |
| EndPoint | POINTER TO MC\_LREAL | Pointer to an array [1..EndPointCount] of the target position vector. |
| EndPointCount | UDINT | Dimension of the EndPoint vector. Must match the number of axes in the axis convention (see [MC Group Coordinated Motion](ms-xhelp:///?Id=beckhoff-02a8-413e-810b-f959e700e534) or [MC Group with Pick-and-Place](ms-xhelp:///?Id=beckhoff-7ae8-4d8f-ae10-53ca658b7d2e)). |
| PathChoice | MC\_CIRC\_PATHCHOICE | Defines the direction of rotation with respect to the normal vector. The input is ignored if the input *CircMode* is set to *mcCircModeBorder* (see [MC\_CIRC\_PATHCHOICE](ms-xhelp:///?Id=beckhoff-54d6-4248-bdd3-e7e1b7d47ec6)). |
| Velocity | MC\_LREAL | The maximum velocity for the programmed segment. The velocity does not always have to be reached. The velocity must be set >0. |
| Acceleration | MC\_LREAL | Maximum path acceleration for the programmed segment. [Special input values](ms-xhelp:///?Id=beckhoff-aff8-4bc7-b1a4-f5f4b932866a) can be used. MC\_DEFAULT executes the command with standard axis values. MC\_MAXIMUM executes the command with the maximum axis values. |
| Deceleration | MC\_LREAL | Maximum path deceleration for the programmed segment. [Special input values](ms-xhelp:///?Id=beckhoff-aff8-4bc7-b1a4-f5f4b932866a) can be used. MC\_DEFAULT executes the command with standard axis values. MC\_MAXIMUM executes the command with the maximum axis values. |
| Jerk | MC\_LREAL | Path jerk for the programmed segment. [Special input values](ms-xhelp:///?Id=beckhoff-aff8-4bc7-b1a4-f5f4b932866a) can be used. MC\_DEFAULT executes the command with standard axis values. |
| BufferMode | MC\_BUFFER\_MODE | Defines how successive motion commands are to be processed (see [MC\_BUFFER\_MODE](ms-xhelp:///?Id=beckhoff-c38c-47ca-b279-280774eefed0)). |
| Transition mode | MC\_TRANSITION\_MODE | Defines the blending mode (see [MC\_TRANSITION\_MODE](ms-xhelp:///?Id=beckhoff-a830-4416-b43e-ba3145cb1246)). |
| TransitionParameter | POINTER TO MC\_LREAL | Pointer to array [1..TransitionParameterCount] of blending parameters. Transition parameters define the blending from the last programmed position (see [MC\_TRANSITION\_MODE](ms-xhelp:///?Id=beckhoff-a830-4416-b43e-ba3145cb1246)). |
| TransitionParameterCount | UDINT | Number of blending parameters. |
| InvokeId | UDINT | Segment ID for analysis purposes. |

## 13722030 56389407 VAR\_IN\_OUT

```
VAR_IN_OUT  
    PathData                 : MC_PATH_DATA_REF;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| PathData | MC\_PATH\_DATA\_REF | Table containing the segments of a path. The table is written by MC\_Move…Preparation and executed by [MC\_MovePath](ms-xhelp:///?Id=beckhoff-33b6-48b3-b766-e02fd42bf25f) (see [MC\_PATH\_DATA\_REF](ms-xhelp:///?Id=beckhoff-db53-4190-b062-b31e45596782)). |

## 37742617 VAR\_OUTPUT

```
VAR_OUTPUT  
    Error                    : BOOL;  
    ErrorId                  : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Error | BOOL | This output becomes TRUE if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in theADS error documentationor in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b)(error codes 0x4nnn and 0x8nnn). |

## Sample of center point programming

Assuming a path consisting of 4 segments as shown in the figure is to be programmed in mcCircModeCenter mode: the user defines the center of the circle as an auxiliary point ("AuxPoint"). When using mcCircModeCenter, the input [MC\_CIRC\_PATHCHOICE](ms-xhelp:///?Id=beckhoff-54d6-4248-bdd3-e7e1b7d47ec6) determines the direction of rotation. Since the plane is defined by the cross product, mcCircPathchoiceCounterClockwise must be selected for both circle segments N20 and N30.

![4139237](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/2668785163__Web.png)

```
VAR  
    Buffer                                  : ARRAY[1..4096] OF BYTE;  
    Path                                    : MC_PATH_DATA_REF (ADR(buffer), SIZEOF(buffer));  
    fbMoveLinPrep                           : MC_MoveLinearAbsolutePreparation;  
    fbMoveCircPrep                          : MC_MoveCircularAbsolutePreparation;  
  
    aTargetPos                              : ARRAY[1..cAxesCount] OF MC_LREAL;  
    aCircPos                                : ARRAY[1..cAxesCount] OF MC_LREAL;  
    aAuxPoint                               : ARRAY[1..3] OF MC_LREAL;  
    aTransitionParam                        : ARRAY[1..2] OF MC_LREAL;  
END_VAR  
VAR CONSTANT  
    cAxesCount                              : UINT:=3;  
END_VAR
```

```
    fbMoveLinPrep.Position                  := ADR(aTargetPos);  
    fbMoveLinPrep.PositionCount             := cAxesCount;  
    fbMoveLinPrep.TransitionParameter       := ADR(aTransitionParam);  
    fbMoveLinPrep.TransitionParameterCount  := 2;  
    fbMoveLinPrep.BufferMode                := mcBuffered;  
    fbMoveLinPrep.TransitionMode            := mcTransModeNone;  
  
    fbMoveCircPrep.EndPoint                 := ADR(aTargetPos);  
    fbMoveCircPrep.EndPointCount            := cAxesCount;  
    fbMoveCircPrep.AuxPoint                 := ADR(aAuxPoint);  
    fbMoveCircPrep.AuxPointCount            := 3;  
    fbMoveCircPrep.CircMode                 := mcCircModeCenter;  
    fbMoveCircPrep.TransitionParameter      := ADR(aTransitionParam);  
    fbMoveCircPrep.TransitionParameterCount := 2;  
    fbMoveCircPrep.BufferMode               := mcBuffered;  
    fbMoveCircPrep.TransitionMode           := mcTransModeNone;  
  
    aTargetPos[1]                           := 200;  
    aTargetPos[2]                           := 0;  
    aTargetPos[3]                           := 0;  
    aTransitionParam[1]                     := 0;  
    aTransitionParam[2]                     := 0;  
    fbMoveLinPrep(PathData:= path, Velocity:= 3000, InvokeId:= 10);  
  
    aTargetPos[1]                           := 300;  
    aTargetPos[2]                           := -100;  
    aTargetPos[3]                           := 0;  
    aAuxPoint[1]                            := 200;  
    aAuxPoint[2]                            := -100;  
    aAuxPoint[3]                            := 0;  
    aTransitionParam[1]                     := 0;  
    aTransitionParam[2]                     := 0;  
    fbMoveCircPrep(PathData:= path, PathChoice:= mcCircPathchoiceCounterClockwise, Velocity:= 1000, InvokeId:= 20);  
  
    aTargetPos[1]                           := 400;  
    aTargetPos[2]                           := -200;  
    aTargetPos[3]                           := 0;  
    aAuxPoint[1]                            := 400;  
    aAuxPoint[2]                            := -100;  
    aAuxPoint[3]                            := 0;  
    aTransitionParam[1]                     := 0;  
    aTransitionParam[2]                     := 0;  
    fbMoveCircPrep(PathData:= path, PathChoice:= mcCircPathchoiceCounterClockwise, Velocity:= 1000, InvokeId:= 30);  
  
    aTargetPos[1]                           := 600;  
    aTargetPos[2]                           := -200;  
    aTargetPos[3]                           := 100;  
    aTransitionParam[1]                     := 0;  
    aTransitionParam[2]                     := 0;  
    fbMoveLinPrep(PathData:= path, Velocity:= 3000, InvokeId:= 40);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.2.47 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
