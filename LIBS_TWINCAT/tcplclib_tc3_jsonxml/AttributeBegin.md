# AttributeBegin

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AttributeBegin

This method returns an iterator over all attributes of an XML node. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD AttributeBegin : SXmlIterator  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
xmlIterator := fbXml.AttributeBegin(xmlNode);  
WHILE NOT fbXml.IsEnd(xmlIterator) DO  
  xmlAttr := fbXml.AttributeFromIterator(xmlIterator);  
  nAttrValue := fbXml.AttributeAsInt(xmlAttr);  
  xmlIterator := fbXml.Next(xmlIterator);  
END_WHILE
```
