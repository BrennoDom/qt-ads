# NodeAsUint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NodeAsUint

This method returns the text of an XML node as data type Unsigned Integer. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD NodeAsUint : UDINT  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
nXmlNode:= fbXml.NodeAsUint(xmlMachine1);
```
