# PushbackBoolValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackBoolValue

This method appends a value of the data type BOOL to the end of an array.

## Syntax

```
METHOD PushbackBoolValue : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : BOOL;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackBoolValue(jsonArray, TRUE);
```
