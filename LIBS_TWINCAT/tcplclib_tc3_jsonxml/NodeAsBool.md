# NodeAsBool

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NodeAsBool

This method returns the text of an XML node as data type Boolean. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD NodeAsBool : BOOL  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
bXmlNode:= fbXml.NodeAsBool(xmlMachine1);
```
