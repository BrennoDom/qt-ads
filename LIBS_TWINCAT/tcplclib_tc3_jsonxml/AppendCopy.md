# AppendCopy

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AppendCopy

This method inserts a new node below an existing node. The name and value of the new node are copied from an existing node. The references to the existing nodes are transferred to the method as input parameters. The method returns a reference to the newly added node.

## Syntax

```
METHOD AppendCopy : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  copy : SXmlNode;  
END_VAR
```

Sample call:

```
xmlNewNode := fbXml.AppendCopy(xmlParentNode, xmlExistingNode);
```
