# AddKeyNull

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddKeyNull

This method creates a new property key and initializes its value with zero.

## Syntax

```
METHOD AddKeyNull  
VAR_IN_OUT CONSTANT  
  key : STRING;  
END_VAR
```

Sample call:

```
fbJson.AddKeyNull('PropertyName');
```
