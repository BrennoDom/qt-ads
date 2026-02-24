# AddDoubleMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddDoubleMember

This method adds a Double member to a JSON object.

## Syntax

```
METHOD AddDoubleMember : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : LREAL;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddDoubleMember(jsonDoc, 'TestDouble', 42.42);
```
