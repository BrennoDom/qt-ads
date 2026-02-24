# AddJsonKeyValueFromSymbol

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddJsonKeyValueFromSymbol

This method generates the JSON representation of a PLC data structure on an [FB\_JsonSaxWriter](ms-xhelp:///?Id=beckhoff-87ea-496b-bbb9-5fd19f9eb8df) object. The method receives as its input parameters the instance of the FB\_JsonSaxWriter function block, the data type name of the structure, and the address and size of the source structure instance. As a result, the FB\_JsonSaxWriter instance contains a valid JSON representation of the structure. Unlike the method [AddJsonValueFromSymbol()](ms-xhelp:///?Id=beckhoff-597f-4ea9-9ad5-f3a511f46039), the elements of the source structure are nested here in a JSON sub-object whose name can be specified via the input/output parameter sKey.

## Syntax

```
METHOD AddJsonValueFromSymbol : BOOL  
VAR_IN_OUT  
  fbWriter  : FB_JsonSaxWriter;  
END_VAR  
VAR_IN_OUT CONSTANT  
  sKey      : STRING;  
  sDatatype : STRING;  
END_VAR  
VAR_INPUT  
  nData     : UDINT;  
  pData     : PVOID;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

A complete sample of how to use this method can be found in section [Tc3JsonXmlSampleJsonDataType](ms-xhelp:///?Id=beckhoff-552f-4c1d-84de-a578416495ad).

Sample call:

```
fbJsonSaxWriter.ResetDocument()  
fbJsonDataType.AddJsonKeyValueFromSymbol(fbJsonSaxWriter, 'Values','ST_Values',SIZEOF(stValues), ADR(stValues));
```
