# FindMemberPath

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# FindMemberPath

This method searches for a specific property in a JSON document and returns it. The property is specified according to its path in the document. 0 is returned if no corresponding property is found.

## Syntax

```
METHOD FindMemberPath : SJsonValue  
VAR_INPUT  
  v : SJsonValue  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMemberPath(jsonDoc, sPath);
```
