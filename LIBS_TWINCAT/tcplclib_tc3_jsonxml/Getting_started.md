# Getting started

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Getting started

This documentation article is intended as a quick-start guide to using the Tc3\_JsonXml PLC library. The article is based on the following use case:

* A JSON document exists that is to be processed further.
* The JSON document is in the form of a file on the local file system.
* The article describes the steps to parse the JSON document.

For more code samples, please refer to our [samples](ms-xhelp:///?Id=beckhoff-6efc-49b6-b6d2-6e0fb2534d5e).

## File contents

The file *myJsonContent.json* is located in the local file system under the following path: *c:\temp\myJsonContent.json* and has the following content:

```
{  
  "Timestamp":"2017-04-04T12:42:42",  
  "Values": {  
      "Sensor1": 42.41999816894531,  
      "Sensor2": [1,2,3,4,5],  
      "Sensor3": 10  
  }  
}
```

## Declarations

The following variable declarations are required for the further procedure:

```
fbJson : FB_JsonDomParser;  
jsonRoot : SJsonValue;  
jsonProp : SJsonValue;  
jsonIterator : SJsonValue;  
jsonIteratorEnd : SJsonValue;  
bLoadJsonFile : BOOL;  
sTimestamp : STRING;  
fSensor1 : LREAL;  
aSensor2 : ARRAY[0..4] OF DINT;  
nSensor3 : DINT;  
i : UINT;
```

Furthermore, please make sure that you have added a reference to the PLC library Tc3\_JsonXml in your PLC project.

## Reading the file

The method [LoadDocumentFromFile](ms-xhelp:///?Id=beckhoff-65c5-4cad-9a1f-10c2fe551cc9) from the function block [FB\_JsonDomParser](ms-xhelp:///?Id=beckhoff-a17a-4054-98b8-8bd8d4525aee) is used to read the file. The execution of the method is controlled by a rising edge at input `bExec`.

```
IF bLoadJsonFile = TRUE THEN  
  fbJson.LoadDocumentFromFile('C:\Temp\myJsonContent.json', bLoadJsonFile);  
END_IF
```

|  |  |
| --- | --- |
| 29844704 | Source of the JSON document  If in your use case the JSON document already exists in the PLC, e.g. in a variable of data type STRING, you can use the method [ParseDocument](ms-xhelp:///?Id=beckhoff-ae13-433c-9b83-a8e52f29abd2) to load the document into memory and for further processing. |

## Parsing the JSON document

The [GetDocumentRoot](ms-xhelp:///?Id=beckhoff-4573-4d82-adb6-0040cfc90a68) method can be used to reference the beginning of the JSON document in memory. The return value of the method is an interface pointer.

```
jsonRoot := fbJson.GetDocumentRoot();
```

From here, the other keys on the first level can be read, e.g. the 'Timestamp' key via the method [GetString](ms-xhelp:///?Id=beckhoff-7181-456e-9e72-1e5f645a1fbf):

```
jsonProp := fbJson.FindMember(jsonRoot, 'Timestamp');  
IF (jsonProp <> 0) THEN  
  sTimestamp := fbJson.GetString(jsonProp);  
END_IF
```

The next key ('Values') is a nested JSON object. The child elements of this object can be read directly via the method [FindMemberPath](ms-xhelp:///?Id=beckhoff-921c-4e05-809d-4f46935ce512), for example for the element 'Values/Sensor1':

```
jsonProp := fbJson.FindMemberPath(jsonRoot, 'Values/Sensor1');  
IF (jsonProp <> 0) THEN  
  fSensor1 := fbJson.GetDouble(jsonProp);  
END_IF
```

The next child element ('Values/Sensor2') is an array. This can be read by using the methods [ArrayBegin](ms-xhelp:///?Id=beckhoff-c2e3-405e-87c9-29f1084edf5f) and [ArrayEnd](ms-xhelp:///?Id=beckhoff-a422-40a3-8352-7056c09225a7).

```
jsonProp := fbJson.FindMemberPath(jsonRoot, 'Values/Sensor2');  
IF (jsonProp <> 0) THEN  
  jsonIterator := fbJson.ArrayBegin(jsonProp);  
  jsonIteratorEnd := fbJson.ArrayEnd(jsonProp);  
  WHILE jsonIterator <> jsonIteratorEnd DO  
    IF (jsonProp <> 0) THEN  
      aSensor2[i] := fbJson.GetInt(jsonIterator);  
    END_IF  
    jsonIterator := fbJson.NextArray(jsonIterator);  
    i := i + 1;  
  END_WHILE  
  i := 0;  
END_IF
```

Handling of the next child element ('Values/Sensor3') is similar to the element 'Values/Sensor1'. Instead of the method [GetDouble](ms-xhelp:///?Id=beckhoff-f929-40b7-b62d-cfc0177ca8d3) the method [GetInt](ms-xhelp:///?Id=beckhoff-93a6-4a29-84c0-82c692cf425d) is used to read the value of the key.

```
jsonProp := fbJson.FindMemberPath(jsonRoot, 'Values/Sensor3');  
IF (jsonProp <> 0) THEN  
  nSensor3 := fbJson.GetInt(jsonProp);  
END_IF
```

## Complete code sample

Below you will find the above code snippets as a complete sample.

**Declaration part**

```
PROGRAM MAIN  
  fbJson : FB_JsonDomParser;  
  jsonRoot : SJsonValue;  
  jsonProp : SJsonValue;  
  jsonIterator : SJsonValue;  
  jsonIteratorEnd : SJsonValue;  
  bLoadJsonFile : BOOL;  
  sTimestamp : STRING;  
  fSensor1 : LREAL;  
  aSensor2 : ARRAY[0..4] OF DINT;  
  nSensor3 : DINT;  
  i : UINT;  
END_VAR
```

**Implementation part**

```
IF bLoadJsonFile = TRUE THEN  
  fbJson.LoadDocumentFromFile('C:\Temp\myJsonContent.json', bLoadJsonFile);  
  jsonRoot := fbJson.GetDocumentRoot();  
  jsonProp := fbJson.FindMember(jsonRoot, 'Timestamp');  
  IF (jsonProp <> 0) THEN  
    sTimestamp := fbJson.GetString(jsonProp);  
  END_IF  
  jsonProp := fbJson.FindMemberPath(jsonRoot, 'Values/Sensor1');  
  IF (jsonProp <> 0) THEN  
    fSensor1 := fbJson.GetDouble(jsonProp);  
  END_IF  
  jsonProp := fbJson.FindMemberPath(jsonRoot, 'Values/Sensor2');  
  IF (jsonProp <> 0) THEN  
    jsonIterator := fbJson.ArrayBegin(jsonProp);  
    jsonIteratorEnd := fbJson.ArrayEnd(jsonProp);  
    WHILE jsonIterator <> jsonIteratorEnd DO  
      IF (jsonProp <> 0) THEN  
        aSensor2[i] := fbJson.GetInt(jsonIterator);  
      END_IF  
      jsonIterator := fbJson.NextArray(jsonIterator);  
      i := i + 1;  
    END_WHILE  
    i := 0;  
  END_IF  
  jsonProp := fbJson.FindMemberPath(jsonRoot, 'Values/Sensor3');  
  IF (jsonProp <> 0) THEN  
    nSensor3 := fbJson.GetInt(jsonProp);  
  END_IF  
END_IF
```

After the above code has been executed successfully, the keys that were read out are in the corresponding PLC variables, e.g. as follows:

![166885](/tcplclib_tc3_jsonxml/1033/Images/png/9007209846379915__Web.png)
