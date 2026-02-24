# BeginByName

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# BeginByName

This method returns an iterator over all child elements of an XML node, starting at a particular element. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD BeginByName : SXmlIterator  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR
```

Sample call:

```
xmlNode := fbXml.ChildByName(xmlDoc, 'Machines');  
xmlIterator := fbXml.BeginByName(xmlNode, 'NameX');  
WHILE NOT fbXml.IsEnd(xmlIterator) DO  
  xmlNodeRef := fbXml.Node(xmlIterator);  
  xmlNodeValue := fbXml.NodeText(xmlNodeRef);  
  xmlIterator := fbXml.Next(xmlIterator);  
END_WHILE
```
