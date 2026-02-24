# SetInt64

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetInt64

This method sets the value of a property to a value of the data type Int64.

## Syntax

```
METHOD SetInt64 : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
  value : LINT;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetInt64(jsonProp, 42);
```
