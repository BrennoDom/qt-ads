# Overview

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Overview

With the aid of the PLC library Tc3\_JsonXml, SAX and DOM parser technologies can be used to create and navigate through JSON and XML documents.

## System requirements

|  |  |
| --- | --- |
| Target System | Win7, WES7, WEC7, Win10 IPC or CX, (x86, x64, ARM) |
| Min. TwinCAT version | 3.1.4022.0 |
| Min. TwinCAT level | TC1200 TC3 PLC |

## SAX (simple API for XML)

SAX was originally developed for handling XML documents, but can also be used for other data formats such as JSON. A SAX parser treats the data to be read or written as a sequential data stream. When reading a data stream, defined callback methods are called, which then return the corresponding contents of the data stream. A SAX parser is therefore also referred to as an event-based parser. The events occurring (callback methods) are stateless, i.e. they are not dependent on the preceding events. The advantage of this is that the XML document never has to be completely contained in the memory and the application can react "on the fly" via the callbacks.

## DOM (Document Object Model)

DOM is a specification for accessing XML documents, but can also be used for other data formats such as HTML or JSON. The interface is based on a defined object model, whose validity is a prerequisite for correct use. This object model represents a document, e.g. a JSON document, in the form of a tree structure in the memory, which can then be used to navigate through the document. DOM allows navigation between the individual nodes, the creation, moving and deletion of nodes, and the reading, changing and deletion of node contents. When editing is finished a new JSON or XML document is generated from the finalized tree structure. The advantage here is that no own data housekeeping needs to be created with the read-in data, since the data exist in the DOM and can be continuously accessed.

## JSON document

The following section shows a JSON document as an example:

```
{  
  "VariableNameX": 0.0,  
  "VariableNameY": 0.0,  
  "VariableNameZ": 0.0  
}
```

## Metadata

The Tc3\_JsonXml library contains the function block [FB\_JsonReadWriteDataType](ms-xhelp:///?Id=beckhoff-f490-4761-8e30-016d582c5cd8), which enables automatic generation of metadata by means of PLC attributes.

```
{  
  "Values": {  
    "VariableNameX": 0.0,  
    "VariableNameY": 0.0,  
    "VariableNameZ": 0.0  
  },  
  "MetaData": {  
    "VariableNameX": {  
      "Unit": "A"  
    },  
    "VariableNameY": {  
      "Unit": "V"  
    },  
    "VariableNameZ": {  
      "Unit": "mA"  
    }  
  }  
}
```

See also: Examples > [Tc3JsonXmlSampleJsonDataType](ms-xhelp:///?Id=beckhoff-552f-4c1d-84de-a578416495ad).

In order to use UTF-8 characters, e.g. in the automatic generation of metadata via the function block [FB\_JsonReadWriteDataType](ms-xhelp:///?Id=beckhoff-f490-4761-8e30-016d582c5cd8), the check box for the support of UTF-8 in the symbolism must be activated in the TwinCAT project. To do this, double-click on **SYSTEM** in the project tree, open the **Settings** tab and activate the corresponding check box.

![33142240](/tcplclib_tc3_jsonxml/1033/Images/png/4382966027__en-US__Web.png)

## JSON Web Token (JWT)

JSON Web Token (JWT) is an open standard (based on RFC 7519) that defines a compact and self-describing format for securely transmitting information between communication devices in the form of a JSON object. The authenticity of the transmitted information can be verified and ensured, since a JWT is provided with a digital signature. The signature can involve a shared secret (via an HMAC algorithm) or a public/private key (via RSA).

The most common application example for JWT is the authorization of a device or user for a service. Once a user has logged into the service, all further requests to the service include the JWT. Based on the JWT, the service can then decide which additional services or resources the user may access. This means, for example, that single sign-on solutions can be implemented in cloud services.

The Tc3\_JsonXml library provides a function for creating a JWT via the [FB\_JwtEncode](ms-xhelp:///?Id=beckhoff-acf0-414a-98c2-c17bdc51eadc) method.
