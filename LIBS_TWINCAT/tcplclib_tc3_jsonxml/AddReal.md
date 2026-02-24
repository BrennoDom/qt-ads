# AddReal

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddReal

This method adds a value of the data type REAL to a property. Usually, a corresponding property was created beforehand with the method [AddKey()](ms-xhelp:///?Id=beckhoff-60aa-4221-b3cc-a3999a39c931).

## Syntax

```
METHOD AddReal  
VAR_INPUT  
  value : REAL;  
END_VAR
```

Sample call:

```
fbJson.AddKey('PropertyName');  
fbJson.AddReal(42.42);
```
