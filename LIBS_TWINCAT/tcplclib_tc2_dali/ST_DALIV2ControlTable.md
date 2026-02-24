# ST_DALIV2ControlTable

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [DUTs](ms-xhelp:///?Id=beckhoff-0d46-4b85-ba71-1afd6231d322)
4. [Structures](ms-xhelp:///?Id=beckhoff-5d3e-4ef1-b36c-0c741eb45d90)
5. ST\_DALIV2ControlTable

# ST\_DALIV2ControlTable

```
TYPE ST_DALIV2ControlTable :  
STRUCT  
  nActualValue  : UINT;  
  nControlValue : BYTE;  
  nSwitchRange  : UINT;  
END_STRUCT  
END_TYPE
```

**nActualValue:** Measured brightness value.

**nControlValue:** Associated switch point/interpolation point for the control value. Valid value range: 0 or nMinLevelMasterDev ... nMaxLevelMasterDev.

**nSwitchRange:** Threshold value around the interpolation point at which switching takes place. The entry "0" marks the beginning of the unused area of the table.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
