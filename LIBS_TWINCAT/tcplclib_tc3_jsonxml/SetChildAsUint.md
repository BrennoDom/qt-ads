# SetChildAsUint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetChildAsUint

This method sets the value of an XML node. The value is transferred to the method as input parameter of data type Unsigned Integer.

## Syntax

```
METHOD SetChildAsUint : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  value : UDINT;  
END_VAR
```

Sample call:

```
xmlNode := fbXml.SetChildAsUint(xmlExistingNode, 42);
```
