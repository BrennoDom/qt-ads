# Error codes

## Library
tcplclib_tc2_smi

## Category
Motion Control

# Error codes

| Value (hex) | Value (dec) | Description |
| --- | --- | --- |
| 0x0000 | 0 | No error. |
| 0x8001 | 32769 | No response from the SMI drive. |
| 0x8002 | 32770 | No terminal feedback for the transmit data from the SMI terminal. |
| 0x8003 | 32771 | The terminal has detected a telegram error (StatusWord.6 = true). This message must be acknowledged by the bResetDataFrameError input of FB\_KL6831KL6841Communication(). |
| 0x8004 | 32772 | NACK received from the drive. |
| 0x8005 | 32773 | Invalid feedback received from the drive. |
| 0x8006 | 32774 | Communication buffer overflow. |
| 0x8007 | 32775 | No response from the communication function block. |
| 0x8008 | 32776 | The SMI\_COMMAND\_BUFFER\_ENTRIES constant is outside the valid range (2-250). |
| 0x8009 | 32777 | The ID byte received is incorrect. |
| 0x800A | 32778 | The data length received is not correct. |
| 0x800B | 32779 | No 24 V supply voltage to the KL6831/KL6841 (StatusWord.2 = false). |
| 0x800C | 32780 | Process image was deactivated by the Switch1 or Switch2 input of the terminal (StatusWord.5 = true). This message must be acknowledged by the bResetInactiveProcessImage input of FB\_KL6831KL6841Communication(). |
| 0x800D | 32781 | The terminal has detected a checksum error (StatusWord.8 = true). This message is reset as soon as a telegram is successfully transmitted. |
| 0x800E | 32782 | The SMI command does not support addressing via slave ID (eAddrType = eSMIAddrTypeSlaveId). |
| 0x800F | 32783 | The wAddr parameter (bit field for group addressing) is outside the valid range (0-65535). |
| 0x8010 | 32784 | The wAddr parameter (address) is outside the valid range (0-15). |
| 0x8011 | 32785 | The eCommandPriority parameter is invalid. |
| 0x8012 | 32786 | The eCommandType parameter is invalid. |
| 0x8013 | 32787 | The uiAngle parameter is outside the valid range (0-510). |
| 0x8014 | 32788 | The wParAddr parameter is outside the valid range (0-4095). |
| 0x8015 | 32789 | The eAddrType parameter is invalid. |
| 0x8016 | 32790 | The eResponseFormat parameter is invalid. |
| 0x8017 | 32791 | The wAddr parameter (manufacturer code) is outside the valid range (0-15). |
| 0x8018 | 32792 | The command supports only individual addressing. |
| 0x8019 | 32793 | The wAddrOption parameter (manufacturer code) is outside the valid range (0-15). |
| 0x801A | 32794 | An internal error has occurred in the FB\_SMIDiscoverySlaveId function block. |
| 0x801B | 32795 | No devices were found. |
| 0x801C | 32796 | All 16 addresses have already been assigned. There are possibly more than 16 devices connected to the SMI bus. |
| 0x801D | 32797 | Invalid diagnostic response received (neither NACK nor ACK). |
| 0x801E | 32798 | The byHighestAddress parameter (highest address) is outside the valid range (0-15). |
| 0x801F | 32799 | Timeout for internal addressing. The terminal has not sent a reply following the start of internal addressing. |
| 0x8020 | 32800 | The internal addressing failed three times. |
