# NodeAsDouble

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NodeAsDouble

This method returns the text of an XML node as data type Double. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD NodeAsDouble : LREAL  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
lrXmlNode:= fbXml.NodeAsDouble(xmlMachine1);
```
