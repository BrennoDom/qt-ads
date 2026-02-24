# GetJsonFromSymbol

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetJsonFromSymbol

This method generates the corresponding JSON representation of a symbol. In contrast to the [AddJsonValueFromSymbol()](ms-xhelp:///?Id=beckhoff-597f-4ea9-9ad5-f3a511f46039) method, the result is not written to an instance of the function block FB\_JsonSaxWriter, but to a string variable. The method receives as its input parameters the data type name of the symbol as well as the address and size of the source symbol, e.g. of a structure instance. The address and size of the destination buffer that contains the JSON representation of the symbol after the call are transferred as further input parameters.

## Syntax

```
METHOD GetJsonFromSymbol : BOOL  
VAR_IN_OUT CONSTANT  
  sDatatype : STRING;  
END_VAR  
VAR_INPUT  
  nData : UDINT;  
  pData : PVOID;  
  nJson : REFERENCE TO UDINT;  
  pJson : POINTER TO STRING;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

|  |  |
| --- | --- |
| 14008765 | Input parameter nJson  The input parameter nJson contains the size of the target buffer when the method is called, and the size of the actually written JSON object in the target buffer when the method call is completed. |

Sample call:

```
fbJsonDataType.GetJsonFromSymbol('ST_Values',SIZEOF(stValues), ADR(stValues), nBufferLength, ADR(sBuffer));
```
