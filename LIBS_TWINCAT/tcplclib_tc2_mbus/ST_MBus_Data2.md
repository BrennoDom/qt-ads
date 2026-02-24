# ST_MBus_Data2

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
4. [Structures](ms-xhelp:///?Id=beckhoff-4dd1-4d9d-808a-6e4cba67de22)
5. ST\_MBus\_Data2

# ST\_MBus\_Data2

Structure of the output values in the block [FB\_MBUS\_General\_Ext()](ms-xhelp:///?Id=beckhoff-7616-46e1-8f68-e6176732685e).

```
TYPE ST_MBus_Data2 :  
STRUCT  
  arrData : ARRAY[1..cMBUS_MaxData] OF ST_MBus_Data;  
END_STRUCT  
END_TYPE
```

**arrData:** Values.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
