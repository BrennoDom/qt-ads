# SetChildAsDouble

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetChildAsDouble

This method sets the value of an XML node. The value is transferred to the method as input parameter of data type Double.

## Syntax

```
METHOD SetChildAsDouble : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  value : LREAL;  
END_VAR
```

Sample call:

```
xmlNode := fbXml.SetChildAsDouble(xmlExistingNode, 42.42);
```
