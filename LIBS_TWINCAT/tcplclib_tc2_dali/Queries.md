# Queries

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-2528-40a8-b5c9-22865af95d5d)
6. Queries

# Queries

## Function blocks

| Name | Description |
| --- | --- |
| [FB\_DALIV2QueryActualLevel](ms-xhelp:///?Id=beckhoff-8756-44bc-884e-1c8eb070aeb6) | Read the [ACTUAL DIM LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable (current lamp power). |
| [FB\_DALIV2QueryContentDTR0](ms-xhelp:///?Id=beckhoff-3a69-46e8-9ea5-047cfa9d2ce4) | Read out the DTR0 (Data Transfer Register 0). |
| [FB\_DALIV2QueryContentDTR1](ms-xhelp:///?Id=beckhoff-7799-4895-b734-7a9fe62d3374) | Read out the DTR1 (Data Transfer Register 1). |
| [FB\_DALIV2QueryContentDTR2](ms-xhelp:///?Id=beckhoff-1e23-48b8-a884-fbd14199aedf) | Read out the DTR2 (Data Transfer Register 2). |
| [FB\_DALIV2QueryControlGearPresent](ms-xhelp:///?Id=beckhoff-ea28-4338-891e-c4d7a45e5324) | Query whether the control gear is ready to operate. |
| [FB\_DALIV2QueryDeviceType](ms-xhelp:///?Id=beckhoff-b5d7-4a6d-88ac-a6bd90ed9aa8) | Query the device type. |
| [FB\_DALIV2QueryFadeTimeFadeRate](ms-xhelp:///?Id=beckhoff-06c2-4588-95cc-55c9b335e4ec) | Read out the variables [FADE RATE](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) and [FADE TIME](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| [FB\_DALIV2QueryGroups](ms-xhelp:///?Id=beckhoff-3954-407a-9a97-ccd570f85b21) | Query the group membership. |
| [FB\_DALIV2QueryGroups0UpTo7](ms-xhelp:///?Id=beckhoff-3472-411a-8fa9-35081c58b934) | Query the group membership (groups 0 to 7). |
| [FB\_DALIV2QueryGroups8UpTo15](ms-xhelp:///?Id=beckhoff-0408-4bcf-b9eb-f861ac4edf2f) | Query the group membership (groups 8 to 15). |
| [FB\_DALIV2QueryLampFailure](ms-xhelp:///?Id=beckhoff-72f5-487a-95c2-003a840c5de3) | Query whether a lamp has failed. |
| [FB\_DALIV2QueryLampPowerOn](ms-xhelp:///?Id=beckhoff-ea26-4721-99f5-1c024d08fe26) | Query as to whether the lamp is switched on. |
| [FB\_DALIV2QueryLimitError](ms-xhelp:///?Id=beckhoff-b26a-40b3-ac3c-56fb16222ebd) | Query whether the last lamp power value could be used or not. |
| [FB\_DALIV2QueryMaxLevel](ms-xhelp:///?Id=beckhoff-c32a-481a-80ef-ae3fbaa42016) | Read the [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable (maximum permitted lamp power). |
| [FB\_DALIV2QueryMinLevel](ms-xhelp:///?Id=beckhoff-361e-4c15-a98e-9e6709b8db7e) | Read the [MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable (minimum permitted lamp power). |
| [FB\_DALIV2QueryMissingShortAddress](ms-xhelp:///?Id=beckhoff-eabc-433e-9204-6fecfb3d708a) | Query as to whether the control gear does not have a short address. |
| [FB\_DALIV2QueryPhysicalMinLevel](ms-xhelp:///?Id=beckhoff-e676-4395-a78d-b6dff54166d8) | Read the [PHYSICAL MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable (lowest lamp power that is physically possible). |
| [FB\_DALIV2QueryPowerFailure](ms-xhelp:///?Id=beckhoff-b7f5-426a-80f6-bf11cd4a48ae) | Query whether the control gear has received a reset or a lamp power control command since it was switched on or not. |
| [FB\_DALIV2QueryPowerOnLevel](ms-xhelp:///?Id=beckhoff-0ba4-4295-8760-d7f8abe6294a) | Read the [POWER ON LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable (initial lamp power when switched on). |
| [FB\_DALIV2QueryRandomAddress](ms-xhelp:///?Id=beckhoff-8cab-4a48-848b-3620d9f7bc0a) | Read the [RANDOM ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable (direct address/long address). |
| [FB\_DALIV2QueryRandomAddressH](ms-xhelp:///?Id=beckhoff-4bdf-416c-b3cf-54053dabd0d6) | Read the high byte of the variable [RANDOM ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) (direct address/long address). |
| [FB\_DALIV2QueryRandomAddressL](ms-xhelp:///?Id=beckhoff-8d4b-4275-b0be-2a5c0eb70ab8) | Read the low byte of the variable [RANDOM ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) (direct address/long address). |
| [FB\_DALIV2QueryRandomAddressM](ms-xhelp:///?Id=beckhoff-f5e1-4280-ad68-2bb4c4c0786f) | Read the middle byte of the variable [RANDOM ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) (direct address/long address). |
| [FB\_DALIV2QueryResetState](ms-xhelp:///?Id=beckhoff-f553-41ce-9160-49447e11bf9b) | Query whether the control gear is in the reset state. |
| [FB\_DALIV2QuerySceneLevel](ms-xhelp:///?Id=beckhoff-838b-46ad-9137-d6a995db9b7c) | Query the lamp power value of a scene. |
| [FB\_DALIV2QueryStatus](ms-xhelp:///?Id=beckhoff-2842-43f6-bb00-117b66c1d25d) | Read the [STATUS INFORMATION](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable. |
| [FB\_DALIV2QuerySystemFailureLevel](ms-xhelp:///?Id=beckhoff-f135-4a22-8485-7d56a6603834) | Read the [SYSTEM FAILURE LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable (the power value for the lamp in the presence of a system error). |
| [FB\_DALIV2QueryVersionNumber](ms-xhelp:///?Id=beckhoff-0f5b-4bc0-bcf1-bab3ceb63e37) | Read the [VERSION NUMBER](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) variable. |
| [FB\_DALIV2ReadMemoryLocation](ms-xhelp:///?Id=beckhoff-c3f7-413c-816a-b4c80d1bacc2) | Reading an 8-bit value from the control gear memory. |

Further Information

* [FB\_DALIV2QueryActualLevel](ms-xhelp:///?Id=beckhoff-8756-44bc-884e-1c8eb070aeb6)
* [FB\_DALIV2QueryContentDTR0](ms-xhelp:///?Id=beckhoff-3a69-46e8-9ea5-047cfa9d2ce4)
* [FB\_DALIV2QueryContentDTR1](ms-xhelp:///?Id=beckhoff-7799-4895-b734-7a9fe62d3374)
* [FB\_DALIV2QueryContentDTR2](ms-xhelp:///?Id=beckhoff-1e23-48b8-a884-fbd14199aedf)
* [FB\_DALIV2QueryControlGearPresent](ms-xhelp:///?Id=beckhoff-ea28-4338-891e-c4d7a45e5324)
* [FB\_DALIV2QueryDeviceType](ms-xhelp:///?Id=beckhoff-b5d7-4a6d-88ac-a6bd90ed9aa8)
* [FB\_DALIV2QueryFadeTimeFadeRate](ms-xhelp:///?Id=beckhoff-06c2-4588-95cc-55c9b335e4ec)
* [FB\_DALIV2QueryGroups](ms-xhelp:///?Id=beckhoff-3954-407a-9a97-ccd570f85b21)
* [FB\_DALIV2QueryGroups0UpTo7](ms-xhelp:///?Id=beckhoff-3472-411a-8fa9-35081c58b934)
* [FB\_DALIV2QueryGroups8UpTo15](ms-xhelp:///?Id=beckhoff-0408-4bcf-b9eb-f861ac4edf2f)
* [FB\_DALIV2QueryLampFailure](ms-xhelp:///?Id=beckhoff-72f5-487a-95c2-003a840c5de3)
* [FB\_DALIV2QueryLampPowerOn](ms-xhelp:///?Id=beckhoff-ea26-4721-99f5-1c024d08fe26)
* [FB\_DALIV2QueryLimitError](ms-xhelp:///?Id=beckhoff-b26a-40b3-ac3c-56fb16222ebd)
* [FB\_DALIV2QueryMaxLevel](ms-xhelp:///?Id=beckhoff-c32a-481a-80ef-ae3fbaa42016)
* [FB\_DALIV2QueryMinLevel](ms-xhelp:///?Id=beckhoff-361e-4c15-a98e-9e6709b8db7e)
* [FB\_DALIV2QueryMissingShortAddress](ms-xhelp:///?Id=beckhoff-eabc-433e-9204-6fecfb3d708a)
* [FB\_DALIV2QueryPhysicalMinLevel](ms-xhelp:///?Id=beckhoff-e676-4395-a78d-b6dff54166d8)
* [FB\_DALIV2QueryPowerFailure](ms-xhelp:///?Id=beckhoff-b7f5-426a-80f6-bf11cd4a48ae)
* [FB\_DALIV2QueryPowerOnLevel](ms-xhelp:///?Id=beckhoff-0ba4-4295-8760-d7f8abe6294a)
* [FB\_DALIV2QueryRandomAddress](ms-xhelp:///?Id=beckhoff-8cab-4a48-848b-3620d9f7bc0a)
* [FB\_DALIV2QueryRandomAddressH](ms-xhelp:///?Id=beckhoff-4bdf-416c-b3cf-54053dabd0d6)
* [FB\_DALIV2QueryRandomAddressL](ms-xhelp:///?Id=beckhoff-8d4b-4275-b0be-2a5c0eb70ab8)
* [FB\_DALIV2QueryRandomAddressM](ms-xhelp:///?Id=beckhoff-f5e1-4280-ad68-2bb4c4c0786f)
* [FB\_DALIV2QueryResetState](ms-xhelp:///?Id=beckhoff-f553-41ce-9160-49447e11bf9b)
* [FB\_DALIV2QuerySceneLevel](ms-xhelp:///?Id=beckhoff-838b-46ad-9137-d6a995db9b7c)
* [FB\_DALIV2QueryStatus](ms-xhelp:///?Id=beckhoff-2842-43f6-bb00-117b66c1d25d)
* [FB\_DALIV2QuerySystemFailureLevel](ms-xhelp:///?Id=beckhoff-f135-4a22-8485-7d56a6603834)
* [FB\_DALIV2QueryVersionNumber](ms-xhelp:///?Id=beckhoff-0f5b-4bc0-bcf1-bab3ceb63e37)
* [FB\_DALIV2ReadMemoryLocation](ms-xhelp:///?Id=beckhoff-c3f7-413c-816a-b4c80d1bacc2)

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
