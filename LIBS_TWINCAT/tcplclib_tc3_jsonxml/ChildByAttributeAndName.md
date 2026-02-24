# ChildByAttributeAndName

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# ChildByAttributeAndName

This method is used to navigate through the DOM. It returns a reference to a child element in the XML document. The start node, the name and value of the attribute, and the name of the child element are transferred to the method as input parameters.

## Syntax

```
METHOD ChildByAttributeAndName : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  attr : STRING;  
  value : STRING;  
  child : STRING;  
END_VAR
```

Sample call:

```
xmlMachine2 := fbXml.ChildByAttributeAndName(xmlMachines, 'Type', '2', 'Machine');
```
