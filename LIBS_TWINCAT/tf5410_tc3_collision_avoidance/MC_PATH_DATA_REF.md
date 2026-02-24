# MC_PATH_DATA_REF

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_PATH\_DATA\_REF

![3531486](/tf5410_tc3_collision_avoidance/1033/Images/png/1516880651__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 31783374 | 17614915 | 24316508 |

MC\_PATH\_DATA\_REF represents the path to be executed by [MC\_MovePath](ms-xhelp:///?Id=beckhoff-d182-4e4b-8ebb-9afbea0ce629), where the number of entries is limited to 30. The path to be executed is written by [MC\_MoveLinearAbsolutePreparation](ms-xhelp:///?Id=beckhoff-87e2-4921-b8f9-0a4325148a49), [MC\_MoveCircularAbsolutePreparation](ms-xhelp:///?Id=beckhoff-a92e-4b93-9f1c-19e3d0160d3d) and [MC\_BlockerPreparation](ms-xhelp:///?Id=beckhoff-b512-4674-9a24-75c6c44ad991). It is initialized with a pointer to a user-defined buffer. Here the user can define the size of the path. The initialization must be done during the declaration. The path table is not reset during execution. To reset, the method [ClearPath](ms-xhelp:///?Id=beckhoff-77fa-4f41-90d1-6c1d937a0ad6) must be called.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    FilledRows            : UDINT;  
    OccupiedBuffer        : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| FilledRows | UDINT | Number of path entries (e.g. path segments). |
| OccupiedBuffer | UDINT | Occupied buffer size in bytes. By analyzing this output, the user can check whether the end of the defined buffer is reached. |

## Example

The example below shows how to declare a path reference and how to reset an existing path.

```
VAR  
    buffer          : ARRAY[1..4096] OF BYTE;  
    Path            : MC_PATH_DATA_REF(ADR(buffer), SIZEOF(buffer));  
END_VAR
```

```
//delete all segments of path table  
Path.ClearPath();
```

|  |  |
| --- | --- |
| 17521988 | The data type `MC_PATH_DATA_REF` is part of the Motion Control (MC) library. Use the `ClearPath()` method to clear path information of type `MC_PATH_DATA_REF` to reset an existing path. For the data type `MC_PATH_DATA_REF` use only Motion Control functions or Motion Control function blocks. In particular, do not use memory functions such as `MEMCMP`, `MEMCPY`, `MEMSET` or `MEMMOVE` for the data type `MC_PATH_DATA_REF`. |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |

Further Information

* [ClearPath](ms-xhelp:///?Id=beckhoff-77fa-4f41-90d1-6c1d937a0ad6)
