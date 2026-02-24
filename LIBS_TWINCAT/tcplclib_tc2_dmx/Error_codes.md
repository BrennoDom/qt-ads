# Error codes

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# Error codes

| Value (hex) | Value (dez) | Description |
| --- | --- | --- |
| 0x0000 | 0 | No error. |
| 0x8001 | 32769 | No answer from the DMX terminal. |
| 0x8002 | 32770 | No answer from the DMX device. |
| 0x8003 | 32771 | Communication buffer overflow. |
| 0x8004 | 32772 | No answer from the communication block. |
| 0x8005 | 32773 | The *byPortId* parameter is outside the valid range. |
| 0x8006 | 32774 | Checksum error. |
| 0x8007 | 32775 | The *eResetDeviceType* parameter is outside the valid range. |
| 0x8008 | 32776 | Timeout. |
| 0x8009 | 32777 | The *uliLowerBoundUID* parameter is larger than the *uliUpperBoundUID.* parameter. |
| 0x800A | 32778 | No RDM commands can be transmitted, because the terminal is in cycle mode. |
| 0x800B | 32779 | The *iDMX512StartAddress* parameter is outside the valid range (1 – 512). |
| 0x800C | 32780 | Error in setting the DMX512 start address. |
| 0x800D | 32781 | No process data can be transmitted, because the terminal is not in cycle mode. |
| 0x800E | 32782 | It is a RDM telegram received with the data length 0. |
| 0x800F | 32783 | RDM response: Reply of the RDM telegramm ist invalid. |
| 0x8010 | 32784 | RDM response: The DMX slave cannot comply with request because the message is not implemented in responder. |
| 0x8011 | 32785 | RDM response: The DMX slave cannot interpret request as controller data was not formatted correctly. |
| 0x8012 | 32786 | RDM response: The DMX slave cannot comply due to an internal hardware fault. |
| 0x8013 | 32787 | RDM response: Proxy is not the RDM line master and cannot comply with message. |
| 0x8014 | 32788 | RDM response: SET Command normally allowed but being blocked currently. |
| 0x8015 | 32789 | RDM response: Not valid for *Command Class* attempted. May be used where GET allowed but SET is not supported. |
| 0x8016 | 32790 | RDM response: Value for given Parameter out of allowable range or not supported. |
| 0x8017 | 32791 | RDM response: Buffer or Queue space currently has no free space to store data. |
| 0x8018 | 32792 | RDM response: Incoming message exceeds buffer capacity. |
| 0x8019 | 32793 | RDM response: *Sub-Device* is out of range or unknown. |
| 0x801A | 32794 | The *iDMX512SlotOffset* lparameter is outside the valid range (0-511). |
| 0x801B | 32795 | The *bySensorNumber* parameter is outside the valid range (0-254). |
| 0x801C | 32796 | RDM-Response: The field *Parameter Data (PD)* is too long. It was not possible to receive all the data of the reply. For this purpose, the function block [FB\_EL6851CommunicationEx()](ms-xhelp:///?Id=beckhoff-6a9b-4d50-8a01-d179a95958e3) must be used. |
| 0x801D | 32797 | The ADS address to access the PDOs is invalid. Was the structure *AdsAddr* of the KL6851 mapped to the corresponding variable? |
| 0x801E | 32798 | During read access to the PDOs an ADS error has occurred. |
