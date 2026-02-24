# SetBool

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetBool

This method sets the value of a property to a value of the data type BOOL.

## Syntax

```
METHOD SetBool : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : BOOL;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetBool(jsonProp, TRUE);
```
