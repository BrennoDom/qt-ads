# OnBool

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnBool

This callback method is triggered if a value of the data type BOOL was found at the position of the SAX reader. The input parameter value contains the value found. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnBool : HRESULT  
VAR_INPUT  
    value : BOOL;  
END_VAR
```
