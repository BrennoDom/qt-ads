# ArrayEnd

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# ArrayEnd

This method returns the last element of an array and can be used together with the methods ArrayBegin() and NextArray() for iteration through a JSON array.

## Syntax

```
METHOD ArrayEnd : SJsonAIterator  
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
