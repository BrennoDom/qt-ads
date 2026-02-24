# NextSiblingByName

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NextSiblingByName

This method returns the next direct node for a given XML node with a particular name at the same XML level.

## Syntax

```
METHOD NextSiblingByName : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR
```

Sample call:

```
xmlSibling := fbXml.NextSibling(xmlNode, 'SomeName');
```
