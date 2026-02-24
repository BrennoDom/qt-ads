# DecodeFileTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# DecodeFileTime

This method enables the generation of a PLC variable of the type FILETIME from a standardized ISO8601 time format (e.g. YYYY-MM-DDThh:mm:ss). FILETIME corresponds to the number of nanoseconds starting from the date 1601-01-01 – measured in 100 nanoseconds. If the conversion was successful the method returns TRUE, otherwise it returns FALSE.

## Syntax

```
METHOD DecodeDateTime : BOOL  
VAR_IN_OUT CONSTANT  
  sFT : STRING;  
END_VAR  
VAR_OUTPUT  
  nFT : FILETIME;  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
bSuccess := fbJson.DecodeFileTime('2017-08-09T06:54:00', nFT => fileTime);
```
