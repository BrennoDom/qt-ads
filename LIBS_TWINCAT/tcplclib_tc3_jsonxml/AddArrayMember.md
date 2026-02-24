# AddArrayMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddArrayMember

This method adds an array member to a JSON object.

## Syntax

```
METHOD AddArrayMember : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR  
VAR_INPUT  
  reserve : UDINT;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.AddArrayMember(jsonDoc, 'TestArray', 0);
```
