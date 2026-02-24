# GetMemberValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetMemberValue

This method returns the value of a JSON property member at the position of the current iterator, e.g. during the iteration of a child element of a JSON property with the methods MemberBegin(), MemberEnd() and NextMember().

## Syntax

```
METHOD GetMemberValue : SJsonValue  
VAR_INPUT  
  i : SJsonIterator;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonIterator := fbJson.MemberBegin(jsonDoc);  
jsonIteratorEnd := fbJson.MemberEnd(jsonDoc);  
WHILE jsonIterator <> jsonIteratorEnd DO  
  jsonValue := fbJson.GetMemberValue(jsonIterator);  
  jsonIterator := fbJson.NextMember(jsonIterator);  
END_WHILE
```
