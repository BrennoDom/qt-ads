# AddKeyDcTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddKeyDcTime

This method creates a new property key and at the same time a value of the data type DCTIME.

## Syntax

```
METHOD AddKeyDcTime  
VAR_IN_OUT CONSTANT  
  key : STRING;  
END_VAR  
VAR_INPUT  
  value : DCTIME;  
END_VAR
```

Sample call:

```
fbJson.AddKeyDcTime('Timestamp', dcTime);
```
