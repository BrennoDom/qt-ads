# AttributeText

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AttributeText

This method returns the text of a given attribute. The attribute is transferred to the method as input parameter.

## Syntax

```
METHOD AttributeText : STRING(255)  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR
```

Sample call:

```
sText := fbXml.AttributeText(xmlAttr);
```
