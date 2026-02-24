# Error codes

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. Error codes

# Error codes

| Value (hex) | Value (dec) | Description |
| --- | --- | --- |
| 0x0000 | 0 | No error. |
| 0x0001 | 1 | No response from the DALI terminal. |
| 0x0002 | 2 | No response from the DALI control gear. |
| 0x0003 | 3 | Communication buffer overflow. |
| 0x0004 | 4 | No response from the communication block. |
| 0x0005 | 5 | DALI collision detected on the backward channel: during the transfer of a DALI telegram, a collision with the transmit data of another DALI slave was detected. |
| 0x0006 | 6 | DALI collision detected on the forward channel: during the transfer of a DALI telegram, a collision with the send data of another DALI master was detected. The error also occurs if the 24 V supply is missing at the power contacts of the KL6811. |
| 0x0007 | 7 | When using the internal DALI power supply unit of the KL6811: overload of the internal DALI power supply unit of the KL6811 (bus under-voltage). |
| 0x0008 | 8 | Parameter *eCommandPriority* lies outside of the valid range. |
| 0x0009 | 9 | Parameter *eAddrType* lies outside of the valid range. |
| 0x000A | 10 | Parameter *nAddr* is a short address and lies outside of the valid range. |
| 0x000B | 11 | Parameter *nAddr* is a group address and lies outside of the valid range. |
| 0x000C | 12 | Parameter *nGroup* lies outside of the valid range. |
| 0x000D | 13 | Parameter *nScene* lies outside of the valid range. |
| 0x000E | 14 | Parameter *nStartWithShortAddress* lies outside of the valid range. |
| 0x000F | 15 | No further free short addresses. |
| 0x0010 | 16 | Parameter *nNewShortAddress* lies outside of the valid range. |
| 0x0011 | 17 | Parameter *nNewShortAddress01* lies outside of the valid range. |
| 0x0012 | 18 | Parameter *nShortAddress02* lies outside of the valid range. |
| 0x0013 | 19 | Parameter *nFreeShortAddress* lies outside of the valid range. |
| 0x0014 | 20 | The short address in parameter *nFreeShortAddress* is occupied within the DALI line. |
| 0x0015 | 21 | Parameter *arrSwapShortAddressList* contains invalid values. |
| 0x0016 | 22 | Parameter *nHysteresis* lies outside of the valid range. |
| 0x0017 | 23 | Parameter *nProlongValue* is outside of the valid range. |
| 0x0018 | 24 | Lamp value of the master device is too long 255 -> possible fault. |
| 0x0019 | 25 | Parameter *nEndLevel* is outside of the valid range. |
| 0x001A | 26 | Target value *nEndLevel* has not yet been reached after double the ramp time. |
| 0x001B | 27 | *FB\_DALIV2LightControl:* There are setpoints (*nSetpoint*) in the value table *arrControlTable* that lie outside of the valid DALI range (0..254). |
| 0x001C | 28 | *FB\_DALIV2LightControl:* The switch range (*nSwitchRange*) in the first or second element of the value table *arrControlTable* is 0, assuming that the table has no or only one value set. |
| 0x001D | 29 | *FB\_DALIV2LightControl:* 2 neighboring input values *nActualValue* in the value table *arrControlTable* lie too close together i.e. each in the switching range of the other. |
| 0x001E | 30 | *FB\_DALIV2LightControl:* A setpoint (*nSetpoint*) in the value table *arrControlTable* lies outside of the valid range. Only queried after *bStart*. |
| 0x001F | 31 | Internal status query of the master device returns "fading active" for too long after the dimming time. See [STATUS INFORMATION](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) (bit4). |
| 0x0020 | 32 | Parameter *nPresenceValue* is outside of the valid range. |
| 0x0021 | 33 | Timeout during internal addressing (see also [FB\_DALIV2AddressingIntRandomAddressing()](ms-xhelp:///?Id=beckhoff-9857-4876-8432-cc4169af880e)). The terminal has not sent a response following the start of internal addressing. |
| 0x0022 | 34 | The terminal has returned an error during internal addressing (see also [FB\_DALIV2AddressingIntRandomAddressing()](ms-xhelp:///?Id=beckhoff-9857-4876-8432-cc4169af880e)). |
| 0x0023 | 35 | At least one test is currently running or is automatically pending. |
| 0x0024 | 36 | The device is in automatic test mode. |
| 0x0025 | 37 | The batteries of the emergency light device are not fully charged for a duration test. |
| 0x0026 | 38 | Test interrupted - no valid emergency mode / emergency status. |
| 0x0027 | 39 | Test interrupted: Test mode was not attained. |
| 0x0028 | 40 | Test interrupted because timeout was exceeded. |
| 0x0029 | 41 | Error while processing a DALI command. |
| 0x002A | 42 | Error while writing into the log file. |
| 0x002B | 43 | Device is not in "normal mode" |
| 0x002C | 44 | FB\_DALIV2Sequencer: The start index *nStartIndex* is outside of the valid range [1..50]. |
| 0x002D | 45 | FB\_DALIV2Sequencer: The start index *nStartIndex* refers to a point that, for its part, marks the end of a sequence (zero entries). |
| 0x002E | 46 | FB\_DALIV2ChangeAddressList: The change list *arrChangeAddressList* is empty. |
| 0x002F | 47 | FB\_DALIV2ChangeAddressList: The change list *arrChangeAddressList* contains an invalid short address entry (>63). |
| 0x0030 | 48 | FB\_DALIV2ChangeAddressList: The change list *arrChangeAddressList* contains a double list item in the short addresses. |
| 0x0031 | 49 | FB\_DALIV2ChangeAddressList: The change list *arrChangeAddressList* contains an entry for a new short address which, however, is already assigned to a device that is not affected by the changes. The addresses were changed back. |
| 0x0032 | 50 | FB\_KL6811Config(): An error occurred during configuration of the terminal. |
| 0x0033 | 51 | FB\_KL6811Config(): Parameter *eOperationMode* is outside the valid range. |
| 0x0034 | 52 | The constant DALI\_MESSAGE\_QUEUE\_ENTRIES is outside the valid range (2-250). |
| 0x0035 | 53 | The constant DALI\_RESPONSE\_TABLE\_ENTRIES is outside the valid range (2-250). |
| 0x0036 | 54 | The constant DALI\_EVENT\_TABLE\_ENTRIES is outside the valid range (2-250). |
| 0x0037 | 55 | When using the internal DALI power supply unit: Power supply unit fault detected. |
| 0x0038 | 56 | The process image was disabled by the DI1 or DI2 inputs of the terminal. |
| 0x0039 | 57 | Parameter *eInstAddrType* is outside the valid range. |
| 0x003A | 58 | Parameter *eDataFrameType* is outside the valid range. |
| 0x003B | 59 | DSI is not supported by the Bus Terminal. |
| 0x003C | 60 | Parameter *nEventPriority* is outside the valid range. |
| 0x003D | 61 | Parameter *nGroup* lies outside of the valid range. |
| 0x003E | 62 | Parameter *nInstanceGroup* is outside the valid range. |
| 0x003F | 63 | Parameter *eEventScheme* is outside the valid range. |
| 0x0040 | 64 | Parameter *eEventFilter* is outside the valid range. |
| 0x0041 | 65 | Parameter *nInstAddr* is outside the valid range. |
| 0x0042 | 66 | Parameter *ePowerSupplyMode* is outside the valid range. |
| 0x0043 | 67 | Parameter eCommandKBusWatchdog is outside the valid range. |
| 0x0044 | 68 | Parameter *eCommandDI1RisingEdge* is outside the valid range. |
| 0x0045 | 69 | Parameter *eCommandDI1FallingEdge* is outside the valid range. |
| 0x0046 | 70 | Parameter *eCommandDI2RisingEdge* is outside the valid range. |
| 0x0047 | 71 | Parameter *eCommandDI2FallingEdge* is outside the valid range. |
| 0x0048 | 72 | During internal addressing (see also [FB\_DALIV2AddressingIntRandomAddressing()](ms-xhelp:///?Id=beckhoff-9857-4876-8432-cc4169af880e)) the terminal has detected that there is no further short address available. |
| 0x0049 | 73 | During internal addressing (see also [FB\_DALIV2AddressingIntRandomAddressing](ms-xhelp:///?Id=beckhoff-9857-4876-8432-cc4169af880e)()) the terminal has detected that several devices have the same long address. |
| 0x004A | 74 | Internal addressing (see also [FB\_DALIV2AddressingIntRandomAddressing](ms-xhelp:///?Id=beckhoff-9857-4876-8432-cc4169af880e)()) has failed 3 times. |
| 0x004B | 75 | The communication buffer for sending the DALI commands has been blocked for longer than permitted. |
| 0x004C | 76 | The constant DALIV2\_TIMEOUT\_LOCK\_MESSAGE\_QUEUE is outside the valid range (0-2 min). |
| 0x004D | 77 | During internal addressing (see also [FB\_DALIV2AddressingIntRandomAddressing()](ms-xhelp:///?Id=beckhoff-9857-4876-8432-cc4169af880e)) the terminal has detected a short circuit on the bus. |
| 0x004E | 78 | Short circuit detected on the DALI bus. Possible causes: - No 24 V supply at the KL6821. - There is a short circuit on the DALI bus. |
| 0x004F | 79 | Undervoltage on the DALI bus. Possible causes: - Collision during telegram transmission (possibly several DALI devices have the same short address). - The internal power supply unit has been deactivated and there is no external bus supply. |
| 0x0050 | 80 | The received data is flawed. |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
