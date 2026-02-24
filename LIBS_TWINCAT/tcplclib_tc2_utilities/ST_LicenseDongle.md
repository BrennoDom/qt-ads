# ST_LicenseDongle

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_LicenseDongle

Structure with identification data of all connected license dongles

```
TYPE ST_LicenseDongle :  
STRUCT  
    stAmsAddr     : AMSADDR;  
    eDevType      : E_LDevType;  
    nFlags        : UDINT;  
    eDongleStatus : E_LDongleStatus;  
    nSerialNo     : UDINT;  
    nReserved1    : UDINT;  
    nReserved2    : UDINT;  
END_STRUCT  
END_TYPE
```

| Name | Description |
| --- | --- |
| stAmsAddr | Network ID (AmsNetId and port) of the license dongle |
| eDevType | See [E\_LDevType](ms-xhelp:///?Id=beckhoff-5b15-4b8c-80a1-4e09a4c330c1) |
| nFlags | 0: statically configured  1: dynamic dongle |
| eDongleStatus | Validation status of the license dongle (see [E\_LDongleStatus](ms-xhelp:///?Id=beckhoff-cfec-4b5f-8055-03197f843d26)) |
| nSerialNo | ID number of the dongle / License Key Terminal |
| nReserved1 | Reserved for future use |
| nReserved2 | Reserved for future use |
