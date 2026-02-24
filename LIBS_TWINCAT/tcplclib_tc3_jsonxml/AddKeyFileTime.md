# AddKeyFileTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddKeyFileTime

This method creates a new property key and at the same time a value of the data type FILETIME.

## Syntax

```
METHOD AddKeyFileTime  
VAR_IN_OUT CONSTANT  
  key : STRING;  
END_VAR  
VAR_INPUT  
  value : FILETIME;  
END_VAR
```

Sample call:

```
fbJson.AddKeyFileTime('Timestamp', ftTime);
```
