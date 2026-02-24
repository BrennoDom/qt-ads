# AddObjectMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddObjectMember

This method adds an Object member to a JSON object.

## Syntax

```
METHOD AddObjectMember : SJsonValue  
VAR_INPUT  
 v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddObjectMember(jsonDoc, 'TestObject');
```
