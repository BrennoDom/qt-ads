# FB_RegQueryValue

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_RegQueryValue

![31767774](/tcplclib_tc2_utilities/1033/Images/png/9007199290296075__Web.png)

The system registry is a hierarchically structured tree. A node in the tree is referred to as a key. Each key can may contain subkeys and data values. The function block "FB\_RegQueryValue" can be used to read individual system registry values from the branch with the predefined handle **HKEY\_LOCAL\_MACHINE**. If successful *cbData* data bytes are copied into the buffer with the address *pData*. The function block can be used to read any value types (e.g. REG\_DWORD, REG\_SZ) or binary data with unlimited byte length (REG\_BINARY).

**Comment:**

The strings *sSubKey* and *sValueName* may not be empty!

|  |  |
| --- | --- |
| 17474517 | HKEY\_LOCAL\_MACHINE\SOFTWARE\ for 64 bit operating systems  In a 64 bit Windows operating system all registry entries of and for 32 bit applications are not stored under HKEY\_LOCAL\_MACHINE\SOFTWARE\ but under HKEY\_LOCAL\_MACHINE\SOFTWARE\WOW6432Node\. The function blocks FB\_RegQueryValue and FB\_RegSetValue work automatically below the WOW6432Node folder like any 32 bit application when a registry entry below the SOFTWARE folder is selected. The redirection is performed automatically by the operating system. |

## VAR\_INPUT

```
VAR_INPUT  
    sNetId    : T_AmsNetId;   
    sSubKey   : T_MaxString;  
    sValName  : T_MaxString;  
    cbData    : UDINT;  
    pData     : POINTER TO BYTE;  
    bExecute  : BOOL;  
    tTimeOut  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: Here you can enter a string with the network address of the TwinCAT computer whose system registry is to be read (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**sSubKey**: String with the subkey name (type: T\_MaxString).

**sValName**: String with the value name (type: T\_MaxString).

**cbData**: The number of value data bytes to be read.

**pData**: Address of a data buffer/variable into which the value data are to be copied. The address can be determined with the ADR operator. The programmer is responsible for dimensioning the data buffer such that it can accommodate cbData data bytes.

**bExecute**: the block is activated by a positive edge at this input.

**tTimeOut**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    cbRead : UDINT;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) or the command-specific error code (table) when the *bError* output is set.

**cbRead**: The number of value data bytes successfully read.

| Error Codes | Error description |
| --- | --- |
| 0x00 | No error |
| 0x01 | The key with the name **sSubKey** could not be opened/found. |
| 0x02 | The key value with the name **sValName** could not be opened/found. |

**Examples:**

The values *AxisId* and *LogFilePath* are to be read from the system registry.

![23052927](/tcplclib_tc2_utilities/1033/Images/gif/35558283__en-US__Web.gif)

```
PROGRAM MAIN  
VAR  
    fbRegQueryValue   : FB_RegQueryValue;  
    bRead             : BOOL;  
    bBusy             : BOOL;  
    bError            : BOOL;  
    nErrId            : UDINT;  
    cbRead            : UDINT;  
    sValData          : STRING;  
    nAxisID           : DWORD;  
END_VAR
```

## Read REG\_DWORD-Value:

![6149759](/tcplclib_tc2_utilities/1033/Images/gif/35561483__en-US__Web.gif)

The value 0x22 of the registry was read in the PLC variable *nAxisId* .

## Read REG\_SZ-Value :

![55347837](/tcplclib_tc2_utilities/1033/Images/gif/35564683__en-US__Web.gif)

The string 'c:\MyProject\Log' of the registry was read in the PLC variable *sValData.*

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64, TC OS ARMT2) | Tc2\_Utilities (System) |
