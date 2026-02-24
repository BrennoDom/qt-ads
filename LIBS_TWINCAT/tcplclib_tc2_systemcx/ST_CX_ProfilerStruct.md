# ST_CX_ProfilerStruct

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Data Types](ms-xhelp:///?Id=beckhoff-4a07-48a9-b44d-b1ed4891f6d2)
3. ST\_CX\_ProfilerStruct

# ST\_CX\_ProfilerStruct

```
TYPE ST_CX_ProfilerStruct:  
STRUCT  
 dwLastExecTime    : DWORD;  
 dwMinExecTime     : DWORD;  
 dwMaxExecTime     : DWORD;  
 dwAverageExecTime : DWORD;  
 dwMeasureCycle    : DWORD;  
END_STRUCT  
END_TYPE
```

**dwLastExecTime**: The most recently measured value for the execution time in [µs]

**dwMinExecTime**: The minimum execution time in [µs]

**dwMaxExecTime**: The maximum execution time in [µs]

**dwAverageExecTime**: The mean execution time for the last 100 measurements in [µs]

**dwMeasureCycle**: The number of measurements that have already been carried out

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | CX (x86) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
