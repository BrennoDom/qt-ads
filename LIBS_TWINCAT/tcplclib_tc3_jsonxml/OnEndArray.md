# OnEndArray

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnEndArray

This callback method is triggered if a square closing bracket, which corresponds to the JSON synonym for an ending array, was found at the position of the SAX reader. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnEndArray : HRESULT
```
