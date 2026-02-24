# GetArcLengthClosestTo

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# GetArcLengthClosestTo

GetArcLengthClosestTo ↔geometry  IPlcGeometry2DLREAL  GetArcLengthClosestTo

Calculate the arc length value where the Planar Track is closest to a geometry's center point.

## Syntax

Definition:

```
METHOD GetArcLengthClosestTo : LREAL  
VAR_IN_OUT  
    geometry : IPlcGeometry2D;  
END_VAR
```

## 58665336 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| geometry | IPlcGeometry2D | The geometry to check the arc length for. |

## 58225979 Return value

LREAL
