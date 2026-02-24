# SetSymbolFromJson

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetSymbolFromJson

This method extracts a string containing a valid JSON message and attempts to save the contents of the JSON object to an equivalent data structure. The method receives as its input parameters the string with the JSON object, the data type name of the target structure, and the address and size of the target structure instance.

## Syntax

```
METHOD SetSymbolFromJson : BOOL  
VAR_IN_OUT CONSTANT  
  sJson : STRING;  
  sDatatype : STRING;  
END_VAR  
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
fbJsonDataType.SetSymbolFromJson(sJson,'ST_Values',SIZEOF(stValuesReceive), ADR(stValuesReceive));
```
