# AddUdint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddUdint

This method adds a value of the data type UDINT to a property. Usually, a corresponding property was created beforehand with the method [AddKey()](ms-xhelp:///?Id=beckhoff-60aa-4221-b3cc-a3999a39c931).

## Syntax

```
METHOD AddUdint  
VAR_INPUT  
  value : UDINT;  
END_VAR
```

Sample call:

```
fbJson.AddKey('PropertyName');  
fbJson.AddUdint(42);
```
