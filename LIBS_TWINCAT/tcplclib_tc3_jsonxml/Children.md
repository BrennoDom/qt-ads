# Children

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Children

This method is used to navigate through the DOM. It returns an iterator for several child elements found in the XML document. The iterator can then be used for further navigation through the elements that were found. The start node and a reference to the iterator are transferred to the method as input parameters.

## Syntax

```
METHOD Children : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  it : REFERENCE TO SXmlIterator;  
END_VAR
```

Sample call:

```
xmlRet := fbXml.Children(xmlNode, xmlIterator);  
WHILE NOT fbXml.IsEnd(xmlIterator) DO  
  xmlMachineNodeRef := fbXml.Node(xmlIterator);  
  xmlMachineNodeText := fbXml.NodeText(xmlMachineNodeRef);  
  xmlIterator := fbXml.Next(xmlIterator);  
END_WHILE
```
