# Constants

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Global constants](ms-xhelp:///?Id=beckhoff-2df3-4ec9-be65-4fa48e73e713)
3. Constants

# Constants

## Port numbers

| Port numbers | Value | Description |
| --- | --- | --- |
| AMSPORT\_LOGGER | 100 | Port number of the Standard-Logger. |
| AMSPORT\_EVENTLOG | 110 | Port number of the TwinCAT Eventlogger. |
| AMSPORT\_R0\_RTIME | 200 | Port number of the TwinCAT Realtime Server. |
| AMSPORT\_R0\_IO | 300 | Port number of the TwinCAT I/O Server. |
| AMSPORT\_R0\_NC | 500 | Port number of the TwinCAT NC Server. |
| AMSPORT\_R0\_NCSAF | 501 | Port number of the TwinCAT NC Serves (Task SAF). |
| AMSPORT\_R0\_NCSVB | 511 | Port number of the TwinCAT NC Server (Task SVB). |
| AMSPORT\_R0\_ISG | 550 | internal |
| AMSPORT\_R0\_CNC | 600 | Port number of the TwinCAT NC I Server. |
| AMSPORT\_R0\_LINE | 700 | internal |
| AMSPORT\_R0\_PLC | 800 | Port number of the TwinCAT PLC Servers (only on the Buscontroller). |
| AMSPORT\_R0\_PLC\_RTS1 | 801 | Port number of the TwinCAT 2.xx PLC Server runtime 1 |
| AMSPORT\_R0\_PLC\_RTS2 | 811 | Port number of the TwinCAT 2.xx PLC Server runtime 2 |
| AMSPORT\_R0\_PLC\_RTS3 | 821 | Port number of the TwinCAT 2.xx PLC Server runtime 3 |
| AMSPORT\_R0\_PLC\_RTS4 | 831 | Port number of the TwinCAT 2.xx PLC Server runtime 4 |
| AMSPORT\_R0\_CAM | 900 | Port number of the TwinCAT CAM Server. |
| AMSPORT\_R0\_CAMTOOL | 950 | Port number of the TwinCAT CAMTOOL Server. |
| AMSPORT\_R3\_SYSSERV | 10000 | Port number of the TwinCAT System Service. |
| AMSPORT\_R3\_SCOPESERVER | 14001 | Port number of the TwinCAT Scope Server. |

## Ads-States

| ADS States | Value | Description |
| --- | --- | --- |
| ADSSTATE\_INVALID | 0 | ADS Status: invalid |
| ADSSTATE\_IDLE | 1 | ADS Status: idle |
| ADSSTATE\_RESET | 2 | ADS Status: reset. |
| ADSSTATE\_INIT | 3 | ADS Status: init |
| ADSSTATE\_START | 4 | ADS Status: start |
| ADSSTATE\_RUN | 5 | ADS Status: run |
| ADSSTATE\_STOP | 6 | ADS Status: stop |
| ADSSTATE\_SAVECFG | 7 | ADS Status: save configuration |
| ADSSTATE\_LOADCFG | 8 | ADS Status: load configuration |
| ADSSTATE\_POWERFAILURE | 9 | ADS Status: Power failure |
| ADSSTATE\_POWERGOOD | 10 | ADS Status: Power good |
| ADSSTATE\_ERROR | 11 | ADS Status: Error |
| ADSSTATE\_SHUTDOWN | 12 | ADS Status: Shutdown |
| ADSSTATE\_SUSPEND | 13 | ADS Status: Suspend |
| ADSSTATE\_RESUME | 14 | ADS Status: Resume |
| ADSSTATE\_CONFIG | 15 | ADS Status: Configuration (System is in config mode) |
| ADSSTATE\_RECONFIG | 16 | ADS Status: Reconfiguration (System should restart in config mode) |
| ADSSTATE\_STOPPING | 17 |  |
| ADSSTATE\_INCOMPATIBLE | 18 |  |
| ADSSTATE\_EXCEPTION | 19 |  |
| ADSSTATE\_MAXSTATES | 20 | Max. number of available ads states |

## ADS/System Services

| Reserved Index Groups | Value | Description |
| --- | --- | --- |
| ADSIGRP\_SYMTAB | 16#F000 |  |
| ADSIGRP\_SYMNAME | 16#F001 |  |
| ADSIGRP\_SYMVAL | 16#F002 |  |
| ADSIGRP\_SYM\_HNDBYNAME | 16#F003 |  |
| ADSIGRP\_SYM\_VALBYNAME | 16#F004 |  |
| ADSIGRP\_SYM\_VALBYHND | 16#F005 |  |
| ADSIGRP\_SYM\_RELEASEHND | 16#F006 |  |
| ADSIGRP\_SYM\_INFOBYNAME | 16#F007 |  |
| ADSIGRP\_SYM\_VERSION | 16#F008 |  |
| ADSIGRP\_SYM\_INFOBYNAMEEX | 16#F009 |  |
| ADSIGRP\_SYM\_DOWNLOAD | 16#F00A |  |
| ADSIGRP\_SYM\_UPLOAD | 16#F00B |  |
| ADSIGRP\_SYM\_UPLOADINFO | 16#F00C |  |
| ADSIGRP\_SYMNOTE | 16#F010 |  |
| ADSIGRP\_IOIMAGE\_RWIB | 16#F020 |  |
| ADSIGRP\_IOIMAGE\_RWIX | 16#F021 |  |
| ADSIGRP\_IOIMAGE\_RISIZE | 16#F025 |  |
| ADSIGRP\_IOIMAGE\_RWOB | 16#F030 |  |
| ADSIGRP\_IOIMAGE\_RWOX | 16#F031 |  |
| ADSIGRP\_IOIMAGE\_RWOSIZE | 16#F035 |  |
| ADSIGRP\_IOIMAGE\_CLEARI | 16#F040 |  |
| ADSIGRP\_IOIMAGE\_CLEARO | 16#F050 |  |
| ADSIGRP\_IOIMAGE\_RWIOB | 16#F060 |  |
| ADSIGRP\_DEVICE\_DATA | 16#F100 |  |
| ADSIOFFS\_DEVDATA\_ADSSTATE | 16#0000 |  |
| ADSIOFFS\_DEVDATA\_DEVSTATE | 16#0002 |  |

## System Service File Service

| System Service Index Groups | Value | Description |
| --- | --- | --- |
| SYSTEMSERVICE\_OPENCREATE | 100 |  |
| SYSTEMSERVICE\_OPENREAD | 101 |  |
| SYSTEMSERVICE\_OPENWRITE | 102 |  |
| SYSTEMSERVICE\_CREATEFILE | 110 |  |
| SYSTEMSERVICE\_CLOSEHANDLE | 111 |  |
| SYSTEMSERVICE\_FOPEN | 120 |  |
| SYSTEMSERVICE\_FCLOSE | 121 |  |
| SYSTEMSERVICE\_FREAD | 122 |  |
| SYSTEMSERVICE\_FWRITE | 123 |  |
| SYSTEMSERVICE\_FSEEK | 124 |  |
| SYSTEMSERVICE\_FTELL | 125 |  |
| SYSTEMSERVICE\_FGETS | 126 |  |
| SYSTEMSERVICE\_FPUTS | 127 |  |
| SYSTEMSERVICE\_FSCANF | 128 |  |
| SYSTEMSERVICE\_FPRINTF | 129 |  |
| SYSTEMSERVICE\_FEOF | 130 |  |
| SYSTEMSERVICE\_FDELETE | 131 |  |
| SYSTEMSERVICE\_FRENAME | 132 |  |
| SYSTEMSERVICE\_REG\_HKEYLOCALMACHINE | 200 |  |
| SYSTEMSERVICE\_SENDEMAIL | 300 |  |
| SYSTEMSERVICE\_TIMESERVICES | 400 |  |
| SYSTEMSERVICE\_STARTPROCESS | 500 |  |
| SYSTEMSERVICE\_CHANGENETID | 600 |  |

## System Servie Timeservices

| System Service Index Offsets (Timeservices) | Value | Description |
| --- | --- | --- |
| TIMESERVICE\_DATEANDTIME | 1 |  |
| TIMESERVICE\_SYSTEMTIMES | 2 |  |
| TIMESERVICE\_RTCTIMEDIFF | 3 |  |
| TIMESERVICE\_ADJUSTTIMETORTC | 4 |  |

## ADSLOG message types

| Masks for log output | Value | Description |
| --- | --- | --- |
| ADSLOG\_MSGTYPE\_HINT | 16#01 |  |
| ADSLOG\_MSGTYPE\_WARN | 16#02 |  |
| ADSLOG\_MSGTYPE\_ERROR | 16#04 |  |
| ADSLOG\_MSGTYPE\_LOG | 16#10 |  |
| ADSLOG\_MSGTYPE\_MSGBOX | 16#20 |  |
| ADSLOG\_MSGTYPE\_RESOURCE | 16#40 |  |
| ADSLOG\_MSGTYPE\_STRING | 16#80 |  |

## BOOTDATA flags

| Masks for Bootdata flags | Value | Description |
| --- | --- | --- |
| BOOTDATAFLAGS\_RETAIN\_LOADED | 16#01 |  |
| BOOTDATAFLAGS\_RETAIN\_INVALID | 16#02 |  |
| BOOTDATAFLAGS\_RETAIN\_REQUESTED | 16#04 |  |
| BOOTDATAFLAGS\_PERSISTENT\_LOADED | 16#10 |  |
| BOOTDATAFLAGS\_PERSISTENT\_INVALID | 16#20 |  |

| Masks for BSOD flags | Value | Description |
| --- | --- | --- |
| SYSTEMSTATEFLAGS\_BSOD | 16#01 | BSOD: Blue Screen of Death |
| SYSTEMSTATEFLAGS\_RTVIOLATION | 16#02 | Realtime violation latency overrun |

## File output modes

| Masks for File output | Value | Description |
| --- | --- | --- |
| FOPEN\_MODEREAD | 16#0001 | 'r': Opens file for reading |
| FOPEN\_MODEWRITE | 16#0002 | 'w': Opens file for reading, (possible) existing files were overwritten. |
| FOPEN\_MODEAPPEND | 16#0004 | 'a': Opens file for reading, is attached to (possible) existing file. If no file existes, it will be created. |
| FOPEN\_MODEPLUS | 16#0008 | '+': Opens file for reading and writing. |
| FOPEN\_MODEBINARY | 16#0010 | 'b': Opens file forbinary reading and writing. |
| FOPEN\_MODETEXT | 16#0020 | 't': Opens file for textual reading and writing: |

## Eventlogger constants

| Masks for Eventlogger Flags | Value | Description |
| --- | --- | --- |
| TCEVENTFLAG\_PRIOCLASS | 16#0010 | Class and priority are defined by the formatter |
| TCEVENTFLAG\_FMTSELF | 16#0020 | The formatting information comes with the event |
| TCEVENTFLAG\_LOG | 16#0040 | Logg. |
| TCEVENTFLAG\_MSGBOX | 16#0080 | Show message box. |
| TCEVENTFLAG\_SRCID | 16#0100 | Use Source-Id instead of Source name. |

| TwinCAT Eventlogger Status messages | Value | Description |
| --- | --- | --- |
| TCEVENTSTATE\_INVALID | 16#0000 | Not valid, occurs also if the event was not reported. |
| TCEVENTSTATE\_SIGNALED | 16#0001 | Event is reported, but neither signed off or acknowledged.. |
| TCEVENTSTATE\_RESET | 16#0002 | Event is signed off ('gone'). |
| TCEVENTSTATE\_CONFIRMED | 16#0010 | Event is acknowledged. |
| TCEVENTSTATE\_RESETCON | 16#0012 | Event is signed off and acknowledged |

| TwinCAT Eventlogger Status messages | Value | Description |
| --- | --- | --- |
| TCEVENT\_SRCNAMESIZE | 15 | Max. Length for the Source name. |
| TCEVENT\_FMTPRGSIZE | 31 | Max. Length for the name of the formatter. |

| Other | Value | Description |
| --- | --- | --- |
| PI | 3.1415926535897932384626433832795 | Pi number |
| DEFAULT\_ADS\_TIMEOUT | T#5s | Default ADS timeout |
| MAX\_STRING\_LENGTH | 255 | The max. string length of T\_MaxString data type |

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
