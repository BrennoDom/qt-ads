# OnDintValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnDintValue

This callback method is triggered if a value of the data type DINT was found at the position of the SAX reader. The input parameter value contains the value found. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnDintValue : HRESULT  
VAR_INPUT  
    level : UDINT;  
    infos : POINTER TO TcJsonLevelInfo;  
    value : DINT;  
END_VAR
```
