# AddFileTimeMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddFileTimeMember

This method adds a FileTime member to a JSON object.

## Syntax

```
METHOD AddFileTimeMember : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : FILETIME;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddFileTimeMember(jsonDoc, 'TestFileTime', ftTime);
```
