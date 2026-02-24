# SetAttributeAsInt

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetAttributeAsInt

This method sets the value of an attribute. The value has the data type Integer.

## Syntax

```
METHOD SetAttributeAsInt : SXmlAttribute  
VAR_INPUT  
  a : SXmlAttribute;  
  value : DINT;  
END_VAR
```

Sample call:

```
xmlAttr := fbXml.SetAttributeAsInt(xmlExistingAttr, 42);
```
