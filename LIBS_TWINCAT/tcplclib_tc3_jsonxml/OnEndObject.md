# OnEndObject

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnEndObject

This callback method is triggered if a curly closing bracket, which corresponds to the JSON synonym for an ending object, was found at the position of the SAX reader. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnEndObject : HRESULT
```
