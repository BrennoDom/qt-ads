# NodeText

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# NodeText

This method returns the text of an XML node. The XML node is transferred to the method as input parameter.

## Syntax

```
METHOD NodeText : STRING(255)  
VAR_INPUT  
  n : SXmlNode;  
END_VAR
```

Sample call:

```
sMachine1Name := fbXml.NodeText(xmlMachine1);
```
