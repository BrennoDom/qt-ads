# MC_CIRC_MODE

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_CIRC\_MODE

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 22593558 | 2015430 | 18138873 |

The circle mode determines which circle definition is used to program a circle.

```
TYPE MC_CIRC_MODE :  
(  
    mcCircModeInvalid        := 16#0000,  
    mcCircModeBorder         := 16#2000,  
    mcCircModeCenter         := 16#2001,  
    mcCircModeRadius         := 16#2002  
)  
END_TYPE
```

## mcCircModeInvalid

|  |  |
| --- | --- |
| **Returns an error** | * This parameter is invalid and results in an error if a valid MC\_CIRC\_MODE argument is required. |

## mcCircModeBorder

![29032137](/tf5410_tc3_collision_avoidance/1033/Images/png/2747844235__Web.png)

|  |  |
| --- | --- |
| **StartPoint** | * The movement starts at the starting point "StartPoint“. * This point is the end point of the previous move command. |
| **EndPoint** | * The user configures the endpoint "EndPoint". * The circular motion ends at this point. |
| **AuxPoint** | * The user configures the auxiliary point "AuxPoint". * The circular motion passes through this point. |
| **PathChoice** | * The input parameter "PathChoice" and the data type "MC\_CIRC\_PATHCHOICE" are ignored. |
| **Applicability** | * The mcCircModeBorder mode cannot be used to describe a full circle (i.e. "StartPoint" equals "EndPoint“). This is due to the fact that the center of the circle would not be unambiguous. * The mode *mcCircModeBorder* cannot be used to describe paths with more than one full revolution of the circle. |

## mcCircModeCenter

![59962646](/tf5410_tc3_collision_avoidance/1033/Images/png/2747847051__Web.png)

|  |  |
| --- | --- |
| **StartPoint** | * The movement starts at the starting point "StartPoint“. * This point is the end point of the previous move command. |
| **EndPoint** | * The user configures the endpoint "EndPoint". * The circular motion ends at this point. |
| **AuxPoint** | * The user configures the auxiliary point "AuxPoint". * For circular motion, this auxiliary point acts as the center of the circle. * The center point must have the same distance from the "StartPoint" and "EndPoint". If the distances differ only slightly, the center point is adjusted. If the distances differ significantly, the circle description is not accepted. |
|  |  |
| **PathChoice** | * There are normally two possible arcs that can be traversed from the "StartPoint" to the "EndPoint". The "PathChoice" parameter makes them unique. See MC\_CIRC\_PATHCHOICE for more information. |
| **Applicability** | * The mcCircModeCenter mode cannot be used to describe a semicircle (i.e. an arc passing through an angle of 180° or very close to it) or a full circle (i.e. "StartPoint" equals "EndPoint"). This is because in these cases the start, center and end points would be collinear and therefore the plane in which the circle lies would not be unique. |
|  | * The mode mcCircModeCenter cannot be used to describe paths with more than one full revolution of the circle. |

## mcCircModeRadius

![2792905](/tf5410_tc3_collision_avoidance/1033/Images/png/2747849867__Web.png)

1234ESnClockwiseCounterclockwiseShort segmentLong segment14323241MC\_CIRC\_PATHCHOICEE=EndPointS=StartPoint

|  |  |
| --- | --- |
| **Images** | * Four different arcs are distinguished by the orientation of the normal vector and the parameter "PathChoice". |
| **StartPoint** | * The movement starts at the starting point "StartPoint“. |
|  | * This point is the end point of the previous move command. |
|  | * The circle to be constructed and its plane contain the starting point. |
|  |  |
| **AuxPoint**  **Normal vector** | * The user configures the "AuxPoint" parameter, which acts as the normal vector of the circle plane in this mode. Its length indicates the radius of the circle. |
| **EndPoint** | * The user configures the endpoint "EndPoint". |
|  | * The movement will end at this point. |
|  | * MC Group only with pick-and-place: If this point lies outside the plane defined by "StartPoint" and the normal vector, the movement follows a helix instead of a circle. |
|  |  |
| **PathChoice and resulting arc** | * The right-hand rule is applied to all "PathChoice" values except mcCircPathchoiceClockwise, which follows the left-hand rule. |
|  | * *mcCircPathchoiceCounterClockwise* and *mcCircPathchoiceShortSegment* describe an arc covering an angle <= 180°, *mcCircPathchoiceClockwise* and *mcCircPathchoiceLongSegment* describe an arc covering an angle >= 180. |
|  | * Which of the four possible arcs with a given radius is chosen depends on the "PathChoice" argument and the orientation of the normal vector. See the table above for more information. |
|  |  |
| **Applicability** | * The mcCircModeRadius mode can only be used to describe arcs that cover an angle < 360. * The length of the normal vector (i.e. the radius of the circle) must be at least half the distance between the start and end points. |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.2.47 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
