# OnString

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnString

This callback method is triggered if a value of the data type STRING was found at the position of the SAX reader. The In/Out parameter value contains the value found. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnString : HRESULT  
VAR_IN_OUT CONSTANT  
    value : STRING;  
END_VAR  
VAR_INPUT  
    len : UDINT;  
END_VAR
```
