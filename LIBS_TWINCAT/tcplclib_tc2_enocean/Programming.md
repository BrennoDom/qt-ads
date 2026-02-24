# Programming

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# Programming

## POUs/KL6021-0023

| POUs | Description |
| --- | --- |
| [FB\_EnOceanReceive](ms-xhelp:///?Id=beckhoff-839a-4586-a2a0-666455178ef5) | Communication with KL6021-0023 |

## POUs/KL6021-0023/Read

| POUs | Description |
| --- | --- |
| [FB\_EnOceanPTM100](ms-xhelp:///?Id=beckhoff-ddd6-4763-84de-f64caad8c52f) | Receives the signals of a PTM100 module |
| [FB\_EnOceanPTM200](ms-xhelp:///?Id=beckhoff-9a1c-4d06-9ada-6cef10785823) | Receives the signals of a PTM200 module |
| [FB\_EnOceanSTM100](ms-xhelp:///?Id=beckhoff-bffe-402b-9d01-ad0b2d364e6e) | Receives the signals of a STM100 module (obsolete) |
| [FB\_EnOceanSTM100Generic](ms-xhelp:///?Id=beckhoff-9dc5-4b02-8cda-5fde9d631674) | Receives the signals of a STM100 module |
| [FB\_EnOceanSTM250](ms-xhelp:///?Id=beckhoff-67c7-4d4e-9a48-38f214e434d4) | Receives the signals of a STM250 module |

## POUs/KL6581

| Function blocks | Description |
| --- | --- |
| [FB\_KL6581](ms-xhelp:///?Id=beckhoff-45e5-4533-98ae-900c39c9c4dc) | Communication with a KL6581 |

## POUs/KL6581/Read

| POUs | Description |
| --- | --- |
| [FB\_Rec\_Generic](ms-xhelp:///?Id=beckhoff-9d7f-46b0-af93-1e402981a5e6) | Receives all types of EnOcean telegrams |
| [FB\_Rec\_1BS](ms-xhelp:///?Id=beckhoff-adfd-4f56-8e46-034ed98bf7e7) | Receives data with ORG telegram 6.Typical EnOcean device: Window contact. |
| [FB\_Rec\_RPS\_Switch](ms-xhelp:///?Id=beckhoff-9d2a-4228-977f-96abbe39058e) | Receives data with ORG telegram 5. Typical EnOcean device: Buttons. |
| [FB\_Rec\_RPS\_Window\_Handle](ms-xhelp:///?Id=beckhoff-2898-498b-a924-189bffa51eb7) | Receives data with ORG telegram 5.Typical EnOcean device: Window handle. |

## POUs/KL6581/Send

| POUs | Description |
| --- | --- |
| [FB\_Send\_Generic](ms-xhelp:///?Id=beckhoff-7c05-4b8d-a33e-47843da57461) | All kinds of EnOcean data telegrams can be sent with this block. |
| [FB\_Send\_4BS](ms-xhelp:///?Id=beckhoff-b129-4282-8755-d132e5f2a557) | Sends EnOcean telegrams in the 4BS format. |
| [FB\_Send\_RPS\_Switch](ms-xhelp:///?Id=beckhoff-2b32-4f43-8a3d-ce1e31a839c6) | Sends EnOcean telegrams in the format of a button. |
| [FB\_Send\_RPS\_SwitchAuto](ms-xhelp:///?Id=beckhoff-19e6-4895-9a32-a59a591e7d8b) | This function block sends data such as those from a switch. |

## POUs/KL6581/Other

| POUs | Description |
| --- | --- |
| [FB\_EnOcean\_Search](ms-xhelp:///?Id=beckhoff-7256-4d98-af27-a625c9557f51) | This function block recognizes all EnOcean devices within its range and displays them. |
| [FB\_Rec\_Teach\_In](ms-xhelp:///?Id=beckhoff-5766-4e2d-ba2e-98f60079c577) | This function block indicates if the LRN bit in an EnOcean telegram is set, independent of its EnOcean ID. |
| [FB\_Rec\_Teach\_In\_Ex](ms-xhelp:///?Id=beckhoff-fa3e-4952-abc4-274b7962d0a4) | This function block indicates pressing of the Learn button at an EnOcean device. |

## POUs/KL6581/Function

| Function blocks | Description |
| --- | --- |
| [F\_Byte\_To\_Temp](ms-xhelp:///?Id=beckhoff-31d8-4933-8068-3582a243f566) | This function converts a byte raw value into a REAL variable. |
| [F\_Byte\_To\_TurnSwitch](ms-xhelp:///?Id=beckhoff-6011-4653-9618-e3431a4db55e) | This function converts a raw byte value to a Boolean array. |

## DUTs/KL6021-0023/Hardware Types

| Data types | Description |
| --- | --- |
| [ST\_EnOceanInData](ms-xhelp:///?Id=beckhoff-ae21-4b2d-b5d2-d7c909ac2ad5) | Process image of the KL6021-0023 inputs |
| [ST\_EnOceanOutData](ms-xhelp:///?Id=beckhoff-001e-487a-a974-cb5121ba6e02) | Process image of the KL6021-0023 outputs |

## DUTs/KL6021-0023

| Data types | Description |
| --- | --- |
| [E\_EnOceanRotarySwitch](ms-xhelp:///?Id=beckhoff-a4b0-4c45-af9b-5d049475e25f) | State of the rotary-switch on the transmitting-module |
| [E\_EnOceanSensorType](ms-xhelp:///?Id=beckhoff-36ea-4246-b787-4e922c1b8f67) | Sensor type |
| [ST\_EnOceanReceivedData](ms-xhelp:///?Id=beckhoff-cc12-4397-a341-a293a6adc9d6) | Internal structure |

## DUTs/KL6581/hardware types

| Data types | Description |
| --- | --- |
| [KL6581\_Input](ms-xhelp:///?Id=beckhoff-1b0f-4c6b-a4a2-2792b44d79e7) | Process image of the KL6581 inputs |
| [KL6581\_Output](ms-xhelp:///?Id=beckhoff-b91e-4512-8aff-fc60e41eca45) | Process image of the KL6581 outputs |

## DUTs/KL6581

| Data types | Description |
| --- | --- |
| [AR\_EnOceanWindow](ms-xhelp:///?Id=beckhoff-04b7-4ad4-8994-fa5536cada8b) | State of the window |
| [E\_ENOCEAN\_Org](ms-xhelp:///?Id=beckhoff-e3c8-482c-89a5-b64382283c8d) | EnOcean telegram type |
| [E\_KL6581\_Err](ms-xhelp:///?Id=beckhoff-3415-4c23-8a89-721c05c3fbe1) | Error messages |
| [STR\_EnOceanSwitch](ms-xhelp:///?Id=beckhoff-cbaa-49ae-a4b4-c12b69cc6ed8) | State of the buttons |
| [STR\_KL6581](ms-xhelp:///?Id=beckhoff-5a94-43ed-9608-18055618a879) | Internal structure |
| [STR\_Teach\_In](ms-xhelp:///?Id=beckhoff-18c2-4fa7-ad13-528da8ce2bbf) | Data structure manufacturer ID, type and profile |
| [STREnOceanTurnSwitch](ms-xhelp:///?Id=beckhoff-f1fc-41fb-bd39-05a81ecbe6da) | Position of the rotary switch at the room control unit |

Further Information

* [POUs](ms-xhelp:///?Id=beckhoff-1944-400d-8749-04e5b6b59f16)
* [DUTs](ms-xhelp:///?Id=beckhoff-5325-4380-9c86-7f0516f49791)
* [Integration into TwinCAT](ms-xhelp:///?Id=beckhoff-d657-4f55-8f84-2ed78b71e501)
