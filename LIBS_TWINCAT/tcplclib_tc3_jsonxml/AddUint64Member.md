# AddUint64Member

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddUint64Member

This method adds an UInt64 member to a JSON object.

## Syntax

```
METHOD AddUint64Member : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : ULINT;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddUint64Member(jsonDoc, 'TestUint64', 42);
```
