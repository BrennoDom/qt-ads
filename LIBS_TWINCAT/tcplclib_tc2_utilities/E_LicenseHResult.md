# E_LicenseHResult

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_LicenseHResult

```
TYPE E_LicenseHResult :  
(  
    //success  
    E_LHR_LicenseOK                : DINT := 0,  
    E_LHR_LicenseOK_Pending        : DINT := 16#203,  
    E_LHR_LicenseOK_Demo           : DINT := 16#254,  
    E_LHR_LicenseOK_OEM            : DINT := 16#255,  
    //error  
    E_LHR_LicenseNoFound           : DINT := DWORD_TO_DINT(16#98110700+16#24),  
    E_LHR_LicenseExpired           : DINT := DWORD_TO_DINT(16#98110700+16#25),  
    E_LHR_LicenseExceeded          : DINT := DWORD_TO_DINT(16#98110700+16#26),  
    E_LHR_LicenseInvalid           : DINT := DWORD_TO_DINT(16#98110700+16#27),  
    E_LHR_LicenseSystemIdInvalid   : DINT := DWORD_TO_DINT(16#98110700+16#28),  
    E_LHR_LicenseNoTimeLimit       : DINT := DWORD_TO_DINT(16#98110700+16#29),  
    E_LHR_LicenseTimeInFuture      : DINT := DWORD_TO_DINT(16#98110700+16#2A),  
    E_LHR_LicenseTimePeriodToLong  : DINT := DWORD_TO_DINT(16#98110700+16#2B),  
    E_LHR_DeviceException          : DINT := DWORD_TO_DINT(16#98110700+16#2C),  
    E_LHR_LicenseDuplicated        : DINT := DWORD_TO_DINT(16#98110700+16#2D),  
    E_LHR_SignatureInvalid         : DINT := DWORD_TO_DINT(16#98110700+16#2E),  
    E_LHR_CertificateInvalid       : DINT := DWORD_TO_DINT(16#98110700+16#2F),  
    E_LHR_LicenseOemNotFound       : DINT := DWORD_TO_DINT(16#98110700+16#30),  
    E_LHR_LicenseRestricted        : DINT := DWORD_TO_DINT(16#98110700+16#31),  
    E_LHR_LicenseDemoDenied        : DINT := DWORD_TO_DINT(16#98110700+16#32),  
    E_LHR_LicensePlatformLevelInv  : DINT := DWORD_TO_DINT(16#98110700+16#33)  
)DINT;  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| E\_LHR\_LicenseOK | License is valid |
| E\_LHR\_LicenseOK\_Pending | Validation of the licensing device (e.g. License Key Terminal) required |
| E\_LHR\_LicenseOK\_Demo | Trial license is valid |
| E\_LHR\_LicenseOK\_OEM | OEM license is valid |
| E\_LHR\_LicenseNoFound | Missing license |
| E\_LHR\_LicenseExpired | License expired |
| E\_LHR\_LicenseExceeded | License has too few instances |
| E\_LHR\_LicenseInvalid | License is invalid |
| E\_LHR\_LicenseSystemIdInvalid | Incorrect system ID for the license |
| E\_LHR\_LicenseNoTimeLimit | License not limited in time |
| E\_LHR\_LicenseTimeInFuture | License problem: Time of issue is in the future |
| E\_LHR\_LicenseTimePeriodToLong | License period too long |
| E\_LHR\_DeviceException | Exception at system startup |
| E\_LHR\_LicenseDuplicated | License data read multiple times |
| E\_LHR\_SignatureInvalid | Invalid signature |
| E\_LHR\_CertificateInvalid | Invalid certificate |
| E\_LHR\_LicenseOemNotFound | OEM license for unknown OEM |
| E\_LHR\_LicenseRestricted | License invalid for the system |
| E\_LHR\_LicenseDemoDenied | Trial license not allowed |
| E\_LHR\_LicensePlatformLevelInv | Invalid platform level for the license |
