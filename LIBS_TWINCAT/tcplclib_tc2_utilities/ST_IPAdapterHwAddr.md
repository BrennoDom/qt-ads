# ST_IPAdapterHwAddr

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_IPAdapterHwAddr

Physical address (MAC).

```
TYPE ST_IPAdapterHwAddr :  
STRUCT  
    length : UDINT := 0;  
    b      : ARRAY[0..MAX_ADAPTER_ADDRESS_LENGTH] OF BYTE;  
END_STRUCT  
END_TYPE
```

**length**: Byte length of the physical hardware address.

**b**: MAC address bytes.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
