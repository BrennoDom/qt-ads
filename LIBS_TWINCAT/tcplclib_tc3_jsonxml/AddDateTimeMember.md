# AddDateTimeMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddDateTimeMember

This method adds a DateTime member to a JSON object.

## Syntax

```
METHOD AddDateTimeMember : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : DATE_AND_TIME;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddDateTimeMember(jsonDoc, 'TestDateTime', DT#2018-11-22-12:12);
```
