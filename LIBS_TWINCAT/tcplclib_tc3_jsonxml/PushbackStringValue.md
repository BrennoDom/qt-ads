# PushbackStringValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackStringValue

This method appends a value of the data type DCTIME to the end of an array.

## Syntax

```
METHOD PushbackStringValue : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  value : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackStringValue(jsonArray, sString);
```
