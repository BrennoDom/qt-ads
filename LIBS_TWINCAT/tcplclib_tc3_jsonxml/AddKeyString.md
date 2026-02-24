# AddKeyString

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddKeyString

This method creates a new property key and at the same time a value of the data type STRING.

## Syntax

```
METHOD AddKeyString  
VAR_IN_OUT CONSTANT  
  key : STRING;  
  value : STRING;  
END_VAR
```

Sample call:

```
fbJson.AddKeyString('PropertyName', 'Hello World');
```
