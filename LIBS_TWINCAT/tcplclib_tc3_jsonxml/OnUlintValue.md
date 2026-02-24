# OnUlintValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnUlintValue

This callback method is triggered if a value of the data type ULINT was found at the position of the SAX reader. The input parameter value contains the value found. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnUlintValue : HRESULT  
VAR_INPUT  
    level : UDINT;  
    infos : POINTER TO TcJsonLevelInfo;  
    value : ULINT;  
END_VAR
```
