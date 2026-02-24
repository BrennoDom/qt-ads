# Devices

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. Devices

# Devices

All certified DALI-2 devices are listed in a product database on the homepage of the Digital Illumination Interface Alliance (<https://www.dali-alliance.org/products>).

Each certified DALI-2 device has a unique GTIN (Global Trade Item Number). This GTIN can be read via memory bank 0 within the addresses 0x03 to 0x08 with the help of the function blocks [FB\_DALI102ReadMemoryBank](ms-xhelp:///?Id=beckhoff-5b05-4a6d-99fe-7e473b13d0d9) and [FB\_DALI103ReadMemoryBank](ms-xhelp:///?Id=beckhoff-f954-4792-aa75-834f862597b7). The memory bank can also be read out with the PLC HMI (see [PLC HMI](ms-xhelp:///?Id=beckhoff-4149-4ddb-9f17-e176e0be2b62)) and the KS2000 (see [KS2000](ms-xhelp:///?Id=beckhoff-4981-43fa-9ce4-5903fe21ad74)).

The devices that are supported by a function block in the library are listed below:

## B.E.G.

| Designation | Function block name | GTIN |
| --- | --- | --- |
| Indoor 180-BMS DALI-2 | [FB\_DALI\_BEG\_Indoor\_180\_BMS\_V8](ms-xhelp:///?Id=beckhoff-1867-4c7e-ba7b-d509d6765667) | 4007529935406 |
| LC-Mini 120-BMS DALI-2 | [FB\_DALI\_BEG\_LC\_Mini\_120\_BMS\_V8](ms-xhelp:///?Id=beckhoff-3504-4117-9fe5-64bff8c4ff61) | 4007529935413 |
| PD11-BMS-FLAT DALI-2 | [FB\_DALI\_BEG\_PD11\_BMS\_V8\_Flat](ms-xhelp:///?Id=beckhoff-ac8c-44ae-9f99-2fa564d78225) | 4007529935420 |
| PD2N-BMS-FC DALI-2 | [FB\_DALI\_BEG\_PD2N\_BMS\_V8\_FC](ms-xhelp:///?Id=beckhoff-21aa-4e97-a54d-cbf369597d66) | 4007529935437 |
| PD2N-BMS-FM DALI-2 | [FB\_DALI\_BEG\_PD2N\_BMS\_V8\_FM](ms-xhelp:///?Id=beckhoff-e156-4e5d-9d0a-a65af9278d4b) | 4007529935444 |
| PD4N-BMS DALI-2 | [FB\_DALI\_BEG\_PD4N\_BMS\_V8](ms-xhelp:///?Id=beckhoff-8f53-4494-b3e2-a9e690cd7acc) | 4007529935468 |
| PD4-BMS-GH-SM DALI-2 | [FB\_DALI\_BEG\_PD4\_BMS\_V8\_GH\_SM](ms-xhelp:///?Id=beckhoff-8946-40f5-87f9-ab95c1e73103) | 4007529935451 |
| PICO-BMS DALI-2 | [FB\_DALI\_BEG\_PICO\_BMS\_V8](ms-xhelp:///?Id=beckhoff-06ba-46d1-b191-31a9096a0f75) | 4007529935475 |

## Esylux

| Designation | Function block name | GTIN |
| --- | --- | --- |
| PD-C 360/8 BMS DALI-2 | [FB\_DALI\_Esylux\_PDC\_360\_BMS](ms-xhelp:///?Id=beckhoff-f640-4067-bed9-ed92357d7161) | 4015120428203 |
| PD-C 360/24 BMS DALI-2 | [FB\_DALI\_Esylux\_PDC\_360\_BMS](ms-xhelp:///?Id=beckhoff-f640-4067-bed9-ed92357d7161) | 4015120428210 |

## Glamox

| Designation | Function block name | GTIN |
| --- | --- | --- |
| LMS DALI-2 PB8 SWITCH PANEL | [FB\_DALI\_Glamox\_LMS\_PB8\_SwitchPanel](ms-xhelp:///?Id=beckhoff-3c06-4dc5-b878-4bb4e9d9bfdd) | 7020940423762 |

## Loytec

| Designation | Function block name | GTIN |
| --- | --- | --- |
| LDALI-BM2 | [FB\_DALI\_Loytec\_LDALI\_BM2](ms-xhelp:///?Id=beckhoff-69c4-414d-ad31-72b79c20129f) | 4710901730512 |
| LDALI-MS4-BT | [FB\_DALI\_Loytec\_LDALI\_MS4\_BT](ms-xhelp:///?Id=beckhoff-4fc7-4d95-85af-6c60737608f2) | 4710901730741 |
| LDALI-MS2-BT | [FB\_DALI\_Loytec\_LDALI\_MS2](ms-xhelp:///?Id=beckhoff-a60e-4add-b9cb-5bcfc14f0851) | 4710901730734 |
| LDALI-MS2 | [FB\_DALI\_Loytec\_LDALI\_MS2](ms-xhelp:///?Id=beckhoff-a60e-4add-b9cb-5bcfc14f0851) | 4710901730505 |

## Lunatone

| Designation | Function block name | GTIN |
| --- | --- | --- |
| DALI-2 CS | [FB\_DALI\_Lunatone\_CS](ms-xhelp:///?Id=beckhoff-7108-4dd0-856f-e1094739183b) | 9010342013546 |
| DALI-2 MC | [FB\_DALI\_Lunatone\_MC](ms-xhelp:///?Id=beckhoff-8c29-4a12-8097-99801977c0fb) | 9010342012730 |
| DALI-2 MC4L | [FB\_DALI\_Lunatone\_MC4L](ms-xhelp:///?Id=beckhoff-3f39-4c90-8fd7-9db7e4eb548a) | 9010342012754 |
| DALI-2 Cross Switch | [FB\_DALI\_Lunatone\_Cross\_Switch](ms-xhelp:///?Id=beckhoff-f5ea-4fb4-bf84-1461012e5ca9) | 9010342010224 |

## Niko

| Designation | Function block name | GTIN |
| --- | --- | --- |
| P46MR for surface mounting | [FB\_DALI\_Niko\_P46MR](ms-xhelp:///?Id=beckhoff-a25c-4e80-b2b0-a734bb5438fd) | 5413736374393 |
| P46MR for SnapFit flush mounting | [FB\_DALI\_Niko\_P46MR](ms-xhelp:///?Id=beckhoff-a25c-4e80-b2b0-a734bb5438fd) | 5413736374362 |
| P46MR for flush-mounting box | [FB\_DALI\_Niko\_P46MR](ms-xhelp:///?Id=beckhoff-a25c-4e80-b2b0-a734bb5438fd) | 5413736374348 |

## Osram

| Designation | Function block name | GTIN |
| --- | --- | --- |
| DALI COUPLER E G2 | [FB\_DALI\_Osram\_Coupler\_E\_G2](ms-xhelp:///?Id=beckhoff-06c6-4816-8893-bc1ac9395948) | 4062172072212 |
| DALI COUPLER HF G2 | [FB\_DALI\_Osram\_Coupler\_HF\_G2](ms-xhelp:///?Id=beckhoff-596a-4cc0-9885-a488fcb816e4) | 4062172072199 |
| DALI COUPLER LS HIGHBAY G2 | [FB\_DALI\_Osram\_Coupler\_LS\_Highbay\_G2](ms-xhelp:///?Id=beckhoff-6ede-486c-8ee1-5ff9f66b2c20) | 4062172072137 |
| DALI COUPLER MULTI3 G2 | [FB\_DALI\_Osram\_Coupler\_Multi3\_G2](ms-xhelp:///?Id=beckhoff-cc0d-472e-b7f4-fa346b95a3fd) | 4062172072113 |
| DALI COUPLER PB G2 | [FB\_DALI\_Osram\_Coupler\_PushB\_G2](ms-xhelp:///?Id=beckhoff-88af-410f-910e-4913dd89c73b) | 4062172087575 |
| LS/PD CI G2 | [FB\_DALI\_Osram\_LS\_PD\_CI\_G2](ms-xhelp:///?Id=beckhoff-f8a8-4124-9688-dadd87c91d0a) | 4062172072069 |
| LS/PD LI G2 | [FB\_DALI\_Osram\_LS\_PD\_LI\_G2](ms-xhelp:///?Id=beckhoff-089e-4e04-bc90-cc27d274f40b) | 4062172072069 |
| LS/PD LI UF G2 | [FB\_DALI\_Osram\_LS\_PD\_LI\_UF\_G2](ms-xhelp:///?Id=beckhoff-2f7b-41f9-815a-49b5d96218e7) | 4062172072045 |

## Steinel

| Designation | Function block name | GTIN |
| --- | --- | --- |
| Dual HF | [FB\_DALI\_Steinel\_ControlProDualHF](ms-xhelp:///?Id=beckhoff-8c3e-40ef-9e3a-c6ea4cbb15ce) | 4007841057459 |
| Dual Tech US | [FB\_DALI\_Steinel\_ControlProDualTech](ms-xhelp:///?Id=beckhoff-2ec7-41d9-b33c-7c22ae60206b) | 4007841057473 |
| Dual US | [FB\_DALI\_Steinel\_ControlProDualUS](ms-xhelp:///?Id=beckhoff-b548-4c78-b052-d54ba3ee3cc6) | 4007841057466 |
| IR Quattro HD | [FB\_DALI\_Steinel\_ControlProIRQuattroHD](ms-xhelp:///?Id=beckhoff-2469-437b-ad45-a930451eb2f9) | 4007841057497 |
| Single US | [FB\_DALI\_Steinel\_ControlProSingleUS](ms-xhelp:///?Id=beckhoff-7a63-4f82-aec7-23b82d655337) | 4007841057503 |
| US 360 | [FB\_DALI\_Steinel\_ControlProUS360](ms-xhelp:///?Id=beckhoff-d9ca-42e1-a50d-b888a0dc0ed1) | 4007841057534 |
| Dual Light Sensor AP | [FB\_DALI\_Steinel\_DualLightSensor](ms-xhelp:///?Id=beckhoff-3563-40e5-a2c9-235071e9e95b) | 4007841066291 |
| Dual Light Sensor AP square shape | [FB\_DALI\_Steinel\_DualLightSensor](ms-xhelp:///?Id=beckhoff-3563-40e5-a2c9-235071e9e95b) | 4007841057411 |
| Dual Light Sensor AP round shape | [FB\_DALI\_Steinel\_DualLightSensor](ms-xhelp:///?Id=beckhoff-3563-40e5-a2c9-235071e9e95b) | 4007841057428 |
| Dual Light Sensor UP | [FB\_DALI\_Steinel\_DualLightSensor](ms-xhelp:///?Id=beckhoff-3563-40e5-a2c9-235071e9e95b) | 4007841066369 |
| Dual Light Sensor UP square shape | [FB\_DALI\_Steinel\_DualLightSensor](ms-xhelp:///?Id=beckhoff-3563-40e5-a2c9-235071e9e95b) | 4007841057435 |
| Dual Light Sensor UP round shape | [FB\_DALI\_Steinel\_DualLightSensor](ms-xhelp:///?Id=beckhoff-3563-40e5-a2c9-235071e9e95b) | 4007841057442 |
| Hallway IPD UP | [FB\_DALI\_Steinel\_Hallway\_IPD](ms-xhelp:///?Id=beckhoff-fa61-4d37-9dca-0a8ce238f85d) | 4007841064532 |
| Hallway IPD AP | [FB\_DALI\_Steinel\_Hallway\_IPD](ms-xhelp:///?Id=beckhoff-fa61-4d37-9dca-0a8ce238f85d) | 4007841064549 |
| Hallway IPD ECO UP | [FB\_DALI\_Steinel\_Hallway\_IPD\_ECO](ms-xhelp:///?Id=beckhoff-d398-48cd-9901-a9ee7fc2f90d) | 4007841079048 |
| Hallway IPD ECO AP | [FB\_DALI\_Steinel\_Hallway\_IPD\_ECO](ms-xhelp:///?Id=beckhoff-d398-48cd-9901-a9ee7fc2f90d) | 4007841079031 |
| HF 3360 AP | [FB\_DALI\_Steinel\_HF3360](ms-xhelp:///?Id=beckhoff-948c-4f14-86b7-bd021c51dd76) | 4007841066284 |
| HF 3360 AP square shape | [FB\_DALI\_Steinel\_HF3360](ms-xhelp:///?Id=beckhoff-948c-4f14-86b7-bd021c51dd76) | 4007841057312 |
| HF 3360 AP round shape | [FB\_DALI\_Steinel\_HF3360](ms-xhelp:///?Id=beckhoff-948c-4f14-86b7-bd021c51dd76) | 4007841057329 |
| ☺HF 3360 UP | [FB\_DALI\_Steinel\_HF3360](ms-xhelp:///?Id=beckhoff-948c-4f14-86b7-bd021c51dd76) | 4007841066352 |
| HF 3360 UP square shape | [FB\_DALI\_Steinel\_HF3360](ms-xhelp:///?Id=beckhoff-948c-4f14-86b7-bd021c51dd76) | 4007841057336 |
| HF 3360 UP round shape | [FB\_DALI\_Steinel\_HF3360](ms-xhelp:///?Id=beckhoff-948c-4f14-86b7-bd021c51dd76) | 4007841057343 |
| HF 360 | [FB\_DALI\_Steinel\_HF360](ms-xhelp:///?Id=beckhoff-9e9f-4066-a13a-0e73ae138811) | 4007841057480 |
| HF 360 II IPD UP | [FB\_DALI\_Steinel\_HF360\_II\_IPD](ms-xhelp:///?Id=beckhoff-a72c-4485-a0e4-df94776517bb) | 4007841064280 |
| HF 360 II IPD AP | [FB\_DALI\_Steinel\_HF360\_II\_IPD](ms-xhelp:///?Id=beckhoff-a72c-4485-a0e4-df94776517bb) | 4007841064297 |
| HF 360 II IPD ECO UP | [FB\_DALI\_Steinel\_HF360\_II\_IPD\_ECO](ms-xhelp:///?Id=beckhoff-7d14-497e-a3af-2370913003dd) | 4007841067465 |
| HF 360 II IPD ECO AP | [FB\_DALI\_Steinel\_HF360\_II\_IPD\_ECO](ms-xhelp:///?Id=beckhoff-7d14-497e-a3af-2370913003dd) | 4007841067458 |
| IR Micro | [FB\_DALI\_Steinel\_IRMicro](ms-xhelp:///?Id=beckhoff-7d5f-406d-a1eb-350467e18534) | 4007841057732 |
| IR Quattro Micro | [FB\_DALI\_Steinel\_IRQuattroMicro](ms-xhelp:///?Id=beckhoff-5c8b-4b12-a855-4021741e72fb) | 4007841053871 |
| IR Quattro Slim XS | [FB\_DALI\_Steinel\_IRQuattroSlimXS](ms-xhelp:///?Id=beckhoff-6868-49db-a84a-b9b485fc99b0) | 4007841065034 |
| IR Quattro Slim XS square shape | [FB\_DALI\_Steinel\_IRQuattroSlimXS](ms-xhelp:///?Id=beckhoff-6868-49db-a84a-b9b485fc99b0) | 4007841057510 |
| IR Quattro Slim XS round shape | [FB\_DALI\_Steinel\_IRQuattroSlimXS](ms-xhelp:///?Id=beckhoff-6868-49db-a84a-b9b485fc99b0) | 4007841057527 |
| IS 345 AP | [FB\_DALI\_Steinel\_IS345](ms-xhelp:///?Id=beckhoff-1730-41a0-8529-eb13792ca384) | 4007841066253 |
| IS 345 AP square shape | [FB\_DALI\_Steinel\_IS345](ms-xhelp:///?Id=beckhoff-1730-41a0-8529-eb13792ca384) | 4007841057275 |
| IS 345 AP round shape | [FB\_DALI\_Steinel\_IS345](ms-xhelp:///?Id=beckhoff-1730-41a0-8529-eb13792ca384) | 4007841057299 |
| IS 345 UP | [FB\_DALI\_Steinel\_IS345](ms-xhelp:///?Id=beckhoff-1730-41a0-8529-eb13792ca384) | 4007841066321 |
| IS 345 UP square shape | [FB\_DALI\_Steinel\_IS345](ms-xhelp:///?Id=beckhoff-1730-41a0-8529-eb13792ca384) | 4007841057282 |
| IS 345 UP round shape | [FB\_DALI\_Steinel\_IS345](ms-xhelp:///?Id=beckhoff-1730-41a0-8529-eb13792ca384) | 4007841057305 |
| IS 345 MX AP | [FB\_DALI\_Steinel\_IS345MX](ms-xhelp:///?Id=beckhoff-3d3b-4d76-8f23-b14b4e155f5c) | 4007841066260 |
| IS 345 MX AP square shape | [FB\_DALI\_Steinel\_IS345MX](ms-xhelp:///?Id=beckhoff-3d3b-4d76-8f23-b14b4e155f5c) | 4007841057398 |
| IS 345 MX UP | [FB\_DALI\_Steinel\_IS345MX](ms-xhelp:///?Id=beckhoff-3d3b-4d76-8f23-b14b4e155f5c) | 4007841066338 |
| IS 3180 AP | [FB\_DALI\_Steinel\_IS3180](ms-xhelp:///?Id=beckhoff-05ce-4584-91ef-75fe5bacc19b) | 4007841066277 |
| IS 3180 AP square shape | [FB\_DALI\_Steinel\_IS3180](ms-xhelp:///?Id=beckhoff-05ce-4584-91ef-75fe5bacc19b) | 4007841057350 |
| IS 3180 UP | [FB\_DALI\_Steinel\_IS3180](ms-xhelp:///?Id=beckhoff-05ce-4584-91ef-75fe5bacc19b) | 4007841066345 |
| IS 3180 UP square shape | [FB\_DALI\_Steinel\_IS3180](ms-xhelp:///?Id=beckhoff-05ce-4584-91ef-75fe5bacc19b) | 4007841057367 |
| IS 3360 AP | [FB\_DALI\_Steinel\_IS3360](ms-xhelp:///?Id=beckhoff-4417-49fc-8113-e487312caaef) | 4007841066239 |
| IS 3360 AP square shape | [FB\_DALI\_Steinel\_IS3360](ms-xhelp:///?Id=beckhoff-4417-49fc-8113-e487312caaef) | 4007841057237 |
| IS 3360 AP round shape | [FB\_DALI\_Steinel\_IS3360](ms-xhelp:///?Id=beckhoff-4417-49fc-8113-e487312caaef) | 4007841057251 |
| IS 3360 UP | [FB\_DALI\_Steinel\_IS3360](ms-xhelp:///?Id=beckhoff-4417-49fc-8113-e487312caaef) | 4007841066307 |
| IS 3360 UP square shape | [FB\_DALI\_Steinel\_IS3360](ms-xhelp:///?Id=beckhoff-4417-49fc-8113-e487312caaef) | 4007841057244 |
| IS 3360 UP round shape | [FB\_DALI\_Steinel\_IS3360](ms-xhelp:///?Id=beckhoff-4417-49fc-8113-e487312caaef) | 4007841057268 |
| IS 3360 MX AP | [FB\_DALI\_Steinel\_IS3360MX](ms-xhelp:///?Id=beckhoff-1326-4575-a0bc-c47c9d42e9ae) | 4007841066246 |
| IS 3360 MX AP square shape | [FB\_DALI\_Steinel\_IS3360MX](ms-xhelp:///?Id=beckhoff-1326-4575-a0bc-c47c9d42e9ae) | 4007841057374 |
| IS 3360 MX UP | [FB\_DALI\_Steinel\_IS3360MX](ms-xhelp:///?Id=beckhoff-1326-4575-a0bc-c47c9d42e9ae) | 4007841066314 |
| IS 3360 MX UP square shape | [FB\_DALI\_Steinel\_IS3360MX](ms-xhelp:///?Id=beckhoff-1326-4575-a0bc-c47c9d42e9ae) | 4007841057381 |

## Sunricher

| Designation | Function block name | GTIN |
| --- | --- | --- |
| PushButtonCoupler | [FB\_DALI\_Sunricher\_PushButtonCoupler](ms-xhelp:///?Id=beckhoff-a424-4e54-9d83-54b9066d656c) | 06971542121819 |

## Theben

| Designation | Function block name | GTIN |
| --- | --- | --- |
| PlanoSpot 360 | [FB\_DALI\_Theben\_PlanoSpot\_360](ms-xhelp:///?Id=beckhoff-36d7-47a2-8dcc-878affbbf26b) | 4003468200360 |
| thePassa P360 | [FB\_DALI\_Theben\_thePassa\_P360](ms-xhelp:///?Id=beckhoff-313c-46b2-958d-2108e5d0945c) | 4003468200353 |
| theRonda P360 | [FB\_DALI\_Theben\_theRonda\_P360](ms-xhelp:///?Id=beckhoff-0f4b-4b88-a566-658cabc96ded) | 4003468200353 |
| theRonda S360 | [FB\_DALI\_Theben\_theRonda\_S360](ms-xhelp:///?Id=beckhoff-5c71-467f-8b54-b615e86d4c5f) | 4003468200384 |
| TA 4 S DALI-2 | [FB\_DALI\_Theben\_TA\_4\_S](ms-xhelp:///?Id=beckhoff-5bee-463c-8ad5-071760615ae6) | 4003468491584 |

## Tridonic

| Designation | Function block name | GTIN |
| --- | --- | --- |
| MSensor G3 SRC 30 PIR 5DPI | [FB\_DALI\_Tridonic\_MSensorG3\_SRC\_30\_PIR](ms-xhelp:///?Id=beckhoff-f0ab-4a2a-b1c4-7e6c21c8d480) | 9006210666693 |
| MSensor G3 SFI 30 PIR 5DPI BK | [FB\_DALI\_Tridonic\_MSensorG3\_SFI\_30\_PIR](ms-xhelp:///?Id=beckhoff-7763-4001-abae-5b378bca7b2d) | 9006210672540 |
| MSensor G3 SFI 30 PIR 5DPI WH | [FB\_DALI\_Tridonic\_MSensorG3\_SFI\_30\_PIR](ms-xhelp:///?Id=beckhoff-7763-4001-abae-5b378bca7b2d) | 9006210672502 |
| MSensor G3 SFI 30 PIR 16DPI WH | [FB\_DALI\_Tridonic\_MSensorG3\_SFI\_30\_PIR](ms-xhelp:///?Id=beckhoff-7763-4001-abae-5b378bca7b2d) | 9006210656205 |
| MSensor G3 SFI 30 PIR 10DPI WH | [FB\_DALI\_Tridonic\_MSensorG3\_SFI\_30\_PIR](ms-xhelp:///?Id=beckhoff-7763-4001-abae-5b378bca7b2d) | 9006210648149 |
| DALI XC G3 CWM 30 DA2 | [FB\_DALI\_Tridonic\_XC\_G3\_CWM30](ms-xhelp:///?Id=beckhoff-c4a3-41a1-b58b-027520b5ac3a) | 9006210708881 |

## Zencontrol

| Designation | Function block name | GTIN |
| --- | --- | --- |
| PIR | [FB\_DALI\_Zencontrol\_PIR](ms-xhelp:///?Id=beckhoff-cbab-43fb-a0d0-6bdb126de7a4) | 9336462199091 |
| Scenepanel Switch | [FB\_DALI\_Zencontrol\_Scenepanel\_Switch](ms-xhelp:///?Id=beckhoff-ee9b-4484-9d36-d3454a843f4e) | 6971103530319 |
| Switch 1 Button | [FB\_DALI\_Zencontrol\_Switch\_1Button](ms-xhelp:///?Id=beckhoff-82c6-47fc-9f28-d0bd54c50b14) | 9336462191897 |

As an alternative to the device function blocks, individual instances of DALI control units can be addressed via the general function blocks. Each of the general function blocks refers to a specific part of IEC 62386.

| IEC 62386-XXX | Function | Function block name |
| --- | --- | --- |
| 103 | General properties of the control devices | [FB\_DALI103ControlDevice](ms-xhelp:///?Id=beckhoff-0640-4af7-9b09-52543572b6a2) |
| 301 | Push buttons | [FB\_DALI301PushButton](ms-xhelp:///?Id=beckhoff-3611-4d6c-b681-6b9d564ec610) |
| 302 | Input devices, absolute encoder | [FB\_DALI302AbsoluteInputDevice](ms-xhelp:///?Id=beckhoff-436b-418d-9835-a1dddb8c5876) |
| 303 | Occupancy sensor | [FB\_DALI303OccupancySensor](ms-xhelp:///?Id=beckhoff-b3ed-4891-a29d-2a013af249e9) |
| 304 | Light sensor | [FB\_DALI304LightSensor](ms-xhelp:///?Id=beckhoff-7c21-47a1-9713-8de948496e63) |

Further function blocks to simplify the application of device function blocks

| Function block name | Function |
| --- | --- |
| [FB\_DALI\_ToPushButtonState](ms-xhelp:///?Id=beckhoff-c0d2-477c-96f3-465feb2dd845) | Determines the static state from the events of a button. |

Further Information

* [Introduction](ms-xhelp:///?Id=beckhoff-76fb-4ae6-b043-d81172882698)
* [B.E.G.](ms-xhelp:///?Id=beckhoff-78fd-41f1-83c3-e4ce141459e4)
* [Esylux](ms-xhelp:///?Id=beckhoff-6826-4353-b659-76c042af8154)
* [Glamox](ms-xhelp:///?Id=beckhoff-d179-41c3-a3a8-14738126cf10)
* [Loytec](ms-xhelp:///?Id=beckhoff-5ef8-4ddf-8346-4de944d9097e)
* [Lunatone](ms-xhelp:///?Id=beckhoff-1489-483a-a839-4e713e491a29)
* [Niko](ms-xhelp:///?Id=beckhoff-1595-4f00-9669-3821479d7864)
* [Osram](ms-xhelp:///?Id=beckhoff-29cb-4eda-adbd-6a699698c409)
* [Steinel](ms-xhelp:///?Id=beckhoff-4433-4e47-b6bb-9f4b9d82c036)
* [Sunricher](ms-xhelp:///?Id=beckhoff-4985-4a18-a77b-8544e538178a)
* [Theben](ms-xhelp:///?Id=beckhoff-bf82-4b3f-bbbd-70c4e1f85c36)
* [Tridonic](ms-xhelp:///?Id=beckhoff-d733-41fc-861d-fb9fd0e0bfd5)
* [Zencontrol](ms-xhelp:///?Id=beckhoff-dc54-408e-8122-694e588c626d)
* [FB\_DALI103ControlDevice](ms-xhelp:///?Id=beckhoff-0640-4af7-9b09-52543572b6a2)
* [FB\_DALI300GenericInstance](ms-xhelp:///?Id=beckhoff-5348-4320-8698-724bbf260ff4)
* [FB\_DALI301PushButton](ms-xhelp:///?Id=beckhoff-3611-4d6c-b681-6b9d564ec610)
* [FB\_DALI302AbsoluteInputDevice](ms-xhelp:///?Id=beckhoff-436b-418d-9835-a1dddb8c5876)
* [FB\_DALI303OccupancySensor](ms-xhelp:///?Id=beckhoff-b3ed-4891-a29d-2a013af249e9)
* [FB\_DALI304LightSensor](ms-xhelp:///?Id=beckhoff-7c21-47a1-9713-8de948496e63)
* [FB\_DALI\_ToPushButtonState](ms-xhelp:///?Id=beckhoff-c0d2-477c-96f3-465feb2dd845)

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
