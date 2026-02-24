# SetArray

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetArray

This method sets the value of a property to the type "Array". New values can now be added to the array with the Pushback methods.

## Syntax

```
METHOD SetArray : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetArray(jsonProp);
```
