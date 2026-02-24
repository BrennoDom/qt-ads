# Begin

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Begin

This method returns an iterator over all child elements of an XML node, always starting from the first child element. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD Begin : SXmlIterator  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
xmlIterator := fbXml.Begin(xmlNode);  
WHILE NOT fbXml.IsEnd(xmlIterator) DO  
  xmlNodeRef := fbXml.Node(xmlIterator);  
  xmlNodeValue := fbXml.NodeText(xmlNodeRef);  
  xmlIterator := fbXml.Next(xmlIterator);  
END_WHILE
```
