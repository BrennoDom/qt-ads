# RemoveAllMembers

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# RemoveAllMembers

This method removes all child elements from a given property.

## Syntax

```
METHOD RemoveAllMembers : BOOL  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
bRemoved := fbJson.RemoveAllMembers(jsonProp);
```
