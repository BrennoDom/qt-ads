# E_RouteTransportType

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_RouteTransportType

Transport layer used for carrying AMS messages. Currently only TCP/IP is supported as transport layer.

```
TYPE E_RouteTransportType :  
(  
    eRouteTransport_None         := 0,  
    eRouteTransport_TCP_IP       := 1,  
    eRouteTransport_IIO_LIGHTBUS := 2,  
    eRouteTransport_PROFIBUS_DP  := 3,  
    eRouteTransport_PCI_ISA_BUS  := 4,  
    eRouteTransport_ADS_UDP      := 5,  
    eRouteTransport_FATP_UDP     := 6,  
    eRouteTransport_COM_PORT     := 7,  
    eRouteTransport_USB          := 8,  
    eRouteTransport_CAN_OPEN     := 9,  
    eRouteTransport_DEVICE_NET   := 10,  
    eRouteTransport_SSB          := 11,  
    eRouteTransport_SOAP         := 12  
);  
END_TYPE
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
