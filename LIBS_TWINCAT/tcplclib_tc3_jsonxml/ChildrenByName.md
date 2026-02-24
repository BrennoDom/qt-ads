# ChildrenByName

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# ChildrenByName

This method is used to navigate through the DOM. It returns an iterator for several child elements found in the XML document. The iterator can then be used for further navigation through the elements that were found. The start node, the name of the child elements to be found and a reference to the iterator are transferred to the method as input parameters.

## Syntax

```
METHOD ChildrenByName : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  it : REFERENCE TO SXmlIterator;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR
```

Sample call:

```
xmlMachineNode := fbXml.ChildrenByName(xmlMachines, xmlIterator, 'Machine');  
WHILE NOT fbXml.IsEnd(xmlIterator) DO  
  xmlMachineNodeRef := fbXml.Node(xmlIterator);  
  xmlMachineNodeText := fbXml.NodeText(xmlMachineNodeRef);  
  xmlIterator := fbXml.Next(xmlIterator);  
END_WHILE
```
