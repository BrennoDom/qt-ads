# GetBase64

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetBase64

This method decodes a Base64 value from a JSON property. If the content of a data structure, for example, is located behind the Base64 value, the decoded content can also be placed on an identical structure again.

## Syntax

```
METHOD GetBase64 : DINT  
VAR_INPUT  
  v : SJsonValue;  
  p : PVOID;  
  n : DINT;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonBase64 := fbJson.FindMember(jsonDoc, 'base64');  
nSize := fbJson.GetBase64(jsonBase64, ADR(stStruct), SIZEOF(stStruct));
```
