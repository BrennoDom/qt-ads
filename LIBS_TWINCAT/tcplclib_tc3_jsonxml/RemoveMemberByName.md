# RemoveMemberByName

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# RemoveMemberByName

This method removes a child element from a given property. The element is referenced by its name.

## Syntax

```
METHOD RemoveMemberByName : BOOL  
VAR_INPUT  
  v         : SJsonValue;  
  keepOrder : BOOL;  
END_VAR  
VAR_IN_OUT CONSTANT  
    member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.RemoveMemberByName(jsonProp, 'ChildName');
```
