# ST_FileRBufferHead

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_FileRBufferHead

Ring buffer file header status. This structure is used by the function block [FB\_FileRingBuffer](ms-xhelp:///?Id=beckhoff-9efb-4052-a2f1-dbe10286d0bb). This structure is read when the ring buffer file opened and saved in the ring buffer file when it is closed. This structure is always updated when data sets are read/written.

```
TYPE ST_FileRBufferHead :  
STRUCT  
    status   : DWORD := 0;(* buffer status flags Bit 0 = 1 => Opened, Bit 0 = 0 => Closed, Bit 1 = 1 file corrupted, all other bits are reserved *)  
    access   : UDINT := 0;(* access counter, increments every time the buffer is reopened *)  
    nID      : UDINT := 0;(* user defined value *)  
    cbBuffer : UDINT := 16#100000;(* max. buffer size (1MB) *)  
    nCount   : UDINT := 0;(* number of fifo entries *)  
    cbSize   : UDINT := 0;(* current (used) file buffer data byte length *)  
    ptrFirst : UDINT := 0;(* seek pointer start position of first (oldest) buffer entry *)  
    ptrLast  : UDINT := 0;(* seek pointer end position of last (newest) buffer entry *)  
    rsrv0    : UDINT := 0;(* reserved *)  
    rsrv1    : UDINT := 0;(* reserved *)  
    rsrv2    : UDINT := 0;(* reserved *)  
    rsrv3    : UDINT := 0;(* reserved *)  
END_STRUCT  
END_TYPE
```

**status**: Status flags. Bit 0 = 1 => file is open, bit 0 = 0 => file is closed. Bit 1 = 1 => file is corrupt (was not closed properly, or the maximum buffer size does not match).

**acces**: Access counter. This counter is incremented whenever the file is opened.

**nID**: User-defined 32-bit value.

**cbBuffer**: Maximum ring buffer file size.

**nCount**: Current number of stored data sets.

**cbSize**: Current number of stored data bytes.

**ptrFirst**: File pointer position of the oldest data set.

**ptrLast**: File pointer position of the latest data set.

**rsrv0..rsrv3**: Reserved.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
