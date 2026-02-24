# GetDataTypeNameByAddress

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetDataTypeNameByAddress

This method returns the data type name of a transferred symbol.

## Syntax

```
METHOD GetDataTypeNameByAddress : STRING  
VAR_INPUT  
  nData : UDINT;  
  pData : PVOID;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
sBuffer := fbJsonDataType.GetDataTypeNameByAddress(SIZEOF(stValues),ADR(stValues));
```
