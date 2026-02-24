# NodeAsLint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NodeAsLint

This method returns the text of an XML node as a data type Integer64. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD NodeAsLint : LINT  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
nXmlNode:= fbXml.NodeAsLint(xmlMachine1);
```
