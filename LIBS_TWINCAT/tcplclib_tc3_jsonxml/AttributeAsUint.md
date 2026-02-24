# AttributeAsUint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AttributeAsUint

This method returns the value of an attribute as data type Unsigned Integer. The attribute is transferred to the method as input parameter.

## Syntax

```
METHOD AttributeAsUint : UDINT  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR
```

Sample call:

```
nValue := fbXml.AttributeAsUint(xmlAttr);
```
