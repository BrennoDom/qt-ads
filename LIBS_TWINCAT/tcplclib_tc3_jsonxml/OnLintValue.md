# OnLintValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnLintValue

This callback method is triggered if a value of the data type LINT was found at the position of the SAX reader. The input parameter value contains the value found. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnLintValue : HRESULT  
VAR_INPUT  
    level : UDINT;  
    infos : POINTER TO TcJsonLevelInfo;  
    value : LINT;  
END_VAR
```
