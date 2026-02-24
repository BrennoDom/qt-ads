# GetType

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetType

This method returns the type of a property value. The return value can assume one of the values of the enum EJsonType.

## Syntax

```
METHOD GetStringLength : EJsonType  
VAR_INPUT  
  v : SJsonValue  
END_VAR  
  
TYPE EJsonType :  
(  
  eNullType := 0,  
  eFalseType := 1,  
  eTrueType := 2,  
  eObjectType := 3,  
  eArrayType := 4,  
  eStringType := 5,  
  eNumberType := 6  
) DINT;
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonProp := fbJson.FindMember(jsonDoc, 'property');  
eJsonType := fbJson.GetType(jsonProp);
```
