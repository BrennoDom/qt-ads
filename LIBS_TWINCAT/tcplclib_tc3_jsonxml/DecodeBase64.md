# DecodeBase64

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# DecodeBase64

This method converts a Base64-formated string to binary data. If the conversion was successful the method returns TRUE, otherwise it returns FALSE.

## Syntax

```
METHOD DecodeBase64 : BOOL  
VAR_INPUT  
  sBase64 : STRING;  
  pBytes  : POINTER TO BYTE;  
  nBytes  : REFERENCE TO DINT;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
bSuccess := fbJson.DecodeBase64('SGVsbG8gVHdpbkNBVA==', ADR(byteArray), byteArraySize);
```
