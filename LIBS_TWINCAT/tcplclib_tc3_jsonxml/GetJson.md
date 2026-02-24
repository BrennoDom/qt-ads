# GetJson

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetJson

This method returns the value of a property as data type STRING(255), if this is a JSON document itself. With longer strings, the method will return a NULL string. In this case the method [CopyJson](ms-xhelp:///?Id=beckhoff-340a-4cdf-9849-4ba31a3c104e)() must be used.

## Syntax

```
METHOD GetJson : STRING(255)  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
sJson := fbJson.GetJson(jsonProp);
```
