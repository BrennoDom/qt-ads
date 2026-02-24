# GetSizeJsonStringFromSymbolProperties

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetSizeJsonStringFromSymbolProperties

This method reads the size of the JSON representation of PLC attributes on a symbol. The value is specified with null termination.

## Syntax

```
METHOD GetSizeJsonStringFromSymbolProperties : UDINT  
VAR_IN_OUT CONSTANT  
  sDatatype   : STRING;  
  sProperties : STRING;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
nLen := fbJsonDataType.GetSizeJsonStringFromSymbolProperties('ST_Test','DisplayName|Unit');
```
