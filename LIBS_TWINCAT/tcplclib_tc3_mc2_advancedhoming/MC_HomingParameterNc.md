# MC_HomingParameterNc

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_HomingParameterNc

```
TYPE MC_HomingParameterNc :  
STRUCT  
    EnableSoftEndMinControl : BOOL;  
    EnableSoftEndMaxControl : BOOL;  
    EnablePosDiffControl    : BOOL;  
    EnableVeloDiffControl   : BOOL;  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| EnableSoftEndMinControl | BOOL | Activation of the software limit position monitoring in the logically positive direction |
| EnableSoftEndMaxControl | BOOL | Activation of the software limit position monitoring in the logically negative direction |
| EnablePosDiffControl | BOOL | Activation of the position lag monitoring |
| EnableVeloDiffControl | BOOL | Activation of the movement monitoring |
