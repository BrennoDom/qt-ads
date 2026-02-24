# ClearArray

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# ClearArray

This method deletes the content of an array.

## Syntax

```
METHOD ClearArray : BOOL  
VAR_INPUT  
  v : SJsonValue;  
  i : SJsonAIterator;  
END_VAR
```

Sample call:

The following JSON document is to be loaded into the DOM memory:

```
sMessage := '{"serialNumber":"123","batteryVoltage":"1547mV","clickType":"SINGLE", "array":["Hello",2,3]}';
```

The values of the JSON array "array" are to be deleted. First of all, the JSON document is searched iteratively for the "array" property, after which all elements of the array are deleted by calling the ClearArray() method.

```
jsonDoc := fbJson.ParseDocument(sMessage);  
jsonIterator := fbJson.MemberBegin(jsonDoc);  
jsonIteratorEnd := fbJson.MemberEnd(jsonDoc);  
WHILE jsonIterator <> jsonIteratorEnd DO  
  sName := fbJson.GetMemberName(jsonIterator);  
  jsonValue := fbJson.GetMemberValue(jsonIterator);  
  IF sName = 'array' THEN  
    jsonArrayIterator := fbJson.ArrayBegin(jsonValue);  
    fbJson.ClearArray(jsonValue, jsonArrayIterator);  
  END_IF  
  jsonIterator := fbJson.NextMember(jsonIterator);  
END_WHILE
```
