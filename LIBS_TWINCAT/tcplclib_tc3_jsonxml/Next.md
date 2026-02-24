# Next

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Next

This method sets an XML iterator for the next object that is to be processed.

## Syntax

```
METHOD Next : SXmlIterator  
VAR_INPUT  
  it : SXmlIterator;  
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
