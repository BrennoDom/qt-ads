# AddString

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddString

This method adds a value of the data type STRING to a property. Usually, a corresponding property was created beforehand with the method [AddKey()](ms-xhelp:///?Id=beckhoff-60aa-4221-b3cc-a3999a39c931).

## Syntax

```
METHOD AddString  
VAR_IN_OUT CONSTANT  
  value : STRING;  
END_VAR
```

Sample call:

```
fbJson.AddKey('PropertyName');  
fbJson.AddString('Hello World');
```
