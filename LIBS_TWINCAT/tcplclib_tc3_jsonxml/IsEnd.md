# IsEnd

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# IsEnd

This method checks whether a given XML iterator is at the end of the iteration that is to be performed.

## Syntax

```
METHOD IsEnd : BOOL  
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
