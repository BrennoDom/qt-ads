# AddInt64Member

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddInt64Member

This method adds an Int64 member to a JSON object.

## Syntax

```
METHOD AddFileTimeMember : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : LINT;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddInt64Member(jsonDoc, 'TestInt64', 42);
```
