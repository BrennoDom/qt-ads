# FB_GetLicensesEx

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetLicensesEx

![13898779](/tcplclib_tc2_utilities/1033/Images/png/4400705163__Web.png)

The function block FB\_GetLicensesEx determines the status of all TwinCAT 3 licenses and OEM licenses.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute : BOOL;  
    tTimeout : TIME;  
    sNetId   : T_AmsNetId;  
END_VAR
```

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Timeout time that must not be exceeded when the command is executed.

**sNetId**: AmsNetId (AMS network identifier) of the TwinCAT computer whose license status is to be read (type: T\_AmsNetId). If it is to be run on the local computer, an empty string can be entered.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy            : BOOL;  
    bError           : BOOL;  
    nErrorId         : UDINT;  
    nValidLicenses   : UDINT  
    aValidLicenses   : ARRAY[1..nMaxLicenses} OF ST_TcOnlineLicenseInfoDataEx  
    nPendingLicenses : UDINT  
    aPendingLicenses : ARRAY[1..nMaxLicenses} OF ST_TcOnlineLicenseInfoDataEx  
    nDemoLicenses    : UDINT  
    aDemoLicenses    : ARRAY[1..nMaxLicenses} OF ST_TcOnlineLicenseInfoDataEx  
    nOemLicenses     : UDINT  
    aOemLicenses     : ARRAY[1..nMaxLicenses} OF ST_TcOnlineLicenseInfoDataEx  
    nFailedLicenses  : UDINT  
    aFailedLicenses  : ARRAY[1..nMaxLicenses} OF ST_TcOnlineLicenseInfoDataEx  
    nInvalidLicenses : UDINT  
    aInvalidLicenses : ARRAY[1..nMaxLicenses} OF ST_TcOnlineLicenseInfoDataEx  
END_VAR 
```

**bBusy**: TRUE, as long as the function block is active.

**bError**: TRUE if an error occurs during command execution.

**nErrorId**: Supplies the ADS error number when the bError output is set.

**nValidLicenses:** Number of valid licenses

**aValidLicenses:** Information on valid licenses

**nPendingLicenses:** Number of open licenses

**aPendingLicenses:** Information on outstanding licenses

**nDemoLicenses:** Number of valid demo licenses

**aDemoLicenses:** Information on valid demo licenses

**nOemLicenses:** Number of valid OEM licenses

**aOemLicenses:** Information on valid OEM licenses

**nFailedLicenses:** Number of failed licenses

**aFailedLicenses:** Information on valid licenses

**nInvalidLicenses:** Number of invalid licenses

**aInvalidLicenses:** Information on invalid licenses

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x64, x86) | Tc2\_Utilties >= 3.3.24.0 |
