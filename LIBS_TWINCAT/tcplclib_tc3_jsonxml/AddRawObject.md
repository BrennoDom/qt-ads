# AddRawObject

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddRawObject

This method adds a valid JSON object to a given property as a value. The object to be added must be in a valid JSON format and may only be added if the SAX writer is at a correspondingly valid position, i.e. for example, directly after a preceding [AddKey()](ms-xhelp:///?Id=beckhoff-60aa-4221-b3cc-a3999a39c931), [StartArray()](ms-xhelp:///?Id=beckhoff-4c25-47cb-92d7-d54fe05cb802) or as the first call after a [ResetDocument()](ms-xhelp:///?Id=beckhoff-ba8e-4ab5-bd38-3c042250086c).

## Syntax

```
METHOD AddRawObject  
VAR_IN_OUT CONSTANT  
  rawJson : STRING;  
END_VAR
```

Sample call:

```
fbJson.AddKey('PropertyName');  
fbJson.AddRawObject('{"x":42, "y":42}');
```
