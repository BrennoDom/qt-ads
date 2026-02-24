# EPlanarObjectType

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# EPlanarObjectType

Identifies a planar object type.

## Syntax

Definition:

```
TYPE EPlanarObjectType :  
(  
    Invalid     := 0,  
    None        := 301,  
    Mover       := 302,  
    Track       := 303,  
    Environment := 304  
)UINT;  
END_TYPE
```

## Values

| Name | Description |
| --- | --- |
| Invalid | Indicates invalid information, e.g. no connection or component not yet ready. |
| None | No planar object. |
| Mover | Planar Mover. |
| Track | Planar Track. |
| Environment | Planar Environment. |
