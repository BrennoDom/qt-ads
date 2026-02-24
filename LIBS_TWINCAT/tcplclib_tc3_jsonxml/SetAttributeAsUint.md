# SetAttributeAsUint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetAttributeAsUint

This method sets the value of an attribute. The value has the data type Unsigned Integer.

## Syntax

```
METHOD SetAttributeAsUint : SXmlAttribute  
VAR_INPUT  
  a : SXmlAttribute;  
  value : UDINT;  
END_VAR
```

Sample call:

```
xmlAttr := fbXml.SetAttributeAsUint(xmlExistingAttr, 42);
```
