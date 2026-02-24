# AddBoolMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddBoolMember

This method adds a Bool member to a JSON object.

## Syntax

```
METHOD AddBoolMember : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : BOOL;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddBoolMember(jsonDoc, 'TestBool', TRUE);
```
