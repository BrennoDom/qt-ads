# DecodeDateTime

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# DecodeDateTime

This method enables the generation of a PLC variable of the type DATE\_AND\_TIME or DT from a standardized ISO8601 time format (e.g. YYYY-MM-DDThh:mm:ss). DT corresponds to the number of seconds starting from the date 1970-01-01. If the conversion was successful the method returns TRUE, otherwise it returns FALSE.

## Syntax

```
METHOD DecodeDateTime : BOOL  
VAR_IN_OUT CONSTANT  
  sDT : STRING;  
END_VAR  
VAR_OUTPUT  
  nDT : DATE_AND_TIME;  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
bSuccess := fbJson.DecodeDateTime('2017-08-09T06:54:00', nDT => dateTime);
```
