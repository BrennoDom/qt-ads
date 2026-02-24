# SetAttributeAsLint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetAttributeAsLint

This method sets the value of an attribute. The value has the data type Integer64.

## Syntax

```
METHOD SetAttributeAsLint : SXmlAttribute  
VAR_INPUT  
  a : SXmlAttribute;  
  value : LINT;  
END_VAR
```

Sample call:

```
xmlAttr := fbXml.SetAttributeAsLint(xmlExistingAttr, 42);
```
