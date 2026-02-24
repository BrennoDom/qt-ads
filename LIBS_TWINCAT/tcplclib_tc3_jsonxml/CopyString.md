# CopyString

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# CopyString

This method copies the value of a key into a variable of the data type STRING, which can be of any length. The method returns the length of the copied string (including null termination). If the target buffer is too small, it is emptied by a null termination and returned as length 0.

## Syntax

```
METHOD CopyString : UDINT  
VAR_INPUT  
  v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  pStr : STRING;  
  nStr : UDINT;  
END_VAR
```

Sample call:

The following JSON document is to be loaded into the DOM memory:

```
sMessage := ' {"serialNumber":"123","batteryVoltage":"1547mV","clickType":"SINGLE"}';
```

The value of the key "clickType" is to be extracted and stored in a variable of data type STRING. First, the JSON document is iteratively searched for the property "clickType".

```
jsonDoc := fbJson.ParseDocument(sMessage);  
jsonIterator := fbJson.MemberBegin(jsonDoc);  
jsonIteratorEnd := fbJson.MemberEnd(jsonDoc);  
WHILE jsonIterator <> jsonIteratorEnd DO  
  sName := fbJson.GetMemberName(jsonIterator);  
  jsonValue := fbJson.GetMemberValue(jsonIterator);  
  IF sName = 'clickType' THEN  
    fbJson.CopyString(jsonValue, sString, SIZEOF(sString));  
  END_IF  
  jsonIterator := fbJson.NextMember(jsonIterator);  
END_WHILE
```

After this run, the sString variable has the following content:

```
SINGLE
```
