# DecodeHexBinary

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# DecodeHexBinary

This method converts a string containing hexadecimal values into binary data. If the conversion was successful the method returns TRUE, otherwise it returns FALSE.

## Syntax

```
METHOD DecodeHexBinary : BOOL  
VAR_IN_OUT CONSTANT  
  sHex : STRING;  
END_VAR  
VAR_INPUT  
  pBytes : POINTER TO BYTE;  
  nBytes : REFERENCE TO DINT;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
bSuccess := fbJson.DecodeHexBinary('ABCEF93A', ADR(byteArray), byteArraySize);
```
