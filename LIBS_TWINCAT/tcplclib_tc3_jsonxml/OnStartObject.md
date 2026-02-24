# OnStartObject

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnStartObject

This callback method is triggered if a curly opening bracket, which corresponds to the JSON synonym for a starting object, was found at the position of the SAX reader. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnStartObject : HRESULT
```
