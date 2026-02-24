# NodeAsFloat

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NodeAsFloat

This method returns the text of an XML node as data type Float. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD NodeAsFloat : REAL  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
rXmlNode:= fbXml.NodeAsFloat(xmlMachine1);
```
