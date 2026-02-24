# OnBoolValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnBoolValue

This callback method is triggered if a value of the data type BOOL was found at the position of the SAX reader. The input parameter value contains the value found. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnBoolValue : HRESULT  
VAR_INPUT  
    level : UDINT;  
    infos : POINTER TO TcJsonLevelInfo;  
    value : BOOL;  
END_VAR
```
