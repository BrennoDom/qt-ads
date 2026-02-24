# AttributeAsDouble

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AttributeAsDouble

This method returns the value of an attribute as data type Double. The attribute is transferred to the method as input parameter.

## Syntax

```
METHOD AttributeAsDouble : LREAL  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR
```

Sample call:

```
lrValue := fbXml.AttributeAsDouble(xmlAttr);
```
