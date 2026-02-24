# AttributeName

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AttributeName

This method returns the name of a given attribute. The attribute is transferred to the method as input parameter.

## Syntax

```
METHOD AttributeName : STRING  
VAR_INPUT  
  a : SXmlAttribute;  
END_VAR
```

Sample call:

```
sName := fbXml.AttributeName(xmlAttr);
```
