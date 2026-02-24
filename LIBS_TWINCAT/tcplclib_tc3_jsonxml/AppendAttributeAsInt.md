# AppendAttributeAsInt

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AppendAttributeAsInt

This method adds a new attribute to an existing node. The value of the attribute has the data type Integer. The name and value of the new attribute and the existing XML node are transferred to the method as input parameters. The method returns a reference to the newly added attribute.

## Syntax

```
METHOD AppendAttributeAsInt : SXmlAttribute  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR  
VAR_INPUT  
  value : DINT;  
END_VAR
```

Sample call:

```
objAttribute := fbXml.AppendAttributeAsInt(objMachine, 'Name', 42);
```
