# ST_CheckLicense

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_CheckLicense

Structure with license information

```
TYPE ST_CheckLicense :  
STRUCT  
    stLicenseId     : GUID;  
    tExpirationTime : TIMESTRUCT;  
    sExpirationTime : STRING(80);  
    eResult         : E_LicenseHResult;  
    nCount          : UDINT;  
END_STRUCT  
END_TYPE
```

| Name | Description |
| --- | --- |
| stLicenseId | License ID |
| tExpirationTime | Expiry date |
| sExpirationTime | Expiry date |
| eResult | License status (see [E\_LicenseHResult](ms-xhelp:///?Id=beckhoff-e8d5-4965-a7a6-449a631cf6fd)) |
| nCount | Number of instances for this license (0=unlimited) |
