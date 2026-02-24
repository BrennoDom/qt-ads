# Overview

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Overview

The PLC library Tc2\_Utilities contains function blocks and functions for calling TwinCAT system functions and operating system functions as well as various conversion functions.

* [Operating system functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [PLC functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [Checksum/CRC functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [System functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [Scope View functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [Scope Server functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [ADS Monitor functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [Converting functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [STRING functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [Extended STRING functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [64 bit functions (unsigned)](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [64 bit functions (signed)](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [16 bit fixed point number functions (signed)](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [Byte order converting functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [FLOAT functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [LCOMPLEX functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [P[TYPE]\_TO\_[TYPE] converting functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [T\_Arg help functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [CSV format functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [Licensing functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)
* [Other functions](ms-xhelp:///?Id=beckhoff-b43f-4db8-a6a6-c50282b8ac99)

## Operating system functions

| Name | Description |
| --- | --- |
| [NT\_Shutdown](ms-xhelp:///?Id=beckhoff-c7cf-4bea-8c4d-74084f597347) | Shutting down the operating system (shutdown). |
| [NT\_AbortShutdown](ms-xhelp:///?Id=beckhoff-2a51-458d-95e1-ca62b624d3ac) | Interrupting the shutdown process. |
| [NT\_Reboot](ms-xhelp:///?Id=beckhoff-67ae-4db7-8398-f9a447120ce5) | Carrying out a restart of the operating system. |
| [NT\_GetTime](ms-xhelp:///?Id=beckhoff-2f0c-4113-8d0b-40bd61b5771c) | Reading the current local Windows system time. |
| [NT\_SetLocalTime](ms-xhelp:///?Id=beckhoff-69e6-480d-9a57-f100d0f6f752) | Setting the current local Windows system time. |
| [NT\_StartProcess](ms-xhelp:///?Id=beckhoff-1fb6-43a8-bf24-b62e3196ce0b) | Starts a Windows application from the PLC. |
| [NT\_SetTimeToRTCTime](ms-xhelp:///?Id=beckhoff-ac7b-4d32-84f6-6f06db4a4da6) | Synchronizing the local Windows system time with the real-time clock of the PC. |
| [FB\_RegQueryValue](ms-xhelp:///?Id=beckhoff-534c-438f-bc50-ad1d33f41765) | Reading out values from the registry. |
| [FB\_RegSetValue](ms-xhelp:///?Id=beckhoff-191a-46aa-bd42-dd91a4f6c942) | Writing values to the Registry. |
| [FB\_EnumFindFileEntry](ms-xhelp:///?Id=beckhoff-010e-4df6-9917-0f23097681b4) | Searches in a directory for a file or a subdirectory whose name is similar to the specified name. Any entries found can be read individually. |
| [FB\_EnumFindFileList](ms-xhelp:///?Id=beckhoff-1b2b-42a1-91ba-e32a06ee7247) | Searches in a directory for a file or a subdirectory whose name is similar to the specified name. The found entries can be read out in groups. |
| [FB\_GetAdaptersInfo](ms-xhelp:///?Id=beckhoff-aada-4944-b976-99571dd96ca2) | Reads network adapter information. |
| [FB\_GetHostName](ms-xhelp:///?Id=beckhoff-bf46-43f6-87b6-a93af95a6a1f) | Reads the host name of the local PC. |
| [FB\_GetHostAddrByName](ms-xhelp:///?Id=beckhoff-715a-4f1b-9574-65ab4b8363f1) | Converts the host name into the (IPv4) Internet protocol network address. |
| [FB\_GetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-e94e-4efc-8b9a-294d8ea2dae1) | Reads the time zone configuration of the operating system. |
| [FB\_SetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-4f69-47a9-b40b-5f2f878dd0cd) | Sets the time zone configuration of the operating system. |
| [FB\_LocalSystemTime](ms-xhelp:///?Id=beckhoff-40ca-431a-ad5c-7de4706ed264) | Returns the local Windows system time and summer time/winter time info. |

## PLC functions

| Name | Description |
| --- | --- |
| [PLC\_Reset](ms-xhelp:///?Id=beckhoff-73e7-40dc-9599-bcb7f15e30ba) | Resets the PLC. |
| [PLC\_Start](ms-xhelp:///?Id=beckhoff-56f3-47df-b17c-f5d6f6643a13) | Starts the PLC. |
| [PLC\_Stop](ms-xhelp:///?Id=beckhoff-286b-4b9c-a31d-6037f2b380c9) | Stops the PLC. |
| [PLC\_ReadSymInfo](ms-xhelp:///?Id=beckhoff-46d3-4919-a87d-3fa0bdcc4830) | Reading the symbol information of the PLC. |
| [PLC\_ReadSymInfoByName](ms-xhelp:///?Id=beckhoff-35a3-4a11-8af3-5a51574e7dd7) | Reading the symbol information of a PLC variable with the help of the symbol name. |
| [PLC\_ReadSymInfoByNameEx](ms-xhelp:///?Id=beckhoff-dc93-4828-bfe7-f2f21f6281ea) | Reading the symbol information of a PLC variable with the help of the symbol name. The comment will be truncated if the available buffer size is insufficient. |
| [Profiler](ms-xhelp:///?Id=beckhoff-06b5-46f0-b9a7-c7cbeb6e235d) | Determining the execution time of the PLC code. |
| [WritePersistentData](ms-xhelp:///?Id=beckhoff-1774-419f-81e7-bff0bfa2ac30) | Saving the persistent data to the data storage device from the PLC program. |
| [FB\_WritePersistentData](ms-xhelp:///?Id=beckhoff-d009-43a5-8dbb-27889de4e9ba) | Saving the persistent data to the data storage device from the PLC program (extended version). |

## Checksum/CRC functions

| Name | Description |
| --- | --- |
| [F\_CheckSum16](ms-xhelp:///?Id=beckhoff-e2e1-49fd-b459-a9b9401fbfbc) | Calculates the 16 bit checksum. |
| [F\_DATA\_TO\_CRC16\_CCITT](ms-xhelp:///?Id=beckhoff-6ccf-4088-9466-01ed2583419a) | Calculates CRC16-CCITT (cyclical redundancy check) of any data type. |
| [F\_BYTE\_TO\_CRC16\_CCITT](ms-xhelp:///?Id=beckhoff-1581-44e8-9f84-c03859e5cdc9) | Calculates CRC16-CCITT (cyclical redundancy check) of an individual data byte. |

## System functions

| Name | Description |
| --- | --- |
| [TC\_Restart](ms-xhelp:///?Id=beckhoff-05e2-482e-9dc9-bb97e9fcba2d) | Restart the TwinCAT system. |
| [TC\_Stop](ms-xhelp:///?Id=beckhoff-0db2-4c90-9640-3c5d8d692a35) | Stop the TwinCAT system. |
| [TC\_Config](ms-xhelp:///?Id=beckhoff-97c9-48da-829e-9cfa8556a57b) | Switching TwinCAT system to CONFIG mode. |
| [TC\_CpuUsage](ms-xhelp:///?Id=beckhoff-2ee2-4828-992b-458cab5e19fd) | Determining CPU usage of the TwinCAT system. |
| [TC\_SysLatency](ms-xhelp:///?Id=beckhoff-dbdb-4839-aad8-e9dc6f5c7cec) | Determining the current and maximum latency time of a TwinCAT system. |
| [GetRemotePCInfo](ms-xhelp:///?Id=beckhoff-446e-46fe-afcf-b8df84f748a6) | Reading router information via the configured remote PCs. |
| [FB\_GetLocalAmsNetId](ms-xhelp:///?Id=beckhoff-8bd6-4a23-a993-e91ec1c265c5) | Reading the AmsNetId of the local TwinCAT PC. |
| [FB\_GetRouterStatusInfo](ms-xhelp:///?Id=beckhoff-76b5-4871-bf56-901a447b81ca) | Reading TwinCAT router status information. |
| [FB\_EnumRouteEntry](ms-xhelp:///?Id=beckhoff-ea9a-408c-9d45-9779461e725a) | Reading router connection information. |
| [FB\_AddRouteEntry](ms-xhelp:///?Id=beckhoff-0340-427d-85f3-8906259b8426) | Adding a new router connection. |
| [FB\_RemoveRouteEntry](ms-xhelp:///?Id=beckhoff-5e2a-4be9-889d-c47698787d1a) | Deleting an existing router connection. |
| [ROUTETRANSPORT\_TO\_STRING](ms-xhelp:///?Id=beckhoff-aa2a-4877-86c1-484239cb1e0c) | Converts the AMS message router transport layer ID into a string. |
| [FB\_GetDeviceIdentification](ms-xhelp:///?Id=beckhoff-ce69-4651-89d9-60afc529e570) | Reads the device ID. |
| [FB\_GetDeviceIdentificationEx](ms-xhelp:///?Id=beckhoff-790c-4ac0-bb96-e292c315bf69) | Reads the device ID. (Allows longer strings with hardware model and serial number.) |
| [FB\_GetLicences](ms-xhelp:///?Id=beckhoff-f433-46e0-a525-72a322cb0ecd) | Reads the valid and invalid TwinCAT licenses. |
| [FB\_GetSystemId](ms-xhelp:///?Id=beckhoff-6e9c-4092-824f-99a2ad74b2be) | Reads the SystemID as GUID. |
| [FB\_GetVolumeId](ms-xhelp:///?Id=beckhoff-b0de-4833-9304-a9ea3fc28883) | Reads the SystemID and the Volume System ID. |

## Scope View functions

TwinCAT Scope View functions are not supported by TwinCAT 3.

## Scope Server functions

| Name | Description |
| --- | --- |
| [FB\_ScopeServerControl](ms-xhelp:///?Id=beckhoff-d943-4605-855c-46da3b86c1b9) | Controls (start/save..) the Scope Server for data logging. |

## ADS Monitor functions

| Name | Description |
| --- | --- |
| [FB\_AmsLogger](ms-xhelp:///?Id=beckhoff-43a8-4a1a-aa0c-e492eebbc366) | Start/stop AMS Logger from the PLC. |

## Converting functions

| Name | Description |
| --- | --- |
| [DT\_TO\_SYSTEMTIME](ms-xhelp:///?Id=beckhoff-798c-4a19-a6cb-decf5642776b) | Converting DATE\_AND\_TIME to Windows system time structure. |
| [DT\_TO\_FILETIME](ms-xhelp:///?Id=beckhoff-28ff-44a2-9c2a-12fe91028e13) | Converting DATE\_AND\_TIME to Windows file time. |
| [SYSTEMTIME\_TO\_DT](ms-xhelp:///?Id=beckhoff-532e-4c69-a8ef-626ad9d7c84a) | Converting Windows system time structure to DATE\_AND\_TIME. |
| [SYSTEMTIME\_TO\_FILETIME](ms-xhelp:///?Id=beckhoff-d566-43ec-8f7d-d1f8b1e606db) | Converting Windows system time structure to file time. |
| [SYSTEMTIME\_TO\_STRING](ms-xhelp:///?Id=beckhoff-7579-4ea6-878c-5ec6cc4284f7) | Converting Windows system time structure to string. |
| [STRING\_TO\_SYSTEMTIME](ms-xhelp:///?Id=beckhoff-72cc-4d41-be9d-4d00dcceff37) | Converting string to Windows system time structure. |
| [FILETIME\_TO\_DT](ms-xhelp:///?Id=beckhoff-6efb-40b3-b9bc-d4f1bc36143f) | Converting Windows file time to DATE\_AND\_TIME. |
| [FILETIME\_TO\_SYSTEMTIME](ms-xhelp:///?Id=beckhoff-d3d3-46c3-8ec5-876d06fab03e) | Converting Windows file time to system time structure. |
| [DEC\_TO\_BCD](ms-xhelp:///?Id=beckhoff-ac31-4879-8763-ac2dae537e3a) | Converting decimal numbers to BCD numbers. |
| [BCD\_TO\_DEC](ms-xhelp:///?Id=beckhoff-5743-49c1-aea6-b5f6bbe8623e) | Converting BCD numbers to decimal numbers. |
| [DEG\_TO\_RAD](ms-xhelp:///?Id=beckhoff-3442-4599-a87f-f1c71268f252) | Converting degree-angle to radian. |
| [RAD\_TO\_DEG](ms-xhelp:///?Id=beckhoff-0d3b-4d0b-b34c-8914da4d2082) | Converting radian to degree-angle. |
| [TIME\_TO\_OTSTRUCT](ms-xhelp:///?Id=beckhoff-db69-40e2-9ffb-8f8895e29dcc) | Converting TIME variable to a structure with resolved milliseconds, seconds, minutes etc. |
| [OTSTRUCT\_TO\_TIME](ms-xhelp:///?Id=beckhoff-fee0-41a3-935a-e9a5b3123482) | Converting a structure with resolved milliseconds, seconds, minutes etc. to TIME variable. |
| [F\_SwapRealEx](ms-xhelp:///?Id=beckhoff-ef1b-4d8e-8681-fd98e6c7bba1) | Replaces by the Hi and Lo Word of a REAL variable. |
| [BYTE\_TO\_LREALEX](ms-xhelp:///?Id=beckhoff-9f09-4fa7-8360-27d8830301f4) | Allows an explicit conversion of the type BYTE to a positive floating point number of the type LREAL. |
| [DWORD\_TO\_LREALEX](ms-xhelp:///?Id=beckhoff-6ead-491d-8018-5697c9b57863) | Allows an explicit conversion of the type DWORD to a positive floating point number of the type LREAL. |
| [UDINT\_TO\_LREALEX](ms-xhelp:///?Id=beckhoff-b007-48b7-95e4-9ada3bbf5171) | Allows an explicit conversion of the type UDINT to a positive floating point number of the type LREAL. |
| [UINT\_TO\_LREALEX](ms-xhelp:///?Id=beckhoff-27f6-4d56-b2f2-3f5df7c6f500) | Allows an explicit conversion of the type UINT to a positive floating point number of the type LREAL. |
| [ULINT\_TO\_ULARGE](ms-xhelp:///?Id=beckhoff-26ec-4aa6-a1a9-e329b64b0787) | Converts a 64 bit number of the type ULINT into a 64 bit number of the type T\_ULARGE\_INTEGER. |
| [USINT\_TO\_LREALEX](ms-xhelp:///?Id=beckhoff-3b5a-44f0-9ca3-156a8525d104) | Allows an explicit conversion of the type USINT to a positive floating point number of the type LREAL. |
| [BYTEARR\_TO\_MAXSTRING](ms-xhelp:///?Id=beckhoff-3421-43c3-a9b9-8cd80d54a9dc) | Converts byte array into a string. |
| [MAXSTRING\_TO\_BYTEARR](ms-xhelp:///?Id=beckhoff-bae7-4d07-9e4a-7e655b3052a6) | Converts string into a byte array. |
| [F\_TranslateFileTimeBias](ms-xhelp:///?Id=beckhoff-674d-4bec-8c10-02c5b94776c0) | Converts UTC time into local time and vice versa (by bias). |
| [FB\_TzSpecificLocalTimeToFileTime](ms-xhelp:///?Id=beckhoff-7cf2-4bdb-8eca-afac6ba61420) | Converts continuous local time (file time format) into UTC time. |
| [FB\_TzSpecificLocalTimeToSystemTime](ms-xhelp:///?Id=beckhoff-2d5a-443c-9aa9-97c8c02f3336) | Converts continuous local time (structured system time format) into UTC time. |
| [FB\_FileTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-ed55-4f54-90d2-a8293198c22f) | Converts UTC time (file time format) into local time. |
| [FB\_SystemTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-20ad-46e0-9bae-a6b428b840f1) | Converts UTC time (structured system time format) into local time. |
| [HEXASCNIBBLE\_TO\_BYTE](ms-xhelp:///?Id=beckhoff-418e-4c93-9898-586d871aa6d4) | Converts the ASCII code of a hexadecimal half-byte character into a decimal value. |
| [HEXCHRNIBBLE\_TO\_BYTE](ms-xhelp:///?Id=beckhoff-d1b3-452f-8c4f-fdf238d2afee) | Converts a hexadecimal half-byte character into its decimal value. |
| [GuidsEqualByVal](ms-xhelp:///?Id=beckhoff-cb68-4d70-bf16-fed1fcefcd28) | Compares two GUID values |

## STRING functions

| Name | Description |
| --- | --- |
| [LREAL\_TO\_FMTSTR](ms-xhelp:///?Id=beckhoff-1e65-47f2-a79d-149b53588f36) | Converts a flowing point number into a string with the desired number of decimal places. |
| [DWORD\_TO\_DECSTR](ms-xhelp:///?Id=beckhoff-8536-42fd-863f-233e41653e37) | Converts a decimal number into a decimal string. |
| [DWORD\_TO\_HEXSTR](ms-xhelp:///?Id=beckhoff-2aeb-4d48-901b-072c495146a6) | Converts a decimal number into a hexadecimal string. |
| [DWORD\_TO\_OCTSTR](ms-xhelp:///?Id=beckhoff-2e35-40a6-b095-2070fc35b0ec) | Converts a decimal number into an octal string. |
| [DWORD\_TO\_BINSTR](ms-xhelp:///?Id=beckhoff-3e69-4a87-b8bc-e1e76249d76f) | Converts a decimal number into a binary string. |
| [LWORD\_TO\_DECSTR](ms-xhelp:///?Id=beckhoff-245d-4a84-871b-9f26856f81fc) | Converts a decimal number into a decimal string. |
| [LWORD\_TO\_HEXSTR](ms-xhelp:///?Id=beckhoff-9be6-4814-b9b0-54b559eba888) | Converts a decimal number into a hexadecimal string. |
| [LWORD\_TO\_OCTSTR](ms-xhelp:///?Id=beckhoff-b88d-436f-b18f-3d702ef884c1) | Converts a decimal number into an octal string. |
| [LWORD\_TO\_BINSTR](ms-xhelp:///?Id=beckhoff-1383-4e9c-aaa1-a46acab7de0e) | Converts a decimal number into a binary string. |
| [PVOID\_TO\_DECSTR](ms-xhelp:///?Id=beckhoff-353e-4715-93ab-2cf66b1c2ceb) | Converts an address (pointer) into a decimal string. |
| [PVOID\_TO\_HEXSTR](ms-xhelp:///?Id=beckhoff-fc84-46e8-887a-62ee7e511630) | Converts an address (pointer) into a hexadecimal string. |
| [PVOID\_TO\_OCTSTR](ms-xhelp:///?Id=beckhoff-a605-46c3-8d0e-e30489b907db) | Converts an address (pointer) into an octal string. |
| [PVOID\_TO\_BINSTR](ms-xhelp:///?Id=beckhoff-ee5c-4cb9-bb0f-d37a3595d8fc) | Converts an address (pointer) into a binary string. |
| [PVOID\_TO\_STRING](ms-xhelp:///?Id=beckhoff-8ce5-42fb-a04e-8b003ca57443) | Converts an address (pointer) into a string. |
| [STRING\_TO\_PVOID](ms-xhelp:///?Id=beckhoff-1ed9-499b-965a-4d4e946697bb) | Converts a string into an address (pointer). |
| [LINT\_TO\_DECSTR](ms-xhelp:///?Id=beckhoff-455b-4b8f-a88f-11c15693ed35) | Converts a signed decimal number (64 bit) into a decimal string. |
| [DINT\_TO\_DECSTR](ms-xhelp:///?Id=beckhoff-9d53-4948-9f3e-50f73bd6c28c) | Converts a signed decimal number (32 bit) into a decimal string. |
| [F\_FormatArgToStr](ms-xhelp:///?Id=beckhoff-eb2c-4b18-8b80-a8518091c3d8) | Converts and formats a decimal number or a flowing point number into a string. |
| [BYTE\_TO\_BINSTR](ms-xhelp:///?Id=beckhoff-f29f-40b4-9420-878a406dbf68) | Converts a decimal number of the type byte into a binary string. |
| [BYTE\_TO\_DECSTR](ms-xhelp:///?Id=beckhoff-cc95-4726-be05-4d59bca57f71) | Converts a decimal number into a decimal string. |
| [BYTE\_TO\_HEXSTR](ms-xhelp:///?Id=beckhoff-7da2-4ca5-9a17-9563d9062ea6) | Converts a decimal number into a hexadecimal string. |
| [BYTE\_TO\_OCTSTR](ms-xhelp:///?Id=beckhoff-29cb-43ef-9294-627742eb881f) | Converts a decimal number into an octal string. |
| [WORD\_TO\_BINSTR](ms-xhelp:///?Id=beckhoff-3e67-42ff-8055-531749cc6240) | Converts a decimal number of the type word into a binary string. |
| [WORD\_TO\_DECSTR](ms-xhelp:///?Id=beckhoff-eba7-4796-b519-fb27ad80388c) | Converts a decimal number of the type word into a decimal string. |
| [WORD\_TO\_HEXSTR](ms-xhelp:///?Id=beckhoff-5a77-4e12-abbb-dc1d68b6ad2b) | Converts a decimal number of the type word into a hexadecimal string. |
| [WORD\_TO\_OCTSTR](ms-xhelp:///?Id=beckhoff-af02-49c0-bcda-c422acb53cda) | Converts a decimal number of the type word into an octal string. |
| [FB\_FormatString](ms-xhelp:///?Id=beckhoff-5a86-4f47-ae1f-3b48b62e5a67) | Converts and formats up to 10 arguments (decimal or flowing point numbers). |
| [FB\_EnumStringNumbers](ms-xhelp:///?Id=beckhoff-8bbb-40cc-b879-0c64a2c3e37b) | Searches a string for numbers. |
| [F\_ToUCase](ms-xhelp:///?Id=beckhoff-7ffe-495f-96ad-aaf8b3eac001) | Converts lowercase letters into uppercase letters in a string. |
| [F\_ToLCase](ms-xhelp:///?Id=beckhoff-2c8e-479d-b6ab-542ab6acb7e4) | Converts uppercase letters into lowercase letters in a string. |
| [F\_LTrim](ms-xhelp:///?Id=beckhoff-93d3-4263-9778-32459bd15abc) | Removes spaces at the beginning of a string. |
| [F\_RTrim](ms-xhelp:///?Id=beckhoff-7e11-4812-bfbe-4840f87f0256) | Removes spaces at the end of a string. |
| [DATA\_TO\_HEXSTR](ms-xhelp:///?Id=beckhoff-11cb-4bcb-887c-c8d12ebc93aa) | Converts binary data into hexadecimal string. |
| [HEXSTR\_TO\_DATA](ms-xhelp:///?Id=beckhoff-233b-4f6c-9bcf-93d88b5448c0) | Converts hexadecimal string to binary data. |
| [GUID\_TO\_STRING](ms-xhelp:///?Id=beckhoff-7b8f-479d-b5bb-501490127b29) | Converts a structured GUID variable into a GUID string variable. |
| [GUID\_TO\_REGSTRING](ms-xhelp:///?Id=beckhoff-1dab-47fa-b684-6de886499be0) | Converts a structured GUID variable into a registry GUID string variable |
| [REGSTRING\_TO\_GUID](ms-xhelp:///?Id=beckhoff-8e27-408c-aa7a-f1f5437ef912) | Converts a registry GUID string variable into a structured GUID variable. |

## Extended STRING functions

| Name | Description |
| --- | --- |
| [CHAR\_TO\_WCHAR](ms-xhelp:///?Id=beckhoff-0047-4a2d-b8f1-ccccbd493afb) | Converts a character of the data type STRING into a character of the data type WSTRING (with null termination). |
| [CONCAT2](ms-xhelp:///?Id=beckhoff-d329-41c8-beac-2c79d3b4eb68) | Concatenates two strings of the data type STRING. |
| [DELETE2](ms-xhelp:///?Id=beckhoff-dc3e-4607-b5ea-cdd13bf2e9c1) | Removes nLen characters from a string, starting at position nPos. |
| [F\_StringIsASCII](ms-xhelp:///?Id=beckhoff-072c-40e3-b5c2-06f777b5424d) | Checks whether a string contains only ASCII characters (0x000 to 0x7F) and returns the number of ASCII characters. |
| [FIND2](ms-xhelp:///?Id=beckhoff-648e-4483-966e-3d249a6f4658) | Finds a string, which may occur more than once, in another string. |
| [FindAndDelete](ms-xhelp:///?Id=beckhoff-f5a1-4df7-affa-b2dc2eee8b2e) | Finds a string, which may occur more than once, in another string and removes it. |
| [FindAndDeleteChar](ms-xhelp:///?Id=beckhoff-90d9-4db6-b208-c11f20304068) | Finds a character, which may occur more than once, in a string and removes it. |
| [FindAndReplace](ms-xhelp:///?Id=beckhoff-40cf-426b-a4df-3faadc83d36e) | Finds a string, which may occur more than once, in another string and replaces it with another string. |
| [FindAndReplaceChar](ms-xhelp:///?Id=beckhoff-1521-436d-9e8a-8ea38f233506) | Finds a character, which may occur more than once, in a string and replaces it with another character. |
| [INSERT2](ms-xhelp:///?Id=beckhoff-0009-48be-bc4c-ebfd83df6943) | Inserts a string into another string after position nPos. |
| [LEN2](ms-xhelp:///?Id=beckhoff-4820-4660-af97-8ac57a989a2c) | Returns the number of characters in a string. |
| [REPLACE2](ms-xhelp:///?Id=beckhoff-95d7-400d-ad47-0fb1e81894e4) | Replaces nLen characters of a string with another string, starting at position nPos. |
| [sLiteral\_TO\_UTF8](ms-xhelp:///?Id=beckhoff-7d26-4fb5-b7c8-75a331f934fd) | Converts any character string of the data type STRING into a character string in UTF-8 format. |
| [STRING\_TO\_UTF8](ms-xhelp:///?Id=beckhoff-6b71-41e3-84c4-d1f7954109ec) | Converts any string of a variable of the data type STRING to a string in UTF-8 format. |
| [STRING\_TO\_WSTRING2](ms-xhelp:///?Id=beckhoff-4273-42d9-b23f-5285ac82f67b) | Converts a variable of the data type STRING into a variable of the data type WSTRING. |
| [STRNCPY](ms-xhelp:///?Id=beckhoff-701b-4577-8ccf-b0525b24487f) | Copies the character string of a variable of the data type STRING and checks whether the character string was completely copied |
| [UTF8\_TO\_STRING](ms-xhelp:///?Id=beckhoff-ae5a-4efa-b81e-4c3fbc7352c4) | Converts a string in UTF-8 format into a string of the data type STRING. |
| [UTF8\_TO\_WSTRING](ms-xhelp:///?Id=beckhoff-f73d-4d56-a03e-a2c353126e15) | Converts a string in UTF-8 format into a string of the data type WSTRING. |
| [UTF8Len](ms-xhelp:///?Id=beckhoff-c3e8-4cf9-9e57-1b0cdcab2a77) | Returns the number of characters in a UTF-8 string. |
| [WCHAR\_TO\_CHAR](ms-xhelp:///?Id=beckhoff-03e2-4c19-8596-b63af989f427) | Converts a variable of the data type WSTRING into a variable of the data type STRING (with null termination) |
| [WCONCAT2](ms-xhelp:///?Id=beckhoff-73e2-4c2d-a2d1-ba5ee413cd4a) | Concatenates two strings of the data type WSTRING of any length. |
| [WLEN2](ms-xhelp:///?Id=beckhoff-4b3b-404b-bee4-2f98b3664749) | Returns the number of characters in a Unicode string of the data type WSTRING. |
| [wsLiteral\_TO\_UTF8](ms-xhelp:///?Id=beckhoff-29e7-4105-940d-4aa23630c02f) | Converts any character string of the data type WSTRING into a character string in UTF-8 format. |
| [WSTRING\_TO\_STRING2](ms-xhelp:///?Id=beckhoff-c7a0-4925-9174-68062ac43a9b) | Converts a variable of the data type WSTRING into a variable of the data type STRING. |
| [WSTRING\_TO\_UTF8](ms-xhelp:///?Id=beckhoff-499d-4246-810b-99ef6bfa9880) | Converts a string of a variable of the data type WSTRING into a string in UTF-8 format. |
| [WSTRNCPY](ms-xhelp:///?Id=beckhoff-d51a-4354-b7fd-f7f0844c4dab) | Copies a character string of a variable of the data type WSTRING and checks whether the character string was completely copied. |

## 64 bit functions (unsigned)

| Name | Description |
| --- | --- |
| [ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-a44b-45ae-835d-95fa2104fb5f) | Initializes/sets a 64 bit number. |
| [UInt64Add64](ms-xhelp:///?Id=beckhoff-b540-4fd7-b466-3fd3ec81d344) | Adds two 64 bit numbers. |
| [UInt64Add64Ex](ms-xhelp:///?Id=beckhoff-89f9-45a2-97bc-0a2b99ba380c) | Adds two 64 bit numbers (with Overflow check). |
| [UInt64Sub64](ms-xhelp:///?Id=beckhoff-9c15-4e66-b71c-8b5e7bb50df9) | Subtracts two 64 bit numbers. |
| [UInt64Cmp64](ms-xhelp:///?Id=beckhoff-517d-49e4-82de-8d255a9caf75) | Compares two 64 bit numbers. |
| [UInt32x32To64](ms-xhelp:///?Id=beckhoff-fb2b-4dd4-8e90-e07f77165dc4) | Multiplies two 32 bit numbers. The result is a 64 bit number. |
| [UInt64Mul64](ms-xhelp:///?Id=beckhoff-f15e-4eb2-b863-92f670ea3f6f) | Multiplies two 64 bit numbers. The result is a 64 bit number. |
| [UInt64Mul64Ex](ms-xhelp:///?Id=beckhoff-e958-4082-ac61-0139e5c5d259) | Multiplies two 64 bit numbers. The result is a 64 bit number (with overflow check). |
| [UInt64Div64](ms-xhelp:///?Id=beckhoff-5a6f-49bf-9f58-a8b0b6397ed4) | Division of two 64 bit numbers. |
| [UInt64Div64Ex](ms-xhelp:///?Id=beckhoff-50a7-46d6-8ea0-002d10308ce8) | Division of two 64 bit numbers (with remainder). |
| [Uint64Div16Ex](ms-xhelp:///?Id=beckhoff-b2e3-494b-acaf-c9c3dd314ce4) | Division of one 64 bit number by a 16 bit number. The result is a 64 bit number. |
| [UInt64Mod64](ms-xhelp:///?Id=beckhoff-383c-4976-9cc2-c9080252a55d) | Modulo division of two 64 bit numbers. |
| [UInt64And](ms-xhelp:///?Id=beckhoff-04dc-4e50-a762-a408c6fb865f) | Bit by bit AND of two 64 bit numbers. |
| [UInt64Or](ms-xhelp:///?Id=beckhoff-ca7f-4175-acde-38470bf2a67a) | Bit by bit OR of two 64 bit numbers. |
| [UInt64Not](ms-xhelp:///?Id=beckhoff-9fee-48fd-aebf-9c504d02148b) | Bit by bit NOT of one 64 bit number. |
| [UInt64Xor](ms-xhelp:///?Id=beckhoff-7683-4363-aaf0-bf67887dfeeb) | Bit by bit XOR of two 64 bit numbers. |
| [UInt64Rol](ms-xhelp:///?Id=beckhoff-bd60-41be-89fb-3567105e6fc5) | Bit by bit left rotation of one 64 bit number. |
| [UInt64Ror](ms-xhelp:///?Id=beckhoff-770a-486c-a5d4-4d0036dcccee) | Bit by bit right rotation of one 64 bit number. |
| [UInt64Shl](ms-xhelp:///?Id=beckhoff-120d-4352-bae7-14f2ff5f256c) | Bit by bit left shift of one 64 bit number. |
| [UInt64Shr](ms-xhelp:///?Id=beckhoff-2b6c-4392-befc-ec9d6e5385b3) | Bit by bit right shift of one 64 bit number. |
| [UInt64Min](ms-xhelp:///?Id=beckhoff-8f68-4966-bd4a-6adbecbae67b) | Minimum function |
| [UInt64Max](ms-xhelp:///?Id=beckhoff-a7cc-4301-8a0e-c395d8e2860a) | Maximum function |
| [UInt64Limit](ms-xhelp:///?Id=beckhoff-3337-43a8-a2bc-9cca6dec61fb) | Limitation |
| [UInt64isZero](ms-xhelp:///?Id=beckhoff-c83f-4f91-ac16-d93929d8d95c) | Checks whether the value of the 64 bit number is zero. |
| [UINT64\_TO\_STRING](ms-xhelp:///?Id=beckhoff-09b1-42f9-bc70-31567f4675ce) | Converts 64 bit number into a string. |
| [UINT64\_TO\_LREAL](ms-xhelp:///?Id=beckhoff-dcf3-49e8-a878-d25ac0c5cb00) | Converts 64 bit number into a LREAL. |
| [STRING\_TO\_UINT64](ms-xhelp:///?Id=beckhoff-4b09-4939-84f3-d16146f0779e) | Converts a STRING into a 64 bit number. |
| [LREAL\_TO\_UINT64](ms-xhelp:///?Id=beckhoff-915a-4f27-b298-c8f65bfe1463) | Converts LREAL into a 64 bit number. |
| [LWORD\_TO\_ULARGE](ms-xhelp:///?Id=beckhoff-c7c2-45c5-8cf3-16edb490ad0c) | Converts a 64 bit number of the type LWORD into a 64 bit number of the type T\_ULARGE\_INTEGER. |
| [ULARGE\_TO\_LWORD](ms-xhelp:///?Id=beckhoff-ef83-4c51-87d7-8ab1d6b4ed2a) | Converts a 64 bit number of the type T\_ULARGE\_INTEGER into a 64 bit number of the type LWORD. |
| [ULARGE\_TO\_ULINT](ms-xhelp:///?Id=beckhoff-eceb-4bbd-b958-905ae12d1484) | Converts a 64 bit number of the type T\_ULARGE\_INTEGER into a 64 bit number ULINT. |

## 64 bit functions (signed)

| Name | Description |
| --- | --- |
| [LARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-b1fb-4a5b-ba7e-11a6de8b26af) | Initializes/sets a 64 bit number. |
| [Int64Add64](ms-xhelp:///?Id=beckhoff-3588-40a6-b460-b7d9af2d0948) | Adds two 64 bit numbers. |
| [Int64Add64Ex](ms-xhelp:///?Id=beckhoff-8bdf-406e-b049-51027aeb0adc) | Adds two 64 bit numbers (with Overflow check). |
| [Int64Sub64](ms-xhelp:///?Id=beckhoff-14bc-4377-9976-504f96db0e76) | Subtracts two 64 bit numbers. |
| [Int64Cmp64](ms-xhelp:///?Id=beckhoff-1621-447c-8f83-af449567f081) | Compares two 64 bit numbers. |
| [Int64Div64Ex](ms-xhelp:///?Id=beckhoff-ce16-4d93-949a-68eac1b5d4e5) | Division of two 64 bit numbers (with remainder). |
| [Int64Not](ms-xhelp:///?Id=beckhoff-c4c5-4568-bb51-da712bafe0a4) | Bit by bit NOT of one 64 bit number. |
| [Int64isZero](ms-xhelp:///?Id=beckhoff-ed19-4877-96af-2050d7391d3b) | Checks whether the value of the 64 bit number is zero. |
| [Int64Negate](ms-xhelp:///?Id=beckhoff-06d6-4cd3-9d7b-7e6528d4558b) | Negates a 64 bit number. |
| [INT64\_TO\_LREAL](ms-xhelp:///?Id=beckhoff-a41f-4e29-8ee3-79b2678492f7) | Converts 64 bit number into a LREAL. |
| [LREAL\_TO\_INT64](ms-xhelp:///?Id=beckhoff-723e-4c40-a9bc-0c51ae3e70b1) | Converts LREAL into a 64 bit number. |
| [LARGE\_TO\_ULARGE](ms-xhelp:///?Id=beckhoff-de86-47a3-8beb-fb4e6950b725) | Converts a signed 64 bit number into an unsigned 64 bit number. |
| [ULARGE\_TO\_LARGE](ms-xhelp:///?Id=beckhoff-4bdf-4728-82e7-ef735593e8f8) | Converts an unsigned 64 bit number into a signed 64 bit number. |
| [LARGE\_TO\_LINT](ms-xhelp:///?Id=beckhoff-1157-4d9d-930a-7441c75b7fff) | Converts a signed 64 bit number of the type LINT into a signed 64 bit number of the type T\_LARGE\_INTEGER. |
| [LINT\_TO\_LARGE](ms-xhelp:///?Id=beckhoff-4385-4f4b-bbca-8d7b5ce7eb7e) | Converts a signed 64 bit number of the type T\_LARGE\_INTEGER into a signed 64 bit number of the type LINT. |

## 16 bit fixed point number functions (signed)

| Name | Description |
| --- | --- |
| [FIX16Add](ms-xhelp:///?Id=beckhoff-66ee-4ab6-a20f-c002de40ac8b) | Adds two fixed-point numbers. |
| [FIX16Align](ms-xhelp:///?Id=beckhoff-5bed-48a2-aea4-c93ea7843a87) | Changes the resolution of a fixed-point number. |
| [FIX16Sub](ms-xhelp:///?Id=beckhoff-7e23-4e9c-b59a-e58d6079a057) | Subtracts two fixed-point numbers. |
| [FIX16Div](ms-xhelp:///?Id=beckhoff-cb6a-42cb-9865-9b4ba269728a) | Divides two fixed-point numbers. |
| [FIX16Mul](ms-xhelp:///?Id=beckhoff-c961-4562-b77f-e2f4a3f0db09) | Multiplies two fixed-point numbers. |
| [LREAL\_TO\_FIX16](ms-xhelp:///?Id=beckhoff-ebc9-4f8b-83fc-fd047b7a3f98) | Converts LREAL into a fixed-point number. |
| [WORD\_TO\_FIX16](ms-xhelp:///?Id=beckhoff-6056-4382-9463-d45c0a777f46) | Converts WORD into a fixed-point number. |
| [FIX16\_TO\_LREAL](ms-xhelp:///?Id=beckhoff-c797-4f5e-a7a8-395cf5116e4d) | Converts a fixed-point number into LREAL. |
| [FIX16\_TO\_WORD](ms-xhelp:///?Id=beckhoff-49a3-4d97-87ef-1b8c8ad74c1c) | Converts a fixed-point number into WORD. |

## Byte order converting functions

| Name | Description |
| --- | --- |
| [HOST\_TO\_BE16](ms-xhelp:///?Id=beckhoff-f6fc-4047-97bf-a66787d0d8d8) | Host-to-network converting (16 bit number) |
| [HOST\_TO\_BE32](ms-xhelp:///?Id=beckhoff-706b-46e7-8747-879dc4157971) | Host-to-network converting (32 bit number) |
| [HOST\_TO\_BE64](ms-xhelp:///?Id=beckhoff-3e6a-47f3-aadc-00e83a8d0b2b) | Host-to-network converting (64 bit number, „legacy“-type: T\_ULARGE\_INTEGER) |
| [HOST\_TO\_BE64EX](ms-xhelp:///?Id=beckhoff-43ac-4948-a550-deb02c3ef4d1) | Host-to-network converting (64 bit number, „native“-type: LWORD) |
| [HOST\_TO\_BE128](ms-xhelp:///?Id=beckhoff-c4ad-4026-8310-169569227dca) | Host-to-network converting (128 bit number, „legacy“-type: T\_UHUGE\_INTEGER) |
| [BE16\_TO\_HOST](ms-xhelp:///?Id=beckhoff-530b-4690-affe-d6162a0bfb24) | Host-to-network converting (16 bit number) |
| [BE32\_TO\_HOST](ms-xhelp:///?Id=beckhoff-43e6-4fe6-b8ff-a557e6fb42e7) | Network-to-host converting (32 number) |
| [BE64\_TO\_HOST](ms-xhelp:///?Id=beckhoff-cb16-4469-adc1-2ff1bc3d0b4d) | Network-to-host converting (64 bit number, „legacy“-type: T\_ULARGE\_INTEGER) |
| [BE64\_TO\_HOSTEX](ms-xhelp:///?Id=beckhoff-5ea2-41be-9273-2c55a25f0fca) | Network-to-host converting (64 bit number, „native“-type: LWORD) |
| [BE128\_TO\_HOST](ms-xhelp:///?Id=beckhoff-3863-469a-ae0c-5161412fd06a) | Network-to-host converting (128 bit number, „legacy“-type: T\_UHUGE\_INTEGER) |

## FLOAT functions

| Name | Description |
| --- | --- |
| [BOOL\_TO\_FLOAT](ms-xhelp:///?Id=beckhoff-be3f-4a4c-b3c1-81b619db2455) | Converts a variable of the type BOOL to a variable of the type LREAL. |
| [DINT\_TO\_FLOAT](ms-xhelp:///?Id=beckhoff-9f8f-4175-83a2-f715bcee2971) | Converts a variable of the type DINT to a variable of the type FLOAT. |
| [FLOAT\_TO\_BOOL](ms-xhelp:///?Id=beckhoff-c031-4cdc-bb74-2f89b8b6571d) | Converts a variable of the type FLOAT to a variable of the type BOOL. |
| [FLOAT\_TO\_DINT](ms-xhelp:///?Id=beckhoff-17fe-4eb1-ad1d-e24892d8d812) | Converts a variable of the type FLOAT to a variable of the type DINT. |
| [FLOAT\_TO\_INT](ms-xhelp:///?Id=beckhoff-7fde-4097-98b7-cc5d7f40ac53) | Converts a variable of the type FLOAT to a variable of the type INT. |
| [FLOAT\_TO\_SINT](ms-xhelp:///?Id=beckhoff-3540-4a6e-bdaa-ff9eab366fce) | Converts a variable of the type FLOAT to a variable of the type SINT. |
| [FLOAT\_TO\_STRING](ms-xhelp:///?Id=beckhoff-16fa-4aa7-9e84-b5adb6bc981b) | Converts a variable of the type FLOAT to a variable of the type STRING. |
| [FLOAT\_TO\_TIME](ms-xhelp:///?Id=beckhoff-a9d5-4f31-a4f8-1b47c9fd46ae) | Converts a variable of the type FLOAT to a variable of the type TIME. |
| [FLOAT\_TO\_UDINT](ms-xhelp:///?Id=beckhoff-762f-4d86-ad0e-f9938303fd0d) | Converts a variable of the type FLOAT to a variable of the type UDINT. |
| [FLOAT\_TO\_UINT](ms-xhelp:///?Id=beckhoff-3957-494f-abdf-049bf9b3be63) | Converts a variable of the type FLOAT to a variable of the type UINT. |
| [INT\_TO\_FLOAT](ms-xhelp:///?Id=beckhoff-0215-4320-83a7-9e41fc07887e) | Converts a variable of the type INT to a variable of the type FLOAT. |
| [SINT\_TO\_FLOAT](ms-xhelp:///?Id=beckhoff-dfc9-4137-8aa2-b3756f31784a) | Converts a variable of the type SINT to a variable of the type FLOAT. |
| [TIME\_TO\_FLOAT](ms-xhelp:///?Id=beckhoff-e1bb-4058-a9c1-2aec1bbab558) | Converts a variable of the type TIME to a variable of the type FLOAT. |
| [UDINT\_TO\_FLOAT](ms-xhelp:///?Id=beckhoff-0dc3-4a47-8a8a-a8b76946051f) | Converts a variable of the type UDINT to a variable of the type FLOAT. |
| [UINT\_TO\_FLOAT](ms-xhelp:///?Id=beckhoff-d2ce-4c77-b265-583ce51b5b5a) | Converts a variable of the type UINT to a variable of the type FLOAT. |
| [LrealIsFinite](ms-xhelp:///?Id=beckhoff-152d-4bfd-ad8b-7bbfacc83c76) | Returns TRUE, when the argument of the type LREAL has a finite value. |
| [LrealIsNaN](ms-xhelp:///?Id=beckhoff-f50b-45e9-8004-cf5c9aa021c3) | Returns TRUE, when the argument of the type LREAL has an undefined value (NaN). |

## LCOMPLEX functions

|  |  |
| --- | --- |
| [LcomplexIsNaN](ms-xhelp:///?Id=beckhoff-5d23-43cf-b4bf-c276191e47f6) | Returns TRUE, when the argument of the type LCOMPLEX has an undefined value (NaN). |
| [LcomplexAbs](ms-xhelp:///?Id=beckhoff-80b3-4f40-b0b8-ec6f6f739f81) | Returns the absolute value of the complex number transferred. |

## P[TYPE]\_TO\_[TYPE] converting functions

| Name | Description |
| --- | --- |
| [PBOOL\_TO\_BOOL](ms-xhelp:///?Id=beckhoff-9609-459a-97f7-68a733318fb5) | Returns the content of a BOOL pointer variable. |
| [PBYTE\_TO\_BYTE](ms-xhelp:///?Id=beckhoff-ca1d-4bc1-8fa8-d83d7b2d174d) | Returns the content of a BYTE pointer variable. |
| [PDATE\_TO\_DATE](ms-xhelp:///?Id=beckhoff-496f-481a-8ee2-cf1875b63174) | Returns the content of a DATE pointer variable. |
| [PDINT\_TO\_DINT](ms-xhelp:///?Id=beckhoff-5f56-4231-883d-e06633afdd33) | Returns the content of a DINT pointer variable. |
| [PDT\_TO\_TO\_DT](ms-xhelp:///?Id=beckhoff-43e3-4d9a-b7bc-1e7ff61876db) | Returns the content of a DT pointer variable. |
| [PDWORD\_TO\_DWORD](ms-xhelp:///?Id=beckhoff-6437-47b6-b307-8a32bf3f05f3) | Returns the content of a DWORD pointer variable. |
| [PHUGE\_TO\_HUGE](ms-xhelp:///?Id=beckhoff-eb8e-4b25-bc2f-f894687f7a82) | Returns the content of a T\_HUGE\_INTEGER pointer variable. |
| [PINT\_TO\_INT](ms-xhelp:///?Id=beckhoff-d3bc-4373-8abd-67e60bb09a92) | Returns the content of an INT pointer variable. |
| [PLARGE\_TO\_LARGE](ms-xhelp:///?Id=beckhoff-e3e1-4cfb-92bd-e902f9ffdc82) | Returns the content of a T\_LARGE\_INTEGER pointer variable. |
| [PLINT\_TO\_LINT](ms-xhelp:///?Id=beckhoff-4b00-4a96-ac05-19664f2a3e80) | Returns the content of a LINT pointer variable. |
| [PLREAL\_TO\_TO\_LREAL](ms-xhelp:///?Id=beckhoff-d42f-42e9-bd89-47e1472a922e) | Returns the content of a LREAL pointer variable. |
| [PLWORD\_TO\_LWORD](ms-xhelp:///?Id=beckhoff-8cac-4174-b58b-28ab61d01616) | Returns the content of a LWORD pointer variable. |
| [PMAXSTRING\_TO\_MAXSTRING](ms-xhelp:///?Id=beckhoff-f509-4583-a3f5-2e8f225ab49f) | Returns the content of a T\_MaxString pointer variable. |
| [PREAL\_TO\_REAL](ms-xhelp:///?Id=beckhoff-39b7-4b53-b52f-b0368c9c5362) | Returns the content of a REAL pointer variable. |
| [PSINT\_TO\_SINT](ms-xhelp:///?Id=beckhoff-2858-48e9-aa35-5e25b8253a8f) | Returns the content of a SINT pointer variable. |
| [PSTRING\_TO\_STRING](ms-xhelp:///?Id=beckhoff-3ee4-4d52-af9d-3ecbe82fdb16) | Returns the content of a STRING pointer variable. |
| [PTIME\_TO\_TIME](ms-xhelp:///?Id=beckhoff-80e5-49ae-b8cb-36c664502e1d) | Returns the content of a TIME pointer variable. |
| [PTOD\_TO\_TOD](ms-xhelp:///?Id=beckhoff-0407-4c30-906a-a67110fc003c) | Returns the content of a TOD pointer variable. |
| [PUDINT\_TO\_UDINT](ms-xhelp:///?Id=beckhoff-186c-44bd-90f6-b6b016be03bc) | Returns the content of an UDINT pointer variable. |
| [PUHUGE\_TO\_UHUGE](ms-xhelp:///?Id=beckhoff-0fa3-45af-b5d7-e6a7201d6743) | Returns the content of a T\_UHUGE\_INTEGER pointer variable. |
| [PUINT\_TO\_UINT](ms-xhelp:///?Id=beckhoff-9f48-4d98-9d4c-aca186102925) | Returns the content of an UINT pointer variable. |
| [PULARGE\_TO\_ULARGE](ms-xhelp:///?Id=beckhoff-a1f9-47ad-a15b-0694c3018f3e) | Returns the content of a T\_ULARGE\_INTEGER pointer variable. |
| [PULINT\_TO\_ULINT](ms-xhelp:///?Id=beckhoff-a5b5-4251-9b10-286ef87e9c5e) | Returns the content of an ULINT pointer variable. |
| [PUSINT\_TO\_USINT](ms-xhelp:///?Id=beckhoff-503e-436a-a70b-90ad9017a273) | Returns the content of an USINT pointer variable. |
| [PWORD\_TO\_WORD](ms-xhelp:///?Id=beckhoff-effe-4b2c-9c9a-bdb9279ed571) | Returns the content of a WORD pointer variable. |
| [PUINT64\_TO\_UINT64](ms-xhelp:///?Id=beckhoff-2b80-4e99-930e-189e943888d1) | Returns the content of a T\_ULARGE\_INTEGER pointer variable. |

## T\_Arg help functions

| Name | Description |
| --- | --- |
| [F\_ARGCMP](ms-xhelp:///?Id=beckhoff-45a6-4a20-9d25-a9ad79937b20) | Compares two variables of the type T\_Arg |
| [F\_ARGCPY](ms-xhelp:///?Id=beckhoff-8c22-4623-b918-599131c83885) | Copies the value of a variable of the type T\_Arg to another variable and returns the number of successfully copied data bytes. |
| [F\_ARGISZERO](ms-xhelp:///?Id=beckhoff-7052-499b-8b6d-26082326355f) | Returns TRUE if one of the T\_Arg member variables has the value zero or was not initialised. |
| [F\_BIGTYPE](ms-xhelp:///?Id=beckhoff-9439-44e6-a903-9c83f5c5d39e) | Returns information on a struct or array variable in a structure of the type T\_Arg. |
| [F\_BOOL](ms-xhelp:///?Id=beckhoff-edb2-4793-bf59-900a7013d870) | Returns information on a BOOL variable in a structure of the type T\_Arg. |
| [F\_BYTE](ms-xhelp:///?Id=beckhoff-d40f-4c2f-a0a9-d9581125e39f) | Returns information on a BYTE variable in a structure of the type T\_Arg. |
| [F\_DINT](ms-xhelp:///?Id=beckhoff-a011-41ba-ac14-ddf227d9d3ec) | Returns information on a DINT variable in a structure of the type T\_Arg. |
| [F\_DWORD](ms-xhelp:///?Id=beckhoff-08e6-4733-a65b-ffeb2bba9033) | Returns information on a DWORD variable in a structure of the type T\_Arg. |
| [F\_HUGE](ms-xhelp:///?Id=beckhoff-1633-47e2-8876-3b4b1297dd9d) | Returns information on a T\_HUGE\_INTEGER variable in a structure of the type T\_Arg. |
| [F\_INT](ms-xhelp:///?Id=beckhoff-8884-46d0-8401-e795f037a2cb) | Returns information on an INT variable in a structure of the type T\_Arg. |
| [F\_LARGE](ms-xhelp:///?Id=beckhoff-bdc0-474e-a6ca-4995f77a5692) | Returns information on a T\_LARGE\_INTEGER variable in a structure of the type T\_Arg. |
| [F\_LINT](ms-xhelp:///?Id=beckhoff-4138-4152-a8d3-6cd25a818ac9) | Returns information on a LINT variable in a structure of the type T\_Arg. |
| [F\_LREAL](ms-xhelp:///?Id=beckhoff-c525-4b79-9cef-7e093c2ed20f) | Returns information on a LREAL variable in a structure of the type T\_Arg. |
| [F\_LWORD](ms-xhelp:///?Id=beckhoff-c9ce-42dd-99f5-1344a6bd2053) | Returns information on a LWORD variable in a structure of the type T\_Arg. |
| [F\_REAL](ms-xhelp:///?Id=beckhoff-9458-453d-8ade-48d9876779e4) | Returns information on a REAL variable in a structure of the type T\_Arg. |
| [F\_SINT](ms-xhelp:///?Id=beckhoff-b325-453e-ad3d-38b18f6a33da) | Returns information on a SINT variable in a structure of the type T\_Arg. |
| [F\_STRING](ms-xhelp:///?Id=beckhoff-6a77-44ce-a6fc-70c776b2fd5a) | Returns information on a T\_MaxString variable in a structure of the type T\_Arg. |
| [F\_UDINT](ms-xhelp:///?Id=beckhoff-9ba1-46a2-bb28-435ec870d7e2) | Returns information on an UDINT variable in a structure of the type T\_Arg. |
| [F\_UHUGE](ms-xhelp:///?Id=beckhoff-0dfd-43f4-8b52-9d1f2346cba9) | Returns information on a T\_UHUGE\_INTEGER variable in a structure of the type T\_Arg. |
| [F\_UINT](ms-xhelp:///?Id=beckhoff-dc19-4c0e-9a2a-90a1c40e5430) | Returns information on an UINT variable in a structure of the type T\_Arg. |
| [F\_ULARGE](ms-xhelp:///?Id=beckhoff-ee6d-43d6-a14f-fe0949b9ef6a) | Returns information on a T\_ULARGE\_INTEGER variable in a structure of the type T\_Arg. |
| [F\_ULINT](ms-xhelp:///?Id=beckhoff-3c34-4c70-a162-c672d8f68fa5) | Returns information on an ULINT variable in a structure of the type T\_Arg. |
| [F\_USINT](ms-xhelp:///?Id=beckhoff-3296-4240-9ec5-2f84c4272563) | Returns information on an USINT variable in a structure of the type T\_Arg. |
| [F\_WORD](ms-xhelp:///?Id=beckhoff-bf56-47a2-b979-8f8d1afba16a) | Returns information on a WORD variable in a structure of the type T\_Arg. |
| [F\_PVOID](ms-xhelp:///?Id=beckhoff-7a09-4b51-8c38-ceb884f3e0a2) | Returns information on a PVOID variable in a structure of the type T\_Arg. |

## CSV format functions

| Name | Description |
| --- | --- |
| [CSVFIELD\_TO\_STRING](ms-xhelp:///?Id=beckhoff-bac9-42bb-a52d-ef0812cb7833) | Converts the value of a string with a data field in CSV format into an PLC string variable. |
| [STRING\_TO\_CSVFIELD](ms-xhelp:///?Id=beckhoff-1943-47a0-a7c9-12bc3a3fad05) | Converts the value of a PLC string variable into a string with a data field in CSV format. |
| [CSVFIELD\_TO\_ARG](ms-xhelp:///?Id=beckhoff-ecdd-4181-86b0-997b40f67d70) | Converts a byte buffer with a data field in CSV format into a value of a random PLC variable. |
| [ARG\_TO\_CSVFIELD](ms-xhelp:///?Id=beckhoff-2037-4b5d-879e-e8cb560a011f) | Converts the value of a random PLC variable into a byte buffer with a data field in CSV format. |
| [FB\_CSVMemBufferReader](ms-xhelp:///?Id=beckhoff-1a3d-4151-8c6a-22708123ce55) | Splits data sets in CSV format which are in a byte buffer into individual data fields. |
| [FB\_CSVMemBufferWriter](ms-xhelp:///?Id=beckhoff-aa85-4a67-bf7a-9380e201eead) | Generates individual or several data sets in a byte buffer from individual data fields |

## Licensing functions

| Name | Description |
| --- | --- |
| [FB\_LicFileGetStorageInfo](ms-xhelp:///?Id=beckhoff-2ec4-4eb5-b2e8-faa731a51f98) | Reads the StorageInfo of the license dongle and the file directory. |
| [FB\_LicFileCreate](ms-xhelp:///?Id=beckhoff-035d-4a20-89b2-dc22f40516ca) | Creates a file on the license dongle. |
| [FB\_LicFileDelete](ms-xhelp:///?Id=beckhoff-2096-494b-b55b-c4e68be3c391) | Deletes a file from the license dongle. |
| [FB\_LicFileRead](ms-xhelp:///?Id=beckhoff-b895-4d5e-835c-a6b8bab006cf) | Reads a file from the license dongle to a buffer. |
| [FB\_LicFileCopyToDongle](ms-xhelp:///?Id=beckhoff-3f21-4f6a-9f37-808a30ed405c) | Copies a file from the hard disk to the license dongle. |
| [FB\_LicFileCopyFromDongle](ms-xhelp:///?Id=beckhoff-de48-4878-abc1-370b995606f3) | Copies a file from the license dongle to the hard disk. |
| [FB\_CheckLicense](ms-xhelp:///?Id=beckhoff-0af8-4a48-b12c-a9bc5aca3e9b) | Determines the TwinCAT 3 license status for a given license ID. |
| [FB\_GetDongleSystemId](ms-xhelp:///?Id=beckhoff-a901-4d7e-9def-787fdb07a18f) | Reads the system ID and the volume ID of the TwinCAT 3 license dongle as GUID. |
| [FB\_GetLicenseDongle](ms-xhelp:///?Id=beckhoff-b476-4a30-9655-abae01d8cbd2) | Determines the number of connected license dongles and returns address and status. |
| [FB\_GetLicenses](ms-xhelp:///?Id=beckhoff-f433-46e0-a525-72a322cb0ecd) | Reads the valid and invalid TwinCAT licenses. |
| [FB\_GetLicensesEx](ms-xhelp:///?Id=beckhoff-9ab0-4a6e-9ffe-4ec28ffd4e2c) | Determines the status of all TwinCAT 3 licenses and OEM licenses. |

## Other functions

| Name | Description |
| --- | --- |
| [FB\_BasicPID](ms-xhelp:///?Id=beckhoff-adf9-4340-8599-81e321d2786e) | Simple PID controller |
| [F\_GetVersionTcUtilities](ms-xhelp:///?Id=beckhoff-f549-4c79-b311-09ee9b74c7a5) | Reading version information of the library. |
| [IsFinite](ms-xhelp:///?Id=beckhoff-d64a-44c6-9893-70cb89e85235) | Verifies the formatting of a floating point number in accordance with the IEEE. |
| [F\_YearIsLeapYear](ms-xhelp:///?Id=beckhoff-c621-45c3-b274-f988fc63303a) | Determines whether a year is a leap year. |
| [F\_GetMaxMonthDays](ms-xhelp:///?Id=beckhoff-3ea5-48b9-8a73-4fa09fc06617) | Determines the maximum number of days in a month. |
| [F\_GetDOYOfYearMonthDay](ms-xhelp:///?Id=beckhoff-b06e-4638-8cdd-ad4afee200e7) | Determines the number of the day in the year. |
| [F\_GetMonthOfDOY](ms-xhelp:///?Id=beckhoff-3ba9-401e-a84a-9ba06571c576) | Determines the month based on the day number in the year. |
| [F\_GetDayOfWeek](ms-xhelp:///?Id=beckhoff-e451-47fc-92f4-5b1e9ddc3e81) | Determines the number of the weekday. |
| [F\_GetWeekOfTheYear](ms-xhelp:///?Id=beckhoff-bf0d-43c9-aecc-71cf4c847050) | Determines the calendar week. |
| [F\_GetDayOfMonthEx](ms-xhelp:///?Id=beckhoff-460e-4307-ba2e-dcbe92699a51) | Determines the date of the first, second etc. weekday in a specified month and year. |
| [F\_GetWeekOfTheYear](ms-xhelp:///?Id=beckhoff-bf0d-43c9-aecc-71cf4c847050) | Returns the number of the calendar week for a predefined date. |
| [RTC](ms-xhelp:///?Id=beckhoff-2d6e-4437-8c41-351693b53644) | "Software"-RTC (Real Time Clock) |
| [RTC\_EX](ms-xhelp:///?Id=beckhoff-707f-42bb-b305-7991c176d0cb) | "Software"-RTC (Real Time Clock) |
| [RTC\_EX2](ms-xhelp:///?Id=beckhoff-9781-443d-9629-00a35143e9cd) | "Software"-RTC (Real Time Clock) |
| [FB\_FileRingBuffer](ms-xhelp:///?Id=beckhoff-9efb-4052-a2f1-dbe10286d0bb) | Writes/reads data sets to or from the file (FIFO). |
| [FB\_MemRingBuffer](ms-xhelp:///?Id=beckhoff-78e0-425e-87c1-cbc261e3da6c) | Writes/reads data sets to or from a buffer variable (FIFO). |
| [FB\_MemRingBufferEx](ms-xhelp:///?Id=beckhoff-c930-4d88-936a-477f35d2380d) | Writes/reads data sets to or from a buffer variable (FIFO). |
| [FB\_StringRingBuffer](ms-xhelp:///?Id=beckhoff-8c4c-417b-aab5-d66909b194c1) | Writes/reads strings to or from a buffer variable (FIFO). |
| [FB\_MemStackBuffer](ms-xhelp:///?Id=beckhoff-ab20-4457-b683-c9bb5c4d5cc1) | Writes/reads data sets to or from a buffer variable (LIFO). |
| [FB\_MemBufferMerge](ms-xhelp:///?Id=beckhoff-a41c-4054-a8a5-d2bb8724eed6) | Merges individual small data segments to one larger data segment. |
| [FB\_MemBufferSplit](ms-xhelp:///?Id=beckhoff-27c7-48ad-9bf7-42700420e578) | Splits a memory area (data buffer) into several smaller segments. |
| [FB\_HashTableCtrl](ms-xhelp:///?Id=beckhoff-b702-456e-9a3d-bc5349e22c87), [F\_CreateHashTableHnd](ms-xhelp:///?Id=beckhoff-d385-465c-a304-0e60b9d1d697) | Simple hash table. |
| [FB\_LinkedListCtrl](ms-xhelp:///?Id=beckhoff-ef44-4813-9f63-c2cc598139aa), [F\_CreateLinkedListHnd](ms-xhelp:///?Id=beckhoff-fd6d-424b-8831-b982879d9f9a) | Simple linked list (double linked). |
| [DCF77\_TIME](ms-xhelp:///?Id=beckhoff-9208-4bd2-b42f-0354e8f0bcca) | A simple DCF77 decoder. |
| [DCF77\_TIME\_EX](ms-xhelp:///?Id=beckhoff-bf0d-4830-baf2-cbf3f6769bd3) | DCF77 decoder with plausibility check of two consecutive telegrams and time zone information. |
