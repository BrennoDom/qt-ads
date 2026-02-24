# PushbackUint64Value

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackUint64Value

This method appends a value of the data type UInt64 to the end of an array.

## Syntax

```
METHOD PushbackUint64Value : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : ULINT;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackUint64Value(jsonArray, 42);
```
