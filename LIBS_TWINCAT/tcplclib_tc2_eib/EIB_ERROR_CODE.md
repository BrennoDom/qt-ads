# EIB_ERROR_CODE

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_ERROR\_CODE

Library error messages.

```
TYPE EIB_ERROR_CODE :  
(  
  NO_EIB_ERROR                       := 0,  
  WRONG_EIB_PHYS_ADDR                := 1,  
  WRONG_EIB_GROUP_ADDR               := 2,  
  WRONG_EIB_GROUP_LEN                := 3,  
  WRONG_EIB_NO_FILTER                := 4,  
  WRONG_EIB_FIRMWARE                 := 10,  
  WRONG_EIB_MODE                     := 11,  
  WRONG_MODE                         := 12,  
  WRONG_EIB_FIRMWARE_B1_NECESSARY    := 14,  
  WRONG_EIB_FIRMWARE_B3_NECESSARY    := 15,  
  WRONG_EIB_DATA_LEN                 := 20,  
  ERROR_EIB_SERVICE_NOT_SUPPORT      := 21,  
  KL6301_TP_TOGGLE_ERROR             := 30,  
  TIME_OUT                           := 31,  
  KL6301_NO_RESPONSE_FROM_TERMINAL   := 32,  
  ERROR_SEND_8BIT_WRONG_Scaling_Mode := 40,  
  ERROR_EIB_PHY_ADDR_NOT_SUPPORT     := 100,  
  ERROR_EIB_WRITE_DATA               := 101,  
  MONITOR_MODE_LEN_IS_NOT_OK_MUST_0  := 102,  
  MONITOR_MODE_ADDR_IS_NOT_OK_MUST_0 := 103,  
  WATCHDOG_ERROR_NO_SEND             := 104,  
  ERROR_EIB_NO_ACK                   := 16#0BBB,  
  ERROR_EIB_NO_COM_TO_TP             := 16#FAFB,  
  ERROR_TP_TEMP_WARNING              := 16#0FCC,  
  ERROR_TP_PROTOCOL_ERROR            := 16#17CC,  
  ERROR_TP_TRANSMITTER_ERROR         := 16#27CC,  
  ERROR_TP_RECEIVE_ERROR             := 16#47CC,  
  ERROR_TP_SLAVE_COLLISION           := 16#87CC  
)  
END_TYPE
```

**NO\_EIB\_ERROR:** No error.

**WRONG\_EIB\_PHYS\_ADDR:** Outdated, no longer used.

**WRONG\_EIB\_GROUP\_ADDR:** The input variable *EIB\_GROUP\_FILTER.GROUP\_ADDR* is faulty. Check *GROUP\_ADDR* of your filters. *MAIN* must be less than 16, *SUB\_MAIN* less than 8.

**WRONG\_EIB\_GROUP\_LEN:** The input variable *EIB\_GROUP\_FILTER.GROUP\_LEN* is faulty. Incorrect filter length. Check the mode and the length of the filters.

**WRONG\_EIB\_NO\_FILTER:** No filter detected. Check your filter in *EIB\_GROUP\_FILTER* and the mode.

**WRONG\_EIB\_FIRMWARE:** The mode is not supported with this firmware.

**WRONG\_EIB\_MODE:** Unsupported mode during parameterization. Check iMode. Permitted values are 0, 1 and 100.

**WRONG\_MODE:** The input variable *iMode* has an incorrect value.

**WRONG\_EIB\_FIRMWARE\_B1\_NECESSARY:** Firmware B1 or higher required.

**WRONG\_EIB\_FIRMWARE\_B3\_NECESSARY:** Firmware B3 or higher required.

**WRONG\_EIB\_DATA\_LEN:** Expected data length of the EIB telegram does not match. Telegram is discarded. Check the EIB group addresses and/or the data type used.

**ERROR\_EIB\_SERVICE\_NOT\_SUPPORT:** A EIB telegram is not supported.

**KL6301\_TP\_TOGGLE\_ERROR:** Terminal did not respond for 1 second. Check the connection with the KL6301. Is it still busy with data exchange?

**TIME\_OUT:** The terminal fails to respond during parameterization. Check the connection with the KL6301.

**KL6301\_NO\_RESPONSE\_FROM\_TERMINAL:** No connection to KL6301. Either the terminal does not exist or the mapping is wrong.

**ERROR\_SEND\_8BIT\_WRONG\_Scaling\_Mode:** Incorrect or unsupported scaling mode.

**ERROR\_EIB\_PHY\_ADDR\_NOT\_SUPPORT:** Physical addressing not permitted.

**ERROR\_EIB\_WRITE\_DATA:** Outdated, no longer used.

**MONITOR\_MODE\_LEN\_IS\_NOT\_OK\_MUST\_0:** For monitor mode the filter length must be 0.

**MONITOR\_MODE\_ADDR\_IS\_NOT\_OK\_MUST\_0:** For monitor mode the addresses must be 0.

**WATCHDOG\_ERROR\_NO\_SEND:** Data transfer not possible. The group address for which the data transfer has failed can be found in the local variable "NotSendGroup" of function block KL6301.

**ERROR\_EIB\_NO\_ACK:** No ACK received.

**ERROR\_EIB\_NO\_COM\_TO\_TP:** No communication with the EIB hardware.

**ERROR\_TP\_TEMP\_WARNING:** Temperature in KL6301 exceeded.

**ERROR\_TP\_PROTOCOL\_ERROR:** Protocol error in EIB hardware.

**ERROR\_TP\_TRANSMITTER\_ERROR:** Protocol error in EIB hardware.

**ERROR\_TP\_RECEIVE\_ERROR:** Protocol error in EIB hardware.

**ERROR\_TP\_SLAVE\_COLLISION:** Too many collisions in the EIB hardware. Reduce the EIB load.

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
