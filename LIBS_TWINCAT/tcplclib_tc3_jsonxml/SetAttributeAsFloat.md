# SetAttributeAsFloat

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetAttributeAsFloat

This method sets the value of an attribute. The value has the data type Float.

## Syntax

```
METHOD SetAttributeAsFloat : SXmlAttribute  
VAR_INPUT  
  a : SXmlAttribute;  
  value : REAL;  
END_VAR
```

Sample call:

```
xmlAttr := fbXml.SetAttributeAsFloat(xmlExistingAttr, 42.42);
```
