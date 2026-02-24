# AddNullMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddNullMember

This method adds a NULL member to a JSON object.

## Syntax

```
METHOD AddNullMember : SJsonValue  
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
jsonMem := fbJson.AddNullMember(jsonDoc, 'TestJson');
```
