# Special commands

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-2528-40a8-b5c9-22865af95d5d)
6. Special commands

# Special commands

## Function blocks

| Name | Description |
| --- | --- |
| [FB\_DALIV2Compare](ms-xhelp:///?Id=beckhoff-b25f-4302-9ef8-a8e6d24a4ea5) | The control gear compares its [RANDOM ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) with the [SEARCH ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| [FB\_DALIV2Initialise](ms-xhelp:///?Id=beckhoff-0a0e-4a05-a0b9-db633ae208a4) | Starts the addressing of the control gears. |
| [FB\_DALIV2PhysicalSelection](ms-xhelp:///?Id=beckhoff-dfc6-4596-9764-6153ca2a7110) | Any control gear that receives this command enters the *physical selection* mode. |
| [FB\_DALIV2ProgramShortAddress](ms-xhelp:///?Id=beckhoff-1714-4de0-a674-d032ef1793e8) | All the selected control gears save the *nShortAddress* ([SHORT ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)) value as their short address. |
| [FB\_DALIV2QueryShortAddress](ms-xhelp:///?Id=beckhoff-275b-49a0-b619-69da6feafe08) | If the [RANDOM ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) is the same as the [SEARCH ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) then the control gear sends its short address. |
| [FB\_DALIV2Randomise](ms-xhelp:///?Id=beckhoff-a006-408c-a86d-aee6e560d647) | The control gears generate a new [RANDOM ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| [FB\_DALIV2SearchAddr](ms-xhelp:///?Id=beckhoff-afcc-4c03-9a17-8477e5adb455) | This function block sets the [SEARCH ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| [FB\_DALIV2SearchAddrH](ms-xhelp:///?Id=beckhoff-843d-44ef-ace4-19706b4fb4af) | This function block sets the upper 8 bits of the 24-bit [SEARCH ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| [FB\_DALIV2SearchAddrL](ms-xhelp:///?Id=beckhoff-8397-44b5-ac9b-6d4b25875ab0) | This function block sets the lower 8 bits of the 24-bit [SEARCH ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| [FB\_DALIV2SearchAddrM](ms-xhelp:///?Id=beckhoff-de95-421e-8bff-89d71774d506) | This function block sets the middle 8 bits of the 24-bit [SEARCH ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| [FB\_DALIV2SetDTR0](ms-xhelp:///?Id=beckhoff-8788-45a6-b023-8c1828f86864) | Writes an 8-bit value into the DTR0 of all the control gears. |
| [FB\_DALIV2SetDTR1](ms-xhelp:///?Id=beckhoff-6c6f-4c9f-b4ed-26b96ba57442) | Writes an 8 bit value into the DTR1 of all the control gears. |
| [FB\_DALIV2SetDTR2](ms-xhelp:///?Id=beckhoff-1999-42f3-b0ee-1691ba343675) | Writes an 8-bit value into the DTR2 of all the control gears. |
| [FB\_DALIV2Terminate](ms-xhelp:///?Id=beckhoff-294f-4f50-b7d8-4e71ae8254f5) | The addressing of all the control gears is halted. |
| [FB\_DALIV2VerifyShortAddress](ms-xhelp:///?Id=beckhoff-29d7-448e-b1b1-6f25a756c22c) | If the short address in the control gear is equal to the *nShortAddress* parameter, TRUE is asserted at the *bAnswer* output. |
| [FB\_DALIV2Withdraw](ms-xhelp:///?Id=beckhoff-1156-4777-b235-bd7e3809a06d) | Control gears in which the [RANDOM ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) is the same as the [SEARCH ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) must no longer react to the [FB\_DALIV2Compare()](ms-xhelp:///?Id=beckhoff-b25f-4302-9ef8-a8e6d24a4ea5) command. |
| [FB\_DALIV2WriteMemoryLocation](ms-xhelp:///?Id=beckhoff-7716-459e-bc99-ef41a27500c2) | Writes an 8-bit value into the memory of a control gear. Access to the memory must first be enabled with the [FB\_DALIV2EnableWriteMemory()](ms-xhelp:///?Id=beckhoff-dab5-475a-9eec-bd17ac110f5f) command. |

Further Information

* [FB\_DALIV2Compare](ms-xhelp:///?Id=beckhoff-b25f-4302-9ef8-a8e6d24a4ea5)
* [FB\_DALIV2Initialise](ms-xhelp:///?Id=beckhoff-0a0e-4a05-a0b9-db633ae208a4)
* [FB\_DALIV2PhysicalSelection](ms-xhelp:///?Id=beckhoff-dfc6-4596-9764-6153ca2a7110)
* [FB\_DALIV2ProgramShortAddress](ms-xhelp:///?Id=beckhoff-1714-4de0-a674-d032ef1793e8)
* [FB\_DALIV2QueryShortAddress](ms-xhelp:///?Id=beckhoff-275b-49a0-b619-69da6feafe08)
* [FB\_DALIV2Randomise](ms-xhelp:///?Id=beckhoff-a006-408c-a86d-aee6e560d647)
* [FB\_DALIV2SearchAddr](ms-xhelp:///?Id=beckhoff-afcc-4c03-9a17-8477e5adb455)
* [FB\_DALIV2SearchAddrH](ms-xhelp:///?Id=beckhoff-843d-44ef-ace4-19706b4fb4af)
* [FB\_DALIV2SearchAddrL](ms-xhelp:///?Id=beckhoff-8397-44b5-ac9b-6d4b25875ab0)
* [FB\_DALIV2SearchAddrM](ms-xhelp:///?Id=beckhoff-de95-421e-8bff-89d71774d506)
* [FB\_DALIV2SetDTR0](ms-xhelp:///?Id=beckhoff-8788-45a6-b023-8c1828f86864)
* [FB\_DALIV2SetDTR1](ms-xhelp:///?Id=beckhoff-6c6f-4c9f-b4ed-26b96ba57442)
* [FB\_DALIV2SetDTR2](ms-xhelp:///?Id=beckhoff-1999-42f3-b0ee-1691ba343675)
* [FB\_DALIV2Terminate](ms-xhelp:///?Id=beckhoff-294f-4f50-b7d8-4e71ae8254f5)
* [FB\_DALIV2VerifyShortAddress](ms-xhelp:///?Id=beckhoff-29d7-448e-b1b1-6f25a756c22c)
* [FB\_DALIV2Withdraw](ms-xhelp:///?Id=beckhoff-1156-4777-b235-bd7e3809a06d)
* [FB\_DALIV2WriteMemoryLocation](ms-xhelp:///?Id=beckhoff-7716-459e-bc99-ef41a27500c2)

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
