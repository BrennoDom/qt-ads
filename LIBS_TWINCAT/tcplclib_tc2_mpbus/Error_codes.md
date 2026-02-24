# Error codes

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. Error codes

# Error codes

| Value (hex) | Value (dec) | Value (enum) | Description |
| --- | --- | --- | --- |
| 0x0000 | 0 | NO\_MP\_ERROR | No error. |
| 0x0001 | 1 | WRONG\_TERMINAL | Incorrect terminal connected. |
| 0x0002 | 2 | NO\_ANSWER\_FROM\_KL6771 | No answer from the KL6771 MP-bus master terminal. This message usually means that there is no connection to the terminal. Terminal linked to the variables in the System Manager? Terminal plugged in incorrectly? Everything corrected, everything translated and re-read into the System Manager? |
| 0x0003 | 3 | NO\_LINK\_TO\_STRUCTURE\_strDataKL6771 | Check the link to the structure [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2). |
| 0x000A | 10 | WRONG\_MP\_ADDRESS\_IS\_0 | MP-bus address is 0. Only addresses between 1 and 8 are allowed. |
| 0x000B | 11 | WRONG\_MP\_ADDRESS | MP-bus address is >8. Only addresses between 1 and 8 are allowed. |
| 0x0015 | 21 | WRONG\_SET\_POINT | Incorrect set point. |
| 0x0019 | 25 | MP\_BUS\_TIMEOUT\_NO\_ANSWER\_FROM\_SLAVE | MP-Bus timeout, no response from slave. |
| 0x001F | 31 | KL6771\_TIME\_OUT | KL6771 Timeout. |
| 0x0020 | 32 | MP\_ADDRESS\_IS\_IN\_USE | MP-Bus address is in use. |
| 0x0021 | 33 | MP\_DISABLED | MP-Bus locked. |
| 0x0057 | 87 | MP\_BUS\_ERROR | MP-Bus error. |
| 0x0058 | 88 | MP\_NO\_ANSWER\_ON\_EVENT | MP-Bus no response to an event. |
| 0x0059 | 89 | MP\_NO\_ANSWER | MP-Bus no response. |
| 0x005A | 90 | MP\_COM\_BREAK | MP-Bus abort communication. |
| 0x0062 | 98 | MP\_LENGTH\_PARITY\_ERROR | MP-Bus length parity error. |
| 0x0063 | 99 | MP\_CROSS\_PARITY\_ERROR | MP-Bus cross parity error. |
| 0x0065 | 101 | MP\_MASTER\_CONFLICT\_ERROR | MP-Bus MASTER\_CONFLICT\_ERROR. |
| 0x0066 | 102 | MP\_GAP\_TIMEOUT\_ERROR | MP-Bus GAP Timeout. |
| 0x0067 | 103 | MP\_NO\_ANSWER\_SLAVE | MP-Bus no response from slave. |
| 0x006E | 110 | MP\_ANSWER\_ERROR\_FLAG | MP-Bus error bit in response telegram is set. |
| 0x006F | 111 | MP\_ANSWER\_WRONG\_LEN | MP-Bus wrong telegram length. |
| 0x0070 | 112 | MP\_ANSWER\_WRONG\_TELEG | MP-Bus wrong telegram received. |
| 0x0073 | 115 | MP\_ANSWER\_WITH\_ERROR | Response contains an error. |
| 0x00C8 | 200 | MP\_ERROR\_WrongDeviceFamily | Wrong device family. |
| 0x800A | 32778 | MP\_ANSWER\_Reserve | Reserve. |
| 0x800B | 32779 | MP\_ANSWER\_UnknowCommand | Unknown command. |
| 0x800C | 32780 | MP\_ANSWER\_WrongOrNoPassword | Wrong or no password. |
| 0x800D | 32781 | MP\_ANSWER\_CommandExecution | Command execution. |
| 0x800E | 32782 | MP\_ANSWER\_ParameterError | Parameter error. |
| 0x800F | 32783 | MP\_ANSWER\_UnknowId | Unknown ID. |
| 0x8010 | 32784 | MP\_ANSWER\_SizeMismatch | Wrong size. |
| 0x8011 | 32785 | MP\_ANSWER\_IllegalBlockNr | Invalid block number. |
| 0x8012 | 32786 | MP\_ANSWER\_InternalBusBusy | Internal bus is busy. |
| 0x80FF | 33023 | MP\_ANSWER\_ReservedForFuture | Reserve. |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
