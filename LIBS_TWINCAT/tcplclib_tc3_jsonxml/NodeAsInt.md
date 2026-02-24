# NodeAsInt

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NodeAsInt

This method returns the text of an XML node as a data type Integer. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD NodeAsInt : DINT  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
nXmlNode:= fbXml.NodeAsInt(xmlMachine1);
```
