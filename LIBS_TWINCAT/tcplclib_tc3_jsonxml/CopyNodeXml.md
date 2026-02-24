# CopyNodeXml

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# CopyNodeXml

This method reads the XML structure of an XML node and writes it to a variable of data type String. The XML node, the target variable and the length to be written are transferred to the method as input parameters. The method returns the actual size.

## Syntax

```
METHOD CopyNodeXml : UDINT  
VAR_INPUT  
  a : SXmlNode;  
END_VAR  
VAR_IN_OUT CONSTANT  
  sXml : STRING;  
END_VAR  
VAR_INPUT  
  nXml : UDINT;  
END_VAR
```

Sample call:

```
nLength := fbXml.CopyNodeXml(xmlNode, sTarget, SIZEOF(sTarget));
```
