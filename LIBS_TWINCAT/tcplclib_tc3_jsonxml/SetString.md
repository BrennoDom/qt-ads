# SetString

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetString

This method sets the value of a property to a value of the data type STRING.

## Syntax

```
METHOD SetString : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  value : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetString(jsonProp, 'Hello World');
```
