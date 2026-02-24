# GetSymbolNameByAddress

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetSymbolNameByAddress

This method returns the complete (ADS) symbol name of a transferred symbol.

The maximum size of the string returned by the method is 255 characters. With longer strings, the method will return a null string. In this case the method [CopySymbolNameByAddress()](ms-xhelp:///?Id=beckhoff-c25c-4b4b-9465-61d0bc9d84aa) must be used.

## Syntax

```
METHOD GetSymbolNameByAddress : STRING(255)  
VAR_INPUT  
  nData : UDINT;  
  pData : PVOID;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
sBuffer := fbJsonDataType.GetSymbolNameByAddress(SIZEOF(stValues), ADR(stValues));
```
