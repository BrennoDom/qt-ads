# FirstNodeByPath

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# FirstNodeByPath

This method navigates through an XML document using a path that was transferred to the method. The path and the start node are transferred to the method as input parameters. The path is specified with "/" as separator. The method returns a reference to the XML node that was found.

## Syntax

```
METHOD FirstNodeByPath : SXmlNode  
VAR_INPUT  
  n : SXmlNode;  
  path : STRING;  
END_VAR
```

Sample call:

```
xmlFoundNode := fbXml.FirstNodeByPath(xmlStartNode, 'Level1/Level2/Level3');
```
