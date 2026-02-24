# GetDcTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetDcTime

This method returns the value of a property of the data type DCTIME.

## Syntax

```
METHOD GetDcTime : DCTIME  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
dcTime := fbJson.GetDcTime(jsonProp);
```
