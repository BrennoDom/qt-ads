# NextSibling

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NextSibling

This method returns the next direct node for a given XML node at the same XML level.

## Syntax

```
METHOD NextSibling : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
xmlSibling := fbXml.NextSibling(xmlNode);
```
