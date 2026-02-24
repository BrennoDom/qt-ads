# SetHexBinary

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetHexBinary

This method sets the value of a property to a HexBinary-coded value. A data structure, for example, can be used as the source. Coding to the HexBinary format takes place inside the method.

## Syntax

```
METHOD SetHexBinary : SJsonValue  
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
jsonValue := fbJson.SetHexBinary(jsonProp, ADR(stStruct), SIZEOF(stStruct));
```
