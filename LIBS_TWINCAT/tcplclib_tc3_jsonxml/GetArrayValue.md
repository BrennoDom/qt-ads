# GetArrayValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetArrayValue

This method returns the value at the current iterator position of an array.

## Syntax

```
METHOD GetArrayValue : SJsonValue  
VAR_INPUT  
  i : SJsonAIterator;  
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
