# ST_KL6821OutData

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [DUTs](ms-xhelp:///?Id=beckhoff-e84a-422d-b94e-99adcaade658)
4. [Structures](ms-xhelp:///?Id=beckhoff-889b-4c62-8488-daa2897ee3a6)
5. ST\_KL6821OutData

# ST\_KL6821OutData

```
TYPE ST_KL6821OutData :  
STRUCT  
  nCtrl             : WORD;  
  aData             : ARRAY [0..3] OF BYTE;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.29 | Tc3\_DALI from v3.1.4.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
