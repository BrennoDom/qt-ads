# MC_TransformPosition

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_TransformPosition

![58796306](/tf5410_tc3_collision_avoidance/1033/Images/png/6289334539__Web.png)

* This function block calculates a coordinate transformation.
* A position specified in the origin coordinate system is returned in the target coordinate system.
* An origin mover template object refers to the origin coordinate system.
* A destination mover template object refers to the target coordinate system.
* Object ID 0, `Oid = 0`, refers to the absolute coordinate system.
* The origin mover template object can refer to the absolute coordinate system, while the destination mover template object can refer to the coordinate system of the Tool Center Point: In this way, the calculation of a coordinate transformation from the absolute coordinate system to the coordinate system of the Tool Center Point is to be performed.
* The origin mover template object can refer to the coordinate system of the Tool Center Point, while the destination mover template object can refer to the absolute coordinate system: Thus, a calculation of the coordinate transformation from the coordinate system of the Tool Center Point to the absolute coordinate system is to be performed.
* For information purposes only: without effect on the setpoints.

## 59404709 VAR\_INPUT

```
VAR_INPUT  
    Execute             : BOOL;  
    OriginOid           : OTCID;  
    DestinationOid      : OTCID;  
    OriginPosition      : MC_LREAL;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | This function block outputs the target position when a rising edge is triggered at `Execute` input. |
| OriginOid | OTCID | This input refers to the origin mover template object as the coordinate system reference. |
| DestinationOid | OTCID | This input refers to the destination mover template object as the coordinate system reference. |
| OriginPosition | MC\_LREAL | Position value in the frame of the coordinate system to which the origin mover template object refers. |

## 64880336 VAR\_OUTPUT

```
VAR_OUTPUT  
    Done                : BOOL;  
    Busy                : BOOL;  
    Error               : BOOL;  
    ErrorId             : UDINT;  
    DestinationPosition : MC_LREAL;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Done | BOOL | This output becomes `TRUE` if the command was executed and the execution was successful. |
| Busy | BOOL | This output becomes `TRUE` when the command is started with `Execute` and remains so as long as the function block executes the command. If `Busy` becomes `FALSE` again, the function block is ready for a new command. At the same time, one of the outputs `Done` or `Error` is set. |
| Error | BOOL | This output becomes `TRUE` if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. |
| DestinationPosition | MC\_LREAL | Position value within the coordinate system to which the destination mover template object refers. |

## Example

```
VAR  
    fbAbsoluteToTcp        : MC_TransformPosition;  
    fbTcpToAbsolute        : MC_TransformPosition;  
    inputPositionAbsolute  : LREAL;  
    inputPositionTcp       : LREAL;  
    outputPositionTcp      : LREAL;  
    outputPositionAbsolute : LREAL;  
    oidMoverTemplate       : OTCID;  
END_VAR
```

```
fbAbsoluteToTcp(  
    Execute                := TRUE,  
    OriginOid              := 0, //absolute  
    DestinationOid         := oidMoverTemplate,  
    OriginPosition         := inputPositionAbsolute,  
    DestinationPosition    => outputPositionTcp  
);  
  
fbTcpToAbsolute(  
    Execute                := TRUE,  
    OriginOid              := oidMoverTemplate,  
    DestinationOid         := 0, //absolute  
    OriginPosition         := inputPositionTcp,  
    DestinationPosition    => outputPositionAbsolute  
);
```

## Requirements

| Development Environment | Target System Type | PLC Libraries to be Linked |
| --- | --- | --- |
| TwinCAT V3.1.4022.25  TF5400 Advanced Motion Pack V3.1.6.07 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
