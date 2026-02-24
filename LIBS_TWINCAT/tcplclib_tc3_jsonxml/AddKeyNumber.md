# AddKeyNumber

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddKeyNumber

This method creates a new property key and at the same time a value of the data type DINT.

## Syntax

```
METHOD AddKeyNumber  
VAR_IN_OUT CONSTANT  
  key : STRING;  
END_VAR  
VAR_INPUT  
  value : DINT;  
END_VAR
```

Sample call:

```
fbJson.AddKeyNumber('PropertyName', 42);
```
