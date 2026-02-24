# Tc3JsonXmlSampleXmlDomReader

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Tc3JsonXmlSampleXmlDomReader

This sample illustrates how an XML document can be processed programmatically based on DOM. The function block FB\_XmlDomParser is used as a basis.

Download: [Tc3JsonXmlSampleXmlDomReader.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_jsonxml/Resources/zip/5529225227.zip)

## Declaration range

```
PROGRAM MAIN  
VAR  
  fbXml : FB_XmlDomParser;  
  xmlDoc : SXmlNode;  
  xmlMachines : SXmlNode;  
  xmlMachine1 : SXmlNode;  
  xmlMachine2 : SXmlNode;  
  xmlIterator : SXmlIterator;  
  xmlMachineNode : SXmlNode;  
  xmlMachineNodeValue : STRING;  
  xmlMachineAttributeRef : SXmlAttribute;  
  xmlMachine1Attribute : SXmlAttribute;  
  xmlMachine2Attribute : SXmlAttribute;  
  sMachine1Name : STRING;  
  sMachine2Name : STRING;  
  nMachineAttribute : DINT;  
  nMachine1Attribute : DINT;  
  nMachine2Attribute : DINT;  
  sMessageToParse : STRING(255) := '<Machines><Machine Type="1" Test="3">Wilde Nelli</Machine><Machine Type="2">Huber8</Machine></Machines>';  
END_VAR
```

## Implementation range

The implementation section shows various options for parsing an XML document.

```
(* Load XML content *)  
xmlDoc := fbXml.ParseDocument(sMessageToParse);  
  
(* Parse XML nodes - Option 1 *)  
xmlMachines := fbXml.ChildByName(xmlDoc, 'Machines');  
xmlMachine1 := fbXml.ChildByAttribute(xmlMachines, 'Type', '1');  
xmlMachine2 := fbXml.ChildByAttributeAndName(xmlMachines, 'Type', '2', 'Machine');  
  
(* Parse XML nodes - Option 2 *)  
xmlMachines := fbXml.ChildByName(xmlDoc, 'Machines');  
xmlMachineNode := fbXml.Children(xmlMachines, xmlIterator);  
WHILE NOT fbXml.IsEnd(xmlIterator) DO  
  xmlMachineNode := fbXml.Node(xmlIterator);  
  xmlMachineNodeValue := fbXml.NodeText(xmlMachineNode);  
  xmlMachineNode := fbXml.Children(xmlMachines, xmlIterator);  
END_WHILE  
  
(* Parse XML nodes - Option 3 *)  
xmlMachines := fbXml.ChildByName(xmlDoc, 'Machines');  
xmlIterator := fbXml.Begin(xmlMachines);  
WHILE NOT fbXml.IsEnd(xmlIterator) DO  
  xmlMachineNode := fbXml.Node(xmlIterator);  
  xmlMachineNodeValue := fbXml.NodeText(xmlMachineNode);  
  xmlIterator := fbXml.Next(xmlIterator);  
  xmlIterator := fbXml.End(xmlMachines);  
END_WHILE  
  
(* Parse XML attributes - Option 1*)  
xmlMachine1Attribute := fbXml.Attribute(xmlMachine1, 'Type');  
xmlMachine2Attribute := fbXml.Attribute(xmlMachine2, 'Type');  
  
(* Parse XML attributes - Option 2*)  
xmlIterator := fbXml.AttributeBegin(xmlMachine1);  
WHILE NOT fbXml.IsEnd(xmlIterator) DO  
  xmlMachineAttributeRef := fbXml.AttributeFromIterator(xmlIterator);  
  nMachineAttribute := fbXml.AttributeAsInt(xmlMachineAttributeRef);  
  xmlIterator := fbXml.Next(xmlIterator);  
END_WHILE  
  
(* Retrieve node values *)  
sMachine1Name := fbXml.NodeText(xmlMachine1);  
sMachine2Name := fbXml.NodeText(xmlMachine2);  
  
(* Retrieve attribute values *)  
nMachine1Attribute := fbXml.AttributeAsInt(xmlMachine1Attribute);  
nMachine2Attribute := fbXml.AttributeAsInt(xmlMachine2Attribute);
```
