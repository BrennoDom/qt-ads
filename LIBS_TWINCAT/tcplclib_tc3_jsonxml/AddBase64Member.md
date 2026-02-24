# AddBase64Member

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddBase64Member

This method adds a Base64 member to a JSON object. A structure, for example, can be addressed as an input parameter. The corresponding Base64 coding is done by the method.

## Syntax

```
METHOD AddBase64Member : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
  p : PVOID;  
  n : DINT;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonBase64 := fbJson.AddBase64Member(jsonDoc, 'TestBase64', ADR(stStruct), SIZEOF(stStruct));
```
