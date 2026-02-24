# OnNullValue

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# OnNullValue

This callback method is triggered if a NULL value was found at the position of the SAX reader. The SAX parsing procedure is aborted by setting the return value HRESULT to S\_FALSE.

## Syntax

```
METHOD OnNull : HRESULT  
VAR_INPUT  
    level : UDINT;  
    infos : POINTER TO TcJsonLevelInfo;  
END_VAR
```
