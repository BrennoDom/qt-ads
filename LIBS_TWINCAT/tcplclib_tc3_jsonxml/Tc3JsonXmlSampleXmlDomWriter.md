# Tc3JsonXmlSampleXmlDomWriter

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Tc3JsonXmlSampleXmlDomWriter

This sample illustrates how an XML document can be created programmatically based on DOM. The function block FB\_XmlDomParser is used as a basis.

Download: [Tc3JsonXmlSampleXmlDomWriter.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_jsonxml/Resources/zip/5529228299.zip)

## Declaration range

```
PROGRAM MAIN  
VAR  
  fbXml : FB_XmlDomParser;  
  objRoot : SXmlNode;  
  objMachines : SXmlNode;  
  objMachine : SXmlNode;  
  objControllers : SXmlNode;  
  objController : SXmlNode;  
  objAttribute : SXmlAttribute;  
  sXmlString : STRING(1000);  
  bCreate     : BOOL := FALSE;  
  bSave : BOOL := TRUE;  
  nLength    : UDINT;  
  newAttr : SXmlAttribute;  
END_VAR
```

## Implementation range

The implementation section shows various options for creating an XML document.

```
IF bCreate THEN  
  (* Create an empty XML document *)  
  objRoot := fbXml.GetDocumentNode();  
  
  (* Create a new XML node 'Machines' and add to the empty document *)  
  objMachines := fbXml.AppendNode(objRoot, 'Machines');  
    
  (* Create a new XML node 'Machine' and add an attribute to this node. Append node to 'Machines' *)  
  objMachine := fbXml.AppendNode(objMachines, 'Machine');  
  objAttribute := fbXml.AppendAttribute(objMachine, 'Name', 'Wilde Nelli');  
  
  (* Create a new XML node 'Controllers' and add to the 'Machine' node *)  
  objControllers := fbXml.AppendNode(objMachine, 'Controllers');  
  
  (* Create a new XML node 'Controller' and add some attributes. Append node to 'Controllers'. *)  
  objController := fbXml.AppendChild(objControllers, 'Controller', 'CX5120', FALSE);  
  objAttribute := fbXml.AppendAttribute(objController, 'Type', 'EPC');  
  objAttribute := fbXml.AppendAttribute(objController, 'OS', 'Windows Embedded Compact 7');  
  
  (* Create a new XML node 'Controller' and add some attributes. Append node to 'Controllers'. *)  
  objController := fbXml.AppendChild(objControllers, 'Controller', 'CX2040', FALSE);  
  objAttribute := fbXml.AppendAttribute(objController, 'Type', 'EPC');  
  objAttribute := fbXml.AppendAttribute(objController, 'OS', 'Windows Embedded Standard 7');  
  
  (* Create a new XML node 'Controller' and add some attributes. Append node to 'Controllers'. *)  
  objController := fbXml.AppendChild(objControllers, 'Controller', 'C6015', FALSE);  
  objAttribute := fbXml.AppendAttribute(objController, 'Type', 'IPC');  
  objAttribute := fbXml.AppendAttribute(objController, 'OS', 'Windows 10 IoT Enterprise');  
  
  (* Create a new XML node 'Machine' and add an attribute to this node. Append node to 'Machines' *)  
  objMachine := fbXml.AppendNode(objMachines, 'Machine');  
  objAttribute := fbXml.AppendAttribute(objMachine, 'Name', 'Stanze Oscar');  
    
  (* Create a new XML node 'Controllers' and add to the 'Machine' node *)  
  objControllers := fbXml.AppendNode(objMachine, 'Controllers');  
  
  (* Create a new XML node 'Controller' and add some attributes. Append node to 'Controllers'. *)  
  objController := fbXml.AppendChild(objControllers, 'Controller', 'C6017', FALSE);  
  objAttribute := fbXml.AppendAttribute(objController, 'Type', 'IPC');  
  objAttribute := fbXml.AppendAttribute(objController, 'OS', 'Windows 10 IoT Enterprise');  
  newAttr := fbXml.InsertAttribute(objController, objAttribute, 'AddAttribute');  
  fbXml.SetAttribute(newAttr, 'Hola');  
  
  (* Retrieve XML document and store in a variable of data type STRING(1000) *)  
  nLength := fbXml.CopyDocument(sXmlString, SIZEOF(sXmlString));  
  bCreate := FALSE;  
END_IF
```
