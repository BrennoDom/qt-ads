# Error codes

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# Error codes

| ErrId (hex) | ErrId (dec) | ErrArg | Description |
| --- | --- | --- | --- |
| 0x0000 | 0 | n/a | No error. |
| 0x8001 | 32769 | n/a | Internal error: no AMS-Net ID is read out. The process image is possibly not correctly linked. |
| 0x8002 | 32770 | n/a | Incorrect baud rate entry. |
| 0x8003 | 32771 | Sub-function-block error number | Internal error while writing the configuration data. *udiErrorArg* contains the error number of the write function block FB\_EcCoESdoWrite() of the internally used library TcEtherCAT.lib. |
| 0x8004 | 32772 | n/a | Internal error: Incorrect pointer assignment *pRegComIn*/*pRegComOut*. One of the two pointers points to the address 0. |
| 0x8005 | 32773 | n/a | Timeout error during the register communication. |
| 0x8019 | 32793 | n/a | Invalid master address. Valid range: 0 - 31. |
| 0x8020 | 32800 | Sub-function-block error number | Error while configuring a KL6xxx (5 bytes of data). *udiErrorArg* contains the error number of the internal configuration function block. |
| 0x8021 | 32801 | Sub-function-block error number | Error while configuring a KL6xxx (22 bytes of data). *udiErrorArg* contains the error number of the internal configuration function block. |
| 0x8022 | 32802 | Sub-function-block error number | Error while configuring a KL6xxx (22 bytes of data). *udiErrorArg* contains the error number of the internal configuration function block. |
| 0x8023 | 32803 | 1 | Incorrect communication type (*eGENIbusComMode* input). |
|  |  | 2 | Incorrect pointer assignment. One of the two addresses of the selected input/output variable (*stGENIbusInData*/*stGENIbusOutData*) points to the address 0. |
|  |  | 3 | Communication via an EtherCAT Terminal is selected. However, the EL6xxx terminal is not in the “OP state”. |
|  |  | 4 | The EL6xxx terminal contains incorrect data. This is signaled by the fact that the input variable “WC State” is set to 1. |
| 0x8024 | 32804 | Sub-function-block error number | Error during the creation of the serial telegram. *udiErrorArg* contains the error number of the internal function block. |
| 0x8025 | 32805 | Sub-function-block error number | Error during the serial data transmission. *udiErrorArg* contains the error number of the internal function block. |
| 0x8026 | 32806 | Sub-function-block error number | Error during the evaluation of the serial telegram. *udiErrorArg* contains the error number of the internal function block. |
| 0x8027 | 32807 | n/a | Timeout error during the transmit-receive cycle. |
| 0x8030 | 32816 | n/a | Index error while transmitting the telegram. |
| 0x8031 | 32817 | n/a | Index error while receiving the telegram. |
| 0x8032 | 32818 | n/a | Incorrect data length while receiving the telegram. |
| 0x8033 | 32819 | n/a | Timeout error while receiving the telegram. |
| 0x8040 | 32832 | Incorrect OS | The response telegram contains an unknown “Operation Specifier” (OS), see *GENIbus Protocol Specification.* |
| 0x8041 | 32833 | n/a | Telegram length error. |
| 0x8042 | 32834 | n/a | Telegram CRC check error. |
| 0x8045 | 32837 | Maximum number of APDUs | Error during the conversion to a telegram: too many APDU entries. *udiErrorArg* shows the maximum possible number of APDU entries. |
| 0x8049 | 32841 | n/a | Invalid device (slave) address. Valid range: 1 - 200. |
| 0x8050 | 32848 | n/a | Incorrect class entry *byClass.* |
| 0x8051 | 32849 | n/a | Incorrect entry *eCommandPriority.* |
| 0x8052 | 32850 | n/a | Incorrect entry *eSetOpMode.* |
| 0x8053 | 32851 | n/a | Incorrect entry *eSetCtrlMode.* |
| 0x8054 | 32852 | n/a | Incorrect entry *eSetNightReductionMode.* |
| 0x8055 | 32853 | n/a | Incorrect entry *eSetKeyMode.* |
| 0x8056 | 32854 | n/a | Command buffer overflow (*stCommandBuffer*): Not all previously transmitted commands have been processed. |
| 0x8057 | 32855 | n/a | Timeout error (runtime monitoring) with the response telegram. |
| 0x8058 | 32856 | n/a | The response telegram of the GENIbus device reports “Data Class Unknown”, see *GENIbus Protocol Specification*, feedback entry “*ACK*”. |
| 0x8059 | 32857 | n/a | The response telegram of the GENIbus device reports “Data Item ID Unknown”, see *GENIbus Protocol Specification*, feedback entry “*ACK*”. |
| 0x805A | 32858 | n/a | The response telegram of the GENIbus device reports “Invalid command or Data Class write buffer is full”, see *GENIbus Protocol Specification*, feedback entry “*ACK*”. |
| 0x805B | 32859 | n/a | Unknown ACK entry in response telegram. |
| 0x805C | 32860 | transferred error number | The FB\_GENIbusCommunication() function block has already detected an error and entered it in the response structure *stResponseTableItem*. *udiErrorArg* contains the error number of the FB\_GENIbusCommunication() function block. |
| 0x805D | 32861 | transferred error number | An internal error has occurred during the scaling. *udiErrorArg* contains the internal error number. |
| 0x8060 | 32864 | n/a | Data size (*eDataSize*) invalid. |
| 0x8061 | 32865 | n/a | Invalid Scale-Info parameter in the telegram (*eSIF*), see *GENIbus Protocol Specification*, feedback entry “SIF”. |
| 0x8062 | 32866 | n/a | Invalid combination of data size and Scale-Info. |
| 0x8063 | 32867 | n/a | No info data available. |
| 0x8064 | 32868 | n/a | The read-out unit index is not assigned to any unit, i.e. it doesn’t exist in the internal tables. |
