# GetAttributeTextLength

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetAttributeTextLength

This method returns the length of the value of an XML attribute. The XML attribute is transferred to the method as input parameter.

## Syntax

```
METHOD GetAttributeTextLength : UDINT  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR
```

Sample call:

```
nLength := fbXml.GetAttributeTextLength(xmlAttr);
```
