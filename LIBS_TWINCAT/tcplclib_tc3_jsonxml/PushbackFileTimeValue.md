# PushbackFileTimeValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackFileTimeValue

This method appends a value of the data type FILETIME to the end of an array.

## Syntax

```
METHOD PushbackFileTimeValue : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : FILETIME;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackFileTimeValue(jsonArray, fileTime);
```
