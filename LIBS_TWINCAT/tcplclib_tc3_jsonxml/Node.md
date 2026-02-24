# Node

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Node

This method is used in conjunction with an iterator to navigate through the DOM. The iterator is transferred to the method as input parameter. The method then returns the current XML node as return value.

## Syntax

```
METHOD Node : SXmlNode  
VAR_INPUT  
  it : SXmlIterator;  
END_VAR
```

Sample call:

```
xmlMachineNode := fbXml.ChildrenByName(xmlMachines, xmlIterator, 'Machine');  
WHILE NOT fbXml.IsEnd(xmlIterator) DO  
  xmlMachineNode := fbXml.Node(xmlIterator);  
  xmlMachineNodeValue := fbXml.NodeText(xmlMachineNode);  
  xmlIterator := fbXml.Next(xmlIterator);  
END_WHILE
```
