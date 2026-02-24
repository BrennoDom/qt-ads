# Error codes

## Library
tcplclib_tc2_eib

## Category
Motion Control

# Error codes

| Value (hex) | Value (dec) | Value (enum) | Description |
| --- | --- | --- | --- |
| 0x0000 | 0 | NO\_EIB\_ERROR | No error. |
| 0x0001 | 1 | WRONG\_EIB\_PHYS\_ADDR | Outdated, no longer used. |
| 0x0002 | 2 | WRONG\_EIB\_GROUP\_ADDR | The input variable *EIB\_GROUP\_FILTER.GROUP\_ADDR* is faulty. Check *GROUP\_ADDR* of your filters. *MAIN* must be less than 16, *SUB\_MAIN* less than 8. |
| 0x0003 | 3 | WRONG\_EIB\_GROUP\_LEN | The input variable *EIB\_GROUP\_FILTER.GROUP\_LEN* is faulty. Incorrect filter length. Check the mode and the length of the filters. |
| 0x0004 | 4 | WRONG\_EIB\_NO\_FILTER | No filter detected. Check your filter in *EIB\_GROUP\_FILTER* and the mode. |
| 0x000A | 10 | WRONG\_EIB\_FIRMWARE | The mode is not supported with this firmware. |
| 0x000B | 11 | WRONG\_EIB\_MODE | Unsupported mode during parameterization. Check *iMode*. Permitted values are 0, 1 and 100. |
| 0x000C | 12 | WRONG\_MODE | The input variable *iMode* has an incorrect value. |
| 0x000E | 14 | WRONG\_EIB\_FIRMWARE\_B1\_NECESSARY | Firmware B1 or higher required. |
| 0x000F | 15 | WRONG\_EIB\_FIRMWARE\_B3\_NECESSARY | Firmware B3 or higher required. |
| 0x0014 | 20 | WRONG\_EIB\_DATA\_LEN | Expected data length of the EIB telegram is wrong. Telegram is discarded. Check the EIB group addresses and/or the data type used. |
| 0x0015 | 21 | ERROR\_EIB\_SERVICE\_NOT\_SUPPORT | A EIB telegram is not supported. |
| 0x001E | 30 | KL6301\_TP\_TOGGLE\_ERROR | Terminal did not respond for one second. Check the connection with the KL6301. Is it still busy with data exchange? |
| 0x001F | 31 | TIME\_OUT | The terminal fails to respond during parameterization. Check the connection with the KL6301. |
| 0x0020 | 32 | KL6301\_NO\_RESPONSE\_FROM\_TERMINAL | No connection to KL6301. Either terminal not available or mapping incorrect. |
| 0x0028 | 40 | ERROR\_SEND\_8BIT\_WRONG\_Scaling\_Mode | Incorrect or unsupported scaling mode. |
| 0x0064 | 100 | ERROR\_EIB\_PHY\_ADDR\_NOT\_SUPPORT | Physical addressing not permitted. |
| 0x0065 | 101 | ERROR\_EIB\_WRITE\_DATA | Outdated. No longer used. |
| 0x0066 | 102 | MONITOR\_MODE\_LEN\_IS\_NOT\_OK\_MUST\_0 | For monitor mode the filter length must be 0. |
| 0x0067 | 103 | MONITOR\_MODE\_ADDR\_IS\_NOT\_OK\_MUST\_0 | For monitor mode the addresses must be 0. |
| 0x0068 | 104 | WATCHDOG\_ERROR\_NO\_SEND | Data transfer not possible. The group address for which the data transfer has failed can be found in the local variable "NotSendGroup" of function block KL6301. |
| 0x0BBB | 3003 | ERROR\_EIB\_NO\_ACK | No ACK received. |
| 0xFAFB | 64251 | ERROR\_EIB\_NO\_COM\_TO\_TP | No communication with the EIB hardware. |
| 0x0FCC | 4044 | ERROR\_TP\_TEMP\_WARNING | Temperature in KL6301 exceeded. |
| 0x17CC | 6092 | ERROR\_TP\_PROTOCOL\_ERROR | Protocol error in EIB hardware. |
| 0x27CC | 10188 | ERROR\_TP\_TRANSMITTER\_ERROR | Protocol error in EIB hardware. |
| 0x47CC | 18380 | ERROR\_TP\_RECEIVE\_ERROR | Protocol error in EIB hardware. |
| 0x87CC | 34764 | ERROR\_TP\_SLAVE\_COLLISION | Too many collisions in the EIB hardware. Reduce the EIB load. |
