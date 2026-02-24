# SetDcTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetDcTime

This method sets the value of a property to a value of the data type DCTIME.

## Syntax

```
METHOD SetDcTime : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : DCTIME;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetDcTime(jsonProp, dcTime);
```
