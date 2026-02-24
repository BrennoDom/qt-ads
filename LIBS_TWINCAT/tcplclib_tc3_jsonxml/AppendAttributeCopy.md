# AppendAttributeCopy

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AppendAttributeCopy

This method adds a new attribute to an existing node. The name and value of the new attribute are copied from an existing attribute. The existing attribute is transferred to the method as input parameter.

## Syntax

```
METHOD AppendAttributeCopy : SXmlAttribute  
INPUT_VAR  
  n : SXmlNode;  
  copy : SXmlAttribute;  
END_VAR
```

Sample call:

```
xmlNewAttribute := fbXml.AppendAttributeCopy(xmlNode, xmlExistingAttribute);
```
