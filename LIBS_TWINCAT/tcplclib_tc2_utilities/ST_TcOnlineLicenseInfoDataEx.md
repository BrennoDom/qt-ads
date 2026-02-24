# ST_TcOnlineLicenseInfoDataEx

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_TcOnlineLicenseInfoDataEx

```
TYPE ST_TcOnlineLicenseInfoDataEx :  
STRUCT  
    stLicenseId       : GUID  
    stLicenseName     : STRING(80);  
    tExpirationTime   : TIMESTRUCT;  
    sExpirtaionTime   : STRING(80);  
    nMaxCount         : UDINT;  
    nUsedCount        : UDINT;  
    eResult           : E_LicenseHResult;  
    nVolumeNo         : UDINT;  
    nOptInfo          : WORD;  
    nRestriction      : WORD;  
    bOemLicense       : BOOL;  
    bBeckhoffLicense  : BOOL;  
    bBeckhoffPC       : BOOL;  
    bEtherCATDongle   : BOOL;  
    bUSBDongle        : BOOL;  
    bGenDevTypeLic    : BOOL;  
END_STRUCT  
END_TYPE
```

| Name | Description |
| --- | --- |
| stLicenseId | License ID |
| stLicenseName | License name |
| tExpirationTime | Expiry date |
| sExpirationTime | Expiry date |
| nMaxCount | Maximum number of instances that can be used for this license (0=unlimited) |
| nUsedCount | Number of license instances used |
| eResult | License status (see [E\_LicenseHResult](ms-xhelp:///?Id=beckhoff-e8d5-4965-a7a6-449a631cf6fd)) |
| nVolumeNo | (only for volume licenses): Volume bundle number  0: no bundle number |
| nOptInfo | (internal) |
| nRestriction | License has restrictions on usage |
| bOemLicense | OEM license |
| bBeckhoffLicense | Beckhoff license |
| bBeckhoffPC | License for Beckhoff hardware (IPC, CX etc.) |
| bEtherCATDongle | License is for EtherCAT License Key Terminal, e.g. EL6070 |
| bUSBDongle | License is for USB license dongle, e.g. C9900-L100 |
| bGenDevTypeLic | License is for the device type |
