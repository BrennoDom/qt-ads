# IsHexBinary

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# IsHexBinary

This method checks whether the value of a property is in the HexBinary format. If that is the case, the method returns TRUE, otherwise it returns FALSE.

## Syntax

```
METHOD IsHexBinary: BOOL  
VAR_INPUT  
  v : SJsonValue  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
bRet := fbJson.IsHexBinary(jsonProp);
```
