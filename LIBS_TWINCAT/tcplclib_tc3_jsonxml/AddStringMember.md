# AddStringMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddStringMember

This method adds a String member to a JSON object.

## Syntax

```
METHOD AddStringMember : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
  value  : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddStringMember(jsonDoc, 'TestString', 'Test');
```
