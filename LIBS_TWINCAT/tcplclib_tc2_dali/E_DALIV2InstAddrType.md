# E_DALIV2InstAddrType

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [DUTs](ms-xhelp:///?Id=beckhoff-0d46-4b85-ba71-1afd6231d322)
4. [Enums](ms-xhelp:///?Id=beckhoff-d73a-4481-8374-39cf24a018fd)
5. E\_DALIV2InstAddrType

# E\_DALIV2InstAddrType

```
TYPE E_ DALIV2InstAddrType:  
(  
  eDALIV2InstAddrTypeNumber            := 0,  (* Instance number (0-31) *)  
  eDALIV2InstAddrTypeGroup             := 1,  (* Instance group (0-31) *)  
  eDALIV2InstAddrTypeType              := 2,  (* Instance type (0-31) *)  
  eDALIV2InstAddrTypeFeatureNumber     := 3,  (* Feature on instance number level (0-31) *)  
  eDALIV2InstAddrTypeFeatureGroup      := 4,  (* Feature on instance group level (0-31) *)  
  eDALIV2InstAddrTypeFeatureType       := 5,  (* Feature on instance type level (0-31) *)  
  eDALIV2InstAddrTypeFeatureBroadcast  := 6,  (* Feature on instance broadcast level *)  
  eDALIV2InstAddrTypeBroadcast         := 7,  (* Instance broadcast *)  
  eDALIV2InstAddrTypeFeatureDevice     := 8,  (* Feature on device level *)  
  eDALIV2InstAddrTypeDevice            := 9   (* Device *)  
);  
END_TYPE
```

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
