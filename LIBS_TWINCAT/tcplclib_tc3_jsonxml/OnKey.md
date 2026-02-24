# OnKey

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnKey

This callback method is triggered if a property was found at the position of the SAX reader. The property name lies on the input/output parameter key and its length on the input parameter len. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnKey : HRESULT  
VAR_IN_OUT CONSTANT  
    key : STRING;  
END_VAR  
VAR_INPUT  
    len : UDINT;  
END_VAR
```
