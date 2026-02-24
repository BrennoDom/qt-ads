# RemoveChild

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# RemoveChild

This method removes an XML child node from a given XML node. The two XML nodes are transferred to the method as input parameters. The method returns TRUE if the operation was successful and the XML node was removed.

## Syntax

```
METHOD RemoveChild : BOOL  
VAR_INPUT  
  n : SXmlNode;  
  child : SXmlNode;  
END_VAR
```

Sample call:

```
bRemoved := fbXml.RemoveChild(xmlParent, xmlChild);
```
