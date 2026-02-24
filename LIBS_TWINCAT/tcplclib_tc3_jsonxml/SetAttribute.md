# SetAttribute

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SetAttribute

This method sets the value of an attribute. The value has the data type String.

## Syntax

```
METHOD SetAttribute : SXmlAttribute  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR  
VAR_IN_OUT CONSTANT  
  value : STRING;  
END_VAR
```

Sample call:

```
xmlAttr := fbXml.SetAttribute(xmlExistingAttr, 'Test');
```
