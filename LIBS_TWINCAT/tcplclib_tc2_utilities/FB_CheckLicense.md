# FB_CheckLicense

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_CheckLicense

|  |  |
| --- | --- |
| 3728830 | If you use OEM licenses make sure you encrypt your boot project!  Remember that the license ID queried via FB\_CheckLicense in the binary code can easily be found and (with a little effort) manipulated with a hex editor. Therefore, be sure to encrypt your boot project (safest), or at least disguise the queried license ID in the source code as best as possible. |

![33559471](/tcplclib_tc2_utilities/1033/Images/png/4400699403__Web.png)

The function block FB\_CheckLicense determines the TwinCAT 3 license status for a given license ID.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute    : BOOL;  
    tTimeout    : TIME;  
    sNetId      : T_AmsNetId;  
    stLicenseId : GUID;  
END_VAR
```

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Timeout time that must not be exceeded when the command is executed.

**sNetId**: AmsNetId (AMS network identifier) of the TwinCAT computer whose license status is to be read (type: T\_AmsNetId). If it is to be run on the local computer, an empty string can be entered.

**stLicenseId**: License ID (type: GUID)

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy          : BOOL;  
    bError         : BOOL;  
    nErrorId       : UDINT;  
    stCheckLicense : ST_CheckLicense  
END_VAR 
```

**bBusy**: TRUE, as long as the function block is active.

**bError**: TRUE if an error occurs during command execution.

**nErrorId**: Supplies the ADS error number when the bError output is set.

**stCheckLicense**: Structure with license data (type: ST\_CheckLicense)

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x64, x86) | Tc2\_Utilties >= 3.3.24.0 |
