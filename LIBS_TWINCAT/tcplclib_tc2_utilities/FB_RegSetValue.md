# FB_RegSetValue

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_RegSetValue

![28368490](/tcplclib_tc2_utilities/1033/Images/png/9007199290308875__Web.png)

The system registry is a hierarchically structured tree. A node in the tree is referred to as a key. Each key can may contain subkeys and data values.

The function block "FB\_RegSetValue" can be used to write or generate individual key values or new key names and values (subkeys+values) in the branch with the predefined handle **HKEY\_LOCAL\_MACHINE**. Any number of value types (e.g. REG\_DWORD, REG\_SZ) or a maximum of 500 bytes of binary data (REG\_BINARY) can be written into the system registry. If a key value does not yet exist, it will automatically be created.

**Comment:**

The strings *sSubKey* and *sValueName* may not be empty!

|  |  |
| --- | --- |
| 53989823 | HKEY\_LOCAL\_MACHINE\SOFTWARE\ for 64 bit operating systems  In a 64 bit Windows operating system all registry entries of and for 32 bit applications are not stored under HKEY\_LOCAL\_MACHINE\SOFTWARE\ but under HKEY\_LOCAL\_MACHINE\SOFTWARE\WOW6432Node\. The function blocks FB\_RegQueryValue and FB\_RegSetValue work automatically below the WOW6432Node folder like any 32 bit application when a registry entry below the SOFTWARE folder is selected. The redirection is performed automatically by the operating system. |

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetId;  
    sSubKey  : T_MaxString;  
    sValName : T_MaxString;  
    eValType : E_RegValueType;  
    cbData   : UDINT;  
    pData    : POINTER TO BYTE;  
    bExecute : BOOL;  
    tTimeOut : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: Here you can enter a string with the network address of the TwinCAT computer whose system registry is to be written (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**sSubKey**: String with the subkey name (type: T\_MaxString).

**sValName**: String with the value name (type: T\_MaxString).

**eValType**: The data type format of the registry data to be written, e.g: REG\_DWORD or REG\_SZ (type: [E\_RegValueType](ms-xhelp:///?Id=beckhoff-15d2-4aa1-bf63-a6310706e646)).

**cbData**: The number of value data bytes that are to be written. (In the case of string variables this includes the final null).

**pD** **ata**: Address of a data buffer/PLC variable containing the value data. The address can be determined with the ADR operator. The programmer is responsible for dimensioning the data buffer such that *cbData* data bytes can be read from it.

**bExecute**: the block is activated by a positive edge at this input.

**tTimeOut**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrId   : UDINT;  
    cbWrite  : UDINT;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) or the command-specific error code (table) when the *bError* output is set.

**cbWrite**: Number of successfully written value data bytes.

| Error Codes | Error description |
| --- | --- |
| 0x00 | No error |
| 0x01 | The key with the name **sSubKey** could not be opened/found. |
| 0x02 | The key value with the name **sValName** could not be opened/found. |

**Example:**

In the branch with the predefined handle *HKEY\_LOCAL\_MACHINE* a subkey *'SOFTWARE\MyCompany\MyProject'* with the key name '*LogFileName'* , the type *REG\_SZ*

and the value '*c:\MyProject\Log'*' is to be created and set.

```
PROGRAM MAIN  
VAR  
    fbRegSetValue   : FB_RegSetValue;  
    bBusy               : BOOL;  
    bError          : BOOL;  
    nErrId          : UDINT;  
    cbWrite         : UDINT;  
    bWrite          : BOOL;  
    sNewValue       : STRING := 'c:\MyProject\Log';  
END_VAR
```

![16146366](/tcplclib_tc2_utilities/1033/Images/gif/35571083__en-US__Web.gif)

![11099566](/tcplclib_tc2_utilities/1033/Images/gif/35558283__en-US__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64, TC OS ARMT2) | Tc2\_Utilities (System) |
