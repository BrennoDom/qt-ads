# E_TcEventClass

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. E\_TcEventClass

# E\_TcEventClass

```
TYPE E_TcEventClass :  
(  
    TCEVENTCLASS_NONE        :=0, (* No class *)  
    TCEVENTCLASS_MAINTENANCE :=1, (* Maintenance hint *)  
    TCEVENTCLASS_MESSAGE     :=2, (* Message *)  
    TCEVENTCLASS_HINT        :=3, (* Hint *)  
    TCEVENTCLASS_STATEINFO   :=4, (* State information *)  
    TCEVENTCLASS_INSTRUCTION :=5, (* Instruction *)  
    TCEVENTCLASS_WARNING     :=6, (* Warning *)  
    TCEVENTCLASS_ALARM       :=7, (* Alarm *)  
    TCEVENTCLASS_PARAMERROR  :=8 (* Parameter error *)  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
