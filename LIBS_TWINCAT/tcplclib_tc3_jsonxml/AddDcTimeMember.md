# AddDcTimeMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddDcTimeMember

This method adds a DcTime member to a JSON object.

## Syntax

```
METHOD AddDcTimeMember : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : DCTIME;  
END_VAR  
VAR_IN_OUT CONSTANT  
    member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddDcTimeMember(jsonDoc, 'TestDcTime', 1234);
```
