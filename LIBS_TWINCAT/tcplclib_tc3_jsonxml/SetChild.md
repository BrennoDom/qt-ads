# SetChild

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetChild

This method sets the value of an XML node. The value is transferred to the method as input parameter of data type String. The input parameter cdata indicates whether the value of the node is to be encapsulated in a CDATA function block, so that certain special characters such as "<" and ">" are allowed as values.

## Syntax

```
METHOD SetChild : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  value : STRING;  
END_VAR  
VAR_INPUT  
  cdata : BOOL;  
END_VAR
```

Sample call:

```
xmlNode := fbXml.SetChild(xmlExistingNode, 'SomeText', FALSE);
```
