# AttributeAsInt

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AttributeAsInt

This method returns the value of an attribute as a data type Integer. The attribute is transferred to the method as input parameter.

## Syntax

```
METHOD AttributeAsInt : DINT  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR
```

Sample call:

```
nValue := fbXml.AttributeAsInt(xmlAttr);
```
