# E_PD_Datatype

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. E\_PD\_Datatype

# E\_PD\_Datatype

E\_PD\_Datatype contains the possible data types of a Profidrive parameter.

```
TYPE E_PD_Datatype :   
(  
    ePD_UNDEFINED    := 0,  
    ePD_BOOL         := 1,(* 0/1 (not impl.) *)  
    ePD_INT08        := 2,(* -128 .. 127 *)  
    ePD_INT16        := 3,(* -32768 .. 32767 *)  
    ePD_INT32        := 4,(* -2147483648 .. 2147483647 *)  
    ePD_UINT08       := 5,(* 0 .. 255 *)  
    ePD_UINT16       := 6,(* 0 .. 65535 *)  
    ePD_UINT32       := 7,(* 0 .. 4294967295 *)  
    ePD_FLOAT        := 8,(* IEEE 754 *)  
    ePD_VSTRING      := 9,(* ISO/IEC 646, variable length *)  
    ePD_OCTSTRING    := 10,(* bytearray, variable length *)  
    ePD_TIMEOFDAY_WDI := 12,(* 6 Bytes: 4 bytes ms  + 2 bytes day since 1.1.1984 *)  
    ePD_TIMEDIFF     := 13,(* 4|6 Bytes: 4 bytes ms  + optional 2 bytes days*)  
    ePD_N2_16BIT     := 33,  
    ePD_N4_32BIT     := 34,  
    ePD_V2_BITSEQ    := 35,  
    ePD_L2_NIBBLE    := 36,  
    ePD_R2_RECIP_TC  := 37,  
    ePD_T2_TC_16BIT  := 38,  
    ePD_T2_TC_32BIT  := 39,  
    ePD_D2_TC        := 40,  
    ePD_E2_FIXPT_16  := 41,  
    ePD_C2_FIXPT_32  := 42,  
    ePD_X2_NV_16     := 43,  
    ePD_X4_NV_32     := 44,  
    ePD_DATE         := 50,(* 7 Bytes: 2 bytes ms + 2 bits (res.), 6 bits(minutes) + 1 bit (0: StdTime/1:DaylightSavingTime), 2 bits (res.), 5 bits(hours) + 3 bits (DayOfWeek), 5 bits(DayOfMonth) + 2 bits (res.), 6 bits(month) + 1 bit (res.), 7 bits (year)*)  
    ePD_TIMEOFDAY_NODI := 52, (* 0 .. 268435455 ms *)  
    ePD_TIMEDIFF_WDI := 53,(* 6 Bytes: 4 bytes ms + 2 bytes days *)  
    ePD_TIMEDIFF_NODI:= 54,(* 0 .. 4294967295 ms *)  
    ePD_ZERO         := 64,  
    ePD_BYTE         := 65,  
    ePD_WORD         := 66,  
    ePD_DWORD        := 67,  
    ePD_ERROR        := 68  
);  
END_TYPE
```

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Beckhoff FC310x PCI, CX1500-M310, EL6731, EL6632 | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
