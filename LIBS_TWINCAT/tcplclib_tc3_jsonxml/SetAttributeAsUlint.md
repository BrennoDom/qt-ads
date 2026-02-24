# SetAttributeAsUlint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetAttributeAsUlint

This method sets the value of an attribute. The value has the data type Unsigned Integer64.

## Syntax

```
METHOD SetAttributeAsUlint : SXmlAttribute  
VAR_INPUT  
  a : SXmlAttribute;  
  value : ULINT;  
END_VAR
```

Sample call:

```
xmlAttr := fbXml.SetAttributeAsUlint(xmlExistingAttr, 42);
```
