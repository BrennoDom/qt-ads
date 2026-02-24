# SetChildAsFloat

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetChildAsFloat

This method sets the value of an XML node. The value is transferred to the method as input parameter of data type Float.

## Syntax

```
METHOD SetChildAsFloat : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  value : REAL;  
END_VAR
```

Sample call:

```
xmlNode := fbXml.SetChildAsFloat(xmlExistingNode, 42.42);
```
