# CDT_PLCTOMC_PLANAR_MOVER

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# CDT\_PLCTOMC\_PLANAR\_MOVER

Contains the information of the Planar Mover passed from PLC to MC.

## Syntax

Definition:

```
TYPE CDT_PLCTOMC_PLANAR_MOVER :  
STRUCT  
    STD : CDT_PLCTOMC_PLANAR_MOVER_STD;  
END_STRUCT  
END_TYPE
```

## Parameters

| Name | Type | Description |
| --- | --- | --- |
| STD | CDT\_PLCTOMC\_PLANAR\_MOVER\_STD | Mover standard data that is transferred from this function block to the Planar Mover. |
