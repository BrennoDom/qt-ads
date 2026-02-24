# GetArraySize

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetArraySize

This method returns the number of elements in a JSON array.

## Syntax

```
METHOD GetArraySize : UDINT  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonArray := fbJson.FindMember(jsonDoc, 'array');  
nSize := fbJson.GetArraySize(jsonArray);
```
