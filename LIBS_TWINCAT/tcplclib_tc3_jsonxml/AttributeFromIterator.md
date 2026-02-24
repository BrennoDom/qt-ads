# AttributeFromIterator

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AttributeFromIterator

This method converts the current position of an iterator to an XML attribute object. The iterator is transferred to the method as input parameter.

## Syntax

```
METHOD AttributeFromIterator : SXmlAttribute  
VAR_INPUT  
  it : SXmlIterator;  
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
