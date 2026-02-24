# ST_IPAdapterInfo

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_IPAdapterInfo

Network adapter information.

```
TYPE ST_IPAdapterInfo :  
STRUCT  
    bDefault      : BOOL;  
    sAdapterName  : STRING(MAX_ADAPTER_NAME_LENGTH) := '';  
    sDescription  : STRING(MAX_ADAPTER_DESCRIPTION_LENGTH) := '';  
    physAddr      : ST_IPAdapterHwAddr;  
    dwIndex       : DWORD;  
    eType         : E_MIB_IF_Type;  
    sIpAddr       : T_IPv4Addr;  
    sSubNet       : T_IPv4Addr;  
    sDefGateway   : T_IPv4Addr;  
    bDhcpEnabled  : BOOL;  
    sDhcpSrv      : T_IPv4Addr;  
    bHaveWins     : BOOL;  
    sPrimWinsSrv  : T_IPv4Addr;  
    sSecWinsSrv   : T_IPv4Addr;  
    tLeaseObt     : DT;  
    tLeaseExp     : DT;  
END_STRUCT  
END_TYPE
```

**bDefault**: This variable is currently **only used under Windows CE**! If TRUE TwinCAT uses the network adapter as default adapter.

**sAdapterName**: Adapter name as string.

**sDescription**: Adapter description as string.

**physAddr**: Physical hardware address. (Type: [ST\_IPAdapterHwAddr](ms-xhelp:///?Id=beckhoff-8edd-4b87-bd9c-0120289341e7))

**dwIndex**: Internal adapter system index.

**eType**: Adapter type (type: [E\_MIB\_IF\_Type](ms-xhelp:///?Id=beckhoff-54b0-46b5-810c-010bc13e81bd)).

**sIpAddr**: IP address (type: T\_Ipv4Addr).

**sSubNet**: IP network mask (type: T\_Ipv4Addr).

**sDefGateway**: IP address of the default gateway (type: T\_Ipv4Addr).

**bDhcpEnabled**: Indicates whether DHCP was activated for this adapter or not.

**sDhcpSrv**: IP address of the DHCP server (type: T\_Ipv4Addr).

**bHaveWins**: Indicates whether the Windows Internet Name Service (WINS) is used or not.

**sPrimWinsSrv**: IP address of the primary WINS server (type: T\_Ipv4Addr).

**sSecWinsSrv**: IP address of the secondary WINS server (type: T\_Ipv4Addr).

**tLeaseObt**: Indicates when the IP address was “hired" by the DHCP server (UTC).

**tLeaseExp**: Indicates how long the IP address can be “rented” by the DHCP server before an ”extension" has to be requested by the DHCP server (UTC).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
