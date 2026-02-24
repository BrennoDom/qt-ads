# System behavior when writing persistent data

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# System behavior when writing persistent data

| Write trigger | Internal optimization of persistent data access | Persistent data consistency | Plc cycle time exceedance |
| --- | --- | --- | --- |
| Function block [WritePersistentData](ms-xhelp:///?Id=beckhoff-1774-419f-81e7-bff0bfa2ac30) | None | All data is from same plc cycle. | Yes, if writing of all data takes more than plc cycle time. |
| Function block [FB\_WritePersistentData](ms-xhelp:///?Id=beckhoff-d009-43a5-8dbb-27889de4e9ba) and [SPDM\_2PASS](ms-xhelp:///?Id=beckhoff-d922-4389-8eb8-82fb561e5965) | Yes | All data is from same plc cycle. | Yes, if writing of all data takes more than plc cycle time. |
| Function block [FB\_WritePersistentData](ms-xhelp:///?Id=beckhoff-d009-43a5-8dbb-27889de4e9ba) and [SPDM\_VAR\_BOOST](ms-xhelp:///?Id=beckhoff-d922-4389-8eb8-82fb561e5965) | Yes | The data of each variable is from same plc cycle. | Rare, if writing of biggest pers. variable takes more than plc cycle time. |
| TwinCAT system stop (all persistent data is written automatically on TwinCAT system stop). | Yes | All data is from same plc cycle. | None |
