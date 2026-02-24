# SetChildAsLint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetChildAsLint

This method sets the value of an XML node. The value is transferred to the method as input parameter of data type Integer64.

## Syntax

```
METHOD SetChildAsLint : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  value : LINT;  
END_VAR
```

Sample call:

```
xmlNode := fbXml.SetChildAsLint(xmlExistingNode, 42);
```
