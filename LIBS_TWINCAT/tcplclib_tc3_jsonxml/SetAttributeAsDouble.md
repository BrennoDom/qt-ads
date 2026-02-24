# SetAttributeAsDouble

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetAttributeAsDouble

This method sets the value of an attribute. The value here has the data type Double.

## Syntax

```
METHOD SetAttributeAsDouble : SXmlAttribute  
VAR_INPUT  
  a : SXmlAttribute;  
  value : LREAL;  
END_VAR
```

Sample call:

```
xmlAttr := fbXml.SetAttributeAsDouble(xmlExistingAttr, 42.42);
```
