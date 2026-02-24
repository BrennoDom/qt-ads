# AddKeyBool

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddKeyBool

This method creates a new property key and at the same time a value of the data type BOOL.

## Syntax

```
METHOD AddKeyBool  
VAR_IN_OUT CONSTANT  
  key : STRING;  
END_VAR  
VAR_INPUT  
  value : BOOL;  
END_VAR
```

Sample call:

```
fbJson.AddKeyBool('bSwitch', TRUE);
```
