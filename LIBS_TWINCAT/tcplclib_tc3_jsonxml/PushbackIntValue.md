# PushbackIntValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackIntValue

This method appends a value of the data type INT to the end of an array.

## Syntax

```
METHOD PushbackIntValue : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : DINT;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackIntValue(jsonArray, 42);
```
