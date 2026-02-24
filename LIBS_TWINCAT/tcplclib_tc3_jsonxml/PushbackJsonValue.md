# PushbackJsonValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackJsonValue

This method appends a JSON document to the end of an array.

## Syntax

```
METHOD PushbackJsonValue : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  rawJson : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackJsonValue(jsonArray, sJson);
```
