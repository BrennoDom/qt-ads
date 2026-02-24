# GetString

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetString

This method returns the value of a property of the data type STRING(255). With longer strings, the method will return a NULL string. In this case the method [CopyString](ms-xhelp:///?Id=beckhoff-0044-44a5-8039-ac56a5957117)() must be used.

## Syntax

```
METHOD GetString : STRING(255)  
VAR_INPUT  
  v : SJsonValue;  
END_VAR
```
