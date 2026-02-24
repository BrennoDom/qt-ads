# ST_TcOnlineLicensesInfoData

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_TcOnlineLicensesInfoData

License information.

```
TYPE ST_TimeZoneInformation :  
STRUCT  
    stLicenseId     : GUID;  
    sLicenseName    : STRING(80);  
    tExpirationTime : TIMESTRUCT;  
    sExpirationTime : STRING(80);  
    nMaxCount       : UDINT;  
    nUsedCount      : UDINT;  
    eResult         : E_LicenseHResult;  
END_STRUCT  
END_TYPE
```

**stLicenseId**: Defines the License ID as [GUID](ms-xhelp:///?Id=beckhoff-7f71-4e6d-8084-282179f8e0ac).

**sLicenseName**: Name of the license as a string.

**tExpirationTime**: Indicates the expiration time of the license (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

**sExpirationTime**: Indicates the expiration time of the license as a string.

**nMaxCount**: Indicates the maximum number of permitted instances, if the license concerned is one that contains a limitation of instances (e.g. TC3 NC PTP Axes Pack 25).

**nUsedCount**: Indicates the number of instances used, if the license concerned is one that contains a limitation of instances.

**eResult**: Outputs an error code for this license as an HResult enumeration. (An error is represented by a negative value here).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0.4018 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) v3.3.9.0 or higher |
