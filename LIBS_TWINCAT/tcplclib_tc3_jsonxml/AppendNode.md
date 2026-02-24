# AppendNode

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AppendNode

This method adds a new node to an existing node. The existing node and the name of the new node are transferred to the method as input parameters. The method returns a reference to the newly added node.

## Syntax

```
METHOD AppendNode : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR
```

Sample call:

```
objMachines := fbXml.AppendNode(objRoot, 'Machines');
```
