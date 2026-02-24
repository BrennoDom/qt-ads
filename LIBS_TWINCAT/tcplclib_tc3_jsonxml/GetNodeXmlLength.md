# GetNodeXmlLength

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetNodeXmlLength

This method returns the length of the XML structure of an XML node. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD GetNodeXmlLength : UDINT  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
nLength := fbXml.GetNodeXmlLength(xmlNode);
```
