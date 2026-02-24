# NextByName

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NextByName

This method sets an XML iterator for the next object that is to be processed, which is identified by its name.

## Syntax

```
METHOD NextByName : SXmlIterator  
VAR_INPUT  
  it : SXmlIterator;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR
```

Sample call:

```
xmlIterator := fbXml.Begin(xmlNode);  
WHILE NOT fbXml.IsEnd(xmlIterator) DO  
  xmlNodeRef := fbXml.Node(xmlIterator);  
  xmlNodeValue := fbXml.NodeText(xmlNodeRef);  
  xmlIterator := fbXml.NextByName(xmlIterator, 'SomeName');  
END_WHILE
```
