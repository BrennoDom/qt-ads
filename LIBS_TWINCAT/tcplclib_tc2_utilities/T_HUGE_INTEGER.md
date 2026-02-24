# T_HUGE_INTEGER

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# T\_HUGE\_INTEGER

Variables of this type represent a TwinCAT 2 signed 128-bit number (“legacy” type).

```
TYPE T_HUGE_INTEGER :  
STRUCT  
   qwLowPart  : T_ULARGE_INTEGER;  
   qwHighPart : T_ULARGE_INTEGER;  
END_STRUCT  
END_TYPE
```

**qwLowPart**: Lower 64 bits.

**qwHighPart**: Upper 64 bits.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
