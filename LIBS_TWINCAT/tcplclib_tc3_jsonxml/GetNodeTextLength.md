# GetNodeTextLength

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetNodeTextLength

This method returns the length of the value of an XML node. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD GetNodeTextLength : UDINT  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
nLength := fbXml.GetNodeTextLength(xmlNode);
```
