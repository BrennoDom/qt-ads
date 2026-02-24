# ArrayBegin

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# ArrayBegin

This method returns the first element of an array and can be used together with the methods ArrayEnd() and NextArray() for iteration through a JSON array.

## Syntax

```
METHOD ArrayBegin : SJsonAIterator  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```

Sample call:

```
jsonIterator := fbJson.ArrayBegin(jsonArray);  
jsonIteratorEnd := fbJson.ArrayEnd(jsonArray);  
WHILE jsonIterator <> jsonIteratorEnd DO  
  sName := fbJson.GetArrayValue(jsonIterator);  
  jsonIterator := fbJson.NextArray(jsonIterator);  
END_WHILE
```
