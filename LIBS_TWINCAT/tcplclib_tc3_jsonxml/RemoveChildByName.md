# RemoveChildByName

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# RemoveChildByName

This method removes an XML child node from a given XML node. The node to be removed is addressed by its name. If there is more than one child node, the last child node is removed. The method returns TRUE if the operation was successful and the XML node was removed.

## Syntax

```
METHOD RemoveChildByName : BOOL  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR
```

Sample call:

```
bRemoved := fbXml.RemoveChildByName(xmlParent, 'SomeName');
```
