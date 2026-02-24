# MC_CIRC_PATHCHOICE

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_CIRC\_PATHCHOICE

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 52084342 | 66105898 | 58082174 |

The MC\_CIRC\_PATHCHOICE data type defines the direction of rotation of a circle if mcCircModeCenter or mcCircModeRadius is selected from the enumeration [MC\_CIRC\_MODE](ms-xhelp:///?Id=beckhoff-d6b3-4f72-ab46-0bafb3bace8c).

```
TYPE MC_CIRC_PATHCHOICE :  
(  
    mcCircPathchoiceClockwise          := 16#3000,  
    mcCircPathchoiceCounterClockwise   := 16#3001  
  
//new from V3.1.10.1  
    mcCircPathchoiceShortSegment       := 16#3002,  
    mcCircPathchoiceLongSegment        := 16#3003  
);  
END_TYPE
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| mcCircPathchoiceClockwise | INT | represents the circle segment with an angle >180°. |
| mcCircPathchoiceCounterClockwise | INT | represents the circle segment with an angle <180°. |
| mcCircPathchoiceShortSegment | INT | represents the circle segment with the smaller angle. |
| mcCircPathchoiceLongSegment | INT | represents the circle segment with the larger angle. |
