# ChildByAttribute

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# ChildByAttribute

This method is used to navigate through the DOM. It returns a reference to a child element in the XML document. The start node and the name and value of the attribute are transferred to the method as input parameters.

## Syntax

```
METHOD ChildByAttribute : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  attr : STRING;  
  value : STRING;  
END_VAR
```

Sample call:

```
xmlMachine1 := fbXml.ChildByAttribute(xmlMachines, 'Type', '1');
```
