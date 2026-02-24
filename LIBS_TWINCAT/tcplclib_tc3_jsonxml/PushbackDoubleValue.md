# PushbackDoubleValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackDoubleValue

This method appends a value of the data type Double to the end of an array.

## Syntax

```
METHOD PushbackDoubleValue : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : LREAL;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackDoubleValue(jsonArray, 42.42);
```
