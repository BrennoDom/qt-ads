# AddJsonKeyPropertiesFromSymbol

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddJsonKeyPropertiesFromSymbol

With the aid of this method, metadata can be added via PLC attributes to the JSON representation of a PLC data structure on an [FB\_JsonSaxWriter](ms-xhelp:///?Id=beckhoff-87ea-496b-bbb9-5fd19f9eb8df) object. The method receives as its input parameters the instance of the FB\_JsonSaxWriter function block, the desired name of the JSON property that is to contain the metadata, the data type name of the structure and a string variable sProperties, which contains a list of the PLC attributes to be extracted, separated by a cross bar.

## Syntax

```
METHOD AddJsonValueFromSymbol : BOOL  
VAR_IN_OUT  
  fbWriter    : FB_JsonSaxWriter;  
END_VAR  
VAR_IN_OUT CONSTANT  
  sKey        : STRING;  
  sDatatype   : STRING;  
  sProperties : STRING;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

The PLC attributes can be specified in the following form on the structure elements:

```
{attribute 'Unit' := 'm/s'}  
{attribute 'DisplayName' := 'Speed'}  
Sensor1 : REAL;
```

A complete sample of how to use this method can be found in section [Tc3JsonXmlSampleJsonDataType](ms-xhelp:///?Id=beckhoff-552f-4c1d-84de-a578416495ad).

Sample call:

```
fbJsonSaxWriter.ResetDocument()  
fbJsonDataType.AddJsonKeyPropertiesFromSymbol(fbJsonSaxWriter, 'MetaData','ST_Values','Unit|DisplayName');
```
