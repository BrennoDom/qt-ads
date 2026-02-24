# SetUint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetUint

This method sets the value of a property to a value of the data type UInt.

## Syntax

```
METHOD SetUint : SJsonValue  
VAR_INPUT  
  v     : SJsonValue;  
  value : UDINT;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetUint(jsonProp, 42);
```
