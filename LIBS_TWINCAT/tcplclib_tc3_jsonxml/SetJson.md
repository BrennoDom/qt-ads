# SetJson

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetJson

This method inserts a further JSON document into the value of a property.

## Syntax

```
METHOD SetJson : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  rawJson : STRING;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
jsonValue := fbJson.SetJson(jsonProp, sJson);
```
