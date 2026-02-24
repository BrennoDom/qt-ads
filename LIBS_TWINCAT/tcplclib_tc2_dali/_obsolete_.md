# [obsolete]

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [obsolete]

# [obsolete]

## Function blocks

| Name | Description |
| --- | --- |
| [FB\_DALIV2Communication](ms-xhelp:///?Id=beckhoff-d5b3-457e-91f9-d1f3e8f70687) | Reads the DALI commands from the buffers sequentially and relays them to the KL6811. |
| [FB\_DALIV2EnableWriteMemory](ms-xhelp:///?Id=beckhoff-dab5-475a-9eec-bd17ac110f5f) | Enables write access via [FB\_DALIV2WriteMemoryLocation()](ms-xhelp:///?Id=beckhoff-7716-459e-bc99-ef41a27500c2) to the internal memory of the control gear. |
| [FB\_DALIV2QueryBallast](ms-xhelp:///?Id=beckhoff-b860-4d4b-9079-9226916ae620) | Query whether the control gear is ready to operate. |
| [FB\_DALIV2QueryContentDTR](ms-xhelp:///?Id=beckhoff-8c16-4159-9c68-40f0bc169c44) | Read out the DTR (Data Transfer Register). |
| [FB\_DALIV2SendDALICommand](ms-xhelp:///?Id=beckhoff-8c67-439e-a8bb-1a1e14531539) | This function block is for the general sending of a DALI command, defined by command number and, if necessary, transfer parameter. |
| [FB\_DALIV2SetDTR](ms-xhelp:///?Id=beckhoff-c545-4587-bc68-e0f5c5db7a1f) | Writes an 8-bit value into the DTR of all the control gears. |
| [FB\_DALIV2StoreActualLevelInDTR](ms-xhelp:///?Id=beckhoff-60dc-4aca-977d-7448d24f5e35) | Writes the current value of the lamp power into the DTR. |
| [FB\_DALIV2StoreDTRAsFadeRate](ms-xhelp:///?Id=beckhoff-daa7-4a6b-9035-0e30a58059a0) | Writes the value in the DTR into the [FADE RATE](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable. |
| [FB\_DALIV2StoreDTRAsFadeTime](ms-xhelp:///?Id=beckhoff-c6f5-4abb-b150-582d34cf97da) | Writes the value in the DTR into the [FADE TIME](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable. |
| [FB\_DALIV2StoreDTRAsMaxLevel](ms-xhelp:///?Id=beckhoff-6c48-4ec6-a1a9-dd9d1c0f5050) | Writes the value in the DTR into the [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable. |
| [FB\_DALIV2StoreDTRAsMinLevel](ms-xhelp:///?Id=beckhoff-9a1b-4ba6-83d4-b868d5cc630f) | Writes the value in the DTR into the [MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable. |
| [FB\_DALIV2StoreDTRAsPowerOnLevel](ms-xhelp:///?Id=beckhoff-f0ce-4d8d-9590-c6de7e38635f) | Writes the value in the DTR into the [POWER ON LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable. |
| [FB\_DALIV2StoreDTRAsScene](ms-xhelp:///?Id=beckhoff-d268-4eb3-afb5-97a5326202ff) | Saves the contents of the DTR as the lamp power value for a scene. |
| [FB\_DALIV2StoreDTRAsShortAddress](ms-xhelp:///?Id=beckhoff-8111-45f4-b14f-7a875b90bedb) | Saves the contents of the DTR as a short address, or deletes the short address. |
| [FB\_DALIV2StoreDTRAsSystemFailureLevel](ms-xhelp:///?Id=beckhoff-0f7e-4ab6-931c-1a78b2159cd5) | Writes the value in the DTR into the [SYSTEM FAILURE LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable. |
| [FB\_KL6811Config](ms-xhelp:///?Id=beckhoff-3fe1-4e92-9974-9a72dff30864) | This function block can be used to configure the KL6821. |

Further Information

* [FB\_DALIV2Communication](ms-xhelp:///?Id=beckhoff-d5b3-457e-91f9-d1f3e8f70687)
* [FB\_DALIV2EnableWriteMemory](ms-xhelp:///?Id=beckhoff-dab5-475a-9eec-bd17ac110f5f)
* [FB\_DALIV2QueryBallast](ms-xhelp:///?Id=beckhoff-b860-4d4b-9079-9226916ae620)
* [FB\_DALIV2QueryContentDTR](ms-xhelp:///?Id=beckhoff-8c16-4159-9c68-40f0bc169c44)
* [FB\_DALIV2SendDALICommand](ms-xhelp:///?Id=beckhoff-8c67-439e-a8bb-1a1e14531539)
* [FB\_DALIV2SetDTR](ms-xhelp:///?Id=beckhoff-c545-4587-bc68-e0f5c5db7a1f)
* [FB\_DALIV2StoreActualLevelInDTR](ms-xhelp:///?Id=beckhoff-60dc-4aca-977d-7448d24f5e35)
* [FB\_DALIV2StoreDTRAsFadeRate](ms-xhelp:///?Id=beckhoff-daa7-4a6b-9035-0e30a58059a0)
* [FB\_DALIV2StoreDTRAsFadeTime](ms-xhelp:///?Id=beckhoff-c6f5-4abb-b150-582d34cf97da)
* [FB\_DALIV2StoreDTRAsMaxLevel](ms-xhelp:///?Id=beckhoff-6c48-4ec6-a1a9-dd9d1c0f5050)
* [FB\_DALIV2StoreDTRAsMinLevel](ms-xhelp:///?Id=beckhoff-9a1b-4ba6-83d4-b868d5cc630f)
* [FB\_DALIV2StoreDTRAsPowerOnLevel](ms-xhelp:///?Id=beckhoff-f0ce-4d8d-9590-c6de7e38635f)
* [FB\_DALIV2StoreDTRAsScene](ms-xhelp:///?Id=beckhoff-d268-4eb3-afb5-97a5326202ff)
* [FB\_DALIV2StoreDTRAsShortAddress](ms-xhelp:///?Id=beckhoff-8111-45f4-b14f-7a875b90bedb)
* [FB\_DALIV2StoreDTRAsSystemFailureLevel](ms-xhelp:///?Id=beckhoff-0f7e-4ab6-931c-1a78b2159cd5)
* [FB\_KL6811Config](ms-xhelp:///?Id=beckhoff-3fe1-4e92-9974-9a72dff30864)

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
