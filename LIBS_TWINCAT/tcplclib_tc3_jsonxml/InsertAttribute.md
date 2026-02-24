# InsertAttribute

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# InsertAttribute

This method adds an attribute to an XML node. The attribute can be placed at a specific position. The XML node and the position and name of the new attribute are transferred to the method as input parameters. The method returns a reference to the newly added attribute. A value for the attribute can then be entered using the SetAttribute() method, for example.

## Syntax

```
METHOD InsertAttribute : SXmlAttribute  
VAR_INPUT  
  n : SXmlNode;  
  before : SXmlAttribute;  
END_VAR  
VAR_IN_OUT CONSTANT  
  name : STRING;  
END_VAR
```

Sample call:

```
xmlNewAttr := fbXml.InsertAttribute(xmlNode, xmlBeforeAttr, 'SomeName');
```
