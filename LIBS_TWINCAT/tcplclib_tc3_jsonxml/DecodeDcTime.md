# DecodeDcTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# DecodeDcTime

This method enables the generation of a PLC variable of the type DCTIME from a standardized ISO8601 time format (e.g. YYYY-MM-DDThh:mm:ss). DCTIME corresponds to the number of nanoseconds starting from the date 2000-01-01. If the conversion was successful the method returns TRUE, otherwise it returns FALSE.

## Syntax

```
METHOD DecodeDcTime : BOOL  
VAR_IN_OUT CONSTANT  
  sDC : STRING;  
END_VAR  
VAR_OUTPUT  
  nDC : DCTIME;  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
bSuccess := fbJson.DecodeDcTime('2017-08-09T06:54:00', nDc => dcTime);
```
