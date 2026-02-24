# SetChildAsBool

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetChildAsBool

This method sets the value of an XML node. The value is transferred to the method as input parameter of data type Boolean.

## Syntax

```
METHOD SetChildAsBool : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  value : BOOL;  
END_VAR
```

Sample call:

```
xmlNode := fbXml.SetChild(xmlExistingNode, TRUE);
```
