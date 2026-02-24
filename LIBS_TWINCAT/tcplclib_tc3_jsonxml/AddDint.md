# AddDint

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddDint

This method adds a value of the data type DINT to a property. Usually, a corresponding property was created beforehand with the method [AddKey()](ms-xhelp:///?Id=beckhoff-60aa-4221-b3cc-a3999a39c931).

## Syntax

```
METHOD AddDint  
VAR_INPUT  
  value : DINT;  
END_VAR
```

Sample call:

```
fbJson.AddKey('nNumber');  
fbJson.AddDint(42);
```
