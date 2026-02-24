# NodeName

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NodeName

This method returns the name of an XML node. A reference to the XML node is transferred to the method as input parameter.

## Syntax

```
METHOD NodeName : STRING  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
sNodeName := fbXml.NodeName(xmlMachine1);
```
