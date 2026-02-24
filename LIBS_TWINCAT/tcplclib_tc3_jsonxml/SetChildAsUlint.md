# SetChildAsUlint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetChildAsUlint

This method sets the value of an XML node. The value is transferred to the method as input parameter of data type Unsigned Integer64.

## Syntax

```
METHOD SetChildAsUlint : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  value : ULINT;  
END_VAR
```

Sample call:

```
xmlNode := fbXml.SetChildAsUlint(xmlExistingNode, 42);
```
