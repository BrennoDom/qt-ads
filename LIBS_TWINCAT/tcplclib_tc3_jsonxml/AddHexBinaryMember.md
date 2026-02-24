# AddHexBinaryMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddHexBinaryMember

This method adds a HexBinary member to a JSON object.

## Syntax

```
METHOD AddHexBinaryMember : SJsonValue  
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
jsonMem := fbJson.AddHexBinaryMember(jsonDoc, 'TestHexBinary', sHexBinary, SIZEOF(sHexBinary));
```
