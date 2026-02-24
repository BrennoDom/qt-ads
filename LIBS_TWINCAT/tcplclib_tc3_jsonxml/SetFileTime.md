# SetFileTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetFileTime

This method sets the value of a property to a value of the data type FILETIME.

## Syntax

```
METHOD SetFileTime : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : FILETIME;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetFileTime(jsonProp, fileTime);
```
