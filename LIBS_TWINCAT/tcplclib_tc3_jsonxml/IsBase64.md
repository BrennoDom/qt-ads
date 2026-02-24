# IsBase64

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# IsBase64

This method checks whether the transferred string corresponds to the Base64 format. If that is the case, the method returns TRUE, otherwise it returns FALSE.

## Syntax

```
METHOD IsBase64 : BOOL  
VAR_IN_OUT CONSTANT  
  sBase64 : STRING;  
END_VAR
```

Sample call:

```
bIsBase64 := fbJson.IsBase64('SGVsbG8gVHdpbkNBVA==');
```
