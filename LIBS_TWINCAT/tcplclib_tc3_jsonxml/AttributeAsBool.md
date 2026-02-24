# AttributeAsBool

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AttributeAsBool

This method returns the value of an attribute as data type Boolean. The attribute is transferred to the method as input parameter.

## Syntax

```
METHOD AttributeAsBool : BOOL  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR
```

Sample call:

```
bValue := fbXml.AttributeAsBool(xmlAttr);
```
