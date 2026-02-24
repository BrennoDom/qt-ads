# Variables

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Part 202 (emergency lighting)](ms-xhelp:///?Id=beckhoff-d13a-4887-aecd-3e1c1e84a57b)
6. Variables

# Variables

Each DALI emergency lighting supply unit has a certain number of variables (parameters) from which different information is read, or through which individual parameters can be modified.

| Name | Default value | Reset value | Valid range | Size | Comment |
| --- | --- | --- | --- | --- | --- |
| [EMERGENCY LEVEL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | EMERGENCY MAX LEVEL | No change | EMERGENCY MIN LEVEL ... EMERGENCY MAX LEVEL or MASK | 1 byte |  |
| [EMERGENCY MIN LEVEL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | Manufacturer-dependent | No change | 1 ... EMERGENCY MAX LEVEL or MASK | 1 byte | read only |
| [EMERGENCY MAX LEVEL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | Manufacturer-dependent | No change | EMERGENCY MIN LEVEL ... 254 or MASK | 1 byte | read only |
| [PROLONG TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | 4 | No change | 0 ... 255 | 1 byte |  |
| [TEST DELAY TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | 0 | 0 | 00 00 ... FF FF | 2 bytes |  |
| [FUNCTION TEST DELAY TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | 0 | No change | 00 00 ... FF FF | 2 bytes |  |
| [DURATION TEST DELAY TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | 0 | No change | 00 00 ... FF FF | 2 bytes |  |
| [FUNCTION TEST INTERVAL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | 7 | No change | 0, 1 ... 255 | 1 byte |  |
| [DURATION TEST INTERVAL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | 13 | No change | 0, 1 ... 97 | 1 byte |  |
| [TEST EXECUTION TIMEOUT](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | 7 | No change | 0 ... 255 | 1 byte |  |
| [BATTERY CHARGE](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | ???? ???? | No change | 0 ... 255 | 1 byte |  |
| [DURATION TEST RESULT](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | 0 | No change | 0 ... 255 | 1 byte |  |
| [LAMP EMERGENCY TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | 0 | No change | 0 ... 255 | 1 byte |  |
| [LAMP TOTAL OPERATION TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | 0 | No change | 0 ... 255 | 1 byte |  |
| [RATED DURATION](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | Manufacturer-dependent | No change | 0 ... 255 | 1 byte | read only |
| [EMERGENCY MODE](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | ???? ???? | No change | 0 ... 255 | 1 byte |  |
| [FEATURES](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | Manufacturer-dependent | No change | 0 ... 255 | 1 byte | read only |
| [FAILURE STATUS](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | ???? ???? | No change | 0 ... 255 | 1 byte |  |
| [EMERGENCY STATUS](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | ???? ???? | No change | 0 ... 255 | 1 byte |  |
| [EXTENDED VERSION NUMBER](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) | 1 | No change | 0 ... 255 | 1 byte | read only |

?: not specified

## EMERGENCY LEVEL

This variable contains the emergency illuminance of the lamp. This value is limited via the variables EMERGENCY MAX LEVEL and EMERGENCY MIN LEVEL. The value can be read via the [FB\_DALIV2QueryEmergencyLevel()](ms-xhelp:///?Id=beckhoff-6c5f-4aa5-a9a0-26d482349c7c) block.

## EMERGENCY MIN LEVEL / EMERGENCY MAX LEVEL

The emergency illuminance is limited via the variables EMERGENCY MIN LEVEL and EMERGENCY MAX LEVEL within the ballast. The exceptions to this are power values of 0 (off) and 255 (mask). The EMERGENCY MIN LEVEL and EMERGENCY MAX LEVEL values are specified by the manufacturer of the ballast. The [FB\_DALIV2QueryEmergencyMinLevel()](ms-xhelp:///?Id=beckhoff-bbce-4b62-a6d2-41d4732054f9) and [FB\_DALIV2QueryEmergencyMaxLevel()](ms-xhelp:///?Id=beckhoff-46a2-479d-881c-c1e99a404305) blocks can be used to read the two variables from the ballast.

## PROLONG TIME

The prolong time defines how long emergency mode is extended after mains voltage is available again. The unit is 30 seconds per step. The value can be read from the ballast via the [FB\_DALIV2QueryTestTiming()](ms-xhelp:///?Id=beckhoff-4d68-48f8-b52c-9f54e44b59ec) block. The [FB\_DALIV2StoreDTRAsProlongTime()](ms-xhelp:///?Id=beckhoff-06e6-454a-a376-06855a767b92) block is used to write to this variable.

## TEST DELAY TIME

The variables FUNCTION TEST DELAY TIME, DURATION TEST DELAY TIME FUNCTION TEST INTERVAL and DURATION TEST INTERVAL are set by means of the TEST DELAY TIME variable. This specifies the time behaviour associated with the functional test and the duration test as follows:

**Function test:**   
 Use [FB\_DALIV2SetDTR()](ms-xhelp:///?Id=beckhoff-c545-4587-bc68-e0f5c5db7a1f) to write the high-order byte for the variable FUNCTION TEST DELAY TIME into the DTR (data transfer register).  
 Use [FB\_DALIV2StoreDTRAsTestDelayTimeHighByte()](ms-xhelp:///?Id=beckhoff-2f02-4aec-af3d-c4547c578b83) to write the content of the DTR into the high-order byte of the 16-bit variable TEST DELAY TIME.  
 Use [FB\_DALIV2SetDTR()](ms-xhelp:///?Id=beckhoff-c545-4587-bc68-e0f5c5db7a1f) to write the low-order byte for the variable FUNCTION TEST DELAY TIME into the DTR (data transfer register).  
 Use [FB\_DALIV2StoreDTRAsTestDelayTimeLowByte()](ms-xhelp:///?Id=beckhoff-4a60-45e4-adbc-19e54912a998) to write the content the DTR into the low-order byte of the 16-bit-variable TEST DELAY TIME.  
 Use [FB\_DALIV2SetDTR()](ms-xhelp:///?Id=beckhoff-c545-4587-bc68-e0f5c5db7a1f) to write the value for the variable FUNCTION TEST INTERVAL into the DTR (data transfer register).  
 Use [FB\_DALIV2StoreDTRAsFunctionTestInterval()](ms-xhelp:///?Id=beckhoff-1060-4c92-994c-059f497a281a) to write the content of the DTR into the variable FUNCTION TEST INTERVAL. The content of the variable TEST DELAY TIME is copied into the variable FUNCTION TEST DELAY TIME.

**Duration test:**   
 Use [FB\_DALIV2SetDTR()](ms-xhelp:///?Id=beckhoff-c545-4587-bc68-e0f5c5db7a1f) to write the high-order byte for the variable DURATION TEST DELAY TIME into the DTR (data transfer register).  
 Use [FB\_DALIV2StoreDTRAsTestDelayTimeHighByte()](ms-xhelp:///?Id=beckhoff-2f02-4aec-af3d-c4547c578b83) to write the content of the DTR into the high-order byte of the 16-bit variable TEST DELAY TIME.  
 Use [FB\_DALIV2SetDTR()](ms-xhelp:///?Id=beckhoff-c545-4587-bc68-e0f5c5db7a1f) to write the low-order byte for the variable DURATION TEST DELAY TIME into the DTR (data transfer register).  
 Use [FB\_DALIV2StoreDTRAsTestDelayTimeLowByte()](ms-xhelp:///?Id=beckhoff-4a60-45e4-adbc-19e54912a998) to write the content the DTR into the low-order byte of the 16-bit-variable TEST DELAY TIME.  
 Use [FB\_DALIV2SetDTR()](ms-xhelp:///?Id=beckhoff-c545-4587-bc68-e0f5c5db7a1f) to write the value for the variable FUNCTION TEST INTERVAL into the DTR (data transfer register).  
 Use [FB\_DALIV2StoreDTRAsDurationTestInterval()](ms-xhelp:///?Id=beckhoff-2a93-4e35-94ca-6fde73887d4b) to write the content of the DTR into the variable DURATION TEST INTERVAL. The content of the variable TEST DELAY TIME is copied into the variable DURATION TEST DELAY TIME.

## FUNCTION TEST DELAY TIME

This variable is used to specify the delay time for the function test. Once this time has elapsed, the function test is executed for the first time. The unit of this variable is 15 minutes per step. This variable can be queried via the [FB\_DALIV2QueryTestTiming()](ms-xhelp:///?Id=beckhoff-4d68-48f8-b52c-9f54e44b59ec) block. TEST DELAY TIME is used to write to this variable (see above).

## DURATION TEST DELAY TIME

This variable is used to specify the delay time for the duration test. Once this time has elapsed, the duration test is executed for the first time. The unit of this variable is 15 minutes per step. This variable can be queried via the [FB\_DALIV2QueryTestTiming()](ms-xhelp:///?Id=beckhoff-4d68-48f8-b52c-9f54e44b59ec) block. TEST DELAY TIME is used to write to this variable (see above).

## FUNCTION TEST INTERVAL

This variable is used to specify the interval time for the function test. The function test is executed periodically at these intervals. The unit of this variable is 1 day per step. This variable can be queried via the [FB\_DALIV2QueryTestTiming()](ms-xhelp:///?Id=beckhoff-4d68-48f8-b52c-9f54e44b59ec) block. TEST DELAY TIME is used to write to this variable (see above).

## DURATION TEST INTERVAL

This variable is used to specify the interval time for the duration test. The duration test is executed periodically at these intervals. The unit of this variable is 1 week per step. This variable can be queried via the [FB\_DALIV2QueryTestTiming()](ms-xhelp:///?Id=beckhoff-4d68-48f8-b52c-9f54e44b59ec) block. TEST DELAY TIME is used to write to this variable (see above).

## TEST EXECUTION TIMEOUT

The function test or duration test can be interrupted through various events. The variable TEST EXECUTION TIMEOUT can be used to specify the maximum execution time within which the respective test must be completed. The unit of this variable is 1 day per step. This variable can be queried via the [FB\_DALIV2QueryTestTiming()](ms-xhelp:///?Id=beckhoff-4d68-48f8-b52c-9f54e44b59ec) block. The [FB\_DALIV2StoreDTRAsTestExecutionTimeout()](ms-xhelp:///?Id=beckhoff-a80a-41d7-bd70-5f1a39abdeda) block is used to write to this variable.

## BATTERY CHARGE

The current state of battery charge can be retrieved via this variable. 0 means minimum load, 254 means maximum load. If the ballast is unable to determine the state of charge, this variable contains the value 255. The [FB\_DALIV2QueryBatteryCharge()](ms-xhelp:///?Id=beckhoff-274a-45a1-aa65-d40c159dbeb4) block can be used to read this variable.

## DURATION TEST RESULT

The result of a duration test is stored in this variable. The unit is 2 minutes per step. The value is only valid if bit 2 is set in the variable EMERGENCY STATUS (see below). The variable DURATION TEST RESULT can be queried with the function [FB\_DALIV2QueryDurationTestResult()](ms-xhelp:///?Id=beckhoff-536e-47c0-9462-a3a3143eacda).

## LAMP EMERGENCY TIME

The emergency mode operating period of the lamp (supply via rechargeable batteries) is stored in this variable. The unit is 1 hour per step. This variable can be queried with the [FB\_DALIV2QueryLampEmergencyTime()](ms-xhelp:///?Id=beckhoff-debd-4e88-be39-89358d0df30f) block and reset with the [FB\_DALIV2ResetLampTime() block](ms-xhelp:///?Id=beckhoff-b176-437d-bbc4-f3b4701871f6).

## LAMP TOTAL OPERATION TIME

The total lamp operating period is stored in this variable. The unit is 4 hours per step. This variable can be queried with the [FB\_DALIV2QueryLampTotalOperationTime()](ms-xhelp:///?Id=beckhoff-c299-495c-bb4b-439887d84199) block and reset with the [FB\_DALIV2ResetLampTime()](ms-xhelp:///?Id=beckhoff-b176-437d-bbc4-f3b4701871f6) block.

## RATED DURATION

The rated service time of the rechargeable battery is stored in this variable. The unit is 2 minutes per step. The value is specified by the manufacturer of the ballast and can be read with the [FB\_DALIV2QueryRatedDuration()](ms-xhelp:///?Id=beckhoff-7c0a-4a5d-9038-e21e11637bb1) block.

## EMERGENCY MODE

In EMERGENCY MODE the ballast stores the current mode. The [FB\_DALIV2QueryEmergencyMode()](ms-xhelp:///?Id=beckhoff-0f4b-4e68-aff8-ea19a8ecee20) block can be used to read the variable.

| Bit | Description |
| --- | --- |
| 0 | Reset mode. 0: No. |
| 1 | Emergency mode readiness (normal operation). 0: No. |
| 2 | Emergency mode. 0: No. |
| 3 | Extended emergency mode once mains voltage is available again. 0: No. |
| 4 | Function test active. 0: No. |
| 5 | Duration test active. 0: No. |
| 6 | Connected suppress push button is active. 0: Not active or not available. |
| 7 | Connected mains voltage is active. 0: Off. |

## FEATURES

The performance characteristics supported by the ballast can be read from this variable via the [FB\_DALIV2QueryFeatures()](ms-xhelp:///?Id=beckhoff-486e-456a-9f7c-b0400768c873) block. The content of this variable is specified by the manufacturer of the ballast and cannot be modified.

| Bit | Description |
| --- | --- |
| 0 | Integrated emergency lighting supply unit. 0: No. |
| 1 | Emergency lighting supply unit in continuous mode. 0: No. |
| 2 | Switchable emergency lighting supply unit in continuous mode. 0: No. |
| 3 | Auto test capability. 0: No. |
| 4 | Adjustable emergency lighting illuminance. 0: No. |
| 5 | Connected suppress push button is supported. 0: No. |
| 6 | Physical selection is supported. 0: No. |
| 7 | Reserved |

## FAILURE STATUS

Possible fault states are displayed in this variable and can be read with the [FB\_DALIV2QueryFailureStatus()](ms-xhelp:///?Id=beckhoff-c426-4d56-bf98-b4649d4c2407) block.

| Bit | Description |
| --- | --- |
| 0 | Fault in the ballast circuit. 0: No. |
| 1 | Battery operation time fault. 0: No. |
| 2 | Battery fault. 0: No. |
| 3 | Emergency lamp fault. 0: No. |
| 4 | Timeout during function test. 0: No. |
| 5 | Timeout during duration test. 0: No. |
| 6 | Function test failed. 0: No. |
| 7 | Duration test failed. 0: No |

## EMERGENCY STATUS

The current state is displayed by the ballast. The [FB\_DALIV2QueryEmergencyStatus()](ms-xhelp:///?Id=beckhoff-6659-42ff-907e-4c6dac79b413) block can be used to read the content of the variable.

| Bit | Description |
| --- | --- |
| 0 | Suppress mode. 0: No. |
| 1 | Function test is completed and result is valid. 0: No. |
| 2 | Duration test is completed and result is valid. 0: No. |
| 3 | Battery charger ready for operation. 0: running. |
| 4 | Start of function test delayed. 0: No. |
| 5 | Start of duration test delayed. 0: No. |
| 6 | Identification active. 0: No. |
| 7 | Selected. 0: No |

## EXTENDED VERSION NUMBER

The extended version number can be read with the FB\_DALIV2QueryExtendedVersionNumber() block. The version number can only be read, and is specified by the manufacturer of the ballasts.

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
