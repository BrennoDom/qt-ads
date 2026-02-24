# Tc3JsonXmlSampleJsonSaxWriter

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Tc3JsonXmlSampleJsonSaxWriter

**Sample of the creation of JSON documents via SAX Writer**

This sample illustrates how a JSON message can be created over the DAX mechanism. The function block FB\_JsonSaxWriter is used as the basis.

Download: [Tc3JsonXmlSampleJsonSaxWriter.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_jsonxml/Resources/zip/3664753419.zip)

## Declaration range

```
PROGRAM MAIN  
VAR  
  dtTimestamp : DATE_AND_TIME := DT#2017-04-04-12:42:42;  
  fbJson      : FB_JsonSaxWriter;  
  sJsonDoc    : STRING(255);  
END_VAR
```

## Implementation range

The SAX mechanism runs sequentially through the JSON document to be created, i.e. the corresponding elements are run though and created one after the other.

```
fbJson.StartObject();  
fbJson.AddKey('Timestamp');  
fbJson.AddDateTime(dtTimestamp);  
fbJson.AddKey('Values');  
fbJson.StartObject();  
fbJson.AddKey('Sensor1');  
fbJson.AddReal(42.42);  
fbJson.AddKey('Sensor2');  
fbJson.AddDint(42);  
fbJson.AddKey('Sensor3');  
fbJson.AddBool(TRUE);  
fbJson.EndObject();  
fbJson.EndObject();  
sJsonDoc := fbJson.GetDocument();  
fbJson.ResetDocument();
```

## Resulting JSON message

```
{  
  "Timestamp": "2017-04-04T12:42:42",  
  "Values": {  
    "Sensor1": 42.42,  
    "Sensor2": 42,  
    "Sensor3": true  
  }  
}
```
