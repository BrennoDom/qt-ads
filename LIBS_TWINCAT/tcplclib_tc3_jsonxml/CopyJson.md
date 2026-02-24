# CopyJson

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# CopyJson

This method extracts a JSON object from a key and stores it in a variable of data type STRING. This STRING can be of any length. The method returns the length of the copied JSON object (including null termination). If the target buffer is too small, it is emptied by a null termination and returned as length 0.

## Syntax

```
METHOD CopyJson : UDINT  
VAR_INPUT  
  v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  pDoc : STRING;  
  nDoc : UDINT;  
END_VAR
```

Sample call:

The following JSON document is to be loaded into the DOM memory:

```
sMessage := ' {"serialNumber":"123","meta":{"batteryVoltage":"1547mV","clickType":"SINGLE"}}';
```

The value of the JSON object "meta" is to be extracted and stored in a variable of data type STRING. First the JSON document is searched iteratively for the property "meta", then its value or sub-object is extracted by calling the method CopyJson().

```
jsonDoc := fbJson.ParseDocument(sMessage);  
jsonIterator := fbJson.MemberBegin(jsonDoc);  
jsonIteratorEnd := fbJson.MemberEnd(jsonDoc);  
WHILE jsonIterator <> jsonIteratorEnd DO  
  sName := fbJson.GetMemberName(jsonIterator);  
  jsonValue := fbJson.GetMemberValue(jsonIterator);  
  IF sName = 'meta' THEN  
    fbJson.CopyJson(jsonValue, sString, SIZEOF(sString));  
  END_IF  
  jsonIterator := fbJson.NextMember(jsonIterator);  
END_WHILE
```

After this run, the sString variable has the following content:

```
{"batteryVoltage":"1547mV","clickType":"SINGLE"}
```
