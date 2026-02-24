# PushbackNullValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackNullValue

This method appends a NULL value to the end of an array.

## Syntax

```
METHOD PushbackNullValue : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackNullValue(jsonArray);
```
