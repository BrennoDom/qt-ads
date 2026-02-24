# AddLreal

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddLreal

This method adds a value of the data type LREAL to a property. Usually, a corresponding property was created beforehand with the method [AddKey()](ms-xhelp:///?Id=beckhoff-60aa-4221-b3cc-a3999a39c931).

## Syntax

```
METHOD AddLreal  
VAR_INPUT  
  value : LREAL;  
END_VAR
```

Sample call:

```
fbJson.AddKey('PropertyName');  
fbJson.AddLreal(42.42);
```
