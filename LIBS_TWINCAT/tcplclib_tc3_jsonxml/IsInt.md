# IsInt

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# IsInt

This method checks whether the value of a given property is of the data type Integer (PLC: DINT). If that is the case, the method returns TRUE, otherwise it returns FALSE.

## Syntax

```
METHOD IsInt : BOOL  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```
