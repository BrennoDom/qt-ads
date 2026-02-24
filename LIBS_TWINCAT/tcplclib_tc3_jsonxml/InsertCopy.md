# InsertCopy

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# InsertCopy

This method adds a new node to an existing XML node and copies an existing node. The new node can be placed anywhere in the existing node. The XML node, the position and a reference to the existing node object are transferred to the method as input parameters. The method returns a reference to the newly added node.

## Syntax

```
METHOD InsertCopy : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  before : SXmlNode;  
  copy : SXmlNode;  
END_VAR
```

Sample call:

```
xmlNewNode := fbXml.InsertCopy(xmlNode, xmlBeforeNode, xmlCopyNode);
```
