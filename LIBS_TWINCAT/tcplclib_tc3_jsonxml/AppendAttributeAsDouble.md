# AppendAttributeAsDouble

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AppendAttributeAsDouble

This method adds a new attribute to an existing node. The value of the attribute has the data type Double. The name and value of the new attribute and the existing XML node are transferred to the method as input parameters. The method returns a reference to the newly added attribute.

## Syntax

```
METHOD AppendAttributeAsDouble : SXmlAttribute  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR  
VAR_INPUT  
  value : LREAL;  
END_VAR
```

Sample call:

```
objAttribute := fbXml.AppendAttributeAsDouble(objMachine, 'Name', 42.42);
```
