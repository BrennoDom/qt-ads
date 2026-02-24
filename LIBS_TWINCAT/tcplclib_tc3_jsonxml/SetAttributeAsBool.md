# SetAttributeAsBool

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetAttributeAsBool

This method sets the value of an attribute. The value has the data type Boolean.

## Syntax

```
METHOD SetAttributeAsBool : SXmlAttribute  
VAR_INPUT  
  a : SXmlAttribute;  
  value : BOOL;  
END_VAR
```

Sample call:

```
xmlAttr := fbXml.SetAttributeAsBool(xmlExistingAttr, TRUE);
```
