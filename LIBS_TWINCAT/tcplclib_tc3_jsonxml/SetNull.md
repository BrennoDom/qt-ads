# SetNull

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetNull

This method sets the value of a property to the value NULL.

## Syntax

```
METHOD SetNull : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetNull(jsonProp);
```
