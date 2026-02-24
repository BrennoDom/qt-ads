# AddIntMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddIntMember

This method adds an Int member to a JSON object.

## Syntax

```
METHOD AddIntMember : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : DINT;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddIntMember(jsonDoc, 'TestInt', 42);
```
