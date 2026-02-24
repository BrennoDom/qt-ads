# Introduction

## Library
tcplclib_tc2_dataexchange

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
2. Introduction

# Introduction

The present function blocks simplify event-driven data exchange between the TwinCAT PLC runtime system and/or other ADS devices (TwinCAT NC, Bus Terminal Controller, ...).

The FB\_WriteXXXOnDelta() function block implements a write procedure when the input signal rises above or falls below a specified limit value. The frequency with which the input signal is examined can be set. Event-driven data writing minimizes the loading on the fieldbus. If an error occurs during transmission, the process is repeated until the connection is established once more. All data types supported in the TwinCAT PLC are permitted as source and destination variables. Symbol names are also supported.

Watchdog function blocks are available to monitor individual communication partners. The device that is to be monitored cyclically transmits an incrementing counter. A check is made at the receiver to see that the counter state changes within a specific time.

## Write/Read Blocks

| Name | Description |
| --- | --- |
| [FB\_ReadAdsSymByName](ms-xhelp:///?Id=beckhoff-a408-4e08-826e-5599820b7076) | Reads a variable of any desired data type by variable name |
| [FB\_WriteAdsSymByName](ms-xhelp:///?Id=beckhoff-b62f-4ae2-9c30-f56d33845f24) | Writes a variable of any desired data type by variable name |
| [FB\_WriteBoolOnDelta](ms-xhelp:///?Id=beckhoff-b06a-4910-8a24-cd16060e8b2c) | Writes a variable of type BOOLEAN in response to an event. |
| [FB\_WriteByteOnDelta](ms-xhelp:///?Id=beckhoff-48b2-44a1-b184-951707e673cf) | Writes a variable of type BYTE in response to an event. |
| [FB\_WriteWordOnDelta](ms-xhelp:///?Id=beckhoff-26a6-48d8-b3f3-5df53c05e4ed) | Writes a variable of type WORD in response to an event. |
| [FB\_WriteDWordOnDelta](ms-xhelp:///?Id=beckhoff-9820-4c8d-b812-63e574264cb4) | Writes a variable of type DWORD in response to an event. |
| [FB\_WriteRealOnDelta](ms-xhelp:///?Id=beckhoff-a18d-442a-aa7f-8f7623bfdabe) | Writes a variable of type REAL in response to an event. |
| [FB\_WriteLRealOnDelta](ms-xhelp:///?Id=beckhoff-46b3-497a-a321-15d9ff11072c) | Writes a variable of type LREAL in response to an event. |

## Monitoring Blocks

| Name | Description |
| --- | --- |
| [FB\_WriteWatchdog](ms-xhelp:///?Id=beckhoff-a27e-412b-bbdb-d7f148c29676) | Writes a watchdog signal (an incrementing counter) cyclically |
| [FB\_CheckWatchdog](ms-xhelp:///?Id=beckhoff-29d0-4e07-aca2-b77369508a96) | Monitors the received watchdog signal |

[TwinCAT 3 | PLC Library: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
