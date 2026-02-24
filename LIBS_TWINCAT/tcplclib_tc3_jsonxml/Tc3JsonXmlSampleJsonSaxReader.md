# Tc3JsonXmlSampleJsonSaxReader

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Tc3JsonXmlSampleJsonSaxReader

**Sample of the parsing of JSON documents via SAX Reader**

This sample illustrates how a JSON message can be run through programmatically. The function block FB\_JsonSaxReader is used as the basis.

Download: [Tc3JsonXmlSampleJsonSaxReader.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_jsonxml/Resources/zip/3664750475.zip)

## Declaration range

```
PROGRAM MAIN  
VAR  
  fbJson     : FB_JsonSaxReader;  
  pJsonParse : JsonSaxHandler;  
  sJsonDoc   : STRING(255) := '{"Values":{"Timestamp":"2017-04-04T12:42:42","Sensor1":42.42,"Sensor2":42}}';  
END_VAR
```

## Implementation range

Through the calling of the Parse() method, the transfer of the JSON message as a STRING and the interface pointer to a function block instance that implements the interface ItcJsonSaxHandler, the SAX Reader is activated and the corresponding callback methods are run through.

```
fbJson.Parse(sJson := sJsonDoc, ipHdl := pJsonParse);
```

## Callback methods

The callback methods are called on the instance of the function block that implements the interface ItcJsonSaxHandler. Each callback method represents a "found" element in the JSON message. For example, the callback method OnStartObject() is called as soon as an opening curly bracket has been detected. According to the example JSON message mentioned above, therefore, the following callback methods are run through in this order:

1. OnStartObject(), due to the first opening curly bracket
2. OnKey(), due to the property "Values"
3. OnStartObject(), due to the second opening curly bracket
4. OnKey(), due to the property "Timestamp"
5. OnString(), due to the value of the property "Timestamp"
6. OnKey(), due to the property "Sensor1"
7. OnLreal(), due to the value of the property "Sensor1"
8. OnKey(), due to the property "Sensor2"
9. OnUdint(), due to the value of the property "Sensor2"
10. OnEndObject(), due to the first closing curly bracket
11. OnEndObject(), due to the second closing curly bracket

Within the callback methods the current state is defined and saved via an instance of the enum E\_JsonStates. This can also be used to determine whether the JSON message is valid. For example, if the callback method OnLreal() is called and the state is not the expected State 70 (JSON\_STATE\_ONLREAL), the return value S\_FALSE can be returned to the method. The SAX Reader then automatically cancels the further processing.
