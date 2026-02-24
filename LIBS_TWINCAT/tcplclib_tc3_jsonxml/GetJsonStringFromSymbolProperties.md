# GetJsonStringFromSymbolProperties

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetJsonStringFromSymbolProperties

This method generates a corresponding JSON representation of PLC attributes on a symbol. In contrast to the [AddJsonKeyPropertiesFromSymbol](ms-xhelp:///?Id=beckhoff-e5bd-4cd5-944d-d438f51cb1c2) method, the result is not written to an instance of the function block FB\_JsonSaxWriter, but to a string variable. The method receives as its input parameters the data type name of the symbol and a string variable that represents a list of the PLC attributes to be extracted, separated by a cross bar. The result is returned directly as the return value of the method.

The maximum size of the string returned by the method is 255 characters. With longer strings, the method will return a NULL string. In this case the method [CopyJsonStringFromSymbolProperties](ms-xhelp:///?Id=beckhoff-8662-42a9-8a44-899f75c3890e)() must be used.

## Syntax

```
METHOD GetJsonStringFromSymbolProperties : STRING(255)  
VAR_IN_OUT CONSTANT  
  sDatatype : STRING;  
  sProperties : STRING;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
sBuffer := fbJsonDataType.GetJsonStringFromSymbolProperties('ST_Values', 'Unit|DisplayName');
```
