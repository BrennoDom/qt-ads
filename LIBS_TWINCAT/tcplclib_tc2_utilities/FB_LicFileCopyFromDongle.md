# FB_LicFileCopyFromDongle

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_LicFileCopyFromDongle

![59962836](/tcplclib_tc2_utilities/1033/Images/png/4579227915__Web.png)

The function block copies a file from the license dongle to the hard disk. If the file is larger than the buffer (cbCopyLen), the file copying procedure is automatically split into several read and write operations until the whole file is copied. Only then does bBusy switch to FALSE.

## VAR\_INPUT

```
VAR_INPUT  
    sNetIdSrc         : T_AmsNetId;  
    nPortSrc          : UINT;  
    sNetIdDest        : T_AmsNetId;  
    sFileNameSrc      : STRING;  
    sFilePathNameDest : T_MaxString;  
    pCopyBuff         : PVOID;  
    cbCopyLen         : UDINT;  
    bExecute          : BOOL;  
    dwPassCode        : DWORD;  
    tTimeout          : TIME    := DEFAULT_ADS_TIMEOUT  
END_VAR
```

**sNetIdSrc**: AmsNetId (AMS network identifier) of the license dongle (type: T\_AmsNetId)

* USB dongle: AmsNetId of the TwinCAT computer. If it is to be run on the local computer, an empty string can be entered.
* EL6070: AmsNetId of the EtherCAT master (see AdsAddr.netId in the InfoData of the EL6070)

**nPortSrc**: AMS port of the license dongle

* USB: ADS port of the ESB device (see ADS port on the ESB Device tab of the USB dongle; the default is 16#7100)
* EL6070: ADS port of the EtherCAT Terminal (see AdsAddr.port in the InfoData of the EL6070)

**sNetIdDest**: AmsNetId (AMS network identifier) of the TwinCAT computer. If it is to be run on the local computer, an empty string can be entered.

**sFileNameSrc**: Name of the file on the license dongle

**sFilePathNameScr**: Path name of the file on the hard disk. (Type: T\_MaxString)

**pCopyBuff**: Buffer address for write

**cbCopyLen**: Count of bytes for write

**bExecute**: The function block is activated by a positive edge at this input.

**dwPassCode**: Passcode for file access

**tTimeout**: Timeout time that must not be exceeded when the command is executed.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrorId : UDINT;  
END_VAR
```

**bBusy:** TRUE, as long as the function block is active.

**bError**: TRUE if an error occurs during command execution.

**nErrorId**: Supplies the ADS error number when the bError output is set.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x64, x86) | Tc2\_Utilties >= 3.3.26.0 |
