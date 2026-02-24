# NextAttribute

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NextAttribute

This method returns the next attribute for a given XML attribute.

## Syntax

```
METHOD NextAttribute : SXmlAttribute  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR
```

Sample call:

```
xmlNextAttr := fbXml.NextAttribute(xmlAttr);
```
