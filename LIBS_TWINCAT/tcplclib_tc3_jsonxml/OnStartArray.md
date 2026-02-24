# OnStartArray

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnStartArray

This callback method is triggered if a square opening bracket, which corresponds to the JSON synonym for a starting array, was found at the position of the SAX reader. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnStartArray : HRESULT
```
