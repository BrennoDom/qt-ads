# Error codes

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. Error codes

# Error codes

| Value (hex) | Value (dec) | Value (enum) | Description |
| --- | --- | --- | --- |
| 0x0000 | 0 | eMBUS\_no\_error | No error is present at the block. The block is currently not querying a counter. |
| 0x0001 | 1 | eMBUS\_busy | The block is querying a meter. |
| 0x0003 | 3 | eMBUS\_Disabled | The block is deselected. |
| 0x0004 | 4 | eMBUS\_FBKL6781\_Disabled | The function block [FB\_MBUSKL6781()](ms-xhelp:///?Id=beckhoff-2b5d-4be4-b4d2-353673675260) is deselected. |
| 0x0065 | 101 | eMBUSERROR\_CIField\_wrong\_72hex\_expected | The 7th byte in the response telegram contains the CI field. In this byte the hexadecimal number 72 is expected. It stands for variable data structure, low byte is sent first. Only this data structure is supported. |
| 0x0066 | 102 | eMBUSERROR\_no\_data\_received | No data was received. |
| 0x0067 | 103 | eMBUSERROR\_error\_checksum | The response telegram includes a checksum (sum of all bytes from byte 5). The received checksum does not match the calculated checksum. This happens if the protocol was not received cleanly (e.g. in the event of interference on the cable or if the cable is too long). |
| 0x0068 | 104 | eMBUSERROR\_error\_in\_head\_data | The first 4 bytes are not included in the checksum. These 4 bytes are monitored separately. |
| 0x0069 | 105 | eMBUSERROR\_usiAddress\_over\_250 | Addresses higher than 250 are not permitted. The input *usiAddress* of the meter block was assigned a value higher than 250 (exception: Address 254. This address can be used if only one meter is connected). |
| 0x006A | 106 | eMBUSERROR\_send\_error | Error message for error during sending. |
| 0x006C | 108 | eMBUSERROR\_received\_address\_wrong | Received address does not match the sent address. |
| 0x006D | 109 | eMBUSERROR\_cMBUS\_MaxCom\_below\_1 | Reserve. |
| 0x006E | 110 | eMBUSERROR\_iComId\_over\_cMBUS\_MaxCom | Reserve. |
| 0x006F | 111 | eMBUSERROR\_manufacturer\_sign\_wrong | The response telegram includes a manufacturer code. This code is allocated to the counter blocks. This message appears if the received manufacturer code does not match the block used. |
| 0x0070 | 112 | eMBUSERROR\_baudrate\_wrong | Input *eBaudrate* of the block was assigned invalid values. Only [E\_MBUS\_Baudrate](ms-xhelp:///?Id=beckhoff-9ee5-43e2-8e09-418785a2cd23) are allowed. |
| 0x0071 | 113 | eMBUSERROR\_ReceiveBufferFull | The receive buffer of the serial interface is full. This may happen with long telegrams and/or long cycle times. The PLC is unable to read the data quick enough from the receive buffer, resulting in data loss. The situation may be resolved by reducing the cycle time. |
| 0x0072 | 114 | eMBUSERROR\_E5hex\_no\_received | No single character E5 hexadecimal was received after initialization of the meter. |
| 0x0073 | 115 | eMBUSERROR\_no\_stop\_character | No end character in the data array. |
| 0x0074 | 116 | eMBUSERROR\_length\_wrong | Number of received characters <> the length field. |
| 0x0075 | 117 | eMBUSERROR\_wrong\_terminal | Incorrect terminal connected |
| 0x0076 | 118 | eMBUSERROR\_Terminal\_is\_not\_initialized | The terminal is not initialized. This message usually means that there is no connection to the terminal. Terminal linked to the variables in the System Manager? Terminal plugged in incorrectly? Everything corrected, everything translated and re-read into the System Manager? |
| 0x0077 | 119 | eMBUSERROR\_stSecAdr\_udiIdNumber\_wrong | The input variable *stSecAdr.udiIdNumber* is not assigned. |
| 0x0078 | 120 | eMBUSERROR\_missing\_parts\_telegram | Not all telegram values were received. |
| 0x0079 | 121 | eMBUSERROR\_no\_stop\_character\_received | No stop characters were received (16hex). |
| 0x007A | 122 | eMBUSERROR\_too\_many\_characters | Too many characters were received. |
| 0x007B | 123 | eMBUSERROR\_TimeOut\_FB\_KL6781 | Timeout *FB\_KL6781*. |
| 0x007C | 124 | eMBUSERROR\_TimeOut\_MeterFB | Meter block timeout. |
| 0x00C9 | 201 | eMBUSERROR\_COM\_PARAMETERCHANGED | Input parameters have changed during reception. |
| 0x00CA | 202 | eMBUSERROR\_COM\_TXBUFFOVERRUN | String > transfer buffer. |
| 0x00D2 | 210 | eMBUSERROR\_COM\_STRINGOVERRUN | End of the string. |
| 0x00D3 | 211 | eMBUSERROR\_COM\_ZEROCHARINVALID | String may not contain any zero characters. |
| 0x00DC | 220 | eMBUSERROR\_COM\_INVALIDPOINTER | Invalid data pointer, e.g. zero. |
| 0x00DD | 221 | eMBUSERROR\_COM\_INVALIDRXPOINTER | Invalid data pointer for *ReceiveData*. |
| 0x00DE | 222 | eMBUSERROR\_COM\_INVALIDRXLENGTH | Invalid length for *ReceiveData* e.g. zero. |
| 0x00DF | 223 | eMBUSERROR\_COM\_DATASIZEOVERRUN | End of the data block. |
| 0x1001 | 4097 | eMBUSERROR\_COM\_INVALIDBAUDRATE | Invalid baud rate. |
| 0x1002 | 4098 | eMBUSERROR\_COM\_INVALIDNUMDATABITS | Invalid data bits. |
| 0x1003 | 4099 | eMBUSERROR\_COM\_INVALIDNUMSTOPBITS | Invalid stop bits. |
| 0x1004 | 4100 | eMBUSERROR\_COM\_INVALIDPARITY | Invalid parity. |
| 0x1005 | 4101 | eMBUSERROR\_COM\_INVALIDHANDSHAKE | Invalid handshake. |
| 0x1006 | 4102 | eMBUSERROR\_COM\_INVALIDNUMREGISTERS | Invalid num register. |
| 0x1007 | 4103 | eMBUSERROR\_COM\_INVALIDREGISTER | Invalid register. |
| 0x1008 | 4109 | eMBUSERROR\_COM\_TIMEOUT | COM timeout. |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
