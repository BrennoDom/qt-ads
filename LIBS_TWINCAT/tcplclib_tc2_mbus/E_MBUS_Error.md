# E_MBUS_Error

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
4. [Enums](ms-xhelp:///?Id=beckhoff-3e72-4e2d-b162-3a62166aa205)
5. E\_MBUS\_Error

# E\_MBUS\_Error

Error messages.

```
TYPE E_MBUS_Error :  
(  
  eMBUS_no_error                          := 0,  
  eMBUS_busy                              := 1,  
  eMBUS_Disabled                          := 3,  
  eMBUS_FBKL6781_Disabled                 := 4,  
  
  eMBUSERROR_CIField_wrong_72hex_expected := 101,  
  eMBUSERROR_no_data_received             := 102,  
  eMBUSERROR_error_checksum               := 103,  
  eMBUSERROR_error_in_head_data           := 104,  
  eMBUSERROR_usiAddress_over_250          := 105,  
  eMBUSERROR_send_error                   := 106,  
  eMBUSERROR_received_address_wrong       := 108,  
  eMBUSERROR_cMBUS_MaxCom_below_1         := 109,  
  eMBUSERROR_iComId_over_cMBUS_MaxCom     := 110,  
  eMBUSERROR_manufacturer_sign_wrong      := 111,  
  eMBUSERROR_baudrate_wrong               := 112,  
  eMBUSERROR_ReceiveBufferFull            := 113,  
  eMBUSERROR_E5hex_no_received            := 114,  
  eMBUSERROR_no_stop_character            := 115,  
  eMBUSERROR_length_wrong                 := 116,  
  eMBUSERROR_wrong_terminal               := 117,  
  eMBUSERROR_Terminal_is_not_initialized  := 118,  
  eMBUSERROR_stSecAdr_udiIdNumber_wrong   := 119,  
  eMBUSERROR_missing_parts_telegram       := 120,  
  eMBUSERROR_no_stop_character_received   := 121,  
  eMBUSERROR_too_many_characters          := 122,  
  eMBUSERROR_TimeOut_FB_KL6781            := 123,  
  eMBUSERROR_TimeOut_MeterFB              := 124,  
  
  eMBUSERROR_COM_PARAMETERCHANGED         := 201,  
  eMBUSERROR_COM_TXBUFFOVERRUN            := 202,  
  eMBUSERROR_COM_STRINGOVERRUN            := 210,  
  eMBUSERROR_COM_ZEROCHARINVALID          := 211,  
  eMBUSERROR_COM_INVALIDPOINTER           := 220,  
  eMBUSERROR_COM_INVALIDRXPOINTER         := 221,  
  eMBUSERROR_COM_INVALIDRXLENGTH          := 222,  
  eMBUSERROR_COM_DATASIZEOVERRUN          := 223,  
  eMBUSERROR_COM_INVALIDBAUDRATE          := 16#1001,  
  eMBUSERROR_COM_INVALIDNUMDATABITS       := 16#1002,  
  eMBUSERROR_COM_INVALIDNUMSTOPBITS       := 16#1003,  
  eMBUSERROR_COM_INVALIDPARITY            := 16#1004,  
  eMBUSERROR_COM_INVALIDHANDSHAKE         := 16#1005,  
  eMBUSERROR_COM_INVALIDNUMREGISTERS      := 16#1006,  
  eMBUSERROR_COM_INVALIDREGISTER          := 16#1007,  
  eMBUSERROR_COM_TIMEOUT                  := 16#1008  
)  
END_TYPE
```

**eMBUS\_no\_error:** No error at the block. The block is currently not querying a meter.

**eMBUS\_busy:** The block is querying a meter.

**eMBUS\_Disabled:** The block is deselected.

**eMBUS\_FBKL6781\_Disabled:** The block [FB\_MBUS\_KL6781()](ms-xhelp:///?Id=beckhoff-2b5d-4be4-b4d2-353673675260) is deselected.

**eMBUSERROR\_CIField\_wrong\_72hex\_expected:**  The 7th byte in the response telegram contains the CI field. In this byte the hexadecimal number 72 is expected. It stands for variable data structure, low byte is sent first. Only this data structure is supported.

**eMBUSERROR\_no\_data\_received:** No data was received.

**eMBUSERROR\_error\_checksum:** The response telegram includes a checksum (sum of all bytes from byte 5). The received checksum does not match the calculated checksum. This happens if the protocol was not received cleanly (e.g. in the event of interference on the cable or if the cable is too long).

**eMBUSERROR\_error\_in\_head\_data:** The first 4 bytes are not included in the checksum. These 4 bytes are monitored separately.

**eMBUSERROR\_usiAddress\_over\_250:** Addresses higher than 250 are not permitted. The input *usiAddress* of the meter block was assigned a value higher than 250 (exception: Address 254. This address can be used if only one meter is connected).

**eMBUSERROR\_send\_error:** Error message for error during sending.

**eMBUSERROR\_received\_address\_wrong:** Received address does not match the sent address.

**eMBUSERROR\_cMBUS\_MaxCom\_below\_1:** Reserve.

**eMBUSERROR\_iComId\_over\_cMBUS\_MaxCom:** Reserve.

**eMBUSERROR\_manufacturer\_sign\_wrong:** The response telegram includes a manufacturer code. This code is allocated to the counter blocks. This message appears if the received manufacturer code does not match the block used.

**eMBUSERROR\_baudrate\_wrong:** Input *eBaudrate* of the block was assigned invalid values. Only [E\_MBUS\_Baudrate](ms-xhelp:///?Id=beckhoff-9ee5-43e2-8e09-418785a2cd23) are allowed.

**eMBUSERROR\_ReceiveBufferFull:** The receive buffer of the serial interface is full. This may happen with long telegrams and/or long cycle times. The PLC is unable to read the data quick enough from the receive buffer, resulting in data loss. The situation may be resolved by reducing the cycle time.

**eMBUSERROR\_E5hex\_no\_received:** No single character E5 hexadecimal was received after initialization of the meter.

**eMBUSERROR\_no\_stop\_character:** No end character in the data array.

**eMBUSERROR\_length\_wrong:** Number of received characters <> the length field.

**eMBUSERROR\_wrong\_terminal:** Incorrect terminal connected

**eMBUSERROR\_Terminal\_is\_not\_initialized:** The terminal is not initialized. This message usually means that there is no connection to the terminal. Terminal linked to the variables in the System Manager? Terminal plugged in incorrectly? Everything corrected, everything translated and re-read into the System Manager?

**eMBUSERROR\_stSecAdr\_udiIdNumber\_wrong:** The input variable *stSecAdr.udiIdNumber* is not assigned

**eMBUSERROR\_missing\_parts\_telegram:** Not all telegram values were received.

**eMBUSERROR\_no\_stop\_character\_received:** No stop characters were received (16hex).

**eMBUSERROR\_too\_many\_characters:** Too many characters were received.

**eMBUSERROR\_TimeOut\_FB\_KL6781:** Timeout *FB\_KL6781*.

**eMBUSERROR\_TimeOut\_MeterFB:** Meter block timeout.

**eMBUSERROR\_COM\_PARAMETERCHANGED:** Input parameters have changed during reception.

**eMBUSERROR\_COM\_TXBUFFOVERRUN:** String > transfer buffer.

**eMBUSERROR\_COM\_STRINGOVERRUN:** End of the string.

**eMBUSERROR\_COM\_ZEROCHARINVALID:** String may not contain any zero characters.

**eMBUSERROR\_COM\_INVALIDPOINTER:** Invalid data pointer, e.g. zero.

**eMBUSERROR\_COM\_INVALIDRXPOINTER:** Invalid data pointer for ReceiveData.

**eMBUSERROR\_COM\_INVALIDRXLENGTH:** Invalid length for ReceiveData e.g. zero.

**eMBUSERROR\_COM\_DATASIZEOVERRUN:** End of the data block.

**eMBUSERROR\_COM\_INVALIDBAUDRATE:** Invalid baud rate.

**eMBUSERROR\_COM\_INVALIDNUMDATABITS:** Invalid data bits.

**eMBUSERROR\_COM\_INVALIDNUMSTOPBITS:** Invalid stop bits.

**eMBUSERROR\_COM\_INVALIDPARITY:** Invalid parity.

**eMBUSERROR\_COM\_INVALIDHANDSHAKE:** Invalid handshake.

**eMBUSERROR\_COM\_INVALIDNUMREGISTERS:** Invalid num register.

**eMBUSERROR\_COM\_INVALIDREGISTER:** Invalid register.

**eMBUSERROR\_COM\_TIMEOUT:** COM timeout.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
