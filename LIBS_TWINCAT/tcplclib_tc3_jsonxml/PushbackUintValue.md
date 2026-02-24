# PushbackUintValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackUintValue

This method appends a value of the data type UInt to the end of an array.

## Syntax

```
METHOD PushbackUintValue : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : UDINT;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackUintValue(jsonArray, 42);
```
