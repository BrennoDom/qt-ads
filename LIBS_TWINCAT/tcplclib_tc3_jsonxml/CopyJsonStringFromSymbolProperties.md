# CopyJsonStringFromSymbolProperties

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# CopyJsonStringFromSymbolProperties

This method generates a corresponding JSON representation of PLC attributes on a symbol. In contrast to the [AddJsonKeyPropertiesFromSymbol](ms-xhelp:///?Id=beckhoff-e5bd-4cd5-944d-d438f51cb1c2) method, the result is not written to an instance of the function block FB\_JsonSaxWriter, but to a string variable. The method receives as its input parameters the data type name of the symbol and a string variable that represents a list of the PLC attributes to be extracted, separated by a cross bar.

The method copies this JSON representation into a variable of the data type STRING, which can be of any length. The method returns the length of the string (including null termination). If the target buffer is too small, it is emptied by a null termination and returned as length 0.

## Syntax

```
METHOD CopyJsonStringFromSymbolProperties : UDINT  
VAR_INPUT  
  nDoc  : UDINT;  
END_VAR  
VAR_IN_OUT CONSTANT  
  pDoc        : STRING;  
  sDatatype   : STRING;  
  sProperties : STRING;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
nLen := fbJsonDataType.CopyJsonStringFromSymbolProperties('ST_Test','Unit|DisplayName',sString,SIZEOF(sString));
```
