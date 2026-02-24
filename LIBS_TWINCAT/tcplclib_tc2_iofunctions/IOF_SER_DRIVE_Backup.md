# IOF_SER_DRIVE_Backup

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [SERCOS](ms-xhelp:///?Id=beckhoff-3607-4eaf-b256-e8662f77e8c2)
4. IOF\_SER\_DRIVE\_Backup

# IOF\_SER\_DRIVE\_Backup

![16346001](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314104459__Web.png)

The “IOF\_SER\_DRIVE\_Backup” function block allows the backup and restore of the drive data (S- and P-parameters) of the PLC in a binary file. The list of S- and P-parameter data to be backed up is taken by default from the Sercos parameter IDN192. Backup and restore require the SERCOS parameter mode (phase 2).

If bStdBackupList = TRUE (standard), the IDN192 parameter is taken as the list of the data to be backed up; otherwise IDN17, the list of all Sercos parameters, is taken. Restore requires a backup file that was created with the IDN192 parameter, since some parameters in the IDN17 list are write protected.

Backup and restore create a CRC16-CCITT and a 16-bit checksum and save them in the IDN142 parameter, if available.

The file format of the backup file is described in the [backup file format](ms-xhelp:///?Id=beckhoff-eea3-43e3-bed2-8714d72e3df9).

## VAR\_INPUT

```
VAR_INPUT  
    bCheck        : BOOL;  
    bBackup       : BOOL;  
    bRestore      : BOOL;  
    bCRCEnable    : BOOL := TRUE;  
    bStdBackupList: BOOL := TRUE;  
    sNetId        : T_AmsNetId;  
    nPort         : UINT;  
    sComment      : T_MaxString;  
    ePath         : E_OpenPath := PATH_BOOTPATH;  
    sPathName     : T_MaxString := 'DRIVEPAR.BIN';  
    tTimeout      : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**bCheck**: The check by CRC and checksum is activated by a rising edge at this input. CRC and checksum are saved persistently and in the IDN142 parameter after a backup or a restore. bCheckOK is set to TRUE if the value from the IDN142 parameter matches the persistent data, otherwise bCheckOK is set to FALSE.

**bBackup**: the backup is activated by a rising edge at this input.

**bRestore**: the restore is activated by a rising edge at this input.

**bCRCEnable**: The CRC16-CCITT and the 16-bit checksum are activated via bCRCEnable = TRUE. The CRC and the checksum are saved in the IDN142 parameter if bCRCEnable = TRUE.

**bStdBackupList**: determines which parameter list is used for the backup. By default IDN192 (bStdBackupList = TRUE) is used for the backup. If bStdBackupList = FALSE, the list of all parameters, IDN017, is used. Restore requires a backup file created with the IDN192 list.

**sNetId**: The network address of the TwinCAT computer on which the ADS command is to be executed can be entered here (type: T\_AmsNetId). If it is to be run on the local computer, an empty string can be entered.

**nPort**: The port number nPort is assigned by the TwinCAT system during the hardware configuration.

**sComment**: A comment that is written in the file header of the backup file (type: T\_MaxString).

**ePath**: Determines the path of the backup file. If ePath = PATH\_BOOTPATH, the TwinCAT boot path is taken. If ePath = PATH\_GENERIC, the path specified in sPathName is taken (type: E\_OpenPath).

**sPathName**: Contains the file name (if using the boot path) or the complete path and file name if using the generic path (type: T\_MaxString).

**tTimeout**: States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrId    : UDINT;  
    bCheckOK  : BOOL;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: If an error should occur during the transfer of the command, then this output is set once the bBusy output was reset.

**nErrId**: Returns the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) or the specific function block error number if the ERR output is set.

| specific function block error number | Description |
| --- | --- |
| 0x1003 | Incorrect parameter mode |
| 0x1004 | Incorrect parameter data size |
| 0x1005 | Incorrect backup parameter type |
| 0x1006 | Backup parameter list was not IDN 192 |

**bCheckOk**: TRUE if the checksum test was successful.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC (x86) | Sercans SCS-P ISA; Sercans SCS-P PCI; Beckhoff FC750x PCI | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
