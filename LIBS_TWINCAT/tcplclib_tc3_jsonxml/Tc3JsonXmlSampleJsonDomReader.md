# Tc3JsonXmlSampleJsonDomReader

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Tc3JsonXmlSampleJsonDomReader

This sample illustrates how a JSON message can be run through programmatically on the basis of DOM. The function block FB\_JsonDomParser is used as the basis.

Download: [Tc3JsonXmlSampleJsonDomReader.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_jsonxml/Resources/zip/3916597387.zip)

## Declaration range

```
PROGRAM MAIN  
VAR  
  fbJson     : FB_JsonDomParser;  
  jsonDoc    : SJsonValue;  
  jsonProp   : SJsonValue;  
  jsonValue  : SJsonValue;  
  bHasMember : BOOL;  
  sMessage   : STRING(255) := '{"serialNumber":"G030PT028191AC4R","batteryVoltage":"1547mV","clickType":"SINGLE"}';  
  stReceivedData : ST_ReceivedData;  
END_VAR
```

## Implementation range

The JSON message is loaded into the DOM tree using the ParseDocument() method. You can subsequently check whether it contains a certain property using the HasMember() method. The FindMember() method selects the property. The GetString() method extracts its value.

```
jsonDoc := fbJson.ParseDocument(sMessage);  
bHasMember := fbJson.HasMember(jsonDoc, 'serialNumber');  
IF (bHasMember) THEN  
  bHasMember := FALSE;  
  jsonProp := fbJson.FindMember(jsonDoc, 'serialNumber');  
  stReceivedData.serialNumber := fbJson.GetString(jsonProp);  
END_IF  
  
bHasMember := fbJson.HasMember(jsonDoc, 'batteryVoltage');  
IF (bHasMember) THEN  
  bHasMember := FALSE;  
  jsonProp := fbJson.FindMember(jsonDoc, 'batteryVoltage');  
  stReceivedData.batteryVoltage := fbJson.GetString(jsonProp);  
END_IF  
  
bHasMember := fbJson.HasMember(jsonDoc, 'clickType');  
IF (bHasMember) THEN  
  bHasMember := FALSE;  
  jsonProp := fbJson.FindMember(jsonDoc, 'clickType');  
  stReceivedData.clickType := fbJson.GetString(jsonProp);  
END_IF
```

The use of the method HasMember() is not absolutely necessary, since the method FindMember() already returns 0 if a property was not found. The code shown above can also be implemented as follows:

```
jsonDoc := fbJson.ParseDocument(sMessage);  
  
jsonProp := fbJson.FindMember(jsonDoc, 'serialNumber');  
IF (jsonProp <> 0) THEN  
  stReceivedData.serialNumber := fbJson.GetString(jsonProp);  
END_IF  
  
jsonProp := fbJson.FindMember(jsonDoc, 'batteryVoltage');  
IF (jsonProp <> 0) THEN  
  stReceivedData.batteryVoltage := fbJson.GetString(jsonProp);  
END_IF  
  
jsonProp := fbJson.FindMember(jsonDoc, 'clickType');  
IF (jsonProp <> 0) THEN  
  stReceivedData.clickType := fbJson.GetString(jsonProp);  
END_IF
```

## Nested JSON objects

The approach is similar with nested JSON objects. Since the entire document is located in the DOM, it is simple to navigate. Let's take a JSON object that looks like this:

```
sMessage : STRING(255) := '{"Values":{"serial":"G030PT028191AC4R"}}';
```

The property we are looking for is located in the sub-object "Values". The following code shows how to extract the property.

```
jsonDoc := fbJson.ParseDocument(sMessage);  
bHasMember := fbJson.HasMember(jsonDoc, 'Values');  
IF (bHasMember) THEN  
  bHasMember := FALSE;  
  jsonProp := fbJson.FindMember(jsonDoc, 'Values');  
  IF jsonProp <> 0 THEN  
    jsonSerial := fbJson.FindMember(jsonProp, 'serial');  
    stReceivedData.serialNumber := fbJson.GetString(jsonSerial);  
  END_IF  
END_IF
```
