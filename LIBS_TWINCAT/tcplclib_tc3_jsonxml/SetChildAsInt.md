# SetChildAsInt

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetChildAsInt

This method sets the value of an XML node. The value is transferred to the method as input parameter of data type Integer.

## Syntax

```
METHOD SetChildAsInt : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  value : DINT;  
END_VAR
```

Sample call:

```
xmlNode := fbXml.SetChildAsInt(xmlExistingNode, 42);
```
