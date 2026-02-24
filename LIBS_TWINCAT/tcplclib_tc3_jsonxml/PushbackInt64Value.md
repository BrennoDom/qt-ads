# PushbackInt64Value

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackInt64Value

This method appends a value of the data type Int64 to the end of an array.

## Syntax

```
METHOD PushbackInt64Value : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
  value : LINT;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackInt64Value(jsonArray, 42);
```
