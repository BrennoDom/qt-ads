# OnUdint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnUdint

This callback method is triggered if a value of the data type UDINT was found at the position of the SAX reader. The input parameter value contains the value found. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnUdint : HRESULT  
VAR_INPUT  
    value : UDINT;  
END_VAR
```
