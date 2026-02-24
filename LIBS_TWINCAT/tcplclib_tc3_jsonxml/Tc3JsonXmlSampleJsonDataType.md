# Tc3JsonXmlSampleJsonDataType

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Tc3JsonXmlSampleJsonDataType

**Sample of the automatic conversion of structures into a JSON message**

This sample illustrates how a data structure can be converted into a JSON message (and vice versa). In the conversion the layout of a structure is converted one-to-one into a corresponding JSON equivalent. Additional metadata can be created via PLC attributes on the member variables of the structure.

Download: [Tc3JsonXmlSampleJsonDataType.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_jsonxml/Resources/zip/3664376331.zip)

## Layout of the data structure to be converted

```
TYPE ST_Values :  
STRUCT  
  
  {attribute 'Unit' := 'm/s'}  
  {attribute 'DisplayName' := 'Speed'}  
  Sensor1 : REAL;  
  
  {attribute 'Unit' := 'V'}  
  {attribute 'DisplayName' := 'Voltage'}  
  Sensor2 : DINT;  
  
  {attribute 'Unit' := 'A'}  
  {attribute 'DisplayName' := 'Current'}  
  Sensor3 : DINT;  
  
END_STRUCT  
END_TYPE
```

## Declaration range

```
PROGRAM MAIN  
VAR  
  dtTimestamp    : DATE_AND_TIME := DT#2017-04-04-12:42:42;  
  fbJson         : FB_JsonSaxWriter;  
  fbJsonDataType : FB_JsonReadWriteDataType;  
  sJsonDoc       : STRING(255);   
  sJsonDoc2      : STRING(2000);   
  stValues       : ST_Values;  
END_VAR
```

## Implementation range

Two ways of generating the JSON message are shown, starting with the instance fbJson of the function block FB\_JsonSaxWriter. The GetDocument() method can be used with a JSON message with no more than 255 characters. However, the CopyDocument() method must be used with larger JSON messages.

```
fbJson.ResetDocument();  
fbJson.StartObject();  
fbjson.AddKeyDateTime('Timestamp', dtTimestamp);  
fbJsonDataType.AddJsonKeyValueFromSymbol(fbJson, 'Values', 'ST_Values', SIZEOF(stValues), ADR(stValues));  
fbJsonDataType.AddJsonKeyPropertiesFromSymbol(fbJson, 'MetaData', 'ST_Values', 'Unit|DisplayName');  
fbJson.EndObject();  
sJsonDoc := fbJson.GetDocument();  
fbJson.CopyDocument(sJsonDoc2, SIZEOF(sJsonDoc2));
```

## Resulting JSON message

```
{  
  "Timestamp": "2017-04-04T12:42:42",  
  "Values": {  
    "Sensor1": 0.0,  
    "Sensor2": 0,  
    "Sensor3": 0  
  },  
  "MetaData": {  
    "Sensor1": {  
      "Unit": "m/s",  
      "DisplayName": "Speed"  
    },  
    "Sensor2": {  
      "Unit": "V",  
      "DisplayName": "Voltage"  
    },  
    "Sensor3": {  
      "Unit": "A",  
      "DisplayName": "Current"  
    }  
  }  
}
```

## Alternative

As an alternative, the method AddJsonValueFromSymbol() can also be used to generate a JSON format directly from a data structure.

```
fbJson.ResetDocument();  
fbJsonDataType.AddJsonValueFromSymbol(fbJson, 'ST_Values', SIZEOF(stValues), ADR(stValues));  
sJsonDoc := fbJson.GetDocument();  
fbJson.CopyDocument(sJsonDoc2, SIZEOF(sJsonDoc2));
```

The resulting JSON object looks like this:

```
{  
  "Sensor1": 0.0,  
  "Sensor2": 0,  
  "Sensor3": 0  
}
```

## Conversion of a JSON message back to a data structure

The above samples show how a JSON object can be generated from a data structure in a simple manner. There is also a corresponding method in the Tc3\_JsonXml library for the reverse process, i.e. the extraction of values from a (received) JSON object back into a data structure. This application is made possible by calling the method SetSymbolFromJson().

```
fbJsonDataType.SetSymbolFromJson(someJson, 'ST_Values', SIZEOF(stValuesReceive), ADR(stValuesReceive));
```

The string variable sJsonDoc2 contains the JSON object, which is transferred into the structure instance stValuesReceive by calling the method.

|  |  |
| --- | --- |
| 39473694 | Target data structure  The target data structure must match the structure of the JSON document. Otherwise SetSymbolFromJson() returns FALSE. |
