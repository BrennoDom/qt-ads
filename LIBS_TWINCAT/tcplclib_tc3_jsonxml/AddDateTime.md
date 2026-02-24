# AddDateTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddDateTime

This method adds a value of the data type DATE\_AND\_TIME to a property. Usually, a corresponding property was created beforehand with the method [AddKey()](ms-xhelp:///?Id=beckhoff-60aa-4221-b3cc-a3999a39c931).

## Syntax

```
METHOD AddDateTime  
VAR_INPUT  
  value : DATE_AND_TIME;  
END_VAR
```

Sample call:

```
fbJson.AddKey('Timestamp');  
fbJson.AddDateTime(dtTime); // dtTime is of type DATE_AND_TIME
```
