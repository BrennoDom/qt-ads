# EnOcean

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# EnOcean

The EnOcean radio technology makes a far-reaching signal with low quantities of ambient energy possible. With 50 µWs, a standard EnOcean radio module can easily transmit a signal over a distance of 300 m (in the free field). The signal period for an EnOcean telegram is approx. 1 thousandth of second.

* Licence-free 868 MHz frequency band with 1% duty cycle
* Multiple telegram transmission with checksum
* Short telegrams (approx. 1 ms) lead to a small probability of collision
* Long range: 30 m inside buildings or 300 m in the free field
* Repeater available for extensions
* Unidirectional and bidirectional communication
* High data transmission rates of 125 kbit/s
* Low ‘data overhead’
* ASK modulation
* Radio protocol is defined and integrated in modules
* Sensor profiles specified and adhered to by users
* Unique transmission ID (32-bit)
* No interference with DECT, WLAN, PMR systems etc.
* System design verified in industrial environment

## Protocol structure

| Protocol | Description | Length |
| --- | --- | --- |
| ORG | Telegram type | 1 byte |
| DB\_3 | Data byte 3 | 1 byte |
| DB\_2 | Data byte 2 | 1 byte |
| DB\_1 | Data byte 1 | 1 byte |
| DB\_0 | Data byte 0 | 1 byte |
| ID\_3 | Transmitter ID byte 3 | 1 byte |
| ID\_2 | Transmitter ID byte 2 | 1 byte |
| ID\_1 | Transmitter ID byte 1 | 1 byte |
| ID\_0 | Transmitter ID byte 0 | 1 byte |
| STATUS | Information status | 1 byte |

Further Information

* [Range planning](ms-xhelp:///?Id=beckhoff-d3e7-4587-854a-a4e3b00bd2cd)
* [Approval of EnOcean wireless technology](ms-xhelp:///?Id=beckhoff-66b9-4b10-9309-b26e303d10ee)
