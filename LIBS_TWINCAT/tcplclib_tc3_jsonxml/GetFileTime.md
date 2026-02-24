# GetFileTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetFileTime

This method returns the value of a property of the data type DCTIME.

## Syntax

```
METHOD GetFileTime : FILETIME  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
fileTime := fbJson.GetFileTime(jsonProp);
```
