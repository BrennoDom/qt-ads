# AddUintMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddUintMember

This method adds an UInt member to a JSON object.

## Syntax

```
METHOD AddUintMember : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : UDINT;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddUintMember(jsonDoc, 'TestUint', 42);
```
