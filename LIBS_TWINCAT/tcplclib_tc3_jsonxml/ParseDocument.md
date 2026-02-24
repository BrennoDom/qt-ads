# ParseDocument

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# ParseDocument

This method loads an XML document into the DOM memory for further processing. The XML document exists as a string and is transferred to the method as input parameter. A reference to the XML document in the DOM is returned to the caller.

## Syntax

```
METHOD ParseDocument : SXmlNode  
VAR_IN_OUT CONSTANT  
  sXml : STRING;  
END_VAR
```

Sample call:

```
xmlDoc := fbXml.ParseDocument(sXmlToParse);
```
