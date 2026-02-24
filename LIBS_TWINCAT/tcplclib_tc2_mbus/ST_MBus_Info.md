# ST_MBus_Info

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
4. [Structures](ms-xhelp:///?Id=beckhoff-4dd1-4d9d-808a-6e4cba67de22)
5. ST\_MBus\_Info

# ST\_MBus\_Info

Value information.

```
TYPE ST_MBus_Info :  
STRUCT  
  sValue : STRING(25);  
  sUnit  : STRING(20);  
  eFct   : E_MBus_Fct;  
END_STRUCT  
END_TYPE
```

**sValue:** Value as string.

**sUnit:** Unit of the value as string.

**eFct:** Function (see [E\_MBus\_Fct](ms-xhelp:///?Id=beckhoff-dd96-4b02-8ca1-4f557facff7b)).

M-Bus devices may supply very large values, which cannot be displayed or can only be displayed inaccurately as numbers on BC/BX systems. The values are therefore supplied as strings (*sValue*).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
