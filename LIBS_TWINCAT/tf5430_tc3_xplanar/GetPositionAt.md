# GetPositionAt

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# GetPositionAt

GetPositionAt arcLength  LREAL↔position  PositionXYC

Get a position on the Planar Track at a specific arc length value.

## Syntax

Definition:

```
METHOD GetPositionAt  
VAR_INPUT  
    arcLength : LREAL;  
END_VAR  
VAR_IN_OUT  
    position  : PositionXYC;  
END_VAR
```

## 54271769 Inputs

| Name | Type | Description |
| --- | --- | --- |
| arcLength | LREAL | Arc length value where the position is evaluated. |

## 18683873 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| position | PositionXYC | The position at the specified arc parameter. |
