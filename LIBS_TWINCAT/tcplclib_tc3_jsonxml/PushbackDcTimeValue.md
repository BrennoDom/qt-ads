# PushbackDcTimeValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# PushbackDcTimeValue

This method appends a value of the data type DCTIME to the end of an array.

## Syntax

```
METHOD PushbackDcTimeValue : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : DCTIME;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
jsonValue := fbJson.PushbackDcTimeValue(jsonArray, dcTime);
```
