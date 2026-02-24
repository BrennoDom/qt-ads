# OnLint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnLint

This callback method is triggered if a value of the data type LINT was found at the position of the SAX reader. The input parameter value contains the value found. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnLint : HRESULT  
VAR_INPUT  
    value : LINT;  
END_VAR
```
