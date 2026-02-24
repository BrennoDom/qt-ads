# SetInt

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetInt

This method sets the value of a property to a value of the data type INT.

## Syntax

```
METHOD SetInt : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
  value : DINT;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetInt(jsonProp, 42);
```
