# FindMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# FindMember

This method searches for a specific property in a JSON document and returns it. 0 is returned if no corresponding property is found.

## Syntax

```
METHOD FindMember : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonProp := fbJson.FindMember(jsonDoc, 'PropertyName');
```
