# MC_CIRC_PATHCHOICE

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_CIRC\_PATHCHOICE

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 25136147 | 24898733 | 22762008 |

The MC\_CIRC\_PATHCHOICE data type defines the direction of rotation of a circle if mcCircModeCenter or mcCircModeRadius is selected from the enumeration [MC\_CIRC\_MODE](ms-xhelp:///?Id=beckhoff-1429-4e53-ae0d-5cbbe082a994).

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
