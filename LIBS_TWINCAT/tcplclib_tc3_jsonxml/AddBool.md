# AddBool

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddBool

This method adds a value of the data type BOOL to a property. Usually, a corresponding property was created beforehand with the method [AddKey()](ms-xhelp:///?Id=beckhoff-60aa-4221-b3cc-a3999a39c931).

## Syntax

```
METHOD AddBool  
VAR_INPUT  
  value : BOOL;  
END_VAR
```

Sample call:

```
fbJson.AddKey('bSwitch');  
fbJson.AddBool(TRUE);
```
