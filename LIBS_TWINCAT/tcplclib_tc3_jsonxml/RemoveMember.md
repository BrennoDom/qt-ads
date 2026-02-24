# RemoveMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# RemoveMember

This method deletes the property at the current iterator.

## Syntax

```
METHOD RemoveMember : BOOL  
VAR_INPUT  
  v : SJsonValue;  
  i : SJsonIterator;  
  keepOrder : BOOL;  
END_VAR
```

Sample call:

The following JSON document is to be loaded into the DOM memory:

```
sMessage := '{"serialNumber":"123","batteryVoltage":"1547mV","clickType":"SINGLE", "array":["Hello",2,3]}';
```

The "array" property is to be deleted. First of all, the JSON document is searched for the "array" property, after which the property is removed.

```
jsonDoc := fbJson.ParseDocument(sMessage);  
jsonIterator := fbJson.MemberBegin(jsonDoc);  
jsonIteratorEnd := fbJson.MemberEnd(jsonDoc);  
WHILE jsonIterator <> jsonIteratorEnd DO  
  sName := fbJson.GetMemberName(jsonIterator);  
  IF sName = 'array' THEN  
    fbJson.RemoveMember(jsonDoc, jsonIterator);  
  END_IF  
  jsonIterator := fbJson.NextMember(jsonIterator);  
END_WHILE
```
