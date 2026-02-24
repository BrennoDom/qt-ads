# GetArrayValueByIdx

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetArrayValueByIdx

This method returns the value of an array in a specified index.

## Syntax

```
METHOD GetArrayValueByIdx : SJsonValue  
VAR_INPUT  
  v : SJsonValue;  
  idx : UDINT;  
END_VAR
```

Sample call:

```
jsonValue := fbJson.GetArrayValueByIdx(jsonArray, 1);
```
