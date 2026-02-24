# ST_AmsRouteEntry

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_AmsRouteEntry

This data type contains information on the configuration of a remote TwinCAT connection.

```
TYPE ST_AmsRouteEntry :  
STRUCT  
    sName      : STRING(MAX_ROUTE_NAME_LEN);  
    sNetID     : T_AmsNetId;  
    sAddress   : STRING(MAX_ROUTE_ADDR_LEN);  
    eTransport : E_RouteTransportType;  
    tTimeout   : TIME;  
    dwFlags    : DWORD;  
END_STRUCT  
END_TYPE
```

**sName**: Symbolic name of the remote TwinCAT system. This name can be chosen freely. The maximum string length is limited through a constant (default: 31 characters).

**sNetID**: Network address of the remote TwinCAT system (type: T\_AmsNetID).

**sAddress**: System address in relation to the respective transport layer. If TCP/IP is used as the transport layer the IP address is specified here. The maximum string length is limited through a constant (default: 79 characters).

**eTransport**: Transport layer used for carrying AMS messages (type: [E\_RouteTransportType](ms-xhelp:///?Id=beckhoff-bc21-47c8-a65b-78ccd53a0ab5)). Currently only the TCP/IP transport layer is supported.

**tTimeout**: Timeout time. (currently reserved but not used).

**dwFlags**: Additional options (currently reserved but not used).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
