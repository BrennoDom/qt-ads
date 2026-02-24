# REMOTEPC

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# REMOTEPC

Remote PC configuration entry.

```
TYPE REMOTEPC :  
STRUCT  
    NetId : T_AmsNetId;  
    Name  : STRING(31);  
END_STRUCT  
ND_TYPE
```

**NetId**: Network address of the remote PC (type: T\_AmsNetID);

**Name**: The remote PC identifier;

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
