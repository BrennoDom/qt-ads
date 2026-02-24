# InsertChild

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# InsertChild

This method adds a node to an existing XML node. The new node can be placed at a specific location. The existing XML node and the position and name of the new node are transferred to the method as input parameters. The method returns a reference to the newly added node. A value for the node can then be entered using the SetChild() method, for example.

## Syntax

```
METHOD InsertChild : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  before : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR
```

Sample call:

```
xmlNewNode := fbXml.InsertChild(xmlNode, xmlBeforeNode, 'SomeName');
```
