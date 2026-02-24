# FB_LicFileRead

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_LicFileRead

![14734188](/tcplclib_tc2_utilities/1033/Images/png/4579237515__Web.png)

The function block reads a file from the license dongle to a buffer (pDestBuff and cbReadLen) via a positive edge at bExecute. The buffer must be large enough for the file, otherwise only the first part of the file is read.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId      : T_AmsNetId;  
    nPort       : UINT;  
    sFileName   : STRING;  
    pDestBuff   : PVOID;  
    cbReadLen   : UDINT  
    bExecute    : BOOL;  
    dwPassCode  : DWORD;  
    tTimeout    : TIME       := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: AmsNetId (AMS network identifier) of the license dongle (type: T\_AmsNetId)

* USB dongle: AmsNetId of the TwinCAT computer. If it is to be run on the local computer, an empty string can be entered.
* EL6070: AmsNetId of the EtherCAT master (see AdsAddr.netId in the InfoData of the EL6070)

**nPort**: AMS port of the license dongle

* USB: ADS port of the ESB device (see ADS port on the ESB Device tab of the USB dongle; the default is 16#7100)
* EL6070: ADS port of the EtherCAT Terminal (see AdsAddr.port in the InfoData of the EL6070)

**sFileName**: Name of the file to be read

**pDestBuff**: Buffer address for read

**cbReadLen**: Count of bytes for read

**bExecute:** The function block is activated by a positive edge at this input.

**dwPassCode:** Passcode for file access

**tTimeout:** Timeout time that must not be exceeded when the command is executed.

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
