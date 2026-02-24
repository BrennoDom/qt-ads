# InsertAttributeCopy

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# InsertAttributeCopy

This method adds an attribute to an XML node. The name and value of an existing attribute are copied. The attribute can be placed at a specific position. The XML node, the position and a reference to the existing attribute object are transferred to the method as input parameters. The method returns a reference to the newly added attribute.

## Syntax

```
METHOD InsertAttributeCopy : SXmlAttribute  
VAR_INPUT  
  n : SXmlNode;  
  before : SXmlAttribute;  
  copy : SXmlAttribute;  
END_VAR
```

Sample call:

```
xmlNewAttr := fbXml.InsertAttributeCopy(xmlNode, xmlBeforeAttr, xmlCopyAttr);
```
