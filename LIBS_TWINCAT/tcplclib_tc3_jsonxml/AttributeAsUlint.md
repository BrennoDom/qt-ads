# AttributeAsUlint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AttributeAsUlint

This method returns the value of an attribute as data type Unsigned Integer64. The attribute is transferred to the method as input parameter.

## Syntax

```
METHOD AttributeAsUlint : ULINT  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR
```

Sample call:

```
nValue := fbXml.AttributeAsUlint(xmlAttr);
```
