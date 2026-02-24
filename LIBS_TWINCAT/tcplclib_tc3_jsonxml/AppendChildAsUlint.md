# AppendChildAsUlint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AppendChildAsUlint

This method inserts a new node below an existing node. The value of the new node has the data type Unsigned Integer64. The name and value of the new node and a reference to the existing node are transferred to the method as input parameters. The method returns a reference to the newly added node.

## Syntax

```
METHOD AppendChildAsUlint : SXmlNode  
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
xmlNewNode := fbXml.AppendChildAsUlint(xmlExisting, 'SomeName', 42);
```
