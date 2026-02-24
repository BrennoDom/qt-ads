# Child

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Child

This method is used to navigate through the DOM. It returns a reference to the (first) child element of the current node. The start node is transferred to the method as input parameter.

## Syntax

```
METHOD ChildByName : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
xmlChild := fbXml.Child(xmlNode);
```
