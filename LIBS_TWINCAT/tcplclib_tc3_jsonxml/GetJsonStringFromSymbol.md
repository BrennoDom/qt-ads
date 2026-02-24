# GetJsonStringFromSymbol

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetJsonStringFromSymbol

This method generates the corresponding JSON representation of a symbol. In contrast to the [AddJsonValueFromSymbol()](ms-xhelp:///?Id=beckhoff-597f-4ea9-9ad5-f3a511f46039) method, the result is not written to an instance of the function block FB\_JsonSaxWriter, but to a string variable. The method receives as its input parameters the data type name of the symbol as well as the address and size of the source symbol, e.g., of a structure instance.

The maximum size of the string returned by the method is 255 characters. With longer strings, the method will return a NULL string. In this case the method [CopyJsonStringFromSymbol](ms-xhelp:///?Id=beckhoff-3456-4a55-91b6-0b1233176ae1)() must be used.

## Syntax

```
METHOD GetJsonStringFromSymbol : STRING(255)  
VAR_IN_OUT CONSTANT  
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
sBuffer := fbJsonDataType.GetJsonStringFromSymbol('ST_Values',SIZEOF(stValues), ADR(stValues));
```
