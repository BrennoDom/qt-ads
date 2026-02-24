# GetDocument

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetDocument

This method returns the content of the DOM memory as the data type STRING(255). With longer strings, the method will return a NULL string. In this case the method [CopyDocument](ms-xhelp:///?Id=beckhoff-00b2-4576-b0b0-79eeef7b627f)() must be used.

## Syntax

```
METHOD GetDocument : STRING(255)
```

Sample call:

```
sJson := fbJson.GetDocument();
```
