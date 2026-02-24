# AppendAttribute

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AppendAttribute

This method adds a new attribute to an existing node. The name and value of the new attribute and the existing XML node are transferred to the method as input parameters. The method returns a reference to the newly added attribute.

## Syntax

```
METHOD AppendAttribute : SXmlAttribute  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
  value : STRING;  
END_VAR
```

Sample call:

```
objAttribute := fbXml.AppendAttribute(objMachine, 'Name', 'some value');
```
