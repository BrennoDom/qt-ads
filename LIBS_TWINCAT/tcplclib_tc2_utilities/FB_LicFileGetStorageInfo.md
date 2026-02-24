# FB_LicFileGetStorageInfo

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_LicFileGetStorageInfo

![24006753](/tcplclib_tc2_utilities/1033/Images/png/4579235595__Web.png)

The function block reads the StorageInfo of the license dongle and the file directory.

The StorageInfo contains administrative data of the storage medium (such as capacity, number of free bytes, number of files,…) and an array of the individual file entries (name, size, attributes,… of the file).

## VAR\_INPUT

```
VAR_INPUT  
    sNetId      : T_AmsNetId;  
    nPort       : UINT;  
    bExecute    : BOOL;  
    dwPassCode  : DWORD;  
    tTimeout    : TIME       := DEFAULT_ADS_TIMEOUT  
END_VAR
```

**sNetId**: AmsNetId (AMS network identifier) of the license dongle (type: T\_AmsNetId)

* USB dongle: AmsNetId of the TwinCAT computer. If it is to be run on the local computer, an empty string can be entered.
* EL6070: AmsNetId of the EtherCAT master (see AdsAddr.netId in the InfoData of the EL6070)

**nPort**: AMS port of the license dongle

* USB: ADS port of the ESB device (see ADS port on the ESB Device tab of the USB dongle; the default is 16#7100)
* EL6070: ADS port of the EtherCAT Terminal (see AdsAddr.port in the InfoData of the EL6070)

**bExecute**: The function block is activated by a positive edge at this input.

**dwPassCode**: Passcode for file access (only for specially protected files)

**tTimeout**: Timeout time that must not be exceeded when the command is executed.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;  
    nErrorId     : UDINT;  
    nFileEntries : UDINT;  
END_VAR
```

**bBusy:** TRUE, as long as the function block is active.

**bError**: TRUE if an error occurs during command execution.

**nErrorId**: Supplies the ADS error number when the bError output is set.

**nFileEntries:** Number of files on the license dongle

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stStorageInfo : ST_LicStorageInfo;  
END_VAR
```

**stStorageInfo:** StorageInfo of the license dongle (type: ST\_LicStorageInfo)

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x64, x86) | Tc2\_Utilties >= 3.3.26.0 |
