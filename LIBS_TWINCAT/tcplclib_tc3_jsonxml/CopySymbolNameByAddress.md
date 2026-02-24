# CopySymbolNameByAddress

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# CopySymbolNameByAddress

This method returns the complete (ADS) symbol name of a transferred symbol. The method returns the size of the string (including null termination). If the target buffer is too small, it is emptied by a null termination and returned as length 0.

## Syntax

```
METHOD CopySymbolNameByAddress : UDINT  
VAR_INPUT  
    nData    : UDINT;    // size of symbol  
    pData    : PVOID;    // address of symbol  
END_VAR  
VAR_IN_OUT CONSTANT  
    sName    : STRING;    // target string buffer where the symbol name should be copied to  
END_VAR  
VAR_INPUT  
    nName    : UDINT;    // size in bytes of target string buffer  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
nSymbolSize := fbJsonDataType.CopySymbolNameByAddress(nData:=SIZEOF(stValues), pData:=ADR(stValues), sName:=sSymbolName, nName:=SIZEOF(sSymbolName));
```

## Requirements

| TwinCAT version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4024.20 | x86, x64, ARM | Tc3\_JsonXml 3.3.15.0 |
