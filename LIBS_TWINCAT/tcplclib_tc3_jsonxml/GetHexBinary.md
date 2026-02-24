# GetHexBinary

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetHexBinary

This method decodes the HexBinary content of a property and writes it to a certain memory address, e.g. to a data structure.

## Syntax

```
METHOD GetHexBinary : DINT  
VAR_INPUT  
  v : SJsonValue;  
  p : PVOID;  
  n : DINT;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
nLen := fbJson.GetHexBinary(jsonProp, ADR(stStruct), SIZEOF(stStruct));
```
