# AddKeyLreal

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddKeyLreal

This method creates a new property key and at the same time a value of the data type LREAL.

## Syntax

```
METHOD AddKeyLreal  
VAR_IN_OUT CONSTANT  
  key : STRING;  
END_VAR  
VAR_INPUT  
  value : LREAL;  
END_VAR
```

Sample call:

```
fbJson.AddKeyLreal('PropertyName', 42.42);
```
