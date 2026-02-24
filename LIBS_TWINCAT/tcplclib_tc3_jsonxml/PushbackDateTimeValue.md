# PushbackDateTimeValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackDateTimeValue

This method appends a value of the data type DATE\_AND\_TIME to the end of an array.

## Syntax

```
METHOD PushbackDateTimeValue : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : DATE_AND_TIME;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackDateTimeValue(jsonArray, dtTime);
```
