# AddFileTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddFileTime

This method adds a value of the data type FILETIME to a property. Usually, a corresponding property was created beforehand with the method [AddKey()](ms-xhelp:///?Id=beckhoff-60aa-4221-b3cc-a3999a39c931).

## Syntax

```
METHOD AddFileTime  
VAR_INPUT  
  value : FILETIME;  
END_VAR
```

Sample call:

```
fbJson.AddKey('Timestamp');  
fbJson.AddFileTime(ftTime); // ftTime is of type FILETIME
```
