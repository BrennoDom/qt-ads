# AddJsonMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddJsonMember

This method adds a JSON member to a JSON object.

## Syntax

```
METHOD AddJsonMember : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member  : STRING;  
  rawJson : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonMem := fbJson.AddJsonMember(jsonDoc, 'TestJson', sJson);
```
