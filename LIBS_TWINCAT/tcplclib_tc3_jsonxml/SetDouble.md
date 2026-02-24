# SetDouble

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetDouble

This method sets the value of a property to a value of the data type Double.

## Syntax

```
METHOD SetDouble : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : LREAL;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetDouble(jsonProp, 42.42);
```
