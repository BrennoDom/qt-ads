# MemberEnd

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# MemberEnd

This method returns the last child element below a JSON property and can be used by a JSON property together with the methods MemberBegin() and NextMember() for iteration.

## Syntax

```
METHOD MemberEnd : SJsonIterator  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```

Sample call:

```
jsonDoc := fbJson.ParseDocument(sExistingJsonDocument);  
jsonIterator := fbJson.MemberBegin(jsonDoc);  
jsonIteratorEnd := fbJson.MemberEnd(jsonDoc);  
WHILE jsonIterator <> jsonIteratorEnd DO  
  sName := fbJson.GetMemberName(jsonIterator);  
  jsonIterator := fbJson.NextMember(jsonIterator);  
END_WHILE
```
