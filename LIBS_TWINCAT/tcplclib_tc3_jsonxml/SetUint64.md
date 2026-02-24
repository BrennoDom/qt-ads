# SetUint64

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetUint64

This method sets the value of a property to a value of the data type UInt64.

## Syntax

```
METHOD SetUint64 : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : ULINT;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetUint64(jsonProp, 42);
```
