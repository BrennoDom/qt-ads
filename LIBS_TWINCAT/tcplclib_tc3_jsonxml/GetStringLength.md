# GetStringLength

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetStringLength

This method returns the length of a property if its value is a string.

## Syntax

```
METHOD GetStringLength : UDINT  
VAR_INPUT  
  v : SJsonValue  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
nLen := fbJson.GetStringLength(jsonProp);
```
