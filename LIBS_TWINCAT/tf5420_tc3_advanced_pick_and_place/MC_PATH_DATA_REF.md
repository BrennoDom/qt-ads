# MC_PATH_DATA_REF

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_PATH\_DATA\_REF

![52977523](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/1516880651__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 7035667 | 63321005 | 33018140 |

MC\_PATH\_DATA\_REF represents the path to be executed by [MC\_MovePath](ms-xhelp:///?Id=beckhoff-33b6-48b3-b766-e02fd42bf25f), where the number of entries is limited to 30. The path to be executed is written by [MC\_MoveLinearAbsolutePreparation](ms-xhelp:///?Id=beckhoff-2ed6-42e1-90a2-a4a27171b040), [MC\_MoveCircularAbsolutePreparation](ms-xhelp:///?Id=beckhoff-0756-4d93-8fd9-8e04c2548627) and [MC\_BlockerPreparation](ms-xhelp:///?Id=beckhoff-13de-483e-af6b-774ec84a1471). It is initialized with a pointer to a user-defined buffer. Here the user can define the size of the path. The initialization must be done during the declaration. The path table is not reset during execution. To reset, the method [ClearPath](ms-xhelp:///?Id=beckhoff-1e46-450d-9ca9-e1a830caab61) must be called.

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
| 28727808 | The data type `MC_PATH_DATA_REF` is part of the Motion Control (MC) library. Use the `ClearPath()` method to clear path information of type `MC_PATH_DATA_REF` to reset an existing path. For the data type `MC_PATH_DATA_REF` use only Motion Control functions or Motion Control function blocks. In particular, do not use memory functions such as `MEMCMP`, `MEMCPY`, `MEMSET` or `MEMMOVE` for the data type `MC_PATH_DATA_REF`. |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |

Further Information

* [ClearPath](ms-xhelp:///?Id=beckhoff-1e46-450d-9ca9-e1a830caab61)
