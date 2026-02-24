# SetDateTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetDateTime

This method sets the value of a property to a value of the data type DATE\_AND\_TIME.

## Syntax

```
METHOD SetDateTime : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : DATE_AND_TIME;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetDateTime(jsonProp, dtTime);
```
