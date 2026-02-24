# IsISO8601TimeFormat

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# IsISO8601TimeFormat

This method checks whether the value of a given property has a time format according to ISO8601. If that is the case, the method returns TRUE, otherwise it returns FALSE.

## Syntax

```
METHOD IsISO8601TimeFormat : BOOL  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```
