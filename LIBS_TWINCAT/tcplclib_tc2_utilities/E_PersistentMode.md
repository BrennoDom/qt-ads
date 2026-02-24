# E_PersistentMode

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_PersistentMode

Mode in which the persistent data should be written. This data type is used by the function block: [FB\_WritePersistentData](ms-xhelp:///?Id=beckhoff-d009-43a5-8dbb-27889de4e9ba).

```
TYPE E_PersistentMode :  
(  
    SPDM_2PASS     := 0,  
    SPDM_VAR_BOOST := 1  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| SPDM\_2PASS | All data are from the same cycle |
| SPDM\_VAR\_BOOST | Data of individual persistent variables are from the same cycle |

**Example:**

See also: [Writing of persistent data: system behaviour](ms-xhelp:///?Id=beckhoff-7dbf-469d-9b3d-bb346f7d2cc4).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
