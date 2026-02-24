# PlanarObjectInfo

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# PlanarObjectInfo

Identifies a planar object uniquely by object id and type.

## Syntax

Definition:

```
TYPE PlanarObjectInfo :  
STRUCT  
    ObjectType : EPlanarObjectType;  
    Id         : UDINT;  
END_STRUCT  
END_TYPE
```

## Parameters

| Name | Type | Description |
| --- | --- | --- |
| ObjectType | [EPlanarObjectType](ms-xhelp:///?Id=beckhoff-3776-494c-9a7a-935168250867) | Object type. |
| Id | UDINT | Object id. |
