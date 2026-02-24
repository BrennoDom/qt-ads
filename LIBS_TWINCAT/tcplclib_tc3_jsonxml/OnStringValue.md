# OnStringValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnStringValue

This callback method is triggered if a value of the data type STRING was found at the position of the SAX reader. The input/output parameter value contains the value found. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnStringValue : HRESULT  
VAR_IN_OUT CONSTANT  
    value : STRING;  
END_VAR  
VAR_INPUT  
    len : UDINT;  
    level : UDINT;  
    infos : POINTER TO TcJsonLevelInfo;  
END_VAR
```
