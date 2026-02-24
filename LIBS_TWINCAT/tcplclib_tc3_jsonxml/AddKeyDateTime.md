# AddKeyDateTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddKeyDateTime

This method creates a new property key and at the same time a value of the data type DATE\_AND\_TIME.

## Syntax

```
METHOD AddKeyDateTime  
VAR_IN_OUT CONSTANT  
  key : STRING;  
END_VAR  
VAR_INPUT  
  value : DATE_AND_TIME;  
END_VAR
```

Sample call:

```
fbJson.AddKeyDateTime('Timestamp', dtTime);
```
