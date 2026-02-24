# PROFILERSTRUCT

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# PROFILERSTRUCT

Status information of the profiler function block.

```
TYPE PROFILERSTRUCT :  
STRUCT  
    LastExecTime     : DWORD;  
    MinExecTime      : DWORD;  
    MaxExecTime      : DWORD;  
    AverageExecTime  : DWORD;  
    MeasureCycle     : DWORD;  
END_STRUCT  
END_TYPE
```

**LastExecTime**: The most recently measured value for the execution time in [µs].

**MinExecTime**: The minimum execution time in [µs].

**MaxExecTime**: The maximum execution time in [µs].

**AverageExecTime**: The mean execution time for the last 10 measurements in [µs].

**MeasureCycle**: The number of measurements that have already been carried out.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
