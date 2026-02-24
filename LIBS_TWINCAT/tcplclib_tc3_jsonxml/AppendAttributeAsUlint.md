# AppendAttributeAsUlint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AppendAttributeAsUlint

This method adds a new attribute to an existing node. The value of the attribute has the data type Unsigned Integer64. The name and value of the new attribute and the existing XML node are transferred to the method as input parameters. The method returns a reference to the newly added attribute.

## Syntax

```
METHOD AppendAttributeAsUlint : SXmlAttribute  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR  
VAR_INPUT  
  value : ULINT;  
END_VAR
```

Sample call:

```
objAttribute := fbXml.AppendAttributeAsUlint(objMachine, 'Name', 42);
```
