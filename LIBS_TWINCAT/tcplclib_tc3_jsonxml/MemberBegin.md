# MemberBegin

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# MemberBegin

This method returns the first child element below a JSON property and can be used by a JSON property together with the methods MemberEnd() and NextMember() for iteration.

## Syntax

```
METHOD MemberBegin : SJsonIterator  
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
