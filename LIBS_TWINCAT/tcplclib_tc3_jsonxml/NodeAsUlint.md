# NodeAsUlint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NodeAsUlint

This method returns the text of an XML node as data type Unsigned Integer64. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD NodeAsUlint : ULINT  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
nXmlNode:= fbXml.NodeAsUlint(xmlMachine1);
```
