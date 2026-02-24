# Programming

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. Programming

# Programming

The manufacturer-specific blocks only output a selection of the most common data. These data are described on the respective pages under "VAR\_OUTPUT". If more or all data are required, the blocks [FB\_MBUS\_General()](ms-xhelp:///?Id=beckhoff-8e90-4a30-8684-e4959275ff37), [FB\_MBUS\_General\_Ext()](ms-xhelp:///?Id=beckhoff-7616-46e1-8f68-e6176732685e) or [FB\_MBUS\_General\_Param()](ms-xhelp:///?Id=beckhoff-ac86-411d-8af8-85905f72b0e0) from the folder "[General](ms-xhelp:///?Id=beckhoff-c2c9-4532-a008-46db7e04da46)" should be used. The block [FB\_MBUS\_General\_Send()](ms-xhelp:///?Id=beckhoff-7b44-4f8f-aefc-9ad31e83ecd2) can be used to send data to the device (e.g. setting of the primary address).

| Manufacturer | Type | Device | Block |
| --- | --- | --- | --- |
| general | Communication with KL6781 |  | [FB\_MBUSKL6781](ms-xhelp:///?Id=beckhoff-2b5d-4be4-b4d2-353673675260) |
| [General](ms-xhelp:///?Id=beckhoff-c2c9-4532-a008-46db7e04da46) | Electricity meter | all electricity meters | [FB\_MBUS\_General\_Electricity](ms-xhelp:///?Id=beckhoff-1136-4a50-98e1-40565d792e03) |
|  | Heat meter | all heat meters | [FB\_MBUS\_General\_Heat](ms-xhelp:///?Id=beckhoff-5419-45e4-a427-0070599355f7) |
|  | Water meter | all water meters | [FB\_MBUS\_General\_Water](ms-xhelp:///?Id=beckhoff-5b79-4998-924b-50a901c4fd9c) |
|  | Raw data of the first telegram | all | [FB\_MBUS\_RawData](ms-xhelp:///?Id=beckhoff-5801-428a-a601-9895f28a88dc) |
|  | max. 40 values from the first telegram | all | [FB\_MBUS\_General](ms-xhelp:///?Id=beckhoff-8e90-4a30-8684-e4959275ff37) |
|  | all telegrams for all values | all | [FB\_MBUS\_General\_Ext](ms-xhelp:///?Id=beckhoff-7616-46e1-8f68-e6176732685e) |
|  | values parameterisable | all | [FB\_MBUS\_General\_Param](ms-xhelp:///?Id=beckhoff-ac86-411d-8af8-85905f72b0e0) |
|  | universal send blocks | all | [FB\_MBUS\_General\_Send](ms-xhelp:///?Id=beckhoff-7b44-4f8f-aefc-9ad31e83ecd2) |
|  | scan block | all | [FB\_MBUS\_Scan](ms-xhelp:///?Id=beckhoff-4bd3-4201-9aa6-b27ead3ce645) |
|  | Change primary address | all | [FB\_MBUS\_ChangeAdr](ms-xhelp:///?Id=beckhoff-e7b9-440c-a46d-f7b90ec2b87b) |
| [ABB](ms-xhelp:///?Id=beckhoff-613d-4813-8c1e-d2f5e07f83e1) | Electricity meter | DELTAplus DZ+ | [FB\_MBUS\_ABB\_DZ](ms-xhelp:///?Id=beckhoff-dd3b-4dd4-a1be-e798658a0b3b) |
| [Actaris](ms-xhelp:///?Id=beckhoff-3074-4aa0-af81-e37b4c703e8b) | Heat meter | CF-Echo II | [FB\_MBUS\_ACW\_CF](ms-xhelp:///?Id=beckhoff-335e-412d-88d7-b6ffb4b897e7) |
|  | Arithmetic unit | CF-51 | [FB\_MBUS\_ACW\_CF](ms-xhelp:///?Id=beckhoff-335e-412d-88d7-b6ffb4b897e7) |
|  | Arithmetic unit | CF-55 | [FB\_MBUS\_ACW\_CF](ms-xhelp:///?Id=beckhoff-335e-412d-88d7-b6ffb4b897e7) |
|  | Water meter | MB +M | [FB\_MBUS\_ACW\_PlusM](ms-xhelp:///?Id=beckhoff-d74e-467d-9e08-956af8f7f85d) |
| [Aquametro](ms-xhelp:///?Id=beckhoff-b3f8-459b-adbf-d96c752c09d5) | Water meter | SAPHIR | [FB\_MBUS\_AMT\_SAPHIR](ms-xhelp:///?Id=beckhoff-3e86-483c-8e6d-37e2e4621399) |
|  | Heat meter | CALEC MB | [FB\_MBUS\_AMT\_CALEC](ms-xhelp:///?Id=beckhoff-e2e7-4e8a-9a75-20e18c73e50b) |
|  | Heat meter | CALEC ST, version C4 | [FB\_MBUS\_AMT\_CALEC\_STC4](ms-xhelp:///?Id=beckhoff-37f7-4d30-9a80-fe80dec37f42) |
|  | Heat meter | AMTRON | [FB\_MBUS\_AMT\_AMTRON](ms-xhelp:///?Id=beckhoff-9422-44d8-a1b5-506cd9afd967) |
|  | Pulse collector | AMBUS | [FB\_MBUS\_AMT\_AMBUS](ms-xhelp:///?Id=beckhoff-4f46-4cdd-be17-2ce57b7fd89a) |
|  | Heat meter | AMTRON SONIC D | [FB\_MBUS\_HYD\_Sharky](ms-xhelp:///?Id=beckhoff-41f9-420e-a041-22cdc21f5bec), [FB\_MBUS\_HYD\_Sharky\_00](ms-xhelp:///?Id=beckhoff-6f7c-4075-9022-42419a9f8748) |
| [Berg](ms-xhelp:///?Id=beckhoff-061f-402f-b1fe-fc0ef2d74ad0) | Electricity meter | DZ+ | [FB\_MBUS\_BEC\_DZ](ms-xhelp:///?Id=beckhoff-63a0-490f-b624-3ab09cac3030) |
|  | Electricity meter | DCMi | [FB\_MBUS\_BEC\_DCMi](ms-xhelp:///?Id=beckhoff-f2f9-4b5c-8f3f-9faa9af59da5) |
| [Brunata](ms-xhelp:///?Id=beckhoff-2c12-4f05-a0c0-b3dfec2828e6) | Heat meter | HGQ / HGS | [FB\_MBUS\_BHG\_HGx](ms-xhelp:///?Id=beckhoff-02e9-4453-8717-da70557ff1e4) |
|  | Heat meter | Optuna H (775) | [FB\_MBUS\_HYD\_Sharky](ms-xhelp:///?Id=beckhoff-41f9-420e-a041-22cdc21f5bec), [FB\_MBUS\_HYD\_Sharky\_00](ms-xhelp:///?Id=beckhoff-6f7c-4075-9022-42419a9f8748) |
| [Carlo Gavazzi](ms-xhelp:///?Id=beckhoff-16f5-435b-8330-e94a549a4b13) | Energy meter | EM24 | [FB\_MBUS\_GAV\_EM24](ms-xhelp:///?Id=beckhoff-937b-4ba0-bed0-1e2876a3f22d) |
| [Cynox](ms-xhelp:///?Id=beckhoff-b2dd-47ed-b4de-6d394d23143d) | Pulse counter | MCount2C | [FB\_MBUS\_CYN\_MCount2C](ms-xhelp:///?Id=beckhoff-9446-47e8-b9e8-f5a7f179b559) |
| [Elster](ms-xhelp:///?Id=beckhoff-f43a-4f57-abf4-e74b40043a90) | Gas meter | Encoder Z6 | [FB\_MBUS\_ELS\_EncoderZ6](ms-xhelp:///?Id=beckhoff-68e0-478a-bb8e-43f1e3b97d56) |
| [elvaco](ms-xhelp:///?Id=beckhoff-2f64-4c4b-a814-dbf5b1f27964) | Temperature and humidity sensors | CMa10 & CMa20 | [FB\_MBUS\_ELV\_CMa10\_20](ms-xhelp:///?Id=beckhoff-49ef-4cfb-bc9f-83ab3aa14224) |
| [EMH](ms-xhelp:///?Id=beckhoff-c43c-4dd2-b3c1-e04ea8136b4e) | Electricity meter | DIZ | [FB\_MBUS\_EMH\_DIZ](ms-xhelp:///?Id=beckhoff-480c-4065-89b1-9f4416f7a8f6) |
|  | Electricity meter | EIZ-E | [FB\_MBUS\_EMH\_EIZE](ms-xhelp:///?Id=beckhoff-e11c-483e-9f47-e7d237d44384) |
|  | Electricity meter | EIZ-G | [FB\_MBUS\_EMH\_EIZG](ms-xhelp:///?Id=beckhoff-30bb-4916-a737-6ef8e7d8ddd7) |
|  | Electricity meter | MIZ | [FB\_MBUS\_EMH\_MIZ](ms-xhelp:///?Id=beckhoff-2992-49a1-a785-be6fe66839ca) |
| [EMU](ms-xhelp:///?Id=beckhoff-f8e9-4283-b71f-0263540fcc8e) | Electricity meter | EMU32x7 | [FB\_MBUS\_EMU\_32x7](ms-xhelp:///?Id=beckhoff-b1b4-475c-842b-7039d5dfce79) |
|  | Electricity meter | EMU32x7 | [FB\_MBUS\_EMU\_32x7\_Option8](ms-xhelp:///?Id=beckhoff-85b7-41a1-a4fe-ae601108687e) |
|  | Electricity meter | Allrounder 3/5 | [FB\_MBUS\_EMU\_3\_5\_Allrounder](ms-xhelp:///?Id=beckhoff-a697-49f4-b0f1-478d42ea76ed) |
|  | Electricity meter | DHZ 5/63 | [FB\_MBUS\_EMU\_DHZ\_5\_63](ms-xhelp:///?Id=beckhoff-6adb-466d-b0cf-3e3a97c5e3b9) |
| [Engelmann](ms-xhelp:///?Id=beckhoff-c6d9-4695-a0de-ef5ef72e81e6) | Heat meter | Sensostar 2C | [FB\_MBUS\_EFF\_SensoStar2C](ms-xhelp:///?Id=beckhoff-821c-4382-a3bd-3f472e219213) |
| [Gossen Metrawatt](ms-xhelp:///?Id=beckhoff-4028-433a-8828-8769d20b7923) | Electricity meter | U128x | [FB\_MBUS\_GMC\_Electricity](ms-xhelp:///?Id=beckhoff-595f-4a0d-9bcb-65573687de13) |
|  | Electricity meter | U138x | [FB\_MBUS\_GMC\_Electricity](ms-xhelp:///?Id=beckhoff-595f-4a0d-9bcb-65573687de13) |
| [GWF](ms-xhelp:///?Id=beckhoff-e4c7-4e6d-874f-d500f525661c) | Water meter |  | [FB\_MBUS\_GWF\_Coder](ms-xhelp:///?Id=beckhoff-4530-49c0-83ac-cdc6de2cb5f3) |
|  | Gas meter | S1 | [FB\_MBUS\_GWF\_Coder](ms-xhelp:///?Id=beckhoff-4530-49c0-83ac-cdc6de2cb5f3) |
|  | Gas meter | Z1 | [FB\_MBUS\_GWF\_Coder](ms-xhelp:///?Id=beckhoff-4530-49c0-83ac-cdc6de2cb5f3) |
| [Hydrometer](ms-xhelp:///?Id=beckhoff-0aa5-4906-8601-9440c083cd4e) | 2 pulse inputs | HYDRO-PORT Pulse | [FB\_MBUS\_HYD\_PortPulse](ms-xhelp:///?Id=beckhoff-e126-46f9-9340-6ccbb370ebd4) |
|  | 2 analog inputs 1 temperature sensor | HYDRO-PORT Analog | [FB\_MBUS\_HYD\_PortAnalog](ms-xhelp:///?Id=beckhoff-f722-4ca0-9bb0-913821693554) |
|  | Water meter | Flypper | [FB\_MBUS\_HYD\_Flypper](ms-xhelp:///?Id=beckhoff-bfac-4a2d-bf3a-e7b9dedf9504) |
|  | Heat meter | Sharky 773 | [FB\_MBUS\_HYD\_Sharky](ms-xhelp:///?Id=beckhoff-41f9-420e-a041-22cdc21f5bec), [FB\_MBUS\_HYD\_Sharky\_00](ms-xhelp:///?Id=beckhoff-6f7c-4075-9022-42419a9f8748) |
|  | Heat meter | Sharky 775 | [FB\_MBUS\_HYD\_Sharky](ms-xhelp:///?Id=beckhoff-41f9-420e-a041-22cdc21f5bec), [FB\_MBUS\_HYD\_Sharky\_00](ms-xhelp:///?Id=beckhoff-6f7c-4075-9022-42419a9f8748) |
| [ista](ms-xhelp:///?Id=beckhoff-8c70-4118-9833-9b1eb952d445) | Water meter | domaqua® m | [FB\_MBUS\_IST\_Istameter](ms-xhelp:///?Id=beckhoff-9454-48bb-b21b-0e0db31b8b46) |
|  | Water meter | istameter® m | [FB\_MBUS\_IST\_Istameter](ms-xhelp:///?Id=beckhoff-9454-48bb-b21b-0e0db31b8b46) |
|  | Water meter | istameter III | [FB\_MBUS\_IST\_IstameterIII](ms-xhelp:///?Id=beckhoff-405b-4eb5-9b09-fb932d5b9e59) |
|  | Pulse counter | pulsonic II | [FB\_MBUS\_IST\_PulsonicII](ms-xhelp:///?Id=beckhoff-35dd-4c42-816e-069c5ab7761d) |
|  | Heat meter | sensonic II | [FB\_MBUS\_IST\_SensonicII](ms-xhelp:///?Id=beckhoff-9c76-423c-9916-2405488e4740) |
| [Itron](ms-xhelp:///?Id=beckhoff-a8a7-4189-92e9-604d90f2a606) | Energy meter | Integral-V-UltraLite | [FB\_MBUS\_ITR\_IntegralVUltraLite](ms-xhelp:///?Id=beckhoff-e0c2-4cae-9b3f-4c58e0c6328a) |
| [Janitza](ms-xhelp:///?Id=beckhoff-dd49-4d17-b510-439c4a4a1348) | Electricity meter | UMG96S | [FB\_MBUS\_JAN\_UMG96S](ms-xhelp:///?Id=beckhoff-1e7d-4931-88e7-978d37871295) |
| [Kamstrup](ms-xhelp:///?Id=beckhoff-541d-4873-b8ce-0ad6f405f356) | Electricity meter | Kamstrup 162 | [FB\_MBUS\_KAM\_KamstrupE](ms-xhelp:///?Id=beckhoff-ed32-4e51-9c19-078eb6d518c0) |
|  | Electricity meter | Kamstrup 351 | [FB\_MBUS\_KAM\_KamstrupE](ms-xhelp:///?Id=beckhoff-ed32-4e51-9c19-078eb6d518c0) |
|  | Electricity meter | Kamstrup 382 | [FB\_MBUS\_KAM\_KamstrupE](ms-xhelp:///?Id=beckhoff-ed32-4e51-9c19-078eb6d518c0) |
|  | Heat/cold meter | Maxical III | [FB\_MBUS\_KAM\_Maxical\_III](ms-xhelp:///?Id=beckhoff-d328-4949-9bb0-2131a051ca16) |
|  | Heat/cold meter | Multical 401 | [FB\_MBUS\_KAM\_Multical](ms-xhelp:///?Id=beckhoff-ec6b-4962-b67a-d03a89122cc8) |
|  | Heat/cold meter | Multical 402 | [FB\_MBUS\_KAM\_Multical402](ms-xhelp:///?Id=beckhoff-7d90-4d77-8754-b50f5b7e6076) |
|  | Water meter | Multical 41 | [FB\_MBUS\_KAM\_Multical41](ms-xhelp:///?Id=beckhoff-1b93-43b6-aa33-db51e425e423) |
|  | Heat/cold meter | Multical 601 | [FB\_MBUS\_KAM\_Multical601](ms-xhelp:///?Id=beckhoff-b04d-4736-ad0a-1d0bc1f3bdf6) |
| [KUNDO](ms-xhelp:///?Id=beckhoff-c22d-4d4f-88be-c0d94a0c90f7) | Heat/cold meter | Compact WMZ G20 | [FB\_MBUS\_KST\_G20](ms-xhelp:///?Id=beckhoff-a3b7-443a-be32-a05a489446af) |
|  | Heat/cold meter | Compact WMZ G21 | [FB\_MBUS\_KST\_G20](ms-xhelp:///?Id=beckhoff-a3b7-443a-be32-a05a489446af) |
|  | External M-Bus module | him1s | [FB\_MBUS\_KST\_him1](ms-xhelp:///?Id=beckhoff-689e-483b-bfcd-e2a5aa917b38) |
|  | External M-Bus module | him1plus | [FB\_MBUS\_KST\_him1](ms-xhelp:///?Id=beckhoff-689e-483b-bfcd-e2a5aa917b38) |
|  | Pulse input | him1plus | [FB\_MBUS\_KST\_him1Puls](ms-xhelp:///?Id=beckhoff-a127-448e-a774-28e168dfd8da) |
| [Landis & Gyr](ms-xhelp:///?Id=beckhoff-ce85-4820-933e-ddfda4dc837e) | Heat/cold meter | ULTRAHEAT 2WR5 | [FB\_MBUS\_LUG\_Heat](ms-xhelp:///?Id=beckhoff-fe8d-4da3-8a4d-e26c51422457) |
|  | Heat/cold meter | ULTRAHEAT 2WR6 | [FB\_MBUS\_LUG\_Heat](ms-xhelp:///?Id=beckhoff-fe8d-4da3-8a4d-e26c51422457) |
|  | Heat/cold meter | ULTRAHEAT UH50 | [FB\_MBUS\_LUG\_Heat](ms-xhelp:///?Id=beckhoff-fe8d-4da3-8a4d-e26c51422457) |
| [Metrima](ms-xhelp:///?Id=beckhoff-b928-4a6c-9837-f13eecbafd48) | Heat meter | F22 (standard values) | [FB\_MBUS\_SVM\_F22](ms-xhelp:///?Id=beckhoff-44a3-48d4-821a-f0fc976a1b24) |
|  | Heat meter | F22 (with additional output values) | [FB\_MBUS\_SVM\_F22\_Ext](ms-xhelp:///?Id=beckhoff-a18a-43b3-9142-e75458d25943) |
| [NZR](ms-xhelp:///?Id=beckhoff-8160-4580-8247-be99e9101f32) | Pulse memory module | IC-M2 | [FB\_MBUS\_NZR\_ICM2](ms-xhelp:///?Id=beckhoff-be44-44f2-9e6f-61ac45941829) |
|  | Pulse memory module | IC-M2C | [FB\_MBUS\_NZR\_ICM2](ms-xhelp:///?Id=beckhoff-be44-44f2-9e6f-61ac45941829) |
|  | Water meter | Modularis 2 | [FB\_MBUS\_NZR\_Modularis2](ms-xhelp:///?Id=beckhoff-2f19-4cb7-82f0-a417be7353e1) |
| [OPTEC](ms-xhelp:///?Id=beckhoff-2787-4ebf-a708-37851232029f) | Electricity meter | ECS Type 2 | [FB\_MBUS\_OPT\_ECSType2](ms-xhelp:///?Id=beckhoff-dd85-4721-b915-dda75c32350e) |
| [Relay](ms-xhelp:///?Id=beckhoff-1803-4536-98ec-cae1ed7656a5) | 1-4 analog inputs | AnDi 1-4 | [FB\_MBUS\_REL\_AnDi](ms-xhelp:///?Id=beckhoff-b0a9-485a-b852-0e80b03a00c0) |
|  | 4 digital inputs | PadIn 4 | [FB\_MBUS\_REL\_PadIn4](ms-xhelp:///?Id=beckhoff-8ecb-427d-a02b-f593c8a75091) |
|  | 1-way pulse adapter | PadPuls M1 | [FB\_MBUS\_REL\_PadPulsM1](ms-xhelp:///?Id=beckhoff-4c58-47d3-b905-ba9c34fc3b50) |
|  | 1-way pulse adapter | PadPuls M1C | [FB\_MBUS\_REL\_PadPulsM1](ms-xhelp:///?Id=beckhoff-4c58-47d3-b905-ba9c34fc3b50) |
|  | 2-way pulse adapter | PadPuls M2 | [FB\_MBUS\_REL\_PadPulsM2](ms-xhelp:///?Id=beckhoff-fa6f-45a4-a6cb-3a23dafaf118) |
|  | 2-way pulse adapter | PadPuls M2C | [FB\_MBUS\_REL\_PadPulsM2](ms-xhelp:///?Id=beckhoff-fa6f-45a4-a6cb-3a23dafaf118) |
|  | 4-way pulse adapter | PadPuls M4 | [FB\_MBUS\_REL\_PadPulsM4](ms-xhelp:///?Id=beckhoff-2de0-4375-b290-96ce3350325b) |
|  | 4-way pulse adapter | PadPuls M4L | [FB\_MBUS\_REL\_PadPulsM4](ms-xhelp:///?Id=beckhoff-2de0-4375-b290-96ce3350325b) |
| [Saia-Burgess](ms-xhelp:///?Id=beckhoff-5bf8-44e5-aa97-69576f1b55d5) | Electricity meter | ALD1 | [FB\_MBUS\_SBC\_ALD1](ms-xhelp:///?Id=beckhoff-04fe-49a1-9f60-690290ec15d7) |
|  | Electricity meter | ALE3 | [FB\_MBUS\_SBC\_ALE3](ms-xhelp:///?Id=beckhoff-7788-4744-b524-63c9ac41adb6) |
|  | Electricity meter | AWD3 | [FB\_MBUS\_SBC\_ALE3](ms-xhelp:///?Id=beckhoff-7788-4744-b524-63c9ac41adb6) |
| [Schlumberger](ms-xhelp:///?Id=beckhoff-b2e0-4198-97f4-cae69dd52071) | Heat meter | Integral-Mk MaXX | [FB\_MBUS\_SLB\_MK\_MaXX](ms-xhelp:///?Id=beckhoff-faa3-4d1a-9352-553520a5691e) |
|  | Heat meter | CF Echo I | [FB\_MBUS\_SLB\_CFEchoI](ms-xhelp:///?Id=beckhoff-77f4-4eda-9334-489623283c85) |
| [Schneider Electric](ms-xhelp:///?Id=beckhoff-bc65-431f-a2ea-4ef56add593c) | Electricity meter | iEM3135 | [FB\_MBUS\_SEC\_iEM3135](ms-xhelp:///?Id=beckhoff-58fe-47f0-bf0c-7dbc87709fb2) |
| [Sensus](ms-xhelp:///?Id=beckhoff-c233-481f-98eb-d64a8789299a) | Heat/cold meter | PolluStat E | [FB\_MBUS\_SEN\_Pollu](ms-xhelp:///?Id=beckhoff-ab89-4739-bc2e-e81717d38257) |
|  | Heat/cold meter | PolluTherm | [FB\_MBUS\_SEN\_Pollu](ms-xhelp:///?Id=beckhoff-ab89-4739-bc2e-e81717d38257) |
|  | Heat/cold meter | PolluCom E | [FB\_MBUS\_SEN\_Pollu](ms-xhelp:///?Id=beckhoff-ab89-4739-bc2e-e81717d38257) |
|  | Water meter |  | [FB\_MBUS\_SEN\_Water](ms-xhelp:///?Id=beckhoff-270b-4910-ae2a-1c176f4a00dd) |
| [Sontex](ms-xhelp:///?Id=beckhoff-b7b0-4c16-aed1-a4d3aa84e921) | Heat/cold meter | Supercal 531 | [FB\_MBUS\_SON\_Supercal531](ms-xhelp:///?Id=beckhoff-84d4-4a85-9c6b-a801530e9198) |
| [TIP](ms-xhelp:///?Id=beckhoff-a2a5-44a1-a89d-f21ae2dda7df) | Electricity meter | SINUS 85 M | [FB\_MBUS\_TIP\_SINUS85M](ms-xhelp:///?Id=beckhoff-38b7-461e-a166-ef2196a6c785) |
| [Zenner](ms-xhelp:///?Id=beckhoff-ab5e-4e7e-b746-988a4578b8b8) | Arithmetic unit | multidataWR3 | [FB\_MBUS\_ZRM\_multidataWR3](ms-xhelp:///?Id=beckhoff-b28f-4439-bd08-dcc86cbce28b) |
|  | Heat meter | zelsiusZR | [FB\_MBUS\_ZRM\_zelsiusZR](ms-xhelp:///?Id=beckhoff-638a-4471-9944-944cd40686c5) |

Further Information

* [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
* [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
* [GLVs](ms-xhelp:///?Id=beckhoff-453b-401b-8790-5f0f931ea1d1)
* [Integration into TwinCAT](ms-xhelp:///?Id=beckhoff-f08d-4d7c-9af4-20f338f2bfa5)

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
