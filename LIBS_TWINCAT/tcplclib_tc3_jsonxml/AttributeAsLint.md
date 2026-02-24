# AttributeAsLint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AttributeAsLint

This method returns the value of an attribute as a data type Integer64. The attribute is transferred to the method as input parameter.

## Syntax

```
METHOD AttributeAsLint : LINT  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR
```

Sample call:

```
nValue := fbXml.AttributeAsLint(xmlAttr);
```
