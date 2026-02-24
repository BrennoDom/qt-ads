# MC_RegisterCompensation

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_RegisterCompensation

![23586666](/tf5410_tc3_collision_avoidance/1033/Images/png/4797300107__Web.png)

Reference to a mover template: An axis refers to a mover template via the function block `MC_RegisterCompensation`.

* This function block selects the compensation type.
* This function block influences the axis behavior.

## 10953403 VAR\_INPUT

```
VAR_INPUT  
    Execute          : BOOL;  
    CompensationType : MC_COMPENSATION_TYPE;  
    CompensationId   : OTCID;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Execute | BOOL | This function block activates the selected compensation type when a rising edge is triggered at its `Execute` input. When activated, the geometry information for geo-compensation is taken into account by the motion function blocks that refer to `Axis`. |
| CompensationType | MC\_COMPENSATION\_TYPE | Select `mcTypeGeoCompensation` for geo-compensation (see [MC\_COMPENSATION\_TYPE](ms-xhelp:///?Id=beckhoff-072a-42d4-8969-9c5627e4cbff)). |
| CompensationId | OTCID | This `CompensationId` input is of type `OTCID` and can thus refer to a mover template. The reference to the geometry information required for geo-compensation is made via the object ID `CompensationId`, which refers to a mover template. |

## 31471768/14810456 VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis  : AXIS_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Axis | AXIS\_REF | The Axis input is of type [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) and refers to an axis, e.g. to a mover. |

## 66185246 VAR\_OUTPUT

```
VAR_OUTPUT  
    Done    : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorId : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Done | BOOL | This output becomes `TRUE` when the command was successfully executed. |
| Busy | BOOL | This output becomes `TRUE` when the command is started with `Execute` and remains so as long as the function block executes the command. If `Busy` becomes `FALSE` again, the function block is ready for a new command. At the same time, one of the outputs `Done` or `Error` is set. |
| Error | BOOL | This output becomes `TRUE` if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. |

## Requirements

| Development Environment | Target System Type | PLC Libraries to be Linked |
| --- | --- | --- |
| TwinCAT V3.1.4022.25 TF5400 Advanced Motion Pack V3.1.6.03 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
