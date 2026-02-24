# FB_GetLicenses

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetLicenses

![57338399](/tcplclib_tc2_utilities/1033/Images/png/9007201131522827__Web.png)

The function block reads the valid and invalid TwinCAT licenses.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute  : BOOL;  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;  
    sNetId    : T_AmsNetId;  
END_VAR
```

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

**sNetId**: This is the parameter to specify the AmsNetID (type: T\_AmsNetID) of the TwinCAT computer, whose current TwinCAT licenses are to be read. If it is to be run on the local computer, an empty string can be entered.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy      : BOOL;  
    bError     : BOOL;  
    nErrorId   : UDINT;  
    nValidLicenses : UDINT;  
    aValidLicenses : ARRAY [1..nMaxLicenses] OF ST_TcOnlineLicenseInfoData;  
    nInvalidLicenses : UDINT;  
    aInvalidLicenses : ARRAY [1..nMaxLicenses] OF ST_TcOnlineLicenseInfoData;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: If an error should occur during the transfer of the command, then this output is set once the bBusy output was reset.

**nErrorId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the bError output is set.

**nValidLicenses**: Returns the number of valid TwinCAT licenses.

**aValidLicenses**: Returns a list of valid TwinCAT licenses of data type [ST\_TcOnlineLicenseInfodata](ms-xhelp:///?Id=beckhoff-9066-47b3-b9c2-dce78b6a13c4).

**nInvalidLicenses**: Returns the number of invalid TwinCAT licenses.

**aInvalidLicenses**: Returns a list of invalid TwinCAT licenses of data type [ST\_TcOnlineLicenseInfodata](ms-xhelp:///?Id=beckhoff-9066-47b3-b9c2-dce78b6a13c4).

|  |  |
| --- | --- |
| 46283551 | By default, the maximum number of license list entries is 50. This limit can be changed in the parameter list of the library via nMaxLicenses. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4018 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (system) v3.3.9.0 or higher |
