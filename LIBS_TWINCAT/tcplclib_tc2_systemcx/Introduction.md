# Introduction

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. Introduction

# Introduction

This library contains functions and function blocks that use features on the devices of the Embedded PC CX series.

## Function blocks

| Name | Description |
| --- | --- |
| [FB\_CXProfiler](ms-xhelp:///?Id=beckhoff-3ae5-4a9d-bab4-4876e9428da1) | Runtime measurement of PLC code via the CPU counter |
| [FB\_CXSetTextDisplay](ms-xhelp:///?Id=beckhoff-c354-4c19-ac87-d9cf9cec3053) | Control of the two-line display of the CX1100 |
| [FB\_CXSetTextDisplayUSB](ms-xhelp:///?Id=beckhoff-710c-4bc4-a856-14937dacd618) | Writing and deleting of rows on the two-line display of the CX 2100 or the EL6090 terminal. |
| [FB\_CXGetTextDisplayUSB](ms-xhelp:///?Id=beckhoff-300f-43b4-9548-bec6fd66a44a) | Reading of rows on the two-line display of the CX 2100 or the EL6090 terminal. |
| [FB\_CXSimpleUps](ms-xhelp:///?Id=beckhoff-0ea1-4ff5-a298-fefc54b8de32) | Control of the UPS CX1190-UPS (device name CX1100-0900, CX1100-0910, CX1100-0920) |
| [FB\_CX5010SetWatchdog](ms-xhelp:///?Id=beckhoff-dd80-4e4a-8e9a-c2e22f61522d) | Activates a hardware watchdog on the CX5010. |
| [FB\_CX5020SetWatchdog](ms-xhelp:///?Id=beckhoff-987a-4529-996a-4129bfa8681e) | Activates a hardware watchdog on the CX5020. |

## Functions

| Name | Description |
| --- | --- |
| [F\_CXSubTimeStamp](ms-xhelp:///?Id=beckhoff-2e4a-47d2-8ba7-54cbb2da1360) | Calculates 64-bit subtraction (time A [100 ns] - time B [100 ns]) as result in µs; only for differences between 0 and 4294967295 us; see link. |
| [F\_CXNaviSwitch](ms-xhelp:///?Id=beckhoff-8536-4dfb-8fbc-c752c31a597c) | This function converts the value of the CX1100 navigation switch to an enum value. |
| [F\_CXNaviSwitchUSB](ms-xhelp:///?Id=beckhoff-1ef1-4855-adf4-4e5e373215d4) | This function converts the value of the CX2100 navigation switch to an enum value. |

See also

* [F\_CX1000SetWatchdog](ms-xhelp:///?Id=beckhoff-f06f-400c-90df-1ef0c630acea)
* [F\_CX9000SetWatchdog](ms-xhelp:///?Id=beckhoff-16da-4e2e-9b58-071cc0270abd)
* [F\_CX9010SetWatchdog](ms-xhelp:///?Id=beckhoff-1318-445f-9cda-2fe6111306a2)
* [FB\_CxGetDeviceIdentificationEx](ms-xhelp:///?Id=beckhoff-7e64-464f-ab34-aac60a17559e)
* [FB\_CxGetDeviceIdentification](ms-xhelp:///?Id=beckhoff-a8c3-45c6-90f8-0637f485017e)
* [FB\_CX1010SetWatchdog](ms-xhelp:///?Id=beckhoff-bcdd-4668-996b-91f9955d7628)
* [FB\_CX1020SetWatchdog](ms-xhelp:///?Id=beckhoff-5385-4169-9c5b-b6dc1a009356)
* [FB\_CX1030SetWatchdog](ms-xhelp:///?Id=beckhoff-d17c-45cb-9667-b9794509db9c)

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
