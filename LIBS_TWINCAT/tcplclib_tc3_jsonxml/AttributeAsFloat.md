# AttributeAsFloat

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AttributeAsFloat

This method returns the value of an attribute as data type Float. The attribute is transferred to the method as input parameter.

## Syntax

```
METHOD AttributeAsFloat : REAL  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR
```

Sample call:

```
rValue := fbXml.AttributeAsFloat(xmlAttr);
```
