# GetJsonLength

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetJsonLength

This method returns the length of a property if this is a JSON document.

## Syntax

```
METHOD GetJsonLength : UDINT  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
nLen := fbJson.GetJsonLength(jsonProp);
```
