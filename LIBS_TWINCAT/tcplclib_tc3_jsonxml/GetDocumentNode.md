# GetDocumentNode

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetDocumentNode

This method returns the root node of an XML document. This is not the same as the first XML node in the document (the method GetRootNode() should be used for this). The method can also be used to create an empty XML document in the DOM.

## Syntax

```
METHOD GetDocumentNode : SXmlNode
```

Sample call:

```
objRoot := fbXml.GetDocumentNode();
```
