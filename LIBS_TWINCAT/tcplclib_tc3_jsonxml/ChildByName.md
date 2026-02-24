# ChildByName

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# ChildByName

This method is used to navigate through the DOM. It returns a reference to a child element in the XML document. The start node and the name of the element to be returned are transferred to the method as input parameters.

## Syntax

```
METHOD ChildByName : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR
```

Sample call:

```
xmlMachines := fbXml.ChildByName(xmlDoc, 'Machines');
```
