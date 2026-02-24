# FB_GetLicenseDongles

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetLicenseDongles

![43653635](/tcplclib_tc2_utilities/1033/Images/png/4400703243__Web.png)

The function block determines the number of connected license dongles and returns address and status.

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
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrorId : UDINT;  
    nLicenseDeviceDongles : UDINT;  
    aLicenseDeviceDongles : ARRAY[1..nMaxLicenseDevices] OF ST_LicenseDongle;  
END_VAR 
```

**bBusy**: TRUE, as long as the function block is active.

**bError**: TRUE if an error occurs during command execution.

**nErrorId**: Supplies the ADS error number when the bError output is set.

**nLicenseDeviceDongles**: Number of license dongles

**aLicenseDeviceDongles:** Identification data of the connected license dongles

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x64, x86) | Tc2\_Utilties >= 3.3.24.0 |
