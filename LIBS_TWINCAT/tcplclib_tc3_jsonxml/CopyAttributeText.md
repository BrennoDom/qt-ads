# CopyAttributeText

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# CopyAttributeText

This method reads the value of an XML attribute and writes it to a variable of data type String. The XML attribute, the target variable and the length to be written are transferred to the method as input parameters. The method returns the actual size.

## Syntax

```
METHOD CopyAttributeText : UDINT  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR  
VAR_IN_OUT CONSTANT  
  sXml : STRING;  
END_VAR  
VAR_INPUT  
  nXml : UDINT;  
END_VAR
```

Sample call:

```
nLength := fbXml.CopyAttributeText(xmlAttr, sTarget, SIZEOF(sTarget));
```
