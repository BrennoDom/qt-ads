# SetObject

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetObject

This method sets the value of a property to the type "Object". This enables the nesting of JSON documents.

## Syntax

```
METHOD SetDouble : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
  value : LREAL;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetObject(jsonProp);
```
