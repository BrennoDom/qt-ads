# AX200x Profibus Parameter Number

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Appendix](ms-xhelp:///?Id=beckhoff-6af7-46b2-b3e4-1069fad0c1b1)
3. AX200x Profibus Parameter Number

# AX200x Profibus Parameter Number

| PNU | Data type | Access | Short description | SERVOSTAR™**ASCII command** |
| --- | --- | --- | --- | --- |
| **Profile parameter** | | | | |
| 904 | UINT32 | ro | Number of the supported PPO write, always 2 | - |
| 911 | UINT32 | ro | Number of the supported PPO read, always 2 | - |
| 918 | UINT32 | ro | Device address on the PROFIBUS | ADDR |
| 930 | UINT32 | r/w | Selection switch for operating mode | - |
| 963 | UINT32 | ro | PROFIBUS baud rate | - |
| 965 | Octet-String2 | ro | Number of the PROFIDRIVE profile (0302H) | - |
| 970 | UINT32 | wo | Load default parameter set | RSTVAR |
| 971 | UINT32 | wo | Store parameter in non-volatile memory | SAVE |
| **SERVOSTAR™ manufacturer-specific parameters** | | | | |
| **General parameters** | | | | |
| 1000 | Visible String4 | ro | Device identifier | - |
| 1001 | UINT32 | ro | Manufacturer-specific error register | ERRCODE |
| 1002 | UINT32 | ro | Manufacturer-specific status register | - |
| **Speed controller parameters** | | | | |
| 1200 | UINT32 | r/w | Kp - amplification factor of the speed controller | GV |
| 1201 | UINT32 | r/w | Tn – integral-action time of the speed controller | GVTN |
| 1202 | UINT32 | r/w | PID – T2 – time constant for the speed controller | GVT2 |
| 1203 | UINT32 | r/w | Set value ramp+, speed controller | ACC |
| 1204 | UINT32 | r/w | Set value ramp-, speed controller | DEC |
| 1205 | UINT32 | r/w | Emergency ramp, speed controller | DECSTOP |
| 1206 | UINT32 | r/w | Maximum rotation speed | VLIM |
| 1207 | UINT32 | r/w | Overspeed | VOSPD |
| 1208 | UINT32 | r/w | Counting direction | DIR |
| **Position controller parameters** | | | | |
| 1250 | UINT32 | r/w | Multiplier for speeds jogging/ref. | VMUL |
| 1251 | UINT32 | r/w | Axis type | POSCNFG |
| 1251 | INTEGER32 | r/w | In-position window | PEINPOS |
| 1253 | INTEGER32 | r/w | Following error window | PEMAX |
| 1254 | INTEGER32 | r/w | Position register 1 | SWE1 |
| 1255 | INTEGER32 | r/w | Position register 2 | SWE2 |
| 1256 | INTEGER32 | r/w | Position register 3 | SWE3 |
| 1257 | INTEGER32 | r/w | Position register 4 | SWE4 |
| 1258 | UINT32 | r/w | Resolution denominator | PGEARO |
| 1259 | UINT32 | r/w | Resolution numerator | PGEARI |
| 1260 | UINT32 | r/w | Minimum acceleration or braking time | PTMIN |
| 1261 | UINT32 | r/w | Position controller feed-forward factor | GPFFV |
| 1262 | UINT32 | r/w | Position controller KV factor | GP |
| 1263 | UINT32 | r/w | Position controller KP factor | GPV |
| 1264 | UINT32 | r/w | Tn - position controller integral-action time | GPTN |
| 1265 | UINT32 | r/w | Maximum speed for positioning operation | PVMAX |
| 1266 | UINT32 | r/w | Configuration variable for software switch | SWCNFG |
| 1267 | UINT32 | r/w | Configuration variable 2 for software switch | SWCNFG2 |
| **Positioning data for position controller mode** | | | | |
| 1300 | INTEGER32 | r/w | Position | O\_P |
| 1301 | INTEGER16 | r/w | Velocity | O\_V |
| 1302 | UINT32 | r/w | Transport instruction type | O\_C |
| 1304 | UINT32 | r/w | Starting up time (acceleration) | O\_ACC1 |
| 1305 | UINT32 | r/w | Braking time (deceleration) | O\_DEC1 |
| 1306 | UINT32 | r/w | Jerk limitation (acceleration) | O\_ACC2 |
| 1307 | UINT32 | r/w | Jerk limitation (deceleration) | O\_DEC2 |
| 1308 | UINT32 | r/w | Number of the subsequent transport instruction | O\_FN |
| 1309 | UINT32 | r/w | Start delay for subsequent transport instruction | O\_FT |
| 1310 | 2 \* UINT16 | wo | Copy a transport instruction | OCOPY |
| **Setting-up mode, position** | | | | |
| 1350 | UINT32 | r/w | Reference travel type | NREF |
| 1351 | UINT32 | r/w | Reference travel direction | DREF |
| 1352 | UINT32 | r/w | Acceleration ramp (jogging/referencing) | ACCR |
| 1353 | UINT32 | r/w | Braking ramp | DECR |
| 1354 | UINT32 | r/w | Reference offset | ROFFS |
| 1355 | UINT32 | ro | Reference travel speed | VREF |
| 1356 | UINT32 | ro | Jogging speed | VJOG |
| **Actual values** | | | | |
| 1400 | INTEGER32 | ro | Actual position represented with 20 bits/rotation | PRD |
| 1401 | INTEGER32 | ro | Speed | - |
| 1402 | INTEGER32 | ro | Incremental actual position value | - |
| 1403 | INTEGER32 | ro | SI - actual position value | PFB |
| 1404 | INTEGER32 | ro | SI - actual speed value | PV |
| 1405 | INTEGER32 | ro | SI - following error | PE |
| 1406 | INTEGER32 | ro | Effective current | I |
| 1407 | INTEGER32 | ro | SI - actual rotation speed | V |
| 1408 | INTEGER32 | ro | Heatsink temperature | TEMPH |
| 1409 | INTEGER32 | ro | Internal temperature | TEMPE |
| 1410 | INTEGER32 | ro | DC link voltage | VBUS |
| 1411 | INTEGER32 | ro | Ballast power | PBAL |
| 1412 | INTEGER32 | ro | I2t - loading | I2T |
| 1413 | INTEGER32 | ro | Period of operation | TRUN |
| **Digital I/O-configuration** | | | | |
| 1450 | UINT32 | r/w | Function of digital input 1 | IN1MODE |
| 1451 | UINT32 | r/w | Function of digital input 2 | IN2MODE |
| 1452 | UINT32 | r/w | Function of digital input 3 | IN3MODE |
| 1453 | UINT32 | r/w | Function of digital input 4 | IN4MODE |
| 1454 | INTEGER32 | r/w | Auxiliary variable for digital input 1 | IN1TRIG |
| 1455 | INTEGER32 | r/w | Auxiliary variable for digital input 2 | IN2TRIG |
| 1456 | INTEGER32 | r/w | Auxiliary variable for digital input 3 | IN3TRIG |
| 1457 | INTEGER32 | r/w | Auxiliary variable for digital input 4 | IN4TRIG |
| 1458 | INTEGER32 | r/w | Function of digital output 1 | O1MODE |
| 1459 | INTEGER32 | r/w | Function of digital output 2 | O2MODE |
| 1460 | UINT32 | r/w | Auxiliary variable for digital output 1 | O1TRIG |
| 1461 | UINT32 | r/w | Auxiliary variable for digital output 2 | O2TRIG |
| 1462 | UINT32 | r/w | State of 4 digital inputs, enable, 2 digital outputs | STATIO |
| **Analog configuration** | | | | |
| 1500 | UINT32 | r/w | Configuration of the analog input functions | ANCNFG |
| 1501 | UINT32 | r/w | Configuration of monitor function for analog output 1 | ANOUT1 |
| 1502 | UINT32 | r/w | Offset voltage for analog input 1 | ANOFF1 |
| 1503 | UINT32 | r/w | Filter time constant for analog input 1 | AVZ1 |
| 1504 | UINT32 | r/w | Speed scaling factor for analog input 1 | VSCALE1 |
| 1505 | UINT32 | r/w | Current scaling factor for analog input 1 | ISCALE1 |
| 1506 | UINT32 | r/w | Configuration of monitor function for analog output 2 | ANOUT2 |
| 1507 | UINT32 | r/w | Offset voltage for analog input 2 | ANOFF2 |
| 1508 | UINT32 | r/w | Speed scaling factor for analog input 2 | VSCALE2 |
| 1509 | UINT32 | r/w | Current scaling factor for analog input 2 | ISCALE2 |
| **Motor parameters** | | | | |
| 1550 | UINT32 | r/w | Brake configuration | MBRAKE |
| 1551 | UINT32 | r/w | Motor number from the motor database | MNUMBER |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
